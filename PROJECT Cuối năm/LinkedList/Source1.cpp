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

bool insert_head(List& L, int data)
{
	NODE* temp = new NODE;
	if (temp == 0)
	{
		return 0;
	}
	if (L.p_head == NULL)
	{
		temp->key = data;
		L.p_head = temp;
		L.p_tail = L.p_head;
		temp->p_next = NULL;
		return 1;
	}
	else
	{
		temp->key = data;
		temp->p_next = L.p_head;
		L.p_head = temp;
		return 1;
	}
}

bool addTail(List& L, int data)
{
	NODE* node = new NODE;

	if (node == NULL)
		return false;

	node->key = data;
	node->p_next = NULL;

	if (L.p_head == NULL)
	{
		L.p_head = node;
		L.p_tail = node;
	}
	else
	{
		L.p_tail->p_next = node;
		L.p_tail = node;
	}

	return true;
}



struct DoublyNode {
	int key;
	DoublyNode* p_next;
	DoublyNode* p_pre;
};

struct ListList {
	DoublyNode* p_head;
	DoublyNode* p_tail;
};

bool addHead_Doubly(ListList& l, int data) {
	DoublyNode* newnode = new DoublyNode;
	newnode->key = data;
	newnode->p_next = l.p_head;
	newnode->p_pre = NULL;
	l.p_head = newnode;
}


void printList(List L)
{
	for (NODE* current = L.p_head; current != NULL; current = current->p_next)
		cout << current->key << " ";
	cout << endl;
}
void removeHead(List& L) {
	if (L.p_head == NULL) {
		cout << "has empty.\n";
		return;
	}
	NODE* p_curr = L.p_head;
	L.p_head = p_curr->p_next;
	delete p_curr;

}

void removeTail(List& L)
{
	NODE* current = L.p_head;
	NODE* previous = NULL;
	if (L.p_head == NULL)
	{
		cout << "Empty.";
	}
	while (current->p_next != NULL)
	{
		previous = current;
		current = current->p_next;
	}
	delete current;
	previous->p_next = NULL;
}


int main()
{
	List L;
	L.p_head = NULL;
	L.p_tail = NULL;

	insert_head(L, 1);
	insert_head(L, 2);
	insert_head(L, 10);
	printList(L);

	removeHead(L);
	removeHead(L);
	removeHead(L);

	insert_head(L, 3);
	insert_head(L, 4);
	insert_head(L, 5);

	removeTail(L);
	printList(L);

	system("pause");
	return 0;
}