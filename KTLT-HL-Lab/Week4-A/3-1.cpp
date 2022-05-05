#include <iostream>
using namespace std;
void addOne(int* ptrNum) {
	*ptrNum += 1;
}
int main() {
	int num = 45;
	cout << "The number before function addOne:" << num << endl;
	addOne(&num);
	cout << "The number after the function addOne:" << num << endl;
}