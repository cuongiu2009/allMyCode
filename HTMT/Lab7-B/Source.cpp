#include <iostream>
using namespace std;
class SoPhuc {
protected:
	double thuc, ao;
public:
	SoPhuc() {
		thuc = ao = 0;
	}
	friend ostream& operator << (ostream& os, SoPhuc& r) {
		if (r.ao > 0)
			os << r.thuc << "+" << r.ao << "i" << endl;
		else if (r.ao == 0)
			os << r.thuc << endl;
		else os << r.thuc << r.ao << "i" << endl;	
		return os;
	}
	friend istream& operator >> (istream& is, SoPhuc& r) {
		cout << "thuc:";
		is >> r.thuc;
		cout << "ao:";
		is >> r.ao;
		return is;
	}
};
class SoPhuc1:public SoPhuc {
public:
	SoPhuc1():SoPhuc(){}
	SoPhuc1 operator+(const double&);
	SoPhuc1 operator-(const double&);
	SoPhuc1 operator - (const SoPhuc1&);
	SoPhuc1 operator + (const SoPhuc1&);
	SoPhuc1 operator * (const SoPhuc1&);
	SoPhuc1 operator / (const SoPhuc1&);
	bool operator >= (const SoPhuc1&r) {
		SoPhuc1 a;
		double s = abs(r.thuc) + abs(r.ao);
		double s1 = abs(a.thuc) + abs(a.ao);
		if (s >= s1)
			return true;
		else return false;
	}
	bool operator <= (const SoPhuc1&r) {
		SoPhuc1 a;
		double s = abs(r.thuc) + abs(r.ao);
		double s1 = abs(a.thuc) + abs(a.ao);
		if (s >= s1)
			return false;
		else return true;
	}
	bool operator != (const SoPhuc1& r) {
		SoPhuc1 a;
		if (a.thuc != r.thuc && a.ao != r.ao)
			return true;
		else return false;
	}
	bool operator == (const SoPhuc1& r) {
		SoPhuc1 a;
		if (a.thuc != r.thuc && a.ao != r.ao)
			return false;
		else return true;
	}
	SoPhuc1 operator++() {
		thuc += 1;
		return *this;
	}
	SoPhuc1 operator--() {
		thuc -= 1;
		return *this;
	}
};
SoPhuc1 SoPhuc1::operator+(const double& n)
{
	SoPhuc1 rt = *this;
	rt.thuc += n;
	return rt;
}
SoPhuc1 SoPhuc1::operator-(const double& n)
{
	SoPhuc1 rt = *this;
	rt.thuc -= n;
	return rt;
}
SoPhuc1 SoPhuc1::operator+(const SoPhuc1& x)
{
	SoPhuc1 c;
	c.thuc = x.thuc + this->thuc;
	c.ao = x.ao + this->ao;
	return c;
}
SoPhuc1 SoPhuc1::operator-(const SoPhuc1& x)
{
	SoPhuc1 c;
	c.thuc = x.thuc + this->thuc;
	c.ao = x.ao + this->ao;
	return c;
}
SoPhuc1 SoPhuc1::operator*(const SoPhuc1& x)
{
	SoPhuc1 c;
	c.thuc = thuc * x.thuc - ao * x.ao;
	c.ao = thuc * x.ao + ao * x.thuc;
	return c;
}
SoPhuc1 SoPhuc1::operator / (const SoPhuc1& x)
{
	SoPhuc1 c;
	c.thuc = (thuc * x.thuc + ao * x.ao) / (x.thuc * x.thuc + x.ao * x.ao);
	c.ao = (x.thuc * ao - thuc * x.ao) / (x.thuc * x.thuc + x.ao * x.ao);
	return c;
}
int main()
{
	SoPhuc1 s1;
	cin >> s1;
	SoPhuc1 s2;
	cin >> s2;
	SoPhuc1 s3 = s1 * s2;
	cout << s3;
	SoPhuc1 s4 = s1 + s2;
	cout << s4;
	++s3;
	cout << s3;
	--s4;
	cout << s4;
	return 0;
}