#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<string>
#include<cstring>
#include <queue>
#include<cmath>
struct NODE {
	int key;
	NODE* left;
	NODE* right;
};
struct AVL {
	int data;
	AVL* left;
	AVL* right;
};
//struct Company {
//	string name;
//	string profit_tax;
//	string address;
//};
const long long M = pow(10.0, 9) + 9;
using namespace std;
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
 // dùng đệ quy
void Insert(NODE*&pRoot, int x)
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
void NLR(NODE* pRoot)//pre
{
	int a;
	if (pRoot != NULL)
	{
		a = pRoot->key;
		cout << a << " ";
		NLR(pRoot->left);
		NLR(pRoot->right);
	}
}
void LRN(NODE* pRoot)//post
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
void LNR(NODE* pRoot)//in order
{
	int a;
	if (pRoot != NULL)
	{
		LNR(pRoot->left);
		a = pRoot->key;
		cout << a << " ";
		LNR(pRoot->right);
	}
}
int Height(NODE* pRoot)
{
	if (pRoot == nullptr)
		return 0;
	int HL, HR;
	HL = Height(pRoot->left);
	HR = Height(pRoot->right);
	if (HL > HR)
		return(1 + HL);
	return(1 + HR);
}
int countNode(NODE* pRoot)
{
	int c = 1;
	if (pRoot == nullptr)
		return 0;
	else
	{
		c += countNode(pRoot->left);
		c += countNode(pRoot->right);
		return c;
	}
}
int sumNode(NODE* pRoot)
{
	int sum = 0;
	if (pRoot == nullptr)
		return sum;
	return (pRoot->key + sumNode(pRoot->left) + sumNode(pRoot->right));
}
NODE* Search(NODE* pRoot, int x)
{
	if (pRoot == nullptr)
		return NULL;
	if (x < pRoot->key)
		Search(pRoot->left, x);
	else
	{
		if (x > pRoot->key)
			Search(pRoot->right, x);
		else
			return pRoot;
	}
}
void levelOrder(NODE* pRoot)
{
	if (pRoot == nullptr)
		return;
	queue<NODE*>q;
	q.push(pRoot);
	while (!q.empty())
	{
		NODE* pCur = q.front();
		q.pop();
		cout << pCur->key << " ";
		if (pCur->left != nullptr) 
			q.push(pCur->left);
		if (pCur->right != nullptr)
			q.push(pCur->right);
	}
}
void findAndReplace(NODE*& r, NODE*& p)
{
	if (p->left)
		findAndReplace(r, p->left);
	else
	{
		r->key = p->key;
		r = p;
		r = r->right;
	}
}
void findAndReplace1(NODE*& r, NODE*& p)
{
	if (p->right)
		findAndReplace(r, p->right);
	else
	{
		r->key = p->key;
		r = p;
		r = r->left;
	}
}
void Remove(NODE*& pRoot, int x)
{
	if (pRoot != nullptr)
	{
		if (x > pRoot->key)
			Remove(pRoot->right, x);
		else if (x < pRoot->key)
			Remove(pRoot->left, x);
		else
		{
			NODE* p = pRoot;
			if (!pRoot->left)
				pRoot = pRoot->right;
			else if (!pRoot->right)
				pRoot = pRoot->left;
			else
				findAndReplace(p, pRoot->right);
			delete p;
		}
	}
	else cout << "can't find!!!\n";
}
NODE* createTree(int a[], int n)
{
	NODE* pRoot = nullptr;
	for (int i = 0; i < n; ++i)
		Insert(pRoot, a[i]);
	return pRoot;
}
void removeTree(NODE*& pRoot)
{
	if (pRoot == nullptr)
		return;
	removeTree(pRoot->left);
	removeTree(pRoot->right);
	cout << pRoot->key << endl;
	delete pRoot;
}
int heightNode(NODE* pRoot, int value)//có lỗi
{
	int d = 0;
	int h = 0;
	if (pRoot == nullptr)
		return -1;
	NODE* p = Search(pRoot, value);
	if (value > pRoot->key)
	{
		NODE* pTemp = pRoot;
		while (pTemp != nullptr)
		{
			pTemp = pTemp->right;
			d++;
		}
		pTemp = pRoot;
		while (pTemp != p)
		{
			pTemp = pTemp->right;
			h++;
		}
		pTemp = nullptr;
		delete pTemp;
	}
	else if (value < pRoot->key)
	{
		NODE* pTemp = pRoot;
		while (pTemp != nullptr)
		{
			pTemp = pTemp->left;
			d++;
		}
		pTemp = pRoot;
		while (pTemp != p)
		{
			pTemp = pTemp->left;
			h++;
		}
		pTemp = nullptr;
		delete pTemp;
	}
	return d - h;
}
int countLeaf(NODE* pRoot)
{
	if (pRoot == nullptr)
		return 0;
	if (pRoot->left == nullptr and pRoot->right == nullptr)
		return 1;
	return countLeaf(pRoot->left) + countLeaf(pRoot->right);
}
int countLess(NODE* pRoot, int x)
{
	if (pRoot == nullptr) {
		return 0;
	}
	int countingRight = countLess(pRoot->right, x);
	int countingLeft = countLess(pRoot->left, x);
	if (x > pRoot->key) {
		return (countingLeft + countingRight + 1);
	}
	else {
		return (countingLeft + countingRight);
	}
}
int countGreater(NODE* pRoot, int x)
{
	if (pRoot == nullptr) {
		return 0;
	}

	int countingRight = countGreater(pRoot->right, x);
	int countingLeft = countGreater(pRoot->left, x);


	if (x < pRoot->key) {
		return (countingLeft + countingRight + 1);
	}
	else {
		return (countingLeft + countingRight);
	}
}
bool isBST(NODE* pRoot)
{
	if (pRoot == nullptr)
		return false;
	if (pRoot->left != nullptr and pRoot->left->key > pRoot->key)
		return false;
	if (pRoot->right != nullptr and pRoot->right->key < pRoot->key)
		return false;
	if (!isBST(pRoot->left) or !isBST(pRoot->right))
		return false;
	else return true;
}
bool isFullBST(NODE* pRoot)
{
	if (pRoot == nullptr)
		return true;
	if (pRoot->left == nullptr && pRoot->right == nullptr)
		return true;
	if ((pRoot->left) && (pRoot->right))
		return (isFullBST(pRoot->left) && isFullBST(pRoot->right));
	return false;
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

bool checkOdd(int data)
{
	if (data % 2 == 1)
		return true;
	else return false;
}
void printNodeOdd(NODE* pRoot, int height)
{
	if (pRoot == nullptr)
		return;
	if (checkOdd(pRoot->key) && Height(pRoot) == height)
		cout << pRoot->key << " ";
	printNodeOdd(pRoot->left, height);
	printNodeOdd(pRoot->right, height);
}

//my view
//void insertAVLfake(AVL*& pRoot) {
//	if (abs(treeLevel(pRoot->left) - treeLevel(pRoot->right)) > 1) {
//		if (treeLevel(pRoot->left) > treeLevel(pRoot->right)) {
//			AVL* p = pRoot->left;
//			if (treeLevel(p->left) >= treeLevel(p->right)) {
//				leftRotate(pRoot);
//			}
//			else {
//				pRoot->left = leftRotate(pRoot->left);
//				pRoot = rightRotate(pRoot);
//			}
//		}
//		else {
//			AVL* p = pRoot->right;
//			if (treeLevel(p->right) >= treeLevel(p->left)) {
//				pRoot = leftRotate(pRoot);
//			}
//			else {
//				pRoot->right = rightRotate(pRoot->right);
//				pRoot = leftRotate(pRoot);
//			}
//		}
//	}
//	if (pRoot->left != NULL) insertAVL(pRoot->left);
//	if (pRoot->right != NULL) insertAVL(pRoot->right);
//}
//void InsertButAVLfake(AVL*& pRoot, int x)
//{
//	if (pRoot == nullptr)
//	{
//		AVL* q = new AVL;
//		q->data = x;
//		q->left = q->right = nullptr;
//		pRoot = q;
//	}
//	else
//	{
//		if (x < pRoot->data)
//			InsertButAVL(pRoot->left, x);
//		else if (x > pRoot->data)
//			InsertButAVL(pRoot->right, x);
//	}
//}
//void RemoveButAVLfake(AVL*& pRoot, int x)
//{
//	if (pRoot != nullptr)
//	{
//		if (x > pRoot->data)
//			RemoveButAVL(pRoot->right, x);
//		else if (x < pRoot->data)
//			RemoveButAVL(pRoot->left, x);
//		else
//		{
//			AVL* p = pRoot;
//			if (!pRoot->left)
//				pRoot = pRoot->right;
//			else if (!pRoot->right)
//				pRoot = pRoot->left;
//			else
//				findAndReplaceAVL(p, pRoot->right);
//			delete p;
//		}
//	}
//}
//void findAndReplaceAVL(AVL*& r, AVL*& p)
//{
//	if (p->left)
//		findAndReplaceAVL(r, p->left);
//	else
//	{
//		r->data = p->data;
//		r = p;
//		r = r->right;
//	}
//}


//vector <Company> ReadComapanyList(string file_name) {
//	vector<Company> list;
//	ifstream fi(file_name, ios::in);
//	if (fi.fail()) return list;
//	while (!fi.eof()) {
//		string info;
//		getline(fi, info);
//		stringstream ss(info);
//		Company x;
//		getline(ss, x.name, '|');
//		getline(ss, x.profit_tax, '|');
//		getline(ss, x.address, '|');
//		list.push_back(x);
//	}
//	fi.close();
//	return list;
//}
//
//long long abc(int x) {
//	long long rs = 1;
//	for (int i = 1; i < x; i++) {
//		rs = ((rs % M) * 31) % M;
//	}
//	return rs;
//}
//
//long long HashFormula(char x, int i) {
//	long long res = 0;
//	long long p = abc(i);
//	res = (x * p % M) % M;
//	return res;
//}
//
//long long HashString(string company_name) {
//	string s = company_name.substr(company_name.length() - 20, 20);
//	long long hashkey = 0;
//	for (int i = 0; i < 20; i++) {
//		hashkey += HashFormula(s[i], i);
//	}
//	return hashkey;
//}
//
//Company* CreateHashTable(string file_name) {
//	vector <Company> ComapyList = ReadComapanyList(file_name);
//	Company* list = new Company[2000];
//	for (int i = 0; i < 2000; i++) {
//		list[i].name = "";
//	}
//	for (int i = 1; i < ComapyList.size(); i++) {
//		long long key = HashString(ComapyList[i].name) % 2000;
//		while (list[key].name != "") {
//			key = (key + 1) % 2000;
//		}
//		list[key] = ComapyList[i];
//	}
//	return list;
//}
//
//void Insert(Company* hash_table, Company company) {
//	// Linear
//	long long  key = HashString(company.name) % 2000;
//	while (hash_table[key].name != "") {
//		key = (key + 1) % 2000;
//	}
//	hash_table[key] = company;
//}
//
//Company* Search(Company* hash_table, string company_name) {
//	if (hash_table == NULL) return NULL;
//	long long key = HashString(company_name) % 2000;
//
//	Company* res = new Company;
//	while (hash_table[key].name != company_name && hash_table[key].name != "") {
//		key = (key + 1) % 2000;
//	}
//
//	if (hash_table[key].name == company_name) {
//		res->name = hash_table[key].name;
//		res->address = hash_table[key].address;
//		res->profit_tax = hash_table[key].profit_tax;
//		return res;
//	}
//	else return NULL;
//}
//
//void printCompanyList(Company* hashtable) {
//	for (int i = 0; i < 2000; i++) {
//		if (hashtable[i].name != "") {
//			cout << hashtable[i].name << "  " << i << endl;
//		}
//	}
//}

int main()
{	
	//Company* hashTable = CreateHashTable("input.txt");
	//printCompanyList(hashTable);
	NODE* root = nullptr;
	int a[10] = { 4,1,2,3,55,12,22,33,14,10 };
	root = createTree(a, 10);
	printTree(root);
	cout << endl;
	printNodeOdd(root, 4);
	return 0;
}