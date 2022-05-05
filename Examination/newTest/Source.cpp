#include <iostream>
using namespace std;
bool isNumber(const char c)
{
    return c >= '0' && c <= '9';
}
int tongSoNguyen(const char* s)
{
	int i = 0;
	int sum = 0;
	int n = 0;
	for (i;i<strlen(s);++i)
	{
		bool check = isNumber(s[i]);
		if (check)
		{
			n = n * 10 + (s[i] - 48);
		}
		if (!check || i==strlen(s)-1 && check)
		{
			sum = sum + n;
			n = 0;
		}
	}
	return sum;
}
//bool isNumber(const char c)
//{
//    return c >= '0' && c <= '9';
//}
//
//int sumNumber(const char* s)
//{
//    int n = strlen(s), sum = 0;
//
//    for (int i = 0, num = 0; i < n; ++i)
//    {
//        bool check = isNumber(s[i]);
//
//        if (check)
//            num = num * 10 + (s[i] - '0');
//
//        if (!check || (i == n - 1 && check))
//        {
//            sum += num;
//            num = 0;
//        }
//    }
//
//    return sum;
//}
int main()
{
	char* s = new char[101];
	cout << "nhap chuoi s:";
	cin.getline(s, 101);
	cout << tongSoNguyen(s);
	return 0;
}