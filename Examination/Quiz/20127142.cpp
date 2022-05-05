//#include <iostream>
//using namespace std;
//int maxDivisor(int n, int temp)
//{
//	int max = 0;
//	for (int i = 1; i < n; i++)
//	{
//		if (n % i == 0)
//			max = i;
//	}
//	return max;
//}
//int maxDivisor1(int n, int temp)
//{
//	if (temp == 1)
//		return 1;
//	if (n % temp == 0)
//		return temp;
//	else return maxDivisor1(n, temp - 1);
//}
//bool isPrime(int a)
//{
//	int c = 0;
//	for (int i = 1; i < a; i++)
//	{
//		if (a % i == 0)
//			c++;
//	}
//	if (c > 2)
//		return false;
//	else return true;
//}
//int* findPrime(int* a, int lena, int* b, int lenb)
//{
//	int count = 0;
//	int index = 0;
//	for (int i = 0; i < lena; i++)
//	{
//		if (isPrime(a[i])) count++;
//	}
//	for (int i = 0; i < lenb; i++)
//	{
//		if (isPrime(b[i])) count++;
//	}
//	int* c = new int[count];
//	for (int i = 0; i < lena; i++)
//	{
//		if (isPrime(a[i])) c[index++]=a[i];
//	}
//	for (int i = 0; i < lenb; i++)
//	{
//		if (isPrime(b[i])) c[index++] = a[i];
//	}
//	return c;
//}
//int main()
//{
//	cout << maxDivisor1(10, 9);
//	cout << maxDivisor(10, 1);
//	return 0;
//}