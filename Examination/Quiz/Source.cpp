#include <iostream>
using namespace std;
void somesum(int n)
{
	int count_assign = 0;
	int sum = 0; ++count_assign;
	int i = 1; ++count_assign;
	int j; ++count_assign;
	while (++count_assign && i <= n) {
		j = n - i; ++count_assign;
		while (++count_assign && j <= i * i) {
			sum = sum + i * j; ++count_assign;
			j += 1; ++count_assign;
		}
		i += 1; ++count_assign;
	}
	cout << sum << " ";
	cout << count_assign;
}
int squaresum_recursion(int n, int &count,int &count2){
	if (++count && n < 1) return 0;
	else {
		++count;
		return n * n + squaresum_recursion(n - 1, count, ++count2);
	}
}
int main()
{
	int b = 0;
	int c = 0;
	int a = squaresum_recursion(500, b, c);
	cout << a << " " << b << " " << c;
	return 0;
}
