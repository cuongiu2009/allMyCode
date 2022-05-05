#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
struct Stack {
    Node* head = nullptr;
    int capacity;
};
void initStack(Stack& s, int n) {
    s.capacity = n;
    s.head = nullptr;
}
Node* createNode(int value) {
    Node* p = new Node;
    if (p == nullptr)
        return nullptr;
    p->data = value;
    p->next = nullptr;
    return p;
}
bool isEmpty(Stack s) {
    if (s.head == nullptr)
        return true;
    return false;
}
void push(Stack& s, int value) {
    Node* p = createNode(value);
    if (isEmpty(s)) {
        s.head = p;
    }
    else {
        p->next = s.head;
        s.head = p;
    }
}
void pop(Stack& s) {
    if (!isEmpty(s)) {
        Node* p = s.head;
        s.head = s.head->next;
        delete p;
    }
}
void emptyStack(Stack& s) {
    Node* p = s.head;
    Node* g = p;
    while (p != nullptr) {
        delete p;
        p = g;
        p = p->next;
        s.capacity--;
    }
}
int sizeOfStack(Stack s) {
    return s.capacity;
}
int main() {
    Stack s;
    initStack(s, 3);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    Node* p = s.head;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
    pop(s);
    Node* g = s.head;
    while (g != nullptr) {
        cout << g->data << " ";
        g = g->next;
    }
    return 0;
}