#include <iostream>
#include <math.h>
using namespace std;
double s(int n)
{
	if (n == 2)
		return 0.5;
	else return 1 / (n*1.0) + s(n - 1);
}
int main()
{
	int n;
	cin >> n;
	cout << s(n);
	return 0;
}