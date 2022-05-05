//#include <iostream>
//
//using namespace std;
//
//struct Node
//{
//    int data;
//    Node* next;
//};
//
//void insert_at_begin(Node*& pHead, int v)
//{
//    // buoc 1: new node for v value
//    Node* newNode = new Node;
//    newNode->data = v;
//    newNode->next = nullptr;
//
//    // buoc 2: gan new next den new node
//    newNode->next = pHead;
//
//    // buoc 3: gan lai pHead cho newNode
//    pHead = newNode;
//}
//
//void insert_at_end(Node*& pHead, int v)
//{
//    // buoc 0: kiem tra pHead == null?
//    if (pHead == nullptr)
//    {
//        pHead = new Node;
//
//        pHead->data = v;
//        pHead->next = nullptr;
//
//        return;
//    }
//
//    // buoc 1: tim node cuoi
//    Node* pCur = pHead;
//    while (pCur->next != nullptr)
//        pCur = pCur->next;
//
//    // buoc 2: new node moi cho v
//    Node* newNode = new Node;
//    newNode->data = v;
//    newNode->next = nullptr;
//
//    // buoc 3: link node cuoi toi node moi
//    pCur->next = newNode;
//}
//
//void delete_at_begin(Node*& pHead)
//{
//    // buoc 0: kiem tra pHead co bang null khoong
//    if (pHead == nullptr)
//        return;
//
//    // buoc 1: tao temp tro vao head
//    Node* pTemp = pHead;
//
//    // buoc 2: cap nhat lai head
//    pHead = pHead->next;
//
//    // buoc 3: delete temp
//    delete pTemp;
//    pTemp = nullptr;
//}
//
//void delete_at_end(Node*& pHead)
//{
//    // buoc 0: kiem tra head co bang null khong
//    if (pHead == nullptr)
//        return;
//
//    // buoc 0.5: kiem tra xem ll co 1 phan tu khong
//    if (pHead->next == nullptr)
//    {
//        delete pHead;
//        pHead = nullptr;
//    }
//
//    // buoc 1: tim node ke cuoi
//    Node* pCur = pHead;
//    while (pCur->next->next != nullptr)
//        pCur = pCur->next;
//
//    // buoc 2: tao temp de tro den node cuoi
//    Node* pTemp = pCur->next;
//
//    // buoc 3: cap nhat pCur thang node cuoi cung
//    pCur->next = nullptr;
//
//    // buoc 4: xoa pTemp
//    delete pTemp;
//    pTemp = nullptr;
//}
//
//void destroy(Node*& pHead)
//{
//    Node* pCur = pHead;
//    while (pCur->next != nullptr)
//    {
//        Node* pTemp = pCur->next;
//
//        delete pCur;
//
//        pCur = pTemp;
//    }
//
//    pHead = nullptr;
//}
//
//int main()
//{
//    Node* pHead = nullptr;
//
//    insert_at_end(pHead, 1);
//    insert_at_end(pHead, 2);
//    insert_at_end(pHead, 3);
//
//    delete_at_end(pHead);
//
//    Node* pCur = pHead;
//    while (pCur != nullptr)
//    {
//        cout << pCur->data << " ";
//        pCur = pCur->next;
//    }
//
//    // destroy
//    destroy(pHead);
//
//    pCur = pHead;
//    cout << "After destroying" << endl;
//    while (pCur != nullptr)
//    {
//        cout << pCur->data << " ";
//        pCur = pCur->next;
//    }
//
//    return 0;
//}