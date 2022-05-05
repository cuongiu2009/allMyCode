#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class SoNguyenLon
{
private:
	string num;
	int length;
	static SoNguyenLon sSNLMax;
public:
	SoNguyenLon()
	{
		num = "0";
		length = 0;
	}
	SoNguyenLon(int s)
	{
		string res = "";
		res = to_string(s) + res;
		this->num = res;
		length = res.length();
		if (sSNLMax.num.length() < length)
			sSNLMax = *this;
	}
	SoNguyenLon(int number, int size)
	{
		string res = "";
		for (int i = 0; i < size; i++)
		{
			res = to_string(number) + res;
		}
		this->num = res;
		length = res.length();
		if (sSNLMax.num.length() < length)
			sSNLMax = *this;
	}
	SoNguyenLon operator+(const SoNguyenLon&);
	SoNguyenLon operator-(const SoNguyenLon&);
	friend SoNguyenLon operator+(const long long&, const SoNguyenLon&);
	friend ostream& operator<<(ostream& os, const SoNguyenLon& as);
	static SoNguyenLon SNLMax();
};
int convert(char a)
{
	return a - '0';
}
SoNguyenLon SoNguyenLon::SNLMax()
{
	return sSNLMax;
}
SoNguyenLon SoNguyenLon::operator+(const SoNguyenLon& snl)
{
	SoNguyenLon keq;
	string a = num;
	string b = snl.num;
	int m = max(a.length(), b.length());
	if (b.length() > a.length())
	{
		while (b.length() > a.length())
			a = '0' + a;
	}
	else {
		while (a.length() > b.length())
			b = '0' + b;
	}
	string res = "";
	int nho = 0, so = 0;
	for (int i = m - 1; i >= 0; i--)
	{
		so = convert(a[i]) + convert(b[i]) + nho;
		if (so >= 10)
			nho = 1;
		else
			nho = 0;
		res = to_string(so % 10) + res;
	}
	if (so >= 10)
		res = '1' + res;
	keq.num = res;
	return keq;
}
SoNguyenLon SoNguyenLon::operator-(const SoNguyenLon& snl)
{
	SoNguyenLon kq;
	string a = num;
	string b = snl.num;
	int m = max(a.length(), b.length());
	if (a.length() < b.length())
	{
		kq.num = "0";
		return kq;
	}
	else
	{
		while (a.length() > b.length())
			b = '0' + b;
	}
	string res = "";
	int nho = 0, so = 0;
	for (int i = m - 1; i >= 0; i--)
	{
		so = convert(a[i]) - convert(b[i]) - nho;
		if (so < 0)
		{
			so = so + 10;
			nho = 1;
		}
		else
			nho = 0;
		res = to_string(so) + res;
	}
	kq.num = res;
	return kq;
}
SoNguyenLon operator+(const long long& number, const SoNguyenLon& snl)
{
	SoNguyenLon s(number);
	return s + snl;
}
SoNguyenLon operator-(const long long& number, const SoNguyenLon& snl)
{
	SoNguyenLon s(number);
	return s - snl;
}
ostream& operator<<(ostream& os, const SoNguyenLon& as)
{
	os << as.num;
	return os;
}
SoNguyenLon SoNguyenLon::sSNLMax = SoNguyenLon();
int main()
{
	SoNguyenLon snl1;
	SoNguyenLon snl2(1234567);
	SoNguyenLon snl3(3, 14);
	SoNguyenLon snl4(9, 20);
	SoNguyenLon snl5 = snl3 - snl2;
	SoNguyenLon snl6 = 45678910 - snl2;
	SoNguyenLon snl7 = snl4 - snl3 + 123456789;
	cout << snl1 << endl << snl2 << endl << snl3 << endl;
	cout << snl4 << endl << snl5 << endl << snl6 << endl;
	cout << snl7 << endl << endl;
	cout << "SoNguyenLon Max:" << endl;
	cout << SoNguyenLon::SNLMax() << endl;
}