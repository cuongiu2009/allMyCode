#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;
int main() {
	fstream f;
	f.open("input.txt");
	string s;
	f >> s;
	stringstream ss;
	ss << s;
	string a;
	ss >> a;
	cout << a;
	return 0;
}