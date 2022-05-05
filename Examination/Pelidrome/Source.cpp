#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
bool isPalindrome(Node* pHead)
{
	int n = 0;

	for (Node* pCur = pHead; pCur != nullptr; pCur = pCur->next)
		++n;

	int* lstArr = new int[n];
	int index = n - 1;

	for (Node* pCur = pHead; pCur != nullptr; pCur = pCur->next)
		lstArr[index--] = pCur->data;

	index = 0;
	for (Node* pCur = pHead; pCur != nullptr; pCur = pCur->next)
	{
		if (lstArr[index++] != pCur->data)
		{
			delete[] lstArr;
			return false;
		}
	}

	delete[] lstArr;
	return true;
}
void printList(Node* head) 
{
	if (head == NULL) {
		return;
	}

	Node* pCur = head;
	while (pCur != NULL)
	{
		cout << pCur->data << " ";
		pCur = pCur->next;
	}
	return;
}
void addEnd(Node*& head, int val) 
{
	Node* newNode = new Node;
	newNode->data = val;
	newNode->next = NULL;
	if (head == NULL) {
		head = newNode;
		return;
	}

	Node* pCur = head;
	while (pCur->next != NULL)
	{
		pCur = pCur->next;
	}
	pCur->next = newNode;
	return;
}
int palidrome(Node*& head, int size)
{
	Node* pCur = head;
	Node* pCur1 = head->next;//Node thu 2
	Node* pMax = new Node;
	Node* pMin = new Node;
	int count = 1;
	for (pCur; pCur->next != nullptr; pCur = pCur->next)
	{
		if (pCur->data > pCur->next->data)
		{
			pMin->data = pCur->data;
		}
		else if (pCur->data < pCur->next->data)
		{
			pMax->data = pCur1->next->data;
		}
		else return 0;
	}
	pCur = head;
	/*có pMax rồi, giờ kiểm tra xem pMax nằm ở node thứ mấy*/
	while (pCur->next != nullptr)
	{
		if (pCur->data == pMax->data)
		{
			if (count == size / 2 || count == (size / 2) + 1)
				return 1;
		}
		else 
		{
			pCur = pCur->next;
			count++;
		}
	}
	return count;
}
int main()
{
	Node* head = nullptr;
	addEnd(head, 1);
	addEnd(head, 2);
	addEnd(head, 3);
	addEnd(head, 4);
	addEnd(head, 5);
	addEnd(head, 6);
	addEnd(head, 6);
	addEnd(head, 5);
	addEnd(head, 4);
	addEnd(head, 3);
	addEnd(head, 2);
	addEnd(head, 1);
	printList(head);
	cout << "\nAfter" << endl;
	cout << palidrome(head, 12);
	return 0;
}