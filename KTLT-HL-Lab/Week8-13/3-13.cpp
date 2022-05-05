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
bool checkLoop(List L,int check) {
	Node* p = L.pHead;
	while (p != nullptr) {
		if (p->key == check)
			return true;
		else p = p->pNext;
	}
	return false;
}
int takeChecknumber(string inputFile) {
	ifstream f;
	f.open(inputFile);
	int s = 0;
	while (!f.eof()) 
		f >> s;
	return s;
}
void outputFile(List L, int check, string outputFile) {
	ofstream f;
	f.open(outputFile);
	if (checkLoop(L, check))
		f << "YES";
	else f << "NO";
}
int main() {
	List L = inputFile("input.txt");
	outputFile(L, takeChecknumber("input.txt"), "output.txt");
	return 0;
}