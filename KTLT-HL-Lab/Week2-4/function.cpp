#include "Header.h"
void readPhone(Phone& p, ifstream& f) {
	f >> p.id;
	f >> p.name;
	f >> p.stock;
	f >> p.price;
}
void readFile(DanhSach& ds, ifstream& f) {
	f >> ds.n;
	for (int i = 0; i < ds.n; i++)
		readPhone(ds.p[i], f);
}
void inputFile(DanhSach& ds, ofstream& f) {
	int res = 0;
	for (int i = 0; i < ds.n; i++) {
		res += ds.p[i].price;
	}
	f << res;
}