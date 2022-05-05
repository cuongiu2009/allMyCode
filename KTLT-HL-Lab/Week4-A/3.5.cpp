#include <iostream>
using namespace std;
int findMode(int* a, int size) {
	int max = 0, maxCount = 0, i, j;
	for (i = 0; i < size; i++) {
		int count = 0;
		for (j = 0; j < size; j++) {
			if (a[j] == a[i])
				count++;
		}
		if (count > maxCount) {
			maxCount = count;
			max = a[i];
		}
		else if (maxCount == 1)
			max = -1;
	}
	return max;
}
int main() {
	int* a = new int[10];
	int b[]= { 1, 2, 3, 4, 5, 7, 7, 8 ,7, 10, 19 };
	a = b;
	int mode = findMode(a, 10);
	cout << mode;
	delete[]a;
	return 0;
}