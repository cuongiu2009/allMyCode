#include <iostream>
#include <fstream>
#include <string>
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

int inputFile(string inputFile) {
	ifstream f;
	f.open(inputFile);
	int s = 0;
	f >> s;
	return s;
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
	f << -1;
}
// 123456
List numbToList(int n) {
	List L;
	int re = n % 10;
	while (re != 0) {
		addHead(L, re);
		n = n / 10;
		re = n % 10;
	}
	return L;
}
int main() {
	List L = numbToList(inputFile("input.txt"));
	outputFile(L, "output.txt");
	return 0;
}