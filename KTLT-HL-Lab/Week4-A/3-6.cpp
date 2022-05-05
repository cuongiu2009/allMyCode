#include <iostream>
using namespace std;
int* doubleArr(int a[], int size) {
	int newSize = size * 2;
	int* newArr = new int[newSize];
	for (int i = 0; i < newSize; i++) {
		if (i >= size)
			newArr[i] = 0;
		else newArr[i] = a[i];
	}
	return newArr;
}
int main() {
	int b[] = { 1,2,3,4,5,6,7,8,9,10 };
	int* a = doubleArr(b, 10);
	for (int i = 0; i < 10; i++) {
		cout << b[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 20; i++) {
		cout << a[i] << " ";
	}
	return 0;
}