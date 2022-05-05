#include "Header.h"
void readDate(Date& d, ifstream& f) {
	f >> d.year;
	string s;
	getline(f, s, ' ');
	f >> d.month;
	getline(f, s, ' ');
	f >> d.day;
}
void readFile(DanhSach& ds, ifstream& f) {
	f >> ds.n;
	for (int i = 0; i < ds.n; i++)
		readDate(ds.d[i], f);
}
void swap(DanhSach& ds1, DanhSach& ds2) {
	DanhSach temp = ds1;
	ds1 = ds2;
	ds2 = temp;
}
DanhSach sortDate(DanhSach& ds) {
	for (int i = 0; i < ds.n - 1; i++) {
		for (int j = 1; j < ds.n; j++) {
			if (ds.d[i].year > ds.d[j].year)
				swap(ds.d[i], ds.d[j]);
			else if (ds.d[i].year == ds.d[j].year and ds.d[i].month>ds.d[j].month)
				swap(ds.d[i], ds.d[j]);
			else if (ds.d[i].year == ds.d[j].year and ds.d[i].month == ds.d[j].month and ds.d[i].day>ds.d[j].day)
				swap(ds.d[i], ds.d[j]);
		}
	}
	return ds;
}
void inputFile(DanhSach& ds, ofstream& f) {
	sortDate(ds);
	for (int i = 0; i < ds.n; i++)
		f << ds.d[i].year << " " << ds.d[i].month << " " << ds.d[i].day << endl;
}