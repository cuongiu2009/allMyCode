#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	string line;
	int s = 0;
	ifstream ifs("text.txt");
	while (ifs >> line)
		++s;
	ifs.close();
	cout << "number of words in paragraph is " << s;
	return 0;
}