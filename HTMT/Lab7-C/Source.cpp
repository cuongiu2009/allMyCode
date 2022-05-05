#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;
class Human {
protected:
	string name, date, address;
public:
	Human() {
		name = "";
		date = "";
		address = "";
	}
	friend ostream& operator << (ostream& os, Human& r) {
		os <<"Ten:"<< r.name << " " <<"Ngay Sinh:"<< r.date << " " <<"Dia chi:"<< r.address << endl;
		return os;
	}
	friend istream& operator >> (istream& is, Human& r) {
		cout << "Ten:";
		getline(is, r.name);
		cout << "Ngay sinh:";
		getline(is, r.date);
		cout << "Dia chi:";
		getline(is, r.address);
		return is;
	}
};
class NV :public Human {
private:
	string phongban, hsluong, phucap;
public:
	NV() :Human() {
		phongban = hsluong = phucap = "";
	}
	NV(string p, string h, string s) :Human(){}
	friend istream& operator >> (istream& is, NV& r) {
		cout << "Ten:"<< endl;
		getline(is, r.name);
		cout << "Ngay Sinh:" << endl;
		getline(is, r.date);
		cout << "Dia Chi:" << endl;
		getline(is, r.address);
		cout << "Phong Ban:" << endl;
		getline(is, r.phongban);
		cout << "He so luong:" << endl;
		getline(is, r.hsluong);
		cout << "Phu cap:" << endl;
		getline(is, r.phucap);
		return is;
	}
	friend ostream& operator << (ostream&os, NV& r){
		os << "Ten:" << r.name<< endl << "Ngay Sinh:" << r.date << endl << "Dia chi:" << r.address << endl;
		os << "Phong ban:" << r.phongban << endl << "he so luong:" << r.hsluong << endl << "phu cap:" << r.phucap << endl;
		return os;
	}
};
int main() {
	Human h;
	cin >> h;
	cout << h;
	NV n1;
	cin >> n1;
	cout << n1;
	vector<NV>n2(20);
	for (int i = 0; i < 20; i++)
		cin >> n2[i];
	cout << "Danh sach:" << endl;
	for (int i = 0; i < 20; i++)
		cout << n2[i];
	return 0;
}