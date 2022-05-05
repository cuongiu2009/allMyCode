#include <iostream>
using namespace std;
int main() {
	int x, z;
	float y;
	char ch, * chp;
	int* ip1, * ip2;
	float* fp;
	x = 100;
	y = 20.0;
	z = 50;
	ch = 'Z';
	ip1 = &x;
	ip2 = &z;
	fp = &y;
	chp = &ch;
	ip2 = ip1;
	ip1 = &z;
	*ip1 = *ip2;
	*ip1 = 200;
	*ip1 = *ip2 + 300;
	*fp = 1.2;
	cout << x << endl; // in ra gia tri cua x
	cout << y << endl; // fp duoc gan dia chi cua y, sau do thay doi gia tri cua fp=1.2 nen gia tri tai bien y cung thay doi
	cout << z << endl; // ip2 tro den z, sau do ip2 tro den x con ip1 tro den z, sau do gan gia tri cua ip1 = *ip2(100)+300 nen z luc nay thay doi gia tri thanh 400
	cout << ip1 << endl; // in ra gia tri dia chi vung nho ma ip1 dang tro toi
	cout << *ip1 << endl; // in ra gia tri cua ip1
	cout << &ip1 << endl; //  in ra gia tri dia chi vung nho cua ip1
	cout << ip2 << endl; // in ra gia tri dia chi vung nho ma ip2 dang tro toi
	cout << *ip2 << endl; // in ra gia tri cua ip2
	cout << &ip2 << endl; //in ra gia tri dia chi vung nho ip2
	cout << fp << endl; // in ra gia tri dia chi vung nho ma fp dang tro toi
	cout << *fp << endl; // in ra gia tri cua fp
	cout << &fp << endl; // in ra dia chi fp
	cout << chp << endl; // in ra gia tri vung nho ma con tro chp dang tro toi
	cout << *chp << endl;// pointer char xu ly theo chuoi nen se in ra gia tri cho den khi gap ki hieu ket thuc
	cout << &chp << endl; // in ra dia chi vung nho cua con tro chp
	return 0;
}