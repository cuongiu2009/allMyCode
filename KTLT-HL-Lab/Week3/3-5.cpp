#include <iostream>
using namespace std;
int main() {
	int v = 8, * r, * s;
	int* p;
	int q = 100;
	p = &q;
	r = p;
	*p = 20;
	p = new int;
	*r = 30;
	q = v;
	s = p;
	*s = 50;
	//*p=50 vi, q=8, *r=8, v=8, *s=50
	// q,r,v bang nhau vi r,v va p ban dau tro vao q, sau do p duoc khoi tao lai vai co gia tri moi la 8 nen r,q,v deu thay doi gia tri, sau do p duoc gan cho s, s co gia tri la 50
	return 0;
}