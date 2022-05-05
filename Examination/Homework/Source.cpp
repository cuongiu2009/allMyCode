#include <iostream>
using namespace std;
int count(int dsSo[], int n)
{
	int count = 0;
	int sum = 0;
	int i = 0;
	for (i; i < n; i++)
	{
		while (dsSo[i] > 0)
		{
			sum = sum + dsSo[i] % 10;
			if (sum == 13)
			{
				count++;
			}
			else dsSo[i] = dsSo[i] / 10;
		}
		if (sum != 13)
			sum = 0;
	}
	return count;
}
//int GetMaxLength(string chuoi)
//{
//	int a[100];
//	
//}
int main()
{
	int dsSo[100] = { 1234,1372,1001,2789,7654,1234,1093 };
	int n = 7;
	string chuoi = "nhap mon lap trinh";
	cout << count(dsSo, n) << endl;
	cout << sizeof(chuoi);
	return 0;
}