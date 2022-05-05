#include <iostream>
using namespace std;
int main() {
	int a = 3;
	int* p = &a;
	cout << *p << endl;// in ra gia tri cua bien a ma con tro p dang tro toi dia chi cua bien a
	p = new int(5); 
	cout << *p << endl; // gan cho con tro gia tri moi nen bay gio con tro co gia tri la 5
	return 0;
}