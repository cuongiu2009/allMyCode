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
}
List* createList(NODE* p_node)
{
	NODE* p_head = nullptr;
	NODE* p_tail = nullptr;
}
bool addHead(List& L, int data)
{
	NODE* newNode = new NODE;
	newNode->key = data;
	newNode->p_next = nullptr;

	newNode->p_next = L.p_head;
	L.p_head = newNode;
	return true;
}
bool addTail(List& L, int data)
{
	if (L.p_head == nullptr)
		addHead(L, data);
	NODE* pCur = L.p_head;
	while (pCur->p_next != nullptr)
		pCur = pCur->p_next;
	NODE* newNode = new NODE;
	newNode->key = data;
	newNode->p_next = nullptr;
	pCur->p_next = newNode;
	return true;
}
bool removeHead(List& L, int data)
{
	if (L.p_head == nullptr)
		return false;
	NODE* pTemp = L.p_head;
	L.p_head = L.p_head->p_next;
	delete pTemp;
	pTemp = nullptr;
	return true;
}
bool removeTail(List& L, int data)
{
	if (L.p_head == nullptr)
		return false;
	if (L.p_head->p_next == nullptr)
	{
		delete L.p_head;
		L.p_head = nullptr;
	}
	NODE* pCur = L.p_head;
	while (pCur->p_next->p_next != nullptr)
		pCur = pCur->p_next;
	NODE* pTemp = pCur->p_next;
	pCur->p_next = nullptr;
	delete pTemp;
	pTemp = nullptr;
}
void sortingLinkedList(List &L)
{
	NODE* pCur1 = L.p_head->p_next;
	NODE* pCur2 = pCur1->p_next;
	NODE* pTemp = new NODE;
	while (pCur1->p_next != nullptr)
	{
		pTemp->key = pCur1->key;
		pCur1->key = pCur2->key;
		pCur2->key = pTemp->key;
		pCur1 = pCur1->p_next;
	}
}

