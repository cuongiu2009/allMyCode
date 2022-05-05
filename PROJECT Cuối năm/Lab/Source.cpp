#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
	int a, b, c;
	ifstream f("text.txt");
	string s, so1, so2, so3, ten;
	while (!f.eof())
	{
		getline(f, s);
		stringstream ss(s);
		getline(ss, ten, ':');
		getline(ss, so1, ',');
		getline(ss, so2, ',');
		getline(ss, so3, ',');
		a = stof(so1);
		b = stof(so2);
		c = stof(so3);
		cout << ten <<" ";
	}
	cout << a << " " << b << " " << c;
	return 0;
}