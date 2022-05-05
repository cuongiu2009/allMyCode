#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Phone {
	string name;
	int id, price, stock;
};
struct DanhSach {
	Phone p[100];
	int n;
};
void readPhone(Phone& p, ifstream& f);
void readFile(DanhSach& ds, ifstream& f);
void inputFile(DanhSach& ds, ofstream& f);