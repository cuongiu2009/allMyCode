#include <iostream>
using namespace std;
int giaithua(int n)
{
	if (n == 1 || n == 0)
		return 1;
	else return n * giaithua(n - 1);
}
int sum(int n)
{
	if (n == 1)
		return 1;
	else if (n == 0)
		return 0;
	else return n + sum(n - 1);
}
int main()
{
	cout << "gia tri giai thua 10 la:" << giaithua(10) << endl;
	cout << "gia tri sum:" << sum(3);
	return 0;
}