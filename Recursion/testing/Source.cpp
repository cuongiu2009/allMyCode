#include<iostream>
using namespace std;

struct node {
	int data;
	node* pNext;
};

struct List {
	node* pHead;
};

int sum(int n, int k = 1)
{
	if (k == n)
		return n;
	return sum(n, k + 1) + k;

}


int factorial(int n) {
	if (n == 0)
		return 1;
	return factorial(n - 1) * n;
}

// Bai 1
void extractNearest(int* A, int N, int X, int*& B, int& M)
{
	// Tim abs min
	int minAbs = INT_MAX;
	int tempAbs = 0;
	for (int i = 0; i < N; i++)
	{
		tempAbs = abs(A[i] - X);

		if (tempAbs < minAbs)
			minAbs = tempAbs;
	}

	// Dem so phan tu cua B
	M = 0;
	for (int i = 0; i < N; i++)
		if (abs(A[i] - X) == minAbs)
			M++;

	// Cap phat don B
	B = new int[M];
	int j = 0;

	// Lay phan tu vao B
	for (int i = 0; i < N; i++)
		if (abs(A[i] - X) == minAbs)
			B[j++] = A[i];
}

// Cau 2
void addHead(List& ls, int value)
{
	// Pre
	node* newNode = new node;
	newNode->data = value;
	newNode->pNext = nullptr;

	// Buoc 0:
	if (ls.pHead == nullptr)
	{
		ls.pHead = newNode;
		return;
	}

	// Buoc 1
	newNode->pNext = ls.pHead;

	// Buoc 2
	ls.pHead = newNode;
}

int countNode(List ls)
{
	if (ls.pHead == nullptr)
		return 0;

	node* pPre = ls.pHead;
	node* pCur = pPre->pNext;
	int count = 0;

	while (pCur->pNext != nullptr)
	{
		if (pPre->data + pCur->pNext->data == pCur->data)
		{
			 count++;
			cout << pCur->data << " ";
		}

		pPre = pCur;
		pCur = pCur->pNext;
	}

	return count;
}


node* findMin(node* start)
{
	if (start == nullptr)
		return nullptr;

	if (start->pNext == nullptr)
		return start;

	node* minBenPhai = findMin(start->pNext);

	if (start->data < minBenPhai->data)
		return start;

	return minBenPhai;
}


int main() {
	/*int A[7] = { 2, 7, 1, 3, -4, 7 };
	int N = 6;
	int X = 5;

	int* B;
	int M = 0;

	extractNearest(A, N, X, B, M);

	for (int i = 0; i < M; i++)
		cout << B[i] << " ";

	delete[] B;*/
	List ls;
	ls.pHead = nullptr;

	addHead(ls, 11);
	addHead(ls, 14);
	addHead(ls, 3);
	addHead(ls, 4);
	addHead(ls, 1);
	addHead(ls, 7);
	addHead(ls, 6);

	node* min = findMin(ls.pHead);
	cout << min->data;

	/*
	cout << countNode(ls);

	cout << "ket qua:" << sum(3);
	cout << endl;
	cout << "Factorial is " << factorial(3);*/
	return 0;
}