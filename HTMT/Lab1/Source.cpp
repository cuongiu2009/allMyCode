#include <iostream>
using namespace std;
class MangSoNguyen {
private:
	int n;
	int* a = new int[n];
public:
	MangSoNguyen()
	{
		n = 0;
	}
	MangSoNguyen(int value)
	{
		n = value;
	}
	MangSoNguyen(int *arr, int value)
	{
		a = arr;
		n = value;
	}
	void xuat()
	{
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
	}
};
int main()
{
	MangSoNguyen msn1;
	msn1.xuat();
	
	MangSoNguyen msn2(5);
	msn2.xuat();
	int arr[10];
	for (int i = 0; i < 8; i++)
	{
		arr[i] = i * i;
	}
	MangSoNguyen msn3(arr, 8);
	msn3.xuat();
	return 0;
}