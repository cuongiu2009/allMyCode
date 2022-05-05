#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct PhanSo {
	int tu;
	int mau;
};
struct DanhSach {
	PhanSo ds_ps[100];
	int n;
};
void readFrac(PhanSo& ps, ifstream& f);
void readFile(DanhSach& ds, ifstream& f);
void inputFile(DanhSach& ds, ofstream& f);
DanhSach sortFrac(DanhSach& ds);
void swap(DanhSach& ds1, DanhSach& ds2);