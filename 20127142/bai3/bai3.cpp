#include <iostream>
using namespace std;
int main() {
	int n, y = 0, w = 0, d = 0;
	cin >> n;
	y = n / 365;//2
	w = (n - y * 365) / 7;//24
	d = n - y * 365 - w * 7;
	cout << "year:" << y << endl;
	cout << "week:" << w << endl;
	cout << "day:" << d << endl;
	return 0;
}