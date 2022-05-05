#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#pragma once
using namespace std;
struct Student {
	int id;
	char* name;
	double score;
	char* address;
};
ostream& operator << (ostream& os, const Student& st) {
	os << "ID:" << st.id << endl;
	os << "ten:" << st.name << endl;
	os << "diem:" << st.score << endl;
	os << "dia chi:" << st.address << endl;
	return os;
}
void input(Student st[], int n) {
	char tmp[100];
	for (int i = 0; i < n; i++) {
		cout << "Sinh vien thu " << i+1 << endl;
		cout << "nhap ID:";
		cin >> st[i].id;
		cin.ignore();
		cout << "nhap ten:";
		cin.getline(tmp, 101);
		st[i].name = new char[strlen(tmp)+1];
		strcpy(st[i].name, tmp);
		cout << "nhap diem:";
		cin >> st[i].score;
		cin.ignore();
		cout << "nhap dia chi:";
		cin.getline(tmp, 101);
		st[i].address = new char[strlen(tmp) + 1];
		strcpy(st[i].address, tmp);
	}
}
void output(Student st[], int n) {
	cout << "List of student:" << endl;
	for (int i = 0; i < n; i++) {
		cout << "Sinh vien thu " << i + 1 << endl;
		cout << "ID:" << st[i].id << endl;
		cout << "ten:" << st[i].name << endl;
		cout << "diem:" << st[i].score << endl;
		cout << "dia chi:" << st[i].address << endl;
		cout << endl;
	}
}
bool badStu(double score) {
	if (score <= 5)
		return true;
	return false;
}
void badStuList(Student st[], int n) {
	for (int i = 0; i < n; i++) {
		if (badStu(st[i].score))
			cout << st[i] << endl;
	}
}
void sortListStuID(Student st[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (st[i].id > st[j].id) {
				Student tmp = st[i];
				st[i] = st[j];
				st[j] = tmp;
			}
		}
	}
}

void sortListStuName(Student st[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (strcmp(st[i].name, st[j].name) < 0) {
				Student tmp = st[i];
				st[i] = st[j];
				st[j] = tmp;
			}
		}
	}
}

int main() {
	Student st[2];
	input(st, 2);
	badStuList(st, 2);
	sortListStuID(st, 2);
	output(st, 2);
	sortListStuName(st, 2);
	output(st, 2);
	return 0;
}