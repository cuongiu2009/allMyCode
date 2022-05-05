#include <iostream>
using namespace std;
int main() {
	int a = 3;
	int* b = &a;
	cout << b << endl; // xuat ra dia chi vung nho cua bien a
	cout << *b << endl; // xuat ra gia tri pointer dang tro toi
	cout << &b << endl; // xuat ra dia chi cua pointer b
	cout << a << endl; // xuat ra gia tri cua a
	cout << &a << endl; // xuat ra dia chi cua a
	return 0;
}