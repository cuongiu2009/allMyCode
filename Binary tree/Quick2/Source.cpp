#include <iostream>
#include <queue>
struct AVL {
	float data;
	AVL* left;
	AVL* right;
};
using namespace std;
void createAVL(AVL*& root, float val)
{
	if (root == NULL)
	{
		root = new AVL;
		root->data = val;
		root->left = nullptr;
		root->right = nullptr;
		return;
	}
}
void levelOrder(AVL* pRoot)
{
	if (pRoot == nullptr)
		return;
	queue<AVL*>q;
	q.push(pRoot);
	while (!q.empty())
	{
		AVL* pCur = q.front();
		q.pop();
		if (pCur->left != nullptr)
			q.push(pCur->left);
		if (pCur->right != nullptr)
			q.push(pCur->right);
		cout << pCur->data << " ";
	}
}
void leftRotate(AVL*& root)
{
	if (root == NULL)
		return;
	AVL* pAVL = root->right;
	root->right = pAVL->left;
	pAVL->left = root;
	root = pAVL;
}
void rightRotate(AVL*& root)
{
	if (root == NULL)
		return;
	AVL* pAVL = root->left;
	root->left = pAVL->right;
	pAVL->right = root;
	root = pAVL;
}
void InsertButAVL(AVL*& pRoot, float x)
{
	if (pRoot == nullptr)
	{
		AVL* q = new AVL;
		q->data = x;
		q->left = q->right = nullptr;
		pRoot = q;
	}
	else
	{
		if (x < pRoot->data)
			InsertButAVL(pRoot->left, x);
		else if (x > pRoot->data)
			InsertButAVL(pRoot->right, x);
	}
}
int Height1(AVL* pRoot)
{
	if (pRoot == nullptr)
		return 0;
	int HL, HR;
	HL = Height1(pRoot->left);
	HR = Height1(pRoot->right);
	if (HL > HR)
		return(1 + HL);
	return(1 + HR);
}
void balanceBHT(AVL*& pRoot)
{
	int a = Height1(pRoot->left) - Height1(pRoot->right);
	if (a > 1)
	{
		if (Height1(pRoot->left->left) >= Height1(pRoot->left->right))
			rightRotate(pRoot);
		else if (Height1(pRoot->left->left) >= Height1(pRoot->left->right))
		{
			leftRotate(pRoot->left);
			rightRotate(pRoot);
		}
	}
	if (a < -1)
	{
		if (Height1(pRoot->right->right) > Height1(pRoot->right->left))
			leftRotate(pRoot);
		else if (Height1(pRoot->right->right) < Height1(pRoot->right->left))
		{
			rightRotate(pRoot->right);
			leftRotate(pRoot);
		}
	}
}
void insertAVL1(AVL* &pRoot, float val)
{
	if (pRoot == nullptr)
		createAVL(pRoot, val);
	else if (pRoot->data == val)
		return;
	else if (pRoot->data > val)
		insertAVL1(pRoot->left, val);
	else if (pRoot->data < val)
		insertAVL1(pRoot->right, val);
	balanceBHT(pRoot);
}
void removeAVL1(AVL*& pRoot, float val)
{
	if (pRoot == nullptr)
		return;
	else if (pRoot->data > val)
		removeAVL1(pRoot->left, val);
	else if (pRoot->data < val)
		removeAVL1(pRoot->right, val);
	else if (pRoot->data == val)
	{
		if (pRoot->left == nullptr and pRoot->right == nullptr)
		{
			delete pRoot;
			pRoot = nullptr;
		}
		else if (pRoot->left != nullptr and pRoot->right == nullptr)
		{
			AVL* p = pRoot;
			pRoot = pRoot->left;
			delete pRoot;
		}
		else if (pRoot->left == nullptr and pRoot->right != nullptr)
		{
			AVL* p = pRoot;
			pRoot = pRoot->right;
			delete p;
		}
		else if (pRoot->left != nullptr and pRoot->right != nullptr)
		{
			AVL* p = pRoot->right;
			while (p->left != nullptr)
			{
				p = p->left;
			}
			pRoot->data = p->data;
			removeAVL1(pRoot->right, pRoot->data);
		}
	}
	if (pRoot == nullptr)
		return;
	balanceBHT(pRoot);
}
AVL* createTree(float a[], int n)
{
	AVL* pRoot = new AVL;
	pRoot = nullptr;
	for (int i = 0; i < n; ++i)
		insertAVL1(pRoot, a[i]);
	return pRoot;
}
void printTree(AVL* pRoot)
{
	if (pRoot == nullptr)
		return;
	else
		cout << pRoot->data << " ";
	printTree(pRoot->left);
	printTree(pRoot->right);
}

//xóa node nhỏ nhất có cùng chiều cao
void findMax(AVL* root, int h, float& res)
{
	if (root == nullptr)
		return;
	if (Height1(root) == h)
		res = max(res, root->data);
	findMax(root->left, h, res);
	findMax(root->right, h, res);
}
void deleteSmallestNode(AVL*& root, int height)
{
	float max = root->data;
	findMax(root, height, max);
	removeAVL1(root, max);
}
bool checkSNT(int data)
{
	int c = 0;
	for (int i = 1; i <= data; i++)
	{
		if (data % i == 0)
			c++;
	}
	if (c == 2)
		return true;
	else return false;
}
void findPrimeNode(AVL *root)
{
	if (root == nullptr)
		return;
	if (root != nullptr && checkSNT(root->data))
		cout << root->data << " ";
	findPrimeNode(root->left);
	findPrimeNode(root->right);
}

//xóa tất cả các node có cùng chiều cao

int main()
{
	AVL* root = nullptr;
	AVL* root1 = nullptr;
	float a[12] = { 10, 8, 7, 15, 11, 18, 1, 30, 42, 43, 47, 60 };
	root = createTree(a, 12);
	levelOrder(root);
	cout << endl;
	findPrimeNode(root);
	return 0;
}