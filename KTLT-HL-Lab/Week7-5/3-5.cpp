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
void sortedList(List& L) {
	for (Node* i = L.pHead; i != nullptr; i = i->pNext) {
		for (Node* j = i->pNext; j != nullptr; j = j->pNext) {
			if (i->key > j->key) {
				int tmp = i->key;
				i->key = j->key;
				j->key = tmp;
			}
		}
	}
}
int main() {
	List L = inputFile("input.txt");
	sortedList(L);
	outputFile(L, "output.txt");
	return 0;

}