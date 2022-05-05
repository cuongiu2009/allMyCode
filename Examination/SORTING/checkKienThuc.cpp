#include <iostream>
using namespace std;
void input(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cin >> a[i];
}
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partion(int a[], int l, int h)
{
	int pi = a[h];
	int i = l - 1;
	for (int j = l; j < h; j++)
	{
		if (a[i] < pi)
		{
			i++;
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[i], &a[h]);
	return (i + 1);
}
void quickSort(int a[], int l, int h)
{
	if (l < h)
	{
		int pi = partion(a, l, h);
		quickSort(a, l, pi - 1);
		quickSort(a, pi + 1, h);
	}
}
void merge(int a[], int l, int m, int h)
{
	int k = l;
	int n1 = m - l + 1;
	int n2 = h - m;
	int* L = new int[n1];
	int* R = new int[n2];
	for (int i = 0; i < n1; i++)
	{
		L[i] = a[l + i];
	}
	for (int j = 0; j < n2; j++)
	{
		R[j] = a[m + j + 1];
	}
	int i = 0, j = 0;
	while (i < n1 && j < n2)
	{
		a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
	}
	while (i < n1)
		a[k++] = L[i++];
	while (j < n2)
		a[k++] = R[j++]; 
}
void mergeSort(int a[], int l, int h)
{
	if (l < h)
	{
		int m = l + (h - l) / 2;
		mergeSort(a, l, m);
		mergeSort(a, m + 1, h);
		merge(a, l, m, h);
	}
}
void interchangeSort(int a[], int n)
{
	for (int i = 0; i <= n-2 ; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (a[i] > a[j])
				swap(&a[i], &a[j]);
		}
	}
}
void selectionSort(int a[], int n)
{
	for (int i = n-1;i>=1;i--)
	{
		int Max = i;
		for (int j = 0; j < 1; j++)
		{
			if (a[j] > a[Max])
				Max = j;
		}
		swap(&a[i], &a[Max]);
	}
}
void bubbleSort(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
				swap(&a[i], &a[j]);
		}
	}
}
void InsertionSort(int a[], int n)
{
	int j, i, next;
	for (i = 1; i < n; i++)
	{
		next = a[i]; 
		j = i - 1;
		for ( j ; j >= 0 && a[j] > next; j--)
			a[j + 1] = a[j];
		a[j + 1] = next; 
	}
}
void heapify(int arr[], int n, int i)// source: cafedev.vn
{
	int largest = i;
	int l = 2 * i + 1; 
	int r = 2 * i + 2; 
	if (l < n && arr[l] > arr[largest])
		largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r;
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}
void heapSort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	for (int i = n - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}
int main()
{
	int a[5] = { 1,2,5,78,5 };
	InsertionSort(a, 5);
	output(a, 5);
	return 0;
}