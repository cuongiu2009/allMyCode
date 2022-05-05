#include "Header.h"
void readCir(Cir& c, ifstream& f) {
	f >> c.x;
	string s;
	getline(f, s, ' ');
	f >> c.y;
	getline(f, s, ' ');
	f >> c.r;
}
void readFile(DanhSach& ds, ifstream& f) {
	f >> ds.n;
	for (int i = 0; i < ds.n; i++) {
		readCir(ds.c[i], f);
	}
}
float sum(DanhSach& ds) {
	float res = 0;
	for (int i = 0; i < ds.n; i++) {
		res += ds.c[i].r * ds.c[i].r * 3.14;
	}
	return res;
}
void inputFile(DanhSach& ds, ofstream& f) {
	float res = sum(ds);
	f <<"ket qua la:"<< res;
}