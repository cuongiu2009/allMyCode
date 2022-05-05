#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#pragma warning (disable : 4996)
using namespace std;
template <typename T>
class Mang {
private:
	T* data;
	int n;
public:
	Mang();
	Mang(T* data1, int n1);
	~Mang();
	void sort();
	int timkiem(const T& key) const;
	void ghifile(const char* tenfile);
	int timmax()const;
	int timmin()const;
	void xuat()const;
	void nhap();
	bool ktRong()const;
};
template <typename T>
Mang<T>::Mang() {
	n = 0;
	data = nullptr;
}
template <typename T>
Mang<T>::Mang(T* data1, int n1) {
	n = n1;
	data = new T[n];
	for (int i = 0; i < n; i++)
		data[i] = data1[i];
}
template <typename T>
Mang<T>::~Mang() {
	if (n > 0)
		delete[]data;
	n = 0;
}
template <typename T>
void Mang<T>::xuat()const {
	for (int i = 0; i < n; i++)
		cout << data[i] << " ";
	cout << endl;
}
template <typename T>
void Mang<T>::nhap() {
	if (n > 0) {
		delete[]data;
		n = 0;
	}
	cout << "nhap n:";
	cin >> n;
	data = new T[n];
	for (int i = 0; i < n; i++) {
		cout << "Nhap phan tu " << i + 1 << ":" << endl;
		cin >> data[i];
	}
}
template <typename T>
void Mang<T>::sort() {
	for (int i = 0; i < n; i++) {
		int j = i;
		while (j > 0 and data[j - 1] > data[j]) {
			swap(data[j - 1], data[j]);
			j--;
		}
	}
}
template <typename T>
int Mang<T>::timkiem(const T& key)const {
	for (int i = 0; i < n; i++)
		if (data[i] == key)
			return i;
	return 0;
}
template <typename T>
int Mang<T>::timmax()const {
	int res = 0;
	for (int i = 0; i < n; i++)
		if (data[i] > data[res])
			res = i;
	return res;
}
template <typename T>
int Mang<T>::timmin()const {
	int res = 0;
	for (int i = 0; i < n; i++)
		if (data[i] < data[res])
			res = i;
	return res;
}
template <typename T>
void Mang<T>::ghifile(const char* tenfile) {
	fstream f(tenfile,ios::out);
	f << n << endl;
	for (int i = 0; i < n; i++)
		f << data[i];
	f.close();
}
template <typename T>
bool Mang<T>::ktRong()const {
	while (data != nullptr)
		return true;
	return false;
}

class Hocsinh {
private:
	char hoten[55];
	int tuoi;
	float dtb;
public:
	Hocsinh() {
		strcpy(hoten, "");
		tuoi = 0;
		dtb = 0;
	}
	Hocsinh(char hoten1[], int tuoi1, float dtb1) {
		strcpy(hoten, hoten1);
		tuoi = tuoi1;
		dtb = dtb1;
	}
	friend ostream& operator<<(ostream& os, Hocsinh& r);
	friend istream& operator>>(istream& is, Hocsinh& r);
	bool operator>(Hocsinh& r);
	bool operator<(const Hocsinh& r);
	friend void sapxep(Hocsinh a[], int n);
};
ostream& operator<<(ostream& os, Hocsinh& r) {
	os << r.hoten << ", " << r.tuoi << ", " << r.dtb << endl;
	return os;
}
istream& operator>>(istream& is, Hocsinh& r) {
	cout << "nhap ho ten:";
	is.ignore();
	is.getline(r.hoten, 55);
	cout << "nhap tuoi:";
	is >> r.tuoi;
	cout << "nhap diem trung binh:";
	is >> r.dtb;
	return is;
}
bool Hocsinh::operator<(const Hocsinh& r) {
	if (dtb < r.dtb)
		return true;
	return false;
}
bool Hocsinh::operator>(Hocsinh& r) {
	if (dtb < r.dtb)
		return false;
	return true;
}
void sapxep(Hocsinh a[], int n) {
	sort(a, a + n);
}
int main() {
	int a1[] = { 10, 2, 13, 24 };
	string s1[] = { "Kim Tan", "Bi Rain", "Le Roi", "Tran Trang" };
	int n1 = 4;
	Mang<int> mi;
	Mang<string> ms;
	Mang<Hocsinh> mhs;
	mhs.nhap();
	mi.nhap();
	ms.nhap();
	mhs.ghifile("hocsinh.txt");
	mhs.sort();
	ms.sort();
	mi.sort();
	ms.xuat();
	mi.xuat();
	mhs.xuat();
	int kq = ms.timkiem(string("Teo"));
	if (kq > 0)
		cout << "Tim thay Teo o vi tri " << kq << endl;
	else
		cout << "Khong tim thay Teo" << endl;
	return 0;
}