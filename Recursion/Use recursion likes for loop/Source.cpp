#include <iostream>
using namespace std;
void printOut(int n)
{
	if (n == 0)
		return;
	cout << "*";
	return printOut(n - 1);
}
void printTriagle(int n)
{
	if (n < 1)
		return;
	printTriagle(n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << "*";
	}
	cout << endl;
}
void printn(int num)
{
	if (num == 0)
		return;
	cout << "* ";
	printn(num - 1);
}
void printTriangle2(int n, int i)
{
	if (n == 0)
		return;
	printn(i);
	cout << endl;
	printTriangle2(n - 1, i + 1);
}

int main()
{
	printTriangle2(3,1);
	system("pause");
	return 0;
}