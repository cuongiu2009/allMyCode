#include <iostream>
using namespace std;
void reverse(char* s)
{
    char* point = s;
    int i, min;
    for (i = 0; *point != '\0'; i++)
        point++;
    min = i;
    point--;
    for (i = min; i > 0; i--)
    {
        cout << *point--;
    }
}
bool isPalindrome(char* cstr)
{
	char* front = cstr;
	char* back = cstr + strlen(cstr) - 1;
    reverse(back);
    int i = 0;
	while (front < back)
	{
        if (back[i] == front[i])
            return true;
        else return false;
        i++;
	}
	return true;
}
int main()
{
    char* a = new char[10];
    cin.getline(a, 10);//ATOYOTA
    if (isPalindrome(a))
        cout << "true";
    else
        cout << "false"; // return true;
    delete[]a;
    return 0;
}