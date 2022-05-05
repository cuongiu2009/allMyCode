#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Student {
	string name,gpa;
	int id;
};
struct DanhSach {
	Student s[100];
	int n;
};
void readStu(Student& s, ifstream& f);
void readFile(DanhSach& ds, ifstream& f);
void inputFile(DanhSach& ds, ofstream& f);