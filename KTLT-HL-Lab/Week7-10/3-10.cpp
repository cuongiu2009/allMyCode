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

List inputFile(string inputFile) {
	ifstream f;
	List L;
	f.open(inputFile);
	int s = 0;
	string tmp;
	while (!f.eof()) {
		f >> s;
		if (s == -1)
			return L;
		addTail(L, s);
		getline(f, tmp, ' ');
	}
	return L;
}


void outputFile(int res, string outputFile) {
	ofstream f;
	f.open(outputFile);
	f << res;
}
// 1 2 3 4 5 6
int ListToNumb(List L) {
	Node* p = L.pHead;

	int i = 0, sum = 0;
	while (p != nullptr) {
		sum = sum * 10 + p->key;
		p = p->pNext;
		i++;

	}
	return sum;
}
int main() {
	List L = inputFile("input.txt");
	outputFile(ListToNumb(L),"output.txt");
	return 0;
}