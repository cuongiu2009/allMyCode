#include <iostream>
using namespace std;
double med(int* a, int size) {
	double m = 0;
	if (size % 2 != 0) {
		m = a[size / 2];
	}
	else m = (a[(size - 1) / 2] + a[size / 2]) / 2.0;
	return m;
}
int main() {
	int* a = new int[5];
	int b[]= { 1,2,3,4,5 };
	a = b;
	double median = med(a, 5);
	cout << median;
	return 0;
}