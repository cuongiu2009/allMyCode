#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Node {
    int data;
    Node* pNext;
};
struct List {
    Node* pHead = nullptr;
};
Node* createNode(int value) {
    Node* temp = new Node;
    temp->data = value;
    temp->pNext = NULL;

    return temp;
}
void addHead(List& L, int data) {
    if (L.pHead == nullptr)
        Node* p = createNode(data);
    Node* p = createNode(data);
    if (p != nullptr) {
        p->pNext = L.pHead;
        L.pHead = p;
    }
}
void addTail(List& L, int data) {
    Node* p = createNode(data);
    if (L.pHead == nullptr) {
        L.pHead = p;
        L.pHead->pNext = nullptr;
    }
    else {
        Node* tmp = L.pHead;
        while (tmp->pNext != nullptr)
            tmp = tmp->pNext;
        tmp->pNext = p;
    }
}


void printList(List L) {
    if (L.pHead == nullptr)
        return;
    Node* temp = L.pHead;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->pNext;
    }
}

List ListOfSum(List L) {
    List newList;
    int sum = 0;
    Node* p = L.pHead;
    while (p != nullptr) {
        sum = sum + p->data;
        addTail(newList, sum);
        p = p->pNext;
    }
    return newList;
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
        f << pTemp->data << " ";
        pTemp = pTemp->pNext;
    }
    f << 0;
}
int main() {
    List L = inputFile("input.txt");
    List L1 = ListOfSum(L);
    outputFile(L1, "output.txt");
    return 0;
}