//Bai 3.1
#include "Header.h"
int main() {
	ifstream f;
	DanhSach ds;
	f.open("input.txt");
	ofstream f1;
	f1.open("output.txt");
	readFile(ds, f);
	inputFile(ds,f1);
	return 0;
}
