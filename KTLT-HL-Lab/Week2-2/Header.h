#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Cir {
	int x, y;
	float r;
};
struct DanhSach {
	Cir c[100];
	int n;
};
void readCir(Cir& c, ifstream& f);
void readFile(DanhSach& ds, ifstream& f);
void inputFile(DanhSach& ds, ofstream& f);
float sum(DanhSach& ds);