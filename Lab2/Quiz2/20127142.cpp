#include <iostream>
using namespace std;
int fib_recur(int n, int& count_assign, int& count_compare)
{
	if (++count_compare && n <= 1)
		return 1;
	else
		return fib_recur(n - 1,++count_assign, count_compare) + fib_recur(n - 2, ++count_assign, count_compare);
}
int fib(int n, int& count_assign, int& count_compare)
{
	if (++count_compare && n <= 1)
		return 1;
	int last = 1; ++count_assign;
	int nextToLast = 1; ++count_assign;
	int answer = 1; ++count_assign;
	++count_assign;
	for (int i = 2; i <= n; i++)
	{
		count_assign += 2;
		answer = last + nextToLast; ++count_assign;
		nextToLast = last; ++count_assign;
		last = answer; ++count_assign;
	}
	count_assign += 1;
	count_compare += 1;
	return answer;
}
int main(int argc, char* argv[])
{
	int count_assign = 0, count_compare = 0;
	if (argc < 2) cout << "not enough arguments\n";
	else
	{
		int n = atoi(argv[1]);
		fib_recur(n, count_assign, count_compare);
		cout << "assign counts=" << count_assign;
		cout << "fib_recur(n) is 0(2^n)" << endl;
		count_assign = 0, count_compare = 0;
		fib(n, count_assign, count_compare);
		cout << "assign counts = " << count_assign;
		cout << "fib(n) is 0(n)" << endl;
	}
	return 0;
}