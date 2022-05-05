#include "Header.h"
void readStu(Student& s, ifstream& f) {
	f >> s.id;
	getline(f, s.name, '\n');
	getline(f, s.gpa);
}
void readFile(DanhSach& ds, ifstream& f) {
	f >> ds.n;
	for (int i = 0; i < ds.n; i++) {
		readStu(ds.s[i], f);
	}
}
void inputFile(DanhSach& ds, ofstream& f) {
	float max = stof(ds.s[0].gpa);
	for (int i = 0; i < ds.n; i++)
		if (stof(ds.s[i].gpa) > max)
			max = stof(ds.s[i].gpa);
	f << max;
}