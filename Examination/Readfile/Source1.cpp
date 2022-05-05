#include <iostream>
#include <fstream>
#include <string>
struct So
{
	int tu, mau;
};
using namespace std;
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
int main()
{
	So s[10];
	double a[10];
	int i = 0;
	string ss;
	ifstream f("input.txt");
	getline(f, ss);
	while (!f.eof())
	{
		f >> s[i].tu;
		f >> s[i].mau;
		i++;
	}
	for (int j = 0; j < i; j++)
	{
		a[j] = s[j].tu * 1.0 / s[j].mau;
	}
	for (int m = 0; m < i; m++)
	{
		for (int n = 0; n < i; n++)
		{
			if (a[m] < a[n])
				swap(a[m], a[n]);
		}
	}
	for (int l = 0; l < i; l++)
		cout << a[l] << " ";
	return 0;
}