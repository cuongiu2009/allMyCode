#include <iostream>
using namespace std;
int main() {
	int* a = new int;
	int* b = new int;
	*a = 2;
	b = a;
	cout << *a << endl;
	cout << *b << endl;
	delete a;
	delete b;
	// bi loi vi khi delete a va b thi con tro van con tro den dia chi cu, nen khi print ra thi dinh dia chi rac'
	return 0;
}
