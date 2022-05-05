#include <iostream>
#include <time.h>
#include <cstdlib>
#include <ctime>
#define MAX 30000
using namespace std;
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
// with time-clock
template <class T>
void selectionSort(T *a, long int n)
{
	for (int i = 0; i< n-1; i++)
	{
		int Min = i;
		for (int j = i+1; j < n; j++)
		{
			if (a[j] < a[Min])
				Min = j;
		}
		swap(a[i], a[Min]);
	}
}
template <class T>
void bubbleSort(T* a, long int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
				swap(a[i], a[j]);
		}
	}
}
template <class T>
void InsertionSort(T* a, long int n)
{
	int j, i, next;
	for (i = 1; i < n; i++)
	{
		next = a[i];
		j = i - 1;
		for (j; j >= 0 && a[j] > next; j--)
			a[j + 1] = a[j];
		a[j + 1] = next;
	}
}
template <class T>
void heapify(T* a, long int n, int i)// source: cafedev.vn
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && a[l] > a[largest])
		largest = l;
	if (r < n && a[r] > a[largest])
		largest = r;
	if (largest != i)
	{
		swap(a[i], a[largest]);
		heapify(a, n, largest);
	}
}
template <class T>
void heapSort(T* a, long int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(a, n, i);
	for (int i = n - 1; i > 0; i--)
	{
		swap(a[0], a[i]);
		heapify(a, i, 0);
	}
}


//Count assign and compare
template <class T>
void selectionSort1(T* a, long int n, long &count_compare)
{
	for (int i = n - 1; i >= 1; i--,count_compare++)
	{
		int Max = i;
		for (int j = 0; j < 1; j++)
		{
			count_compare++;
			if (++count_compare && a[j] > a[Max])
				Max = j; 
		}
		swap(a[i], a[Max]);
	}
	cout << count_compare;
}
template <class T>
void bubbleSort1(T* a, long int n,long& count_compare)
{
	for (int i = 0; i < n; i++,count_compare++)
	{
		for (int j = i + 1; j < n; j++)
		{
			count_compare++;
			if (++count_compare && a[i] > a[j])
			{
				swap(a[i], a[j]);
			}
		}
	}
	cout << count_compare;
}
template <class T>
void InsertionSort1(T* a, long int n,long& count_compare)
{
	int j, i, next;
	for (i = 1; i < n; i++)
	{
		count_compare++;
		next = a[i];
		j = i - 1;
		for (j; j >= 0 && a[j] > next; j--,count_compare += 2)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = next;
	}
	cout << count_compare;
}
template <class T>
void heapify1(T* a, long int n, int i,long& count_compare)// source: cafedev.vn
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if ((++count_compare && l < n) && (++count_compare && a[l] > a[largest]))
	{
		largest = l;
	}
	if ((++count_compare && r < n) && (++count_compare && a[r] > a[largest]))
	{
		largest = r; 
	}
	if (++count_compare && largest != i)
	{
		swap(a[i], a[largest]);
		heapify1(a, n, largest,count_compare);
	}
}
template <class T>
void heapSort1(T* a, long int n,long &count_compare)
{
	for (int i = n / 2 - 1; i >= 0; i--,count_compare+=2)
		heapify(a, n, i);
	for (int i = n - 1; i > 0; i--,count_compare+=2)
	{
		swap(a[0], a[i]);
		heapify1(a, i, 0,count_compare);
	}
	cout << count_compare;
}
int main()
{
	clock_t start, end;
	double time_use;
	long count_compare = 0;
	int* a = new int[MAX];
	srand(time(NULL));
	for (int i = 0; i < MAX; i++)
		a[i] = rand();
	start = clock();
	selectionSort(a, MAX);
	end = clock();
	time_use = (double)(end - start) / CLOCKS_PER_SEC;
	cout << time_use << endl;
	selectionSort1(a, MAX, count_compare);
	delete[]a;
	return 0;
}