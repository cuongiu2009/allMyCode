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
NODE* createTree(NODE* pRoot)
{
	int a[100];
	fstream f("input.txt", ios::in);
	string s;
	getline(f, s);
	int i = 0;
	while (!f.eof())
	{
		f << s[i];
		Insert(pRoot, s[i]);
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
void printTree(NODE* pRoot)
{
	if (pRoot == nullptr)
		return;
	else
		cout << pRoot->key << " ";
	printTree(pRoot->left);
	printTree(pRoot->right);
}
int main()
{
	NODE* root = nullptr;
	NODE* p = createTree(root);
	printTree(root);
	return 0;
}