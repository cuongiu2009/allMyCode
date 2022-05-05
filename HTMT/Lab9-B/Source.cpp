#include <iostream>
#include <vector>
using namespace std;
class NhanVien {
protected:
	string hoten;
	int maSo;
	static int sl, n;
public:
	NhanVien() :hoten(""), maSo(0) {}
	NhanVien(int ms, string ten) :maSo(ms), hoten(ten) {}
	int num() { return sl; }
	int QL() { return n; }
	virtual~NhanVien() { sl--; }
	virtual float salary() {
		return 0;
	}
	virtual void Display() = 0;
	virtual int getSoluong() {
		return n;
	}
};
class NhanVienSX :public NhanVien {
private:
	int sp;
public:
	NhanVienSX() :NhanVien(), sp(0) {}
	NhanVienSX(int ms, string ten, int pro) :NhanVien(ms, ten), sp(pro) { sl++; }
	float salary() {
		return 20000 * sp;
	}
	void Display() { cout << "ten:" << hoten << ", ma so:" << maSo << ", tien luong:" << salary() << endl; }
};
class NhanVienCN :public NhanVien {
private:
	int ngayCong;
public:
	NhanVienCN() :NhanVien(), ngayCong(0) {}
	NhanVienCN(int ms, string ten, int ngay) :NhanVien(ms, ten), ngayCong(ngay) { sl++; }
	float salary() {
		return 50000 * ngayCong;
	}
	void Display() { cout << "ten:" << hoten << ", ma so:" << maSo << ", tien luong:" << salary() << endl; }
};
class NhanVienQL :public NhanVien {
private:
	int hsluong;
public:
	NhanVienQL() :NhanVien(), hsluong(0) {}
	NhanVienQL(int ms, string ten, int hs) :NhanVien(ms, ten), hsluong(hs) { sl++; n++; }
	float salary() {
		return 4000000 * hsluong;
	}
	int getSoluong() {
		return n;
	}
	void Display() { cout << "ten:" << hoten << ", ma so:" << maSo << ", tien luong:" << salary() << endl; }
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
			for (int i = 0; i < nv.size(); i++)
				delete nv[i];
		}
	}
	void addNV(NhanVien* nhanvien) {
		nv.push_back(nhanvien);
	}
	void danhSach() {
		if (!nv.empty()) {
			for (vector<NhanVien*>::iterator it = nv.begin(); it != nv.end(); it++) {
				if (*it)
					(*it)->Display();
			}
		}
	}
	int SoLuongNV() {
		int res = 0;
		if (!nv.empty()) {
			for (vector<NhanVien*>::iterator it = nv.begin(); it != nv.end(); it++) {
				if (*it)
					res = (*it)->num();
			}
		}
		return res;
	}
	int luongNVQL() {//bug
		int res = 0;
		if (!nv.empty()) {
			for (vector<NhanVien*>::iterator it = nv.begin(); it != nv.end(); it++) {
				if (*it)
					res = (*it)->getSoluong();
			}
		}
		return res;
	}
};
int NhanVien::sl = 0;
int NhanVien::n = 0;
int main() {
	CongTy ct;
	ct.addNV(new NhanVienCN(20127142, "Le Phi Duong", 20));
	ct.addNV(new NhanVienSX(20127143, "Le Hai Duong", 30));
	ct.addNV(new NhanVienSX(20127144, "Le Hai Duong", 2));
	ct.addNV(new NhanVienQL(20127144, "Le Hai Duong", 2));
	ct.addNV(new NhanVienQL(20127144, "Le Hai Duong", 2));
	ct.danhSach();
	cout << "so luong nv:" << ct.SoLuongNV() << endl;
	cout << "NVQL:" << ct.luongNVQL();
	return 0;
}