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


List inputFile(string inputFile) {
	ifstream f;
	List L;
	f.open(inputFile);
	int s = 0;
	string tmp;
	while (!f.eof()) {
		f >> s;
		if (s == 0)
			return L;
		addTail(L, s);
		getline(f, tmp, ' ');
	}
	return L;
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

List resizeList(List &L) {//1 2 3 4 5 6
	List newList;
	Node* p = L.pHead;
	
	while (p != nullptr) {
		p = p->pNext;
		addTail(newList, p->key);
		p = p->pNext;
	}
	return newList;
}
List newOriginList(List& L, List L1) {
	Node* p = L.pHead;
	Node* k = L1.pHead;
	while (p != nullptr) {
		if (p->key == k->key) {
			Node* tmp = p->pNext;
			removeElement(L, p->key);
			p = tmp;
			k = k->pNext;
		}
		else p = p->pNext;
	}
	return L;
}
void outputFile(List L1, List L2, string outputFile) {
	ofstream f;
	f.open(outputFile);
	if (L1.pHead == nullptr)
		return;
	Node* pTemp1 = L1.pHead;
	Node* pTemp2 = L2.pHead;
	while (pTemp1 != nullptr)
	{
		f << pTemp1->key << " ";
		pTemp1 = pTemp1->pNext;
	}
	f << 0 << endl;
	while (pTemp2 != nullptr) {
		f << pTemp2->key << " ";
		pTemp2 = pTemp2->pNext;
	}
	f << 0;
}
int main() {
	List L = inputFile("input.txt");
	List newList = resizeList(L);
	L = newOriginList(L, newList);
	outputFile(L, newList, "output.txt");
	
	//print(newList);
	return 0;
}