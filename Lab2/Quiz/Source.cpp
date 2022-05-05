#include <iostream>
using namespace std;
//bai1
void marjorityElement(int a[], int n, int& count_assign, int& count_compare)
{
	int count = 0; ++count_assign;
	int element; ++count_assign;
	int i = 0; ++count_assign;
	while (++count_compare && i<n)
	{
		if (++count_compare && count == 0)
		{
			element = a[i]; ++count_assign; i++; ++count_assign;
		}
		if (++count_compare && a[i] == element)
		{
			count++; ++count_assign; i++; ++count_assign;
		}
		else { count--; ++count_assign; i++; ++count_assign; }
	}
	i = 0; ++count_assign;
	count = 0; ++count_assign;
	while (++count_compare && i < n)
	{
		if (++count_compare && a[i] == element)
		{
			count++; ++count_assign; i++; ++count_assign;
		}
		else i++;
	}
	if (++count_compare && count > element / 2)
		cout << count_assign << " " << count_compare;
}
void marjorityElement1(int a[], int n,int &count_assign,int &count_compare)
{
	int element = 0; ++count_assign;
	int count = 1; ++count_assign;
	int i = 0; ++count_assign;
	while (++count_compare && i<n)
	{
		if (++count_compare && a[element] == a[i])
		{
			count++;
			i++;
		}
		else {
			count--; ++count_assign; i++;
		}
		if (++count_compare && count == 0)
		{
			++count_assign;
			element = i; ++count_assign;
			count = 1; ++count_assign;
		}
	}
	cout << count_assign << " " << count_compare;
}


//bai2
void greatestDivisor(int a, int b, int& count_assign, int& count_compare)
{
	int i = 1; ++count_assign;
	int max = i; ++count_assign;
	while (++count_compare && i < b)
	{
		if (++count_compare && a % i == 0 && ++count_compare && b % i == 0)
		{
			max = i;
			i++; ++count_assign;
		}
		else {
			i++; ++count_assign;
		}
	}
	cout << count_assign << " "<<count_compare;
}

//bai3

void seeSaw(int a, int b, int w[], int n)
{
	int i = 0, j = 0;
	while (i<n)
	{
		j = 0;
		while (j<n)
		{
			if (a + w[i] == b + w[j])
			{
				cout <<"("<< i << "," <<j<< ")" << endl;
			}
			j++;
		}
		i++;
	}
}
int main(int argc, char* argv[])
{
	//int count_assign = 0, count_compare = 0, count_assign1 = 0, count_compare1 = 0;
	int a[8] = { 5,0,5,3,3,4,5,3 };
	seeSaw(8, 12, a , 8);
	return 0;
}