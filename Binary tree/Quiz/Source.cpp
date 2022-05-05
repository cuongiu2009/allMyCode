#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct NODE {
	int key;
	NODE* left;
	NODE* right;
};
NODE* createNode(int data)
{
	NODE* pNode = new NODE;
	if (pNode == nullptr)
		return nullptr;
	pNode->key = data;
	pNode->left = nullptr;
	pNode->right = nullptr;
	return pNode;
}
void Insert(NODE*& pRoot, int x)
{
	if (pRoot == nullptr)
	{
		NODE* q = new NODE;
		q->key = x;
		q->left = q->right = nullptr;
		pRoot = q;
	}
	else
	{
		if (x < pRoot->key)
			Insert(pRoot->left, x);
		else if (x > pRoot->key)
			Insert(pRoot->right, x);
	}
}
NODE* createTree(NODE*& pRoot)
{
	fstream f("input.txt", ios::in);
	int n;
	f >> n;
	int i = 0;
	int* a = new int[n];
	while (n--)
	{
		f >> a[i];
		Insert(pRoot, a[i]);
		i++;
	}
	f.close();
	return pRoot;
}
void LRN(NODE* pRoot)
{
	int a;
	if (pRoot != NULL)
	{
		LRN(pRoot->left);
		LRN(pRoot->right);
		a = pRoot->key;
		cout << a << " ";
	}
}
int main()
{
	NODE* root = new NODE;
	root = nullptr;
	createTree(root);
	LRN(root);
	return 0;
}
