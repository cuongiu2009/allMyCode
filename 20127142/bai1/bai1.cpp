#include <iostream>
using namespace std;
int ucln(int a, int b)
{
	int temp = a;
	while (!(a % temp == 0 && b % temp == 0 && temp > 0))
		temp--;
	return temp;
}
class PhanSo {
private:
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
	void rutgon();
	PhanSo operator+(const PhanSo&);
	PhanSo operator-(const PhanSo&);
	friend PhanSo operator+(const int, const PhanSo&);
	friend PhanSo operator-(const int, const PhanSo&);
	friend ostream& operator << (ostream&, PhanSo&);
};
void PhanSo::rutgon()
{
	int uc = ucln(tu, mau);
	tu = tu / uc;
	mau = mau / uc;
}
ostream& operator << (ostream&os, PhanSo&r)
{
	os << r.tu << "/" << r.mau << endl;
	return os;
}
PhanSo PhanSo::operator+(const PhanSo& r)
{
	int t, m;
	t = tu * r.mau + mau * r.tu;
	m = mau * r.mau;
	int uc = ucln(t, m);
	t = t / uc;
	m = m / uc;
	return PhanSo(t, m);
}
PhanSo PhanSo::operator-(const PhanSo& r)
{
	int t, m;
	t = tu * r.mau - mau * r.tu;
	m = mau * r.mau;
	int uc = ucln(t, m);
	t = t / uc;
	m = m / uc;
	return PhanSo(t, m);
}
PhanSo operator+(int n, const PhanSo&r)
{
	PhanSo a;
	a.tu = n * r.mau + r.tu;
	a.mau = r.mau;
	a.rutgon();
	return a;	
}
PhanSo operator-(int n, const PhanSo& r)
{
	PhanSo a;
	a.tu = n * r.mau + r.tu;
	a.mau = r.mau;
	a.rutgon();
	return a;
}
int main()
{
	PhanSo ps;
	PhanSo ps1(200);
	PhanSo ps2(6, 8);
	PhanSo ps3 = ps1 + ps2;
	PhanSo ps4 = 150 + ps2;
	PhanSo ps5 = ps1 - ps2;
	PhanSo ps6 = 225 - ps2;
	cout << ps1 << endl << ps2 << endl << ps3 << endl << ps4 << endl << ps5 << endl << ps6;
	return 0;
}
