#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
struct NODE {
	string s;
	float s1;
	NODE* pNext = NULL;
};
struct stack {
	NODE* pTop = NULL;
};
struct stack1 {
	NODE* pTop = NULL;
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
NODE* createNode1(float data) {
	NODE* newNode = new NODE;
	if (newNode == NULL)
	{
		return NULL;
	}
	newNode->s1 = data;
	newNode->pNext = NULL;
	return newNode;
}
// stack
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
void Push1(stack1& head, float data) {
	NODE* newNode = createNode1(data);
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
void Pop1(stack1& head) {
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
float Top1(stack1 head) {
	if (head.pTop == NULL)
	{
		return 0;
	}
	return head.pTop->s1;
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


//process


void perfectString(string& p)
{
	for (int i = 0; i < p.length(); i++)
	{
		if (p[i] == ' ')
			p = p.erase(i, 1);
	}
}
string getString(string& s)//lay cac phan tu trong chuoi cua file txt
{
	int size = s.size();
	string result;
	int c = 0;
	if (s[0]==' ')
	{
		result.resize(1);
		result = s[0];
		s.erase(0, 1);
		return result;
	}
	if (s[0] == 'ˆ')
	{
		result.resize(1);
		result = "^";
		s.erase(0, 1);
		return result;
	}
	if (s[0] == '(' || s[0] == ')'||s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/' || s[0] == '[' || s[0] == ']' || s[0] == '{' || s[0] == '}')
	{
		result.resize(1);
		result = s[0];
		s.erase(0, 1);
		return result;
	}
	int i = 0;
	while (i < size)
	{
		if (s[i] >= '0' && s[i] <= '9' || s[i]=='.')
		{
			if (s[i] == '.')
			{
				c++;
				result.resize(i + 1);
				result[i] = s[i];
				if (c > 1)
					break;
			}
			else {
				result.resize(i + 1);
				result[i] = s[i];
			}
		}	
		else break;
		i++;
	}
	s.erase(0, i);
	return result;  
}
int checkPhanTu(string temp)
{
	if (temp == "+" || temp == "-" || temp == "*" || temp == "/"|| temp == "^")
		return 1;
	else
	{
		if (temp == "(" || temp == ")"||temp=="[" || temp == "]" || temp == "{" || temp == "}")
			return -1;
		else return 0;
	}
}
void deleteQueue(queue& qu)
{
	while (!QueueEmpty(qu))
		Dequeue(qu);
	Enqueue(qu, "E");
}
int priority(string p)
{
	if (p == "^")
		return 3;
	if (p == "+" || p == "-")
		return 1;
	if (p == "*" || p == "/")
		return 2;
}
void convert(string bieuThuc, stack& st, queue& qu)
{
	int key = 0;
	if (bieuThuc.size() < 5)
	{
		deleteQueue(qu);
		return;
	}
	while (!bieuThuc.empty())
	{
		string temp = getString(bieuThuc);
		if (temp[0] ==' ')
			continue;
		else if (checkPhanTu(temp) == 0)
		{
			Enqueue(qu, temp);
			if (key == 1)
			{
				deleteQueue(qu);
				return;
			}
			key = 1;
		}
		else
		{
			if (checkPhanTu(temp) == 1)
			{
				if (key == 2)
				{
					deleteQueue(qu);
					return;
				}
				key = 2;
				while (!isEmpty(st))
				{
					if (checkPhanTu(Top(st)) == 1 && priority(Top(st)) >= priority(temp))
					{
						Enqueue(qu, Top(st));
						Pop(st);
					}
					else break;
				}
				Push(st, temp);
			}
			else
			{
				if (temp == "("|| temp == "[" || temp == "{")
				{
					if (key == 3)
					{
						deleteQueue(qu);
						return;
					}
					key = 2;
				}
				else if (temp == ")" || temp == "]" || temp == "}")
				{
					if (key == 2)
					{
						deleteQueue(qu);
						return;
					}
					key = 3;
				}
				else 
				{
					if (key == 4)
					{
						deleteQueue(qu);
						return;
					}
					key = 4;
				}
				if (temp == "("|| temp == "[" || temp == "{")
					Push(st, temp);
				else
				{
					if (temp == ")" || temp == "]" || temp == "}")
					{
						while (!isEmpty(st))
						{
							if (Top(st) != "(" && Top(st) != "[" && Top(st) != "{")
							{
								Enqueue(qu, Top(st));
								Pop(st);
							}
							else break;
						}
						Pop(st);
					}
				}
			}
		}
	}
	while (!isEmpty(st))
	{
		Enqueue(qu, Top(st));
		Pop(st);
	}
}
float cal(string dau,float a,float b)
{
	if (dau == "+")
		return a + b;
	if (dau == "-")
		return a - b;
	if (dau == "*")
		return a * b;
	if (dau == "/")
		return a / b;
}
float Result(queue qu, stack1 st2)
{
	float result = 0;
	while (!QueueEmpty(qu))
	{
		string tmp = Front(qu);
		Dequeue(qu);
		if (checkPhanTu(tmp) == 0)
		{
			Push1(st2, stof(tmp));
		}
		else
		{
			float num1 = Top1(st2);
			Pop1(st2);
			float num2 = Top1(st2);
			Pop1(st2);
			result = cal(tmp, num2, num1);
			Push1(st2, result);
		}
	}
	return result;
}
void input(string file)
{
	fstream ff("output.txt", ios::out);
	fstream f(file, ios::in);
	string s;
	while (!f.eof())
	{
		stack st;
		queue qu;
		getline(f, s);
		convert(s, st, qu);
		while (!QueueEmpty(qu))
		{
			if (Front(qu) == "E")
			{
				ff << "E";
				break;
			}
			if (Front(qu) == "0")
			{
				ff << '0' << " ";
				Dequeue(qu);
			}
			if (priority(Front(qu)) == 3)
			{
				ff << 'ˆ' << " ";
				Dequeue(qu);
			}
			else
			{
				ff << Front(qu) << " ";
				Dequeue(qu);
			}
		}
		ff << endl;
	}
	f.close();
	ff.close();
}
int main(int agrc, char *argv[])
{
	
}