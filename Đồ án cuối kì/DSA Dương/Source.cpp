#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
struct NODE {
	string s;
	NODE* pNext = NULL;
};
NODE* createNode(string data) {
	NODE* newNode = new NODE;
	if (newNode == NULL)
	{
		return NULL;
	}
	newNode->s = data;
	newNode->pNext = NULL;
	return newNode;
}
// stack
struct stack {
	NODE* pTop = NULL;
};
bool isEmpty(stack head) {
	if (head.pTop == NULL)
	{
		return true;
	}
	return false;
}
void Push(stack& head, string data) {
	NODE* newNode = createNode(data);
	if (newNode == NULL)
	{
		return;
	}
	if (head.pTop == NULL)
	{
		head.pTop = newNode;
		return;
	}
	newNode->pNext = head.pTop;
	head.pTop = newNode;
	return;
}
void Pop(stack& head) {
	if (head.pTop == NULL)
	{
		return;
	}
	NODE* hold = head.pTop;
	head.pTop = head.pTop->pNext;
	delete hold;
}
string Top(stack head) {
	if (head.pTop == NULL)
	{
		string t = {};
		return t;
	}
	return head.pTop->s;
}

// queue
struct queue {
	NODE* pTop = NULL;
};
bool QueueEmpty(queue head) {
	if (head.pTop == NULL)
	{
		return true;
	}
	return false;
}
void Enqueue(queue& head, string data) {
	NODE* newNode = createNode(data);
	if (newNode == NULL)
	{
		return;
	}
	if (head.pTop == NULL)
	{
		head.pTop = newNode;
		return;
	}
	newNode->pNext = head.pTop;
	head.pTop = newNode;
	return;
}
void Dequeue(queue& head) {
	if (head.pTop == NULL)
	{
		return;
	}
	if (head.pTop->pNext == NULL)
	{
		NODE* hold = head.pTop;
		head.pTop = head.pTop->pNext;
		delete hold;
		return;
	}
	NODE* pcur = head.pTop;
	while (pcur->pNext->pNext != NULL)
	{
		pcur = pcur->pNext;
	}
	NODE* hold = pcur->pNext;
	pcur->pNext = pcur->pNext->pNext;
	delete hold;
}
string Front(queue head) {
	string k;
	if (head.pTop == NULL)
	{
		string t = {};
		return t;
	}
	NODE* pcur = head.pTop;
	while (pcur->pNext != NULL)
	{
		pcur = pcur->pNext;
	}
	k = pcur->s;
	return k;
}
string phanTu(string& s)//lay cac phan tu trong chuoi cua file txt
{
	int size = s.size();
	string result;
	if (s[0] == '(' || s[0] == ')')
	{
		result.resize(1);
		result = s[0];
		s.erase(0, 1);
		return result;
	}
	if (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/')
	{
		result.resize(1);
		result = s[0];
		s.erase(0, 1);
		return result;
	}
	int i = 0;
	while (i < size)
	{
		if (s[i] >= '0' && s[i] <= '9' || s[i] == '.')
		{
			result.resize(i + 1);
			result[i] = s[i];
		}
		else break;
		i++;
	}
	s.erase(0, i);
	return result;
}
int checkNumber(string temp)
{
	if (temp == "+" || temp == "-" || temp == "*" || temp == "/")
		return 1;
	else
	{
		if (temp == "(" || temp == ")")
			return -1;
		else return 0;
	}
}
void perfectString(string& p)
{
	for (int i = 0; i < p.length(); i++)
	{
		if (p[i] == ' ')
			p = p.erase(i, 1);
	}
}
int priority(string p)
{
	if (p == "+" || p == "-")
		return 1;
	if (p == "*" || p == "/")
		return 2;
}
void polandTechnique(string s, stack& mystack, queue& myqueue)
{
	while (!s.empty())
	{
		string temp = phanTu(s);
		if (checkNumber(temp) == 0)
			Enqueue(myqueue, temp);
		else
		{
			if (checkNumber(temp) == 1)
			{
				while (!isEmpty(mystack))
				{
					if (checkNumber(Top(mystack)) == 1 && priority(Top(mystack)) >= priority(temp))
					{
						Enqueue(myqueue, Top(mystack));//lay gia tri 
						Pop(mystack);//xoa gia tri khoi stack
					}
					else break;
				}
				Push(mystack, temp);
			}
			else
			{
				if (temp == "(")
					Push(mystack, temp);
				else
				{
					if (temp == ")")
					{
						while (!isEmpty(mystack))
						{
							if (Top(mystack) != "(")
							{
								Enqueue(myqueue, Top(mystack));
								Pop(mystack);
							}
							else break;
						}
						Pop(mystack);
					}
				}
			}
		}
	}
	while (!isEmpty(mystack))
	{
		Enqueue(myqueue, Top(mystack));
		Pop(mystack);
	}
}
// Cho thu nhat chinh string thanh queue
float Caculator(/*string dau*/queue myqueue, float a, float b)
{
	string dau = Front(myqueue);
	if (dau == "+")
		return a + b;
	if (dau == "-")
		return a - b;
	if (dau == "/")
		return a / b;
	if (dau == "*")
		return a * b;
	if (dau == "^")
		return pow(a, b);
}
// cho thu 2 chinh lai ham output 
void outputResult(queue myqueue/*, stack mystack2*/)
{
	float a = stof(Front(myqueue));
	Dequeue(myqueue);
	float b = stof(Front(myqueue));
	Dequeue(myqueue);
	while (!QueueEmpty(myqueue))
	{
		string s = Front(myqueue);
		int flag = priority(s);
		if (flag == 0)
		{
			b = stof(Front(myqueue));
		}
		else {
			a = Caculator(myqueue, a, b);
		}
		Dequeue(myqueue);
	}
	cout << a;
	/*float result = 0;

	while (!QueueEmpty(myqueue))
	{
		string temp = Front(myqueue);
		Enqueue(myqueue, temp);
		if (checkNumber(temp) == 0)
			Push(mystack2, temp);
		else
		{
			stringstream ss;
			float num1 = stof(Top(mystack2));
			cout << num1 << " ";
			Pop(mystack2);
			float num2 = stof(Top(mystack2));
			cout << num2;
			Pop(mystack2);
			result = Caculator(temp, num2, num1);
			cout << temp;
			ss << result;
			string s(ss.str());
			Push(mystack2, s);
			result = stof(s);
		}
	}*/
}
int main()
{
	stack st;
	queue qu;
	string s = "3+3+2";
	polandTechnique(s, st, qu);
	outputResult(qu);
	return 0;
}