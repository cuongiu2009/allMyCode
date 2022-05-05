#include <iostream>
using namespace std;
int UCLL(int a, int b)
{
	if (b == 0)
		return a;
	return UCLL(a, a % b);
}
void TOH(int num, char x, char y, char z)
{
	if (num == 1)
	{
		cout << x << "->" << z << endl;
		return;
	}
	TOH(num - 1, x, z, y);
	TOH(1, x, y, z);
	TOH(num - 1, y, x, z);
}
int main()
{
	int num;
	cin >> num;
	TOH(num, 'A', 'B', 'C');;
	return 0;
}