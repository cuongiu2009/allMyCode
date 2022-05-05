#include "Header.h"
void readFrac(PhanSo& ps, ifstream& f) {
	f >> ps.tu;
	string s;
	getline(f, s, ' ');
	f >> ps.mau;
}
void readFile(DanhSach& ds, ifstream& f) {
	f >> ds.n;
	for (int i = 0; i < ds.n; i++) {
		readFrac(ds.ds_ps[i], f);
	}
}
void swap(DanhSach&ds1, DanhSach&ds2) {
	DanhSach temp = ds1;
	ds1 = ds2;
	ds2 = temp;
}
DanhSach sortFrac(DanhSach& ds) {
	for (int i = 0; i < ds.n-1; i++) {
		for (int j = 1; j < ds.n; j++) {
			if (1.0*ds.ds_ps[i].tu / ds.ds_ps[i].mau < 1.0*ds.ds_ps[j].tu / ds.ds_ps[j].mau)
				swap(ds.ds_ps[i], ds.ds_ps[j]);
		}
	}
	return ds;
}
void inputFile(DanhSach& ds, ofstream& f) {
	sortFrac(ds);
	for (int i = 0; i < ds.n; i++) {
		f << ds.ds_ps[i].tu << "/" << ds.ds_ps[i].mau << endl;
	}
}