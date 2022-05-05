#include <iostream>
#include <vector>
#include <string>
using namespace std;

class NhanVien
{
protected:
    string m_name;         
	string m_city;
public:
    NhanVien() : m_name(""), m_city(""){}
    NhanVien(string name, string city) : m_name(name), m_city(city){}
    virtual ~NhanVien() {}
  
	virtual bool isGood() { return true; }
    void DisplayDefault()    
    {
        cout << m_name << " ,<" << m_city<<">" << endl;
    }
    void DisplayRank()        
    {
        cout << m_name << " ,<" << m_city << ">, ";
        cout << endl;
    }
    virtual void DisplayDetail() = 0;       
    virtual void DisplayRankDetail() = 0;  
};
class NhanVienThuKy : public NhanVien
{
private:
	string m_language;    
	int m_report;       
public:
	NhanVienThuKy() : NhanVien(), m_language(""), m_report(0) {}
	NhanVienThuKy(string name, string city, string language, int report)
		: NhanVien(name, city), m_language(language), m_report(report) {}
	~NhanVienThuKy() {}
	bool isGood() {
		if (m_report >= 12)
			return true;
	}
	void DisplayDetail()
	{
		cout << m_name << " ,<" << m_city << ">, " << m_language << ", bao cao hoan thanh:" << m_report << endl;
	}
	void DisplayRankDetail()
	{
		cout << m_name << " ,<" << m_city << ">, " << m_language << ", bao cao hoan thanh:" << m_report;
		cout << endl;
	}
};
class NhanVienKyThuat :public NhanVien {
private:
	string certify;
	int creative;
public:
	NhanVienKyThuat() :NhanVien(), certify(""), creative(0) {}
	NhanVienKyThuat(string m_name, string m_city, string m_certify, int m_creative)
		:NhanVien(m_name, m_city), certify(m_certify), creative(m_creative) {}
	~NhanVienKyThuat(){}
	bool isGood() {
		if (creative >= 6)
			return true;
	}
	void DisplayDetail() {
		cout << m_name << " ,<" << m_city << ">, " << certify << ", sang tao:" << creative << endl;
	}
	void DisplayRankDetail() {
		cout << m_name << " ,<" << m_city << ">, " << certify << ", sang tao:" << creative;
		cout << endl;
	}
};
class CongTy {
private:
	vector<NhanVien*>nv;
public:
	CongTy() {
		nv.resize(0);
	}
	~CongTy() {
		if (!nv.empty()) {
			for (vector<NhanVien*>::iterator it = nv.begin(); it != nv.end(); it++) {
				if (*it)
					delete(*it);
			}
		}
	}
	void ThemNhanVien(NhanVien* nvien) {
		nv.push_back(nvien);
	}
	void DanhSachNV(ostream&) {
		if (!nv.empty()) {
			for (vector<NhanVien*>::iterator it = nv.begin(); it != nv.end(); it++) {
				if (*it)
					(*it)->DisplayDetail();
			}
		}
		cout << endl;
	}
	void DanhSachNVXuatSac(ostream&) {
		if (!nv.empty()) {
			for (vector<NhanVien*>::iterator it = nv.begin(); it != nv.end(); it++) {
				if ((*it) and (*it)->isGood()==true)
					(*it)->DisplayDetail();
			}
		}
	}
};
int main() {
	CongTy cty;
	cty.ThemNhanVien(new NhanVienThuKy("Nguyen Thi A", "Tp Ho Chi Minh", "Toefl iBT 100", 15));
	cty.ThemNhanVien(new NhanVienKyThuat("Tran Van B", "Tp Ho Chi Minh", "CNTT",8));
	cty.ThemNhanVien(new NhanVienThuKy("Le Nguyen Z", "Tp Ha Noi", "TOEIC 700",10));
	cty.ThemNhanVien(new NhanVienKyThuat("Do Lan T", "Binh Duong", "Hoa thuc pham", 4));
	cty.ThemNhanVien(new NhanVienKyThuat("Hoang Van D", "Khanh Hoa", "Dien tu",10));
	cty.ThemNhanVien(new NhanVienThuKy("Ngo E", "Tp Ha Noi", "IELTS 7.0", 12));
	cout << "DS Nhan vien trong cong ty:" << endl;
	cty.DanhSachNV(cout);
	cout << endl << "DS Nhan vien xuat sac:" << endl;
	cty.DanhSachNVXuatSac(cout);
	cout << endl;
	return 0;
}