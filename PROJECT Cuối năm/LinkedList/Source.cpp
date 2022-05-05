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
NODE* createNode(int data)
{
	NODE* newNode = new NODE;
	newNode->key = data;
	newNode->p_next = nullptr;
	return newNode;
}
List* createList(NODE* p_node)
{
	NODE*p_head = nullptr;
	NODE*p_tail = nullptr;
}
bool addHead(List*& l, int data)
{
	NODE* newNode = new NODE;
	newNode->key = data;
	newNode->p_next = nullptr;

	newNode->p_next = l->p_head;
	l->p_head = newNode;
}
bool addTail(List*& L, int data)
{
	NODE* newNode = new NODE;
	newNode->key = data;
	newNode->p_next = nullptr;

	if (L->p_head == nullptr)
	{
		L->p_head = new NODE;
		L->p_head->key = data;
		L->p_head->p_next = nullptr;
	}

	NODE* pCur = L->p_head;
	while (pCur->p_next != nullptr)
	{
		pCur = pCur->p_next;
	}
	pCur->p_next = newNode;
}
void removeHead(List*& L)
{
	if (L->p_head == nullptr)
	{
		return;
	}
	NODE* pTemp = L->p_head;
	L->p_head = L->p_head->p_next;
	delete pTemp;
	pTemp = nullptr;
}
void removeTail(List*& L)
{
	if (L->p_head == nullptr)
		return;
	if (L->p_head->p_next == nullptr)
	{
		delete L->p_head;
		L->p_head = nullptr;
	}
	NODE* pCur = L->p_head;
	while (pCur->p_next->p_next != nullptr)
	{
		pCur = pCur->p_next;
	}
	NODE* pTemp = pCur->p_next;
	pCur->p_next = nullptr;
	delete pTemp;
	pTemp = nullptr;
}
void removeAll(List*& L)
{
	NODE* pCur = L->p_head;
	while (pCur->p_next != nullptr)
	{
	    NODE* pTemp = pCur->p_next;
	
	    delete pCur;
	
		pCur = pTemp;
	}
	L->p_head = nullptr;
}
void removeBefore(List*& L, int val)
{
	if (L->p_head == nullptr)
		return;
	if (L->p_head->p_next == nullptr)
	{
		delete L->p_head;
		L->p_head = nullptr;
	}
	int k = 1;
	NODE* pCur = L->p_head;
	while (pCur->p_next != NULL && k != val)
	{
		pCur = pCur->p_next;
		k++;
	}
	if (k == val)
	{
		pCur = pCur->p_next;
	}
}
void removePos(List*& L, int data, int pos)
{
	if (L->p_head == nullptr)
		return;
	if (L->p_head->p_next == nullptr)
	{
		delete L->p_head;
		L->p_head = nullptr;
	}
	int k = 1;
	NODE* pCur = L->p_head;
	while (pCur->p_next != NULL && k != pos-1)
	{
		pCur = pCur->p_next;
		k++;
	}
	pCur->p_next = pCur->p_next->p_next;
}