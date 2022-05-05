#include <iostream>
using namespace std;
int ucln(int a, int b)
{
	if (a % b != 0)
		return ucln(b, a % b);
	return b;
}
class PhanSo {
protected:
	int tu, mau;
public:
	PhanSo()
	{
		tu = 0;
		mau = 1;
	}
	PhanSo(const int& a)
	{
		tu = a;
		mau = 1;
	}
	PhanSo(int a, int b)
	{
		tu = a;
		mau = b;
		rutgon();
	}
	void rutgon() {
		int uc = ucln(tu, mau);
		tu = tu / uc;
		mau = mau / uc;
	}
	PhanSo operator+(const PhanSo&r) {
		int t, m;
		t = tu * r.mau + mau * r.tu;
		m = mau * r.mau;
		int uc = ucln(t, m);
		t = t / uc;
		m = m / uc;
		return PhanSo(t, m);
	}
	friend ostream& operator << (ostream& os, const PhanSo& r) {
		os << r.tu << "/" << r.mau << endl;
		return os;
	}
	friend istream& operator >> (istream& is, PhanSo& r) {
		is >> r.tu;
		is >> r.mau;
		return is;
	}
};
class PhanSo1:public PhanSo {
private:
	int dau;
public:
	PhanSo1();
	PhanSo1(const int& a) :PhanSo(a) {
		dau = 1;
	}
	PhanSo1(const int&, const int& , int s);
	PhanSo1 operator-(const PhanSo1& r);
	PhanSo1 operator+(const PhanSo1& r);
	PhanSo1 operator*(const PhanSo1& r);
	PhanSo1 operator / (const PhanSo1& r);
	bool operator >= (const PhanSo1& r) {
		PhanSo1 a;
		if (a.dau == r.dau) {
			if (a.mau == r.mau && a.tu >= r.tu)
				return true;
			else if (a.mau == r.mau && a.tu <= r.tu)
				return false;
			else if (a.mau != r.mau)
			{
				double temp1 = 1.0 * a.tu / a.mau;
				double temp2 = 1.0 * r.tu / r.mau;
				if (temp1 - temp2 >= 0)
					return false;
			}
		}
		else if (a.dau == 0 && r.dau == 1)
			return false;
		else if (a.dau == 1 && r.dau == 0)
			return true;
	}
	bool operator <= (const PhanSo1& r) {
		PhanSo1 a;
		if (a.dau == r.dau)
		{
			if (a.mau == r.mau && a.tu >= r.tu)
				return false;
			else if (a.mau == r.mau && a.tu <= r.tu)
				return true;
			else if (a.mau != r.mau)
			{
				double temp1 = 1.0 * a.tu / a.mau;
				double temp2 = 1.0 * r.tu / r.mau;
				if (temp1 - temp2 >= 0)
					return true;
			}
		}
		else if (a.dau == 0 && r.dau == 1)
			return false;
		else if (a.dau == 1 && r.dau == 0)
			return true;
	}
	bool operator == (const PhanSo1& r) {
		PhanSo1 a;
		double temp = 1.0 * a.tu / a.mau;
		double temp1 = 1.0 * r.tu / r.mau;
		if (temp1 != temp)
			return false;
		else return true;
	}
	bool operator != (const PhanSo1& r) {
		PhanSo1 a;
		double temp = 1.0 * a.tu / a.mau;
		double temp1 = 1.0 * r.tu / r.mau;
		if (temp1 != temp)
			return true;
		else return false;
	}
	PhanSo1 operator ++() {
		tu += mau;
		return *this;
	}
	PhanSo1 operator --() {
		tu -= mau;
		return *this;
	}
	friend ostream& operator << (ostream& os, const PhanSo1& r);
};
PhanSo1::PhanSo1() :PhanSo() {
	dau = 1;
}
PhanSo1::PhanSo1(const int& a, const int& b, int s):PhanSo(a,b) {
	dau = s;
	PhanSo::rutgon();
}
PhanSo1 PhanSo1::operator-(const PhanSo1& r)
{
	int t, m;
	t = tu * r.mau - mau * r.tu;
	m = mau * r.mau;
	int uc = ucln(t, m);
	t = t / uc;
	m = m / uc;
	return PhanSo1(t, m, 1);
}
PhanSo1 PhanSo1::operator+(const PhanSo1& r) {
	int t, m;
	t = tu * r.mau + mau * r.tu;
	m = mau * r.mau;
	int uc = ucln(t, m);
	t = t / uc;
	m = m / uc;
	return PhanSo1(t, m, 1);
}
PhanSo1 PhanSo1::operator*(const PhanSo1& r) {
	if (dau == 0 or r.dau==0)
	{
		int t = -tu * r.tu;
		int m = mau * r.mau;
		return PhanSo1(t, m, 1);
	}
	else {
		int t = tu * r.tu;
		int m = mau * r.mau;
		return PhanSo1(t, m, 1);
	}
}
PhanSo1 PhanSo1::operator/(const PhanSo1& r) {
	if (dau == 0 or r.dau == 0) {
		int t = -tu * r.mau;
		int m = mau * r.tu;
		return PhanSo1(t, m, 1);
	}
	else {
		int t = tu * r.mau;
		int m = mau * r.tu;
		return PhanSo1(t, m, 1);
	}
}
ostream& operator << (ostream& os, const PhanSo1& r) {
	if (r.dau == 0)
		os << "-" << (PhanSo)r;
	else os << (PhanSo)r;
	return os;
}
int main()
{
	PhanSo1 sp1(1, 4, 1);
	PhanSo1 sp2(4, 2, 0);
	PhanSo1 sp4(1);
	PhanSo1 sp3 = sp1 - sp2;
	cout << sp4;
	return 0;
}
