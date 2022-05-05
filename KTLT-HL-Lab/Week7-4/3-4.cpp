#include <iostream>
#include <string>
#include <fstream>
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
List creatList(Node* pNode)
{
	List L;
	L.pHead = pNode;
	L.pTail = pNode;
	return L;
}

Node* createNode(int data) {
	Node* p = new Node;
	if (p == NULL) {
		return NULL;
	}
	p->key = data;
	p->pNext = p->pPrev = NULL;
	return p;
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
void insertAfter(Node* p, int value) {
	Node* q = new Node;
	if (q == NULL) {
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

List inputFile(string inputFile) {
	ifstream f;
	List L;
	f.open(inputFile);
	int s = 0;
	string tmp;
	while (!f.eof()) {
		f >> s;
		if (s == 0) {
			return L;
		}
		addTail(L, s);
		getline(f, tmp, ' ');
	}
	return L;
}
void insertEvenNumbers(List& L) {
	int i = 2;
	addHead(L, i);
	Node* p = L.pHead;
	p = p->pNext;
	while (p->pNext != nullptr) {
		//2 1 4 3 6 5 8 7 10 9
		p = p->pNext;
		addBefore(L, i += 2, p->key);
	}

}

void outputFile(List L, string outputFile) {
	ofstream f;
	f.open(outputFile);
	if (L.pHead == nullptr)
		return;
	Node* pTemp = L.pHead;
	while (pTemp != nullptr)
	{
		f << pTemp->key << " ";
		pTemp = pTemp->pNext;
	}
	f << endl;
}

int main()
{
	List L = inputFile("input.txt");
	insertEvenNumbers(L);
	outputFile(L, "output.txt");
	return 0;
}