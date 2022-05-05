#include<iostream>
#include<string>
using namespace std;
const int n = 10;
//int check(string s, int n, int& count) {
//    int unit[4] = { 0 };
//    for (int i = 0; i < n; ++i) {
//        if (s[i] >= '0' && s[i] <= '9') {
//            unit[0]++;
//        }
//        if (s[i] >= 'a' && s[i] <= 'z') {
//            unit[1]++;
//        }
//        if (s[i] >= 'A' && s[i] <= 'Z') {
//            unit[2]++;
//        }
//        if ((s[i] >= '#' && s[i] <= '&') || (s[i] >= '(' && s[i] <= '+') || s[i] == '^' || s[i] == '!' || s[i] == '@' || s[i] == '-') {
//            unit[3]++;
//        }
//    }
//    for (int i = 0; i < 4; i++) {
//        if (unit[i] == 0) {
//            count++;
//        }
//    }
//    int tmp;
//    if (n < 6) {
//        tmp = 6 - n;
//        if (count < tmp) {
//            count = tmp;
//        }
//    }
//    return count;
//}
//int main() {
//    int length;
//    cin >> length;
//    string s;
//    cin.ignore();
//    getline(cin, s);
//    int count = 0;
//    cout << check(s, length, count);
//int gt(int n)
//{
//	if (n == 1)
//		return 1;
//	return n * gt(n - 1);
//}
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a[5] = { 3,2,1,4,5 };
	for (int i = 0; i < 5; ++i)
	{
		int max = i;
		for (int j = i + 1; j < 5; j++)
		{
			if (a[j] > a[max]) max = j;
		}
		swap(a[max], a[i]);
	}
	for (int i = 0; i < 5; i++)
		cout << a[i];
	return 0;
}

