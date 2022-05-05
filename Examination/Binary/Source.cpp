#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

struct Sale {
	unsigned short id;
	char name[30];
	double value;
};

int findMin(int a, int b) {
	if (a < b)
	{
		return a;
	}
	return b;
}
int timMaxRecursionInArray(int a[], int n) {
	if (n == 0)
		return a[0];
	return findMin(a[n - 1], timMaxRecursionInArray(a, n - 1));
}

void writeToBinary(ofstream& f, Sale a[]) {
	f.open("loadfile.dat", ios::binary);
	for (int i = 0; i < 6; i++)
	{
		f.write((char*)&a[i], sizeof(a[i]));
	}
	f.close();
}

void readAndShow(const char* fileName) {
	fstream fg;
	Sale a[100];

	fg.open(fileName, ios::in | ios::binary);
	int i = 0;

	while (fg.read((char*)&a[i], sizeof(a[i])))
	{
		i++;
	}

	for (int k = 0; k < i; k++)
	{
		cout << a[k].id << " " << a[k].name << " " << a[k].value << endl;
	}
}
int main() {

	int n = 0;
	fstream f;
	Sale sales[100];

	/*writeToBinary(f, sales);*/
	readAndShow("loadfile.dat");

	return 0;
}