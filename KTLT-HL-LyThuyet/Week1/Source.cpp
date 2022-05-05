#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int* a = new int[n];
	*a = 3;
	cout << *a;
}