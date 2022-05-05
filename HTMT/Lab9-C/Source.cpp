#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Detail {
protected:
	string seri;
public:
	Detail() :seri("") {}
	friend istream& operator>>(istream& is, Detail d) {
		cout << "nhap seri chi tiet may:";
		is >> d.seri;
		is.ignore();
		return is;
	}
	friend ostream& operator<<(ostream& os, Detail d) {
		cout << "ma seri la:" << d.seri << endl;
		return os;
	}
};
class simpleDetail:public Detail {
private:
	float weight, price;
public:
	simpleDetail() :Detail(), weight(0), price(0) {}
	float trongLuong() {
		return this->weight;
	}
	float giaThanh() {
		return this->price;
	}
	friend istream& operator >> (istream& is, simpleDetail& s) {
		Detail* d = static_cast<Detail*>(&s);
		is >> *d;
		cout << "nhap trong luong:";
		is >> s.weight;
		cout << "nhan gia thanh:";
		is >> s.price;
		return is;
	}
	friend ostream& operator<<(ostream& os, simpleDetail& s) {
		Detail d = static_cast<Detail>(s);
		os << d;
		os << "trong luong:" << s.weight << endl;
		os << "gia thanh:" << s.price << endl;
		return os;
	}
};
class complexDetail :public Detail {
private:
	vector<simpleDetail>s;
public:
	friend istream& operator>>(istream& is, complexDetail& c) {
		bool check = false;
		int i = 0, choose;
		do {
			simpleDetail si;
			cout << "nhap chi tiet don (" << i + 1 << "):" << endl;
			is.ignore();
			is >> si;
			c.s.push_back(si);
			i++;
			cout << "nhap tiep:";
			is >> choose;
		} while (choose);
		return is;
	}
	string getSeri() {
		return seri;
	}
};
class Machine {
private:
	vector<complexDetail>c;
	vector<simpleDetail>s;
	float weight, price;
public:
	Machine() :weight(0), price(0) { c.resize(0); s.resize(0); }
	void input() {
		int choose;
		int i = 0, j = 0;
		do
		{
			cout << "1. Nhap chi tiet don:" << endl;
			cout << "2. nhap chi tiet phuc:" << endl;
			cout << "3. Thoat" << endl;
			cout << "chon:";
			cin >> choose;
			switch (choose) {
			case 1: {
				cout << "nhap chi tiet don" << endl;
				simpleDetail si;
				cin >> si;
				s.push_back(si);
				break;
			}
			case 2: {
				cout << "nhap chi tiet phuc" << endl;
				complexDetail co;
				cin >> co;
				c.push_back(co);
				break;
			}
		
			}
		} while (choose != 3);
	}
	float price_machine() {
		float sum = 0;
		for (int i = 0; i < s.size(); i++) {
			sum += s[i].giaThanh();
		}
		return 50000 * 0.2 + sum;
	}
	float weight_machine() {
		float sum = 0;
		float thietbinoi = (s.size() + c.size()) / 2;
		for (int i = 0; i < s.size(); i++) {
			sum += s[i].trongLuong();
		}
		return sum + 0.1 * thietbinoi;
	}
};
int main() {
	Machine a;
	string s;
	a.input();
	cout << "Trong luong co may:" << a.weight_machine() << endl;
	cout << "Gia thanh co may:" << a.price_machine() << endl;
	cout << "nhap seri can tim:";
	cin.ignore();
	getline(cin, s);
	return 0;
}