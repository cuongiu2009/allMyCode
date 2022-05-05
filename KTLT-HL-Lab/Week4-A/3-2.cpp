#include <iostream>
using namespace std;
int doSomething(int* x, int* y) {
	int temp = *x;
	*x = *y * 10;
	*y = temp * 10;
	return *x + *y;
}
int main() {
	int* a = new int(3);
	int* b = new int(4);
	int c = doSomething(a, b);
	delete a,b;
	cout << c << endl;
}