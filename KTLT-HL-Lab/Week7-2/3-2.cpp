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
	f << 0;
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


int main()
{
	List L = inputFile("input.txt");

	removeDuplicate(L);
	outputFile(L, "output.txt");
	return 0;
}