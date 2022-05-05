#include <iostream>
#include <vector>
#include <algorithm>
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
	virtual bool isY() {
		return true;
	}
	virtual string name() = 0;
};
class HinhTamGiac :
	public HinhHocPhang
{
private:
	float a1, a2, b1, b2, c1, c2;
public:
	HinhTamGiac() :HinhHocPhang(), a1(0), b1(0), c1(0),a2(0),b2(0),c2(0) {}
	HinhTamGiac(float xA, float yA, float xB,float yB,float xC,float yC) :HinhHocPhang(), a1(xA),a2(yA),b1(xB),b2(yB),c1(xC),c2(yC) {}
	float ChuVi() {
		float s = 0;
		return s = sqrt((a1 - b1) * (a1 - b1) + (a2 - b2) * (a2 - b2)) + sqrt((b1 - c1) * (b1 - c1) + (b2 - c2) * (b2 - c2)) + sqrt((a1 - c1) * (a1 - c1) + (a2 - c2) * (a2 - c2));
	}
	float TinhDienTich() {
		float p = ChuVi() / 2.0;
		return sqrt(p - sqrt((a1 - b1) * (a1 - b1) + (a2 - b2) * (a2 - b2))) * (p - sqrt((b1 - c1) * (b1 - c1) + (b2 - c2) * (b2 - c2))) * (p - sqrt((a1 - c1) * (a1 - c1) + (a2 - c2) * (a2 - c2)));
	}
	bool isY() {
		if (a1 > 0 && a2 > 0 && b1 > 0 && b2 > 0 && c1 > 0 && c2 > 0)
			return false;
		else if (a1 < 0 && a2 < 0 && b1 < 0 && b2 < 0 && c1 < 0 && c2 < 0)
			return false;
		else return true;
	}
	string name() {
		string s = "Hinh tam giac";
		return s;
	}
};
class HinhChuNhat :
	public HinhHocPhang
{
private:
	float a1, a2, b1, b2, c1, c2;
public:
	HinhChuNhat():a1(0),a2(0),b1(0),b2(0),c1(0),c2(0) {}
	HinhChuNhat(float xA, float yA, float xB, float yB, float xC, float yC) :HinhHocPhang(), a1(xA), a2(yA), b1(xB), b2(yB), c1(xC), c2(yC) {}
	~HinhChuNhat() {}
	float TinhDienTich() {
		return sqrt((a1 - b1) * (a1 - b1) + (a2 - b2) * (a2 - b2)) * sqrt((b1 - c1) * (b1 - c1) + (b2 - c2) * (b2 - c2));
	}
	float ChuVi() {
		return sqrt((a1 - b1) * (a1 - b1) + (a2 - b2) * (a2 - b2)) + sqrt((b1 - c1) * (b1 - c1) + (b2 - c2) * (b2 - c2)) * 2;
	}
	bool isY() {
		if (a1 > 0 && a2 > 0 && b1 > 0 && b2 > 0 && c1 > 0 && c2 > 0)
			return true;
		else if (a1 < 0 && a2 < 0 && b1 < 0 && b2 < 0 && c1 < 0 && c2 < 0)
			return true;
		else return false;
	}
	string name() {
		string s = "Hinh chu nhat";
		return s;
	}
};
#define PI 3.14159
class HinhTron :
	public HinhHocPhang
{
private:
	float a1, a2, b1, b2;
public:
	HinhTron() :HinhHocPhang(), a1(0), a2(0), b1(0), b2(0) {}
	HinhTron(float xA, float yA, float xB, float yB) :HinhHocPhang(), a1(xA), a2(yA), b1(xB), b2(yB) {}
	~HinhTron() {}
	float TinhDienTich() {
		return PI * sqrt((a1 - b1) * (a1 - b1) + (a2 - b2) * (a2 - b2)) * sqrt((a1 - b1) * (a1 - b1) + (a2 - b2) * (a2 - b2));
	}
	float ChuVi() {
		return PI * sqrt((a1 - b1) * (a1 - b1) + (a2 - b2) * (a2 - b2)) * 2;
	}
	bool isY() {
		if (a1 > 0 && a2 > 0 && b1 > 0 && b2 > 0)
			return false;
		else if (a1 < 0 && a2 < 0 && b1 < 0 && b2 < 0)
			return false;
		else return true;
	}
	string name() {
		string s = "Hinh tron";
		return s;
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
	void outputCV() {
		if (!HHP.empty()) {
			for (vector<HinhHocPhang*>::iterator it = HHP.begin(); it != HHP.end(); it++) {
				if (*it)
					cout << (*it)->ChuVi() << " ";
			}
		}
	}
	void outputDT() {
		if (!HHP.empty()) {
			for (vector<HinhHocPhang*>::iterator it = HHP.begin(); it != HHP.end(); it++) {
				if (*it)
					cout << (*it)->TinhDienTich() << " ";
			}
		}
	}
	void outputisY() {
		if (!HHP.empty()) {
			for (int i = 0; i < HHP.size(); i++) {
				if (HHP[i]->isY())
					cout << HHP[i]->name() << " ";
			}
		}
	}
};
int main() {
	QuanLyHinhHocPhang ql;
	ql.AddHinh(new HinhChuNhat(0, 0, 1, 0, 1, 1));
	ql.AddHinh(new HinhTamGiac(0, 0, 1, 0, 1, 1));
	ql.AddHinh(new HinhTron(0, 0, 1, 1));
	ql.outputCV();
	cout << endl;
	ql.outputDT();
	cout << endl;
	ql.outputisY();
	return 0;
}