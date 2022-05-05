#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
class SoNguyen
{
private:
	int v;
public:
	SoNguyen() {
		v = 0;
	}
	SoNguyen(int val)
	{
		v = val;
	}
	int getValue() {
		return v;
	}
	bool operator > (const SoNguyen& n)
	{
		SoNguyen t = *this;
		if (n.v > t.v)
			return true;
	}
	bool operator < (const SoNguyen& n)
	{
		SoNguyen t = *this;
		if (n.v < t.v)
			return true;
	}
	SoNguyen operator+(const SoNguyen&);
	friend ostream& operator << (ostream&, SoNguyen&);
	friend istream& operator >> (istream&, SoNguyen&);
};
ostream& operator << (ostream& os, SoNguyen& r)
{
	os << r.v;
	return os;
}
istream& operator >> (istream& os, SoNguyen& r)
{
	os >> r.v;
	return os;
}
SoNguyen SoNguyen::operator+(const SoNguyen& s)
{
	SoNguyen a;
	return a.v + s.v;
}
int main()
{
	srand(time(nullptr));
	vector<SoNguyen> a;
	
	return 0;
}