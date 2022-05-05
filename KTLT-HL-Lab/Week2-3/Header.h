#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Date {
	int day, month, year;
};
struct DanhSach {
	Date d[100];
	int n;
};
void readDate(Date &d, ifstream& f);
void readFile(DanhSach& ds, ifstream& f);
void inputFile(DanhSach& ds, ofstream& f);
DanhSach sortDate(DanhSach& ds);
void swap(DanhSach& ds1, DanhSach& ds2);