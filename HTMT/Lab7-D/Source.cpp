#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
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
};
class HinhTamGiac :
	public HinhHocPhang
{
private:
	float a, b, c;
public:
	HinhTamGiac() :HinhHocPhang(), a(0), b(0), c(0) {}
	HinhTamGiac(float canh1, float canh2, float canh3) :HinhHocPhang(),a(abs(canh1)),b(abs(canh2)),c(abs(canh3)){}
	float ChuVi() {
		float s = 0;
		s = a + b + c;
		return s;
	}
	float TinhDienTich() {
		float p = ChuVi() / 2.0;
		return sqrt(p * (p - a) * (p - b) * (p - c));//56.56
	}
};
class HinhThangVuong :public HinhHocPhang {
private:
	float cao, rong, dai;
public:
	HinhThangVuong() :HinhHocPhang(), cao(0), rong(0), dai(0) {}
	HinhThangVuong(float large, float small, float height) :HinhHocPhang(), dai(large), rong(small), cao(height) {}
	float TinhDienTich() {
		return ((dai + rong) * cao) / 2;//32.725
	}
	float ChuVi() {
		return sqrt((dai - rong) * (dai - rong) + cao * cao) + dai + rong + cao;
	}
};
class HinhChuNhat:
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
};
#define PI 3.14159
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
};
class QuanLyHinhHocPhang {
private:
	vector<HinhHocPhang*>HHP;
public:
	QuanLyHinhHocPhang() {
		HHP.resize(0);
	}
	~QuanLyHinhHocPhang() {
		if (!HHP.empty()) {
			for (int i = 0; i < HHP.size(); i++)
				delete HHP[i];
		}
	}
	void AddHinh(HinhHocPhang* p) {
		HHP.push_back(p);
	}
	float TongDienTich() {
		float tdt = 0;
		if (!HHP.empty()) {
			for (vector<HinhHocPhang*>::iterator it = HHP.begin(); it != HHP.end(); it++) {
				if (*it)
					tdt += (*it)->TinhDienTich();
			}
		}
		return tdt;
	}
	float TongChuVi() {
		float tcv = 0;
		if (!HHP.empty()) {
			for (vector<HinhHocPhang*>::iterator it = HHP.begin(); it != HHP.end(); it++) {
				if (*it)
					tcv += (*it)->ChuVi();
			}
		}
		return tcv;
	}
};
int main()
{
	QuanLyHinhHocPhang ql;
	ql.AddHinh(new HinhChuNhat(5.6, 2.3));
	ql.AddHinh(new HinhTamGiac(-1.5, 6.7, 5.9));
	ql.AddHinh(new HinhTron(12.7));
	ql.AddHinh(new HinhThangVuong(8.6, 10.1, 3.5));
	cout << "Tong Dien tich: " << ql.TongDienTich() << endl;
	cout << "Tong Chu vi: " << ql.TongChuVi() << endl;
	return 0;
}