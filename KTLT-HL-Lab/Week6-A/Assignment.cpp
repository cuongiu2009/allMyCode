#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#pragma once
using namespace std;
struct Student {
	char* name, * id;
	double score;
};
ostream& operator << (ostream& os, const Student& st) {
	os << "ID:" << st.id << endl;
	os << "ten:" << st.name << endl;
	os << "diem:" << st.score << endl;
	return os;
}
bool checkID(char* s) {
	if (strlen(s) > 7 || strlen(s) < 7)
		return false;
	else return true;
}

char* upperChar(char* s) {
	for (int i = 0; i < strlen(s); i++) {
		if (i == 0 || (i > 0 && s[i - 1] == 32)) {
			if (s[i] >= 97 && s[i] <= 122)
				s[i] = s[i] - 32;
		}
		else {
			if (s[i] >= 65 && s[i] <= 90)
				s[i] = s[i] + 32;
		}
	}
	return s;
}

void input(Student *st, int n) {
	char tmp[100];
	for (int i = 0; i < n; i++) {
		cout << "Sinh vien thu " << i + 1 << endl;
		cout << "nhap ID:";
		cin.getline(tmp, 101);
		while (checkID(tmp)==false) {
			cout << "nhap ID khong hop le, moi nhap lai (7 ky tu):";
			cin.getline(tmp, 101);
		}
		st[i].id = new char[strlen(tmp) + 1];
		strcpy(st[i].id, tmp);
		cout << "nhap ten:";
		cin.getline(tmp, 101);
		st[i].name = new char[strlen(tmp) + 1];
		strcpy(st[i].name, tmp);
		st[i].name = upperChar(st[i].name);
		cout << "nhap diem:";
		cin >> st[i].score;
		cin.ignore();
	}
}
void output(Student *st, int n) {
	cout << "List of student:" << endl;
	for (int i = 0; i < n; i++) {
		cout << "Sinh vien thu " << i + 1 << endl;
		cout << "ID:" << st[i].id << endl;
		cout << "ten:" << st[i].name << endl;
		cout << "diem:" << st[i].score << endl;
		cout << endl;
	}
}
void DisplayBestStu(Student* st, int n) {
	for (int i = 0; i < n; i++) {
		if (st[i].score >= 8.0)
			cout << st[i] << endl;
	}
}
void searchName(Student* st, int n, const char* s) {
	for (int i = 0; i < n; i++) {
		if (strcmp(st[i].name, s) == 0)
			cout << st[i] << endl;
	}
}
int main() {
	int n;
	cout << "nhap so luong sinh vien:";
	cin >> n;
	cin.ignore();
	Student* st = new Student[n];
	const char* s = "le phi duong";
	input(st, n);
	output(st, n);
	//DisplayBestStu(st, 3);
	//searchName(st, 1, s);
	return 0;
}