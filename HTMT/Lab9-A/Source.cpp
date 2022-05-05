#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define PI 3.14159
class HinhHocPhang
{
public:
	HinhHocPhang(void) {}
	~HinhHocPhang(void) {}
	virtual float TinhDienTich() {
		return 0;
	}
	virtual float ChuVi() {
		return 0;
	}
	virtual void DisplayDetail() = 0;
};
class HinhTamGiacDeu :
	public HinhHocPhang
{
private:
	float a;
public:
	HinhTamGiacDeu() :HinhHocPhang(), a(0) {}
	HinhTamGiacDeu(float canh1) :HinhHocPhang(), a(abs(canh1)) {}
	float ChuVi() {
		float s = 0;
		s = a * 3;
		return s;
	}
	float TinhDienTich() {
		float p = ChuVi() / 2.0;
		return sqrt(p * (p - a) * (p - a) * (p - a));//56.56
	}
	void DisplayDetail() {
		cout << "Hinh tam giac deu canh " << a << " co P=" << ChuVi() << ", S=" << TinhDienTich() << endl;
	}
};
class HinhChuNhat :
	public HinhHocPhang
{
private:
	float chieuDai, chieuRong;
public:
	HinhChuNhat() {
		chieuDai = chieuRong = 0;
	}

	HinhChuNhat(const float& cd, const float& cr) {
		chieuDai = (cd == 0) ? 1 : abs(cd);
		chieuRong = (cr == 0) ? 1 : abs(cr);
	}
	~HinhChuNhat() {}
	float TinhDienTich() {
		return chieuDai * chieuRong;//12.88
	}
	float ChuVi() {
		return (chieuDai + chieuRong) * 2;
	}
	void DisplayDetail() {
		cout << "Hinh chu nhat co chieu dai: " << chieuDai <<", chieu rong:"<<chieuRong<< ", co P=" << ChuVi() << ", S=" << TinhDienTich() << endl;
	}
};
class HinhVuong :
	public HinhHocPhang
{
private:
	float canh;
public:
	HinhVuong():HinhHocPhang(),canh(0){}
	HinhVuong(float a):HinhHocPhang(),canh(a){}
	~HinhVuong(){}
	float ChuVi() {
		return canh * 4;
	}
	float TinhDienTich() {
		return canh * canh;
	}
	void DisplayDetail() {
		cout << "Hinh vuong co canh: " << canh << ", co P=" << ChuVi() << ", S=" << TinhDienTich() << endl;
	}
};
class HinhTron :
	public HinhHocPhang
{
private:
	float banKinh;
public:
	HinhTron() {
		banKinh = 0;
	}
	HinhTron(const float& bk) {
		banKinh = (bk == 0) ? 1 : abs(bk);
	}
	~HinhTron() {}
	float TinhDienTich() {
		return PI * banKinh * banKinh;//506.45
	}
	float ChuVi() {
		return PI * banKinh * 2;
	}
	void DisplayDetail() {
		cout << "Hinh tron co ban kinh: " << banKinh << ", co P=" << ChuVi() << ", S=" << TinhDienTich() << endl;
	}
};

class HinhKhongGian {
public:
	HinhKhongGian(void){}
	~HinhKhongGian(void){}
	virtual float DienTichXQ(){
		return 0;
	}
	virtual float TheTich() {
		return 0;
	}
	virtual void DisplayDetail() = 0;
};
class HinhCau :
	public HinhKhongGian
{
private:
	float r;
public:
	HinhCau():HinhKhongGian(),r(0){}
	HinhCau(float a) :HinhKhongGian(), r(a) {}
	~HinhCau(){}
	float DienTichXQ() {
		return 4 * PI * r * r;
	}
	float TheTich() {
		return (4 * 1.0 / 3) * PI * r * r * r;
	}
	void DisplayDetail() {
		cout << "Hinh cau co ban kinh: " << r << ", co dien tich xung quanh=" << DienTichXQ() << ", the tich=" << TheTich() << endl;
	}
};
class HinhLapPhuong :
	public HinhKhongGian
{
private:
	float canh;
public:
	HinhLapPhuong():HinhKhongGian(),canh(0){}
	HinhLapPhuong(float a):HinhKhongGian(),canh(a){}
	~HinhLapPhuong(){}
	float DienTichXQ() {
		return canh * canh * 4;
	}
	float TheTich() {
		return canh * canh * canh;
	}
	void DisplayDetail() {
		cout << "Hinh lap phuong co canh: " << canh << ", co dien tich xung quanh=" << DienTichXQ() << ", the tich=" << TheTich() << endl;
	}
};

class HinhHoc {
private:
	vector<HinhKhongGian*>HKG;
	vector<HinhHocPhang*>HHP;
public:
	HinhHoc() {
		HHP.resize(0);
		HKG.resize(0);
	}
	~HinhHoc() {
		if (!HHP.empty()) {
			for (int i = 0; i < HHP.size(); i++) {
				delete HHP[i];
			}
		}
		if (!HKG.empty()) {
			for (int i = 0; i < HKG.size(); i++) {
				delete HKG[i];
			}
		}
	}
	void addHinhHocPhang(HinhHocPhang* hhp) {
		HHP.push_back(hhp);
	}
	void addHinhKhongGian(HinhKhongGian* hkg) {
		HKG.push_back(hkg);
	}
	void DanhSachHH() {
		if (!HHP.empty()) {
			for (vector<HinhHocPhang*>::iterator it = HHP.begin(); it != HHP.end(); it++) {
				if (*it)
					(*it)->DisplayDetail();
			}
		}
		if (!HKG.empty()) {
			for (vector<HinhKhongGian*>::iterator it = HKG.begin(); it != HKG.end(); it++) {
				if (*it)
					(*it)->DisplayDetail();
			}
		}
		cout << endl;
	}

};
int main()
{
	HinhHoc hh;
	hh.addHinhHocPhang(new HinhTron(3));
	hh.addHinhHocPhang(new HinhTamGiacDeu(4));
	hh.addHinhHocPhang(new HinhChuNhat(3, 4));
	hh.addHinhHocPhang(new HinhVuong(5));
	hh.addHinhKhongGian(new HinhCau(3));
	hh.addHinhKhongGian(new HinhLapPhuong(5));
	hh.DanhSachHH();
	return 0;
}
