#include <iostream>
using namespace std;
class SoPhuc
{
private:
	int thuc, ao;
public:
	SoPhuc();
	SoPhuc(int t, int a);
	SoPhuc(const int&);
	SoPhuc operator+(const int&);
	SoPhuc operator-(const int&);
	SoPhuc operator - (const SoPhuc&);
	SoPhuc operator + (const SoPhuc&);
	SoPhuc operator * (const SoPhuc&);
	SoPhuc operator / (const SoPhuc&);
	friend ostream& operator<<(ostream&, const SoPhuc&);
};
SoPhuc::SoPhuc()
{
	thuc = ao = 0;
}
SoPhuc::SoPhuc(int t, int a)
{
	thuc = t;
	ao = a;
}
SoPhuc::SoPhuc(const int& n)
{
	thuc = n;
	ao = 0;
}
SoPhuc SoPhuc::operator+(const int& n)
{
	SoPhuc rt = *this;
	rt.thuc += n;
	return rt;
}
SoPhuc SoPhuc::operator-(const int& n)
{
	SoPhuc rt = *this;
	rt.thuc -= n;
	return rt;
}
SoPhuc SoPhuc::operator+(const SoPhuc& x)
{
	SoPhuc c;
	c.thuc = x.thuc + this->thuc;
	c.ao = x.ao + this->ao;
	return c;
}
SoPhuc SoPhuc::operator-(const SoPhuc& x)
{
	SoPhuc c;
	c.thuc = x.thuc - this->thuc;
	c.ao = x.ao - this->ao;
	return c;
}
SoPhuc SoPhuc::operator*(const SoPhuc& x)
{
	SoPhuc c;
	c.thuc = thuc * x.thuc - ao * x.ao;
	c.ao = thuc * x.ao + ao * x.thuc;
	return c;
}
SoPhuc SoPhuc::operator / (const SoPhuc& x)
{
	SoPhuc c;
	c.thuc = (thuc * x.thuc + ao * x.ao) / (x.thuc * x.thuc + x.ao * x.ao);
	c.ao = (x.thuc * ao - thuc * x.ao) / (x.thuc * x.thuc + x.ao * x.ao);
	return c;
}
ostream& operator<<(ostream& os, const SoPhuc& sp)
{
	if (sp.ao == 0)
		os << sp.thuc;
	else 
		os << sp.thuc << " + " << sp.ao << "*i";
	return os;
}
int main()
{
	SoPhuc sp1(3, 5);
	SoPhuc sp2(4, 5);
	SoPhuc sp3 = sp1 - sp2;
	SoPhuc sp4 = sp1 * sp2;
	SoPhuc sp5 = sp1.operator+(10);
	cout << sp3 << endl << sp4 << endl << sp5;
	return 0;
}