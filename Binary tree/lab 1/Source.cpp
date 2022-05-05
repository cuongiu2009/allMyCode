#include <iostream>
#include <ctime>
using namespace std;
struct NODE {
	int key;
	NODE* p_prev;
	NODE* p_next;
};
struct List {
	NODE* p_head;
	NODE* p_tail;
};
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void inputArray(int*& a, int n)
{
	for (int i = 0; i < n; ++i)
		cin >> a[i];
}
void generateArray(int*& a, int& n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 20;
	}
}
int* sum(int* a, int* b)
{
	int* res = 0;
	*res = *a + *b;
	return res;
}
void printArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}
int countEvens(int* a, int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			count++;
		}
	}
	return count;
}
int* generateSubArray(int* a, int n, int count) {
	int* Sub = new int[count];
	int index = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			Sub[index] = a[i];
			index++;
		}
	}
	return Sub;
	delete[]Sub;
}
int* findLongestAscendingSubarray(int* a, int n, int& length) {
	length = 1;
	int max = 1;
	int* ptr = NULL;
	for (int i = 1; i < n; i++)
	{
		if (a[i] > a[i - 1]) {
			length++;
			if (max < length) {
				ptr = a + i + 1 - length;
				max = length;
			}
		}
		else
			length = 1;
	}
	return ptr;
}
void swapArrays(int*& a, int*& b, int& na, int& nb) {
	int* p = a;
	a = b;
	b = p;

	int c = na;
	na = nb;
	nb = c;
}
int* concatenate2Arr(int* a, int* b, int na, int nb) {
	if (a && b) {
		int* combinedArr = new int[na + nb];
		int index = 0;
		for (int i = 0; i < na; i++) {
			combinedArr[index] = a[i];
			index++;
		}
		for (int i = 0; i < nb; i++) {
			combinedArr[index] = b[i];
			index++;
		}
		return combinedArr;
	}
	return NULL;
}
void generateMatrix1(int**& A, int& length, int& width) {
	cout << "Nhap so dong: ";
	cin >> length;
	cout << "Nhap so cot: ";
	cin >> width;
	A = new int* [length];
	for (int i = 0; i < length; i++) {
		A[i] = new int[width];
	}
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			A[i][j] = rand() % 20;
		}
	}
}
void inputMatrix(int**& a, int& length, int& width)
{
	cout << "Nhap so dong: ";
	cin >> length;
	cout << "Nhap so cot: ";
	cin >> width;

	a = new int* [length];
	for (int i = 0; i < length; i++) {
		a[i] = new int[width];
	}

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			cout << "a[" << i << "][" << j << "]=";
			cin >> a[i][j];
		}
	}
}
int** transposeMatrix(int** a, int length, int width)
{
	int** matrix = new int* [width];
	for (int i = 0; i < width; i++)
	{
		matrix[i] = new int[length];
	}

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < length; j++)
		{
			matrix[i][j] = a[j][i];
		}
	}
	return matrix;
}
void printMatrix(int** a, int length, int width)
{
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
int** findSubmatrix(int** a, int r, int c, int& rS, int& cS)
{
	cin >> rS >> cS;

	if (rS < 0 || cS < 0 || rS > r || cS > c)
	{
		rS = 0;
		cS = 0;
		return nullptr;
	}

	int** res = new int* [rS];

	for (int i = 0; i < rS; ++i)
		res[i] = new int[cS];

	int max = INT_MIN;

	for (int i = 0; i <= r - rS; ++i)
	{
		for (int j = 0; j <= c - cS; ++j)
		{
			int sum = 0;

			for (int k = 0; k < rS; ++k)
				for (int h = 0; h < cS; ++h)
					sum += a[i + k][j + h];

			if (max < sum)
			{
				max = sum;

				for (int k = 0; k < rS; ++k)
					for (int h = 0; h < cS; ++h)
						res[k][h] = a[i + k][j + h];
			}
		}
	}

	return res;
}


int sum(int n)
{
	if (n == 0)
		return 0;
	return sum(n - 1);
}
int factorial(int n)
{
	if (n == 0 || n == 1)
		return 1;
	return factorial(n - 1) * n;
}
int power(int x, int n)
{
	if (n == 0)
		return 1;
	else if (n == 1)
		return x;
	return power(x, n - 1) * x;
}
int countDigit(int n)
{
	int k = 1;
	if (n / 10 == 0)
		return k;
	return countDigit(n / 10) + k;
}
int countOdd(int n)
{
	int c = 0;
	if (n / 10 == 0 && n % 2 == 1)
		return 1;
	else if (n / 10 == 0)
		return 0;
	else if (n % 2 == 1)
		c++;
	return countOdd(n / 10) + c;
}
bool verifyEven(int n)
{
	int c = 0;
	if (n / 10 == 0)
		return true;
	else if (n % 2 == 1)
		return false;
	else return true;
	verifyEven(n / 10);
}
int demSo(int n)
{
	if (n == 0)
		return 0;
	return demSo(n / 10) + 1;
}
int tongSo(int n, int k)
{
	if (k > 1)
		return tongSo(n * 10, k - 1);
	return 0;
}
int reverse(int n)
{
	if (n == 0)
		return 0;
	int t = demSo(n);
	int v = n % 10;
	int sum = tongSo(v, t);
	return reverse(n / 10) + sum;
}
int binaryNumber(int n, int i = 1)
{
	int k = n % 2;
	if (n == 0)
		return 0;
	return binaryNumber(n / 2, i + 1) + k * pow(10, i);
}
int ucln(int a, int b) {
	if (b == 0) return a;
	if (a % b == 0) return b;
	return ucln(b, a % b);
}



NODE* createNode(int data) {
	NODE* p = new NODE;
	if (p == NULL) {
		return NULL;
	}
	p->key = data;
	p->p_next = p->p_prev = NULL;
	return p;
}
List creatList(NODE* pNode)
{
	List L;
	L.p_head = pNode;
	L.p_tail = pNode;
	return L;
}
bool addHead(List& L, int data) {
	if (L.p_head == nullptr)
	{
		NODE* p = createNode(data);
		if (p != nullptr)
		{
			L = creatList(p);
			return true;
		}
		return false;
	}
	NODE* p = createNode(data);
	if (p != nullptr)
	{
		p->p_next = L.p_head;
		L.p_head->p_prev = p;
		L.p_head = p;
		return true;
	}
	return false;
}
bool addTail(List& L, int data) {
	NODE* p = createNode(data);
	if (L.p_head == NULL) {
		L.p_head = L.p_tail = p;
		L.p_head->p_prev = NULL;
		L.p_tail->p_next = NULL;
	}
	else {
		L.p_tail->p_next = p;
		p->p_prev = L.p_tail;
		L.p_tail = p;
		L.p_tail->p_next = NULL;
	}
	return true;
}
void remove(List& L, NODE* p) {

	if (p->p_next != NULL) {
		p->p_next->p_prev = p->p_prev;
	}
	else if (p->p_prev != NULL) {
		p->p_prev->p_next = p->p_next;
	}
	free(p);
}
void removeHead(List& L) {
	if (L.p_head == nullptr)
		return;
	if (L.p_head == L.p_tail)
	{
		NODE* pTemp = L.p_head;
		L.p_head = nullptr;
		L.p_tail = nullptr;
		delete pTemp;
		pTemp = nullptr;
	}
	NODE* pTemp = L.p_head;
	L.p_head = L.p_head->p_next;
	L.p_head->p_prev = nullptr;
	delete pTemp;
	pTemp = nullptr;
}
void removeTail(List& L) {
	if (L.p_head == nullptr)
		return;
	if (L.p_head == L.p_tail)
	{
		NODE* pTemp = L.p_head;
		L.p_head = nullptr;
		L.p_tail = nullptr;
		delete pTemp;
		pTemp = nullptr;
	}
	NODE* pTemp = L.p_tail;
	L.p_tail = L.p_tail->p_prev;
	L.p_tail->p_next = nullptr;
	delete pTemp;
	pTemp = nullptr;
}
void removeAll(List& L) {
	NODE* pCur = L.p_head;
	while (pCur->p_next != nullptr)
	{
		NODE* pTemp = pCur->p_next;

		delete pCur;

		pCur = pTemp;
	}
	L.p_head = nullptr;
}
void removeBefore(List& L, int val) {
	if (L.p_head == nullptr)
		return;
	if (L.p_head->p_next == nullptr)
	{
		delete L.p_head;
		L.p_head = nullptr;
	}
	if (L.p_head->key == val)
		return removeHead(L);
	NODE* p = L.p_head->p_next;
	while (p!=nullptr && p->key != val)
		p = p->p_next;
	NODE* p1 = p->p_prev;
	p->p_prev == p1->p_prev;
	p1->p_prev->p_next = p;
	delete p1;
	p1 = nullptr;
}
void removeAfter(List& L, int val) {
	if (L.p_head == nullptr)
		return;
	if (L.p_head->p_next == nullptr)
		return;
	if (L.p_tail->key == val)
		return removeTail(L);
	NODE* p = L.p_head;
	while (p != nullptr && p->key != val)
		p = p->p_next;
	NODE* p1 = p->p_next;
	p->p_next = p1->p_next;
	p1->p_next->p_prev = p;
	delete p1;
	p1 = nullptr;
}
bool addPos(List& L, int data, int pos) {
	NODE* temp, * s;
	temp = new NODE;
	temp->key = data;
	s = L.p_head;
	int count = 1, flag = 1;
	if (pos == 1) {
		cout << "Try another position!!!" << endl;
		return false;
	}
	else {
		while (count != pos - 1) {
			s = s->p_next;
			if (s == NULL) {
				flag = 0;
				break;
			}
			count++;
		}
		if (flag == 1) {
			temp->p_next = s->p_next;
			s->p_next->p_prev = temp;
			s->p_next = temp;
			temp->p_prev = s;
			return true;
		}
		else {
			cout << "Position not found" << endl;
			return false;
		}
	}
}
void removePos(List& L, int pos) {
	if (L.p_head == nullptr)
		return;
	if (L.p_head->p_next == nullptr)
	{
		delete L.p_head;
		L.p_head = nullptr;
	}
	int k = 1;
	NODE* pCur = L.p_head;
	while (pCur->p_next != NULL && k != pos - 1)
	{
		pCur = pCur->p_next;
		k++;
	}
	pCur->p_next = pCur->p_next->p_next;
}
void insertAfter(NODE* p, int value) {
	NODE* q = new NODE;
	if (q == NULL) {
		exit(4);
		return;
	}
	q->key = value;
	q->p_prev = p;
	q->p_next = p->p_next;
	if (p->p_next != NULL) {
		p->p_next->p_prev = q;
	}
	p->p_next = q;
}
bool addBefore(List& L, int data, int val) {
	for (NODE* k = L.p_head; k != NULL; k = k->p_next) {
		if (k->p_next->key == val) {
			insertAfter(k, data);
			return true;
		}
	}
}
bool addAfter(List& L, int data, int val) {
	for (NODE* k = L.p_head; k != NULL; k = k->p_next) {
		if (k->key == val) {
			insertAfter(k, data);
			return true;
		}
	}
}
void printFoward(List L) {
	if (L.p_head == nullptr)
		return;
	NODE* pTemp = L.p_head;
	while (pTemp != nullptr)
	{
		cout << pTemp->key << " ";
		pTemp = pTemp->p_next;
	}
	cout << endl;
}
int countElements(List L) {
	int count = 0;
	NODE* current = L.p_head;
	while (current != NULL) {
		count++;
		current = current->p_next;
	}
	return count;
}
void printBackward(List L) {
	if (L.p_head == nullptr)
		return;
	NODE* pTemp = L.p_tail;
	while (pTemp != nullptr)
	{
		cout << pTemp->key << " ";
		pTemp = pTemp->p_prev;
	}
	cout << endl;
}
void removeDuplicate(List& L) {
	if (L.p_head != NULL) {
		NODE* curr = L.p_head, * temp = NULL, * find = NULL;
		while (curr != NULL) {
			temp = curr->p_next;
			while (temp != NULL) {
				if (temp->key == curr->key) {
					find = temp;
				}
				temp = temp->p_next;
				if (find != NULL) {
					if (find->p_prev != NULL) {
						find->p_prev->p_next = temp;
					}
					if (temp != NULL) {
						temp->p_prev = find->p_prev;
					}
					find->p_prev = NULL;
					find->p_next = NULL;
					delete find;
					find = NULL;
				}
			}
			curr = curr->p_next;
		}
	}
}
void removeElement(List& L, int key) {
	if (L.p_head == NULL) {
		return;
	}
	NODE* current = L.p_head;
	NODE* next;
	while (current != NULL) {
		if (current->key == key) {
			next = current->p_next;
			remove(L, current);
			current = next;
		}
		else {
			current = current->p_next;
		}
	}
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
int countSNT(int*& a, int n)
{
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		if (checkSNT(a[i]))
			num++;
	}
	return num;
}
int* arrayPrime(int* &a, int n)
{
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		if (checkSNT(a[i]))
			num++;
	}

	int* array = new int[num];
	int index = 0;
	for (int i = 0; i < n; i++)
	{
		if (checkSNT(a[i]))
		{
			array[index] = a[i];
			index++;
		}
	}
	return array;
	delete[]array;
}
int main()
{
	//int n,length;
	//cin >> n;
	/*int n = 9;
	int* a = new int[n];
	generateArray(a, n);
	printArray(a, n);
	int* b = arrayPrime(a, n);
	cout << endl;
	printArray(b, countSNT(a,n));*/
	/*inputArray(b, nb);*/
	//int *x = concatenate2Arr(a, b, na, nb);
	//outputArray(x, na + nb);
	//outputArray(a, n);
	//int *ptr = findLongestAscendingSubarray(a, n, length);
	//outputArray(ptr, length);


	//swapArrays(a, b, n, m);

	/*int count = countEvens(a, n);
	cout << count << endl;
	int*Sub=generateSubArray(a, n, count);
	outputArray(Sub, count);*/
	//int length, width, subLength, subWidth;
	//int** a;
	//generateMatrix1(a, length, width);
	//printMatrix(a, length, width);
	//int** matrix = findSubmatrix(a, length, width, subLength, subWidth);
	//printMatrix(matrix, subLength, subWidth);
	List L;
	L.p_head = L.p_tail = nullptr;
	addTail(L, 1);
	addTail(L, 2);
	addTail(L, 3);
	addTail(L, 4);
	addTail(L, 5);
	addTail(L, 6);
	addTail(L, 7);
	addTail(L, 8);
	addTail(L, 9);
	addTail(L, 10);

	printFoward(L);
	printBackward(L);

	return 0;
}