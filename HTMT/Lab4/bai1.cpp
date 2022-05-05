#include <iostream>
using namespace std;
struct Node {
    int info;
    Node* pNext;
    Node(int info, Node* pNext) : info(info), pNext(pNext) { }
};

class LinkedList {
    friend ostream& operator<<(ostream& os, const LinkedList& right);
private:
    Node* pHead, * pTail;
    int curN;
public:
    LinkedList(void);
    ~LinkedList(void);
    Node* addHead(const int& n);
    Node* addTail(const int& n);
    Node* removeHead();
    Node* removeTail();
    static Node* CreateNode(const int& n);
    int& operator[](const int& i);
};
LinkedList::LinkedList(void) : curN(0) {
    pHead = pTail = NULL;
}
Node* LinkedList::CreateNode(const int& n)
{
    Node* p = new Node(n, nullptr);
    if (p == nullptr) {
        return nullptr;
    }
   /* p->info = n;
    p->pNext = nullptr;*/
    return p;
}

LinkedList::~LinkedList(void) {
    Node* p = pHead, * next = NULL;
    for (; p != NULL; p = next) {
        next = p->pNext;
        delete p;
    }
    curN = 0;
}

Node* LinkedList::addTail(const int& n) {
    if (pTail == NULL) 
        pHead = pTail = new Node(n, NULL);
    else {
        pTail->pNext = new Node(n, NULL);
        pTail = pTail->pNext;
    }
    curN++;
    return pTail;
}

Node* LinkedList::addHead(const int& n) {
    if (pTail == NULL) 
        pHead = pTail = new Node(n, NULL);
    else pHead = new Node(n, pHead);
    curN++;
    return pHead;
}

Node* LinkedList::removeHead() {
    Node* p = pHead;
    if (pHead != NULL) {
        pHead = pHead->pNext;
        delete p;
        if (pHead == NULL) pTail = NULL;
        curN--;
    }
    return p;
}

Node* LinkedList::removeTail() {
    Node* p = pTail;
    if (pTail != NULL) {
        if (pHead->pNext == NULL) {
            delete pHead;
            pHead = pTail = NULL;
        }
        else {
            Node* t = pHead;
            while (t->pNext != pTail) 
                t = t->pNext;
            delete pTail;
            t->pNext = NULL;
            pTail = t;
        }
        curN--;
    }
    return p;
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
    for (Node* k = ll.pHead; k != NULL; k = k->pNext) {
        os << k->info << ", ";
    }
    return os;
}

int& LinkedList::operator[](const int& i) {
    int index = i;
    if (index < 0) index = 0;
    if (index >= curN) index = curN - 1;
    Node* p = pHead;
    for (int k = 0; k < index; ++k, p = p->pNext) {}
    return p->info;
}
int main()
{
    srand(1234);
    LinkedList l;
    for (int i = 0; i < 10; ++i)
    {
        if (rand() % 2 == 0)
        {
            l.addHead(rand() % 1001);
        }
        else
        {
            l.addTail(rand() % 1001);
        }
    }
    cout << l << endl;
    l.removeHead();
    l.removeTail();
    l[-1] = 9000;
    l[4] = 2000;
    l[100] = 10000;
    cout << l << endl;
    return 0;
}