#include <iostream>
using namespace std;
struct NODE {
	int key;
	NODE* p_next;
};

struct List {
	NODE* p_head;
	NODE* p_tail;
};
NODE* CreateNode(int data)
{
	NODE* node = new NODE;
	node->key = data;
	node->p_next = NULL;
	return node;
}
List CreateList(List& l)
{
	l.p_head = NULL;
	l.p_tail = NULL;
}
void PrintList(List l)
{
	if (l.p_head != NULL)
	{
		NODE* node = l.p_head;
		while (node != NULL)
		{
			cout << node->key << ' ';
			node = node->p_next;
		}
	}
}
