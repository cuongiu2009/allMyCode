#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;
class SoNguyen
{
private:
	int v;
public:
	SoNguyen();
	SoNguyen(const int&);
	int getValue()const {
		return v;
	}
	bool operator > (const SoNguyen& n) const
	{
		return this->v > n.v;
	}
	bool operator < (const SoNguyen& n) const
	{
		return this->v < n.v;
	}
	/*bool operator == (const SoNguyen& n) const {
		if (this->v == n.v)
			return true;
	}*/
	SoNguyen operator+(const SoNguyen&)const;
	friend ostream& operator << (ostream&,const SoNguyen&);
	friend istream& operator >> (istream&, SoNguyen&);
};
SoNguyen::SoNguyen() :v(0) {}
SoNguyen::SoNguyen(const int& val) : v(val) {}
ostream& operator << (ostream& os, const SoNguyen& r) {
	os << r.v;
	return os;
}
istream& operator >> (istream& is, SoNguyen& r)
{
	is >> r.v;
	return is;
}
SoNguyen SoNguyen::operator+(const SoNguyen& s)const
{
	SoNguyen a;
	return a.v = v + s.v;
}
vector<SoNguyen>mang() {
	SoNguyen n;
	do
	{
		cout << "nhap n:";
		cin >> n;
	} while (n.getValue() < 1 || n.getValue() > 50);
	vector<SoNguyen>a(n.getValue());
	for (SoNguyen i = 0; i < n; i = i + 1) {
		a[i.getValue()] = rand() % 10;
	}
	return a;
}
void outputArr(const vector<SoNguyen>& a) {
	for (SoNguyen i = 0; i < a.size(); i = i + 1)
		cout << a[i.getValue()] << " ";
	cout << endl;
}
SoNguyen minIs(const vector<SoNguyen>& a) {
	SoNguyen min = INT_MAX;
	for (SoNguyen i = 0; i < a.size(); i = i + 1) {
		if (a[i.getValue()] < min)
			min = a[i.getValue()];
	}
	return min;
}
void SapXep(vector<SoNguyen>& x) {
	sort(x.begin(), x.end());
}
int main()
{
	srand(time(nullptr));
	vector<SoNguyen> a = mang();
	outputArr(a);
	cout << "min=" << minIs(a) << endl;
	SapXep(a);
	outputArr(a);
	return 0;
}