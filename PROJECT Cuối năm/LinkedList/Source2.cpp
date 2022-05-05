#include <iostream>
using namespace std;
struct NODE
{
	int key;
	NODE* next;
};
struct List
{
	NODE* p_head;
	NODE* p_tail;
};
NODE* createNode(int data)
{
	NODE* newNode = new NODE;
	newNode->key = data;
	newNode->next = nullptr;
	return newNode;
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
	newNode->next = nullptr;
	newNode->next = L.p_head;
	L.p_head = newNode;
	return 1;
}
bool addTail(List& L, int data)
{
	if (L.p_head == nullptr)
	{
		L.p_head = new NODE;
		L.p_head->key = data;
		L.p_head->next = nullptr;
		return 1;
	}
	NODE* pCur = L.p_head;
	while (pCur->next != nullptr)
		pCur = pCur->next;
	NODE* newNode = new NODE;
	newNode->key = data;
	newNode->next = nullptr;
	pCur->next = newNode;
	return 1;
}
void removeHead(List& L)
{
	if (L.p_head == nullptr)
		return;
	NODE* pTemp = L.p_head;
	L.p_head = L.p_head->next;
	delete pTemp;
	pTemp = nullptr;
}
void removeTail(List& L)
{
	if (L.p_head == nullptr)
		return;
	if (L.p_head->next == nullptr)
	{
		delete L.p_head;
		L.p_head = nullptr;
	}
	NODE* pCur = L.p_head;
	while (pCur->next->next != nullptr)
		pCur = pCur->next;
	NODE* pTemp = pCur->next;
	pCur->next = nullptr;
	delete pTemp;
	pTemp = nullptr;
}