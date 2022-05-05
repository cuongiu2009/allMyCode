#include <iostream>
#include <ctime>
using namespace std;
struct Node {
	int key;
	Node* pPrev;
	Node* pNext;
};
struct List {
	Node* pHead = nullptr;
	Node* pTail = nullptr;
};


Node* createNode(int data) {
	Node* p = new Node;
	if (p == NULL) {
		return NULL;
	}
	p->key = data;
	p->pNext = p->pPrev = NULL;
	return p;
}
List creatList(Node* pNode)
{
	List L;
	L.pHead = pNode;
	L.pTail = pNode;
	return L;
}
bool addHead(List& L, int data) {
	if (L.pHead == nullptr)
	{
		Node* p = createNode(data);
		if (p != nullptr)
		{
			L = creatList(p);
			return true;
		}
		return false;
	}
	Node* p = createNode(data);
	if (p != nullptr)
	{
		p->pNext = L.pHead;
		L.pHead->pPrev = p;
		L.pHead = p;
		return true;
	}
	return false;
}
bool addTail(List& L, int data) {
	Node* p = createNode(data);
	if (L.pHead == NULL) {
		L.pHead = L.pTail = p;
		L.pHead->pPrev = NULL;
		L.pTail->pNext = NULL;
	}
	else {
		L.pTail->pNext = p;
		p->pPrev = L.pTail;
		L.pTail = p;
		L.pTail->pNext = NULL;
	}
	return true;
}
void remove(List& L, Node* p) {

	if (p->pNext != NULL) {
		p->pNext->pPrev = p->pPrev;
	}
	else if (p->pPrev != NULL) {
		p->pPrev->pNext = p->pNext;
	}
	free(p);
}
void removeHead(List& L) {
	if (L.pHead == nullptr)
		return;
	if (L.pHead == L.pTail)
	{
		Node* pTemp = L.pHead;
		L.pHead = nullptr;
		L.pTail = nullptr;
		delete pTemp;
		pTemp = nullptr;
	}
	Node* pTemp = L.pHead;
	L.pHead = L.pHead->pNext;
	L.pHead->pPrev = nullptr;
	delete pTemp;
	pTemp = nullptr;
}
void removeTail(List& L) {
	if (L.pHead == nullptr)
		return;
	if (L.pHead == L.pTail)
	{
		Node* pTemp = L.pHead;
		L.pHead = nullptr;
		L.pTail = nullptr;
		delete pTemp;
		pTemp = nullptr;
	}
	Node* pTemp = L.pTail;
	L.pTail = L.pTail->pPrev;
	L.pTail->pNext = nullptr;
	delete pTemp;
	pTemp = nullptr;
}
void removeAll(List& L) {
	Node* pCur = L.pHead;
	while (pCur->pNext != nullptr)
	{
		Node* pTemp = pCur->pNext;

		delete pCur;

		pCur = pTemp;
	}
	L.pHead = nullptr;
}
void removeBefore(List& L, int val) {
	if (L.pHead == nullptr)
		return;
	if (L.pHead->pNext == nullptr)
	{
		delete L.pHead;
		L.pHead = nullptr;
	}
	if (L.pHead->key == val)
		return removeHead(L);
	Node* p = L.pHead->pNext;
	while (p != nullptr && p->key != val)
		p = p->pNext;
	Node* p1 = p->pPrev;
	p->pPrev == p1->pPrev;
	p1->pPrev->pNext = p;
	delete p1;
	p1 = nullptr;
}
void removeAfter(List& L, int val) {
	if (L.pHead == nullptr)
		return;
	if (L.pHead->pNext == nullptr)
		return;
	if (L.pTail->key == val)
		return removeTail(L);
	Node* p = L.pHead;
	while (p != nullptr && p->key != val)
		p = p->pNext;
	Node* p1 = p->pNext;
	p->pNext = p1->pNext;
	p1->pNext->pPrev = p;
	delete p1;
	p1 = nullptr;
}
bool addPos(List& L, int data, int pos) {
	Node* temp, * s;
	temp = new Node;
	temp->key = data;
	s = L.pHead;
	int count = 1, flag = 1;
	if (pos == 1) {
		cout << "Try another position!!!" << endl;
		return false;
	}
	else {
		while (count != pos - 1) {
			s = s->pNext;
			if (s == NULL) {
				flag = 0;
				break;
			}
			count++;
		}
		if (flag == 1) {
			temp->pNext = s->pNext;
			s->pNext->pPrev = temp;
			s->pNext = temp;
			temp->pPrev = s;
			return true;
		}
		else {
			cout << "Position not found" << endl;
			return false;
		}
	}
}
void removePos(List& L, int pos) {
	if (L.pHead == nullptr)
		return;
	if (L.pHead->pNext == nullptr)
	{
		delete L.pHead;
		L.pHead = nullptr;
	}
	int k = 1;
	Node* pCur = L.pHead;
	while (pCur->pNext != NULL && k != pos - 1)
	{
		pCur = pCur->pNext;
		k++;
	}
	pCur->pNext = pCur->pNext->pNext;
}
void insertAfter(Node* p, int value) {
	Node* q = new Node;
	if (q == NULL) {
		exit(4);
		return;
	}
	q->key = value;
	q->pPrev = p;
	q->pNext = p->pNext;
	if (p->pNext != NULL) {
		p->pNext->pPrev = q;
	}
	p->pNext = q;
}
bool addBefore(List& L, int data, int val) {
	for (Node* k = L.pHead; k != NULL; k = k->pNext) {
		if (k->pNext->key == val) {
			insertAfter(k, data);
			return true;
		}
	}
}
bool addAfter(List& L, int data, int val) {
	for (Node* k = L.pHead; k != NULL; k = k->pNext) {
		if (k->key == val) {
			insertAfter(k, data);
			return true;
		}
	}
}
void printFoward(List L) {
	if (L.pHead == nullptr)
		return;
	Node* pTemp = L.pHead;
	while (pTemp != nullptr)
	{
		cout << pTemp->key << " ";
		pTemp = pTemp->pNext;
	}
	cout << endl;
}
int countElements(List L) {
	int count = 0;
	Node* current = L.pHead;
	while (current != NULL) {
		count++;
		current = current->pNext;
	}
	return count;
}
void printBackward(List L) {
	if (L.pHead == nullptr)
		return;
	Node* pTemp = L.pTail;
	while (pTemp != nullptr)
	{
		cout << pTemp->key << " ";
		pTemp = pTemp->pPrev;
	}
	cout << endl;
}
void removeDuplicate(List& L) {
	if (L.pHead != NULL) {
		Node* curr = L.pHead, * temp = NULL, * find = NULL;
		while (curr != NULL) {
			temp = curr->pNext;
			while (temp != NULL) {
				if (temp->key == curr->key) {
					find = temp;
				}
				temp = temp->pNext;
				if (find != NULL) {
					if (find->pPrev != NULL) {
						find->pPrev->pNext = temp;
					}
					if (temp != NULL) {
						temp->pPrev = find->pPrev;
					}
					find->pPrev = NULL;
					find->pNext = NULL;
					delete find;
					find = NULL;
				}
			}
			curr = curr->pNext;
		}
	}
}
void removeElement(List& L, int key) {
	if (L.pHead == NULL) {
		return;
	}
	Node* g = new Node;
	for (Node* k = L.pHead; k != nullptr; k = k->pNext) {
		if (k->key == key) {
			g->pNext = k->pNext;
			delete k;
			return;
		}
		g = k;
	}
}



int main()
{
	List L;
	L.pHead = L.pTail = nullptr;
	addTail(L, 1);
	addTail(L, 2);
	addTail(L, 3);
	addTail(L, 4);
	addTail(L, 5);
	addTail(L, 6);
	addTail(L, 7);
	addTail(L, 8);
	addTail(L, 10);
	addTail(L, 10);

	printFoward(L);
	removeDuplicate(L);
	printFoward(L);
	return 0;
}