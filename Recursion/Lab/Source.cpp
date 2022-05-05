#include <iostream>
using namespace std;
int sum(int n)
{
	if (n == 0)
		return 0;
	return sum(n - 1);
}
int factorial(int n)
{
	if (n == 0 || n == 1)
		return 1;
	return factorial(n - 1) * n;
}
int power(int x,int n)
{
	if (n == 0)
		return 1;
	else if (n == 1)
		return x;
	return power(x, n-1) * x;
}
int countDigit(int n)
{
	int k = 1;
	if (n / 10 == 0)
		return k;
	return countDigit(n / 10) + k;
}
int countOdd(int n)
{
	int c = 0;
	if (n / 10 == 0 && n % 2 == 1)
		return 1;
	else if (n / 10 == 0)
		return 0;
	else if (n % 2 == 1)
		c++;
	return countOdd(n / 10) + c;
}
bool verifyEven(int n)
{
	int c = 0;
	if (n / 10 == 0)
		return true;
	else if (n % 2 == 1)
		return false;
	else return true;
	verifyEven(n / 10);
}
int demSo(int n)
{
	if (n == 0)
		return 0;
	return demSo(n/10) + 1;
}
int tongSo(int n, int k)
{
	if (k > 1)
		return tongSo(n * 10, k - 1);
	return 0;
}
int reverse(int n)
{
	if (n == 0)
		return 0;
	int t = demSo(n);
	int v = n % 10;
	int sum = tongSo(v, t);
	return reverse(n / 10) + sum;
}
int binaryNumber(int n,int i=1)
{
	int k = n % 2;
	if (n == 0)
		return 0;
	return binaryNumber(n / 2, i + 1) + k * pow(10, i);
}
int main()
{
	cout << binaryNumber(12, 1);
	return 0;
}