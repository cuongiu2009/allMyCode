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


void inputFile(List &L1, List &L2, string inputFile) {
	ifstream f;
	f.open(inputFile);
	int s = 0;
	string tmp;
	while (!f.eof()) {
		f >> s;
		if (s != 0) {
			addTail(L1, s);
			getline(f, tmp, ' ');
		}
		else {
			if (s != 0) {
				addTail(L2, s);
				getline(f, tmp, ' ');
			}
		}
	}
}
void print(List L) {
	Node* p = L.pHead;
	while (p != nullptr) {
		cout << p->key << " ";
		p = p->pNext;
	}
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
	List L1, L2;
	inputFile(L1, L2, "input.txt");
	print(L1);

	//print(newList);
	return 0;
}