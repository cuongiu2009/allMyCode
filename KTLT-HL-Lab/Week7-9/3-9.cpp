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
void remove(List& L, Node* p) {

	if (p->pNext != NULL) {
		p->pNext->pPrev = p->pPrev;
	}
	else if (p->pPrev != NULL) {
		p->pPrev->pNext = p->pNext;
	}
	free(p);
}

void joinList(List& L, int key) {
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


List inputFile(string inputFile) {
	ifstream f;
	List L;
	f.open(inputFile);
	int s = 0;
	string tmp;
	while (!f.eof()) {
		f >> s;
		addTail(L, s);
		getline(f, tmp, ' ');
	}
	return L;
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
}

int main()
{
	List L;
	L = inputFile("input.txt");
	joinList(L, 0);
	outputFile(L, "output.txt");
	return 0;
}