////QUICKSORT
//
//#include <iostream>
//using namespace std;
//void inputArr(int arr[], int &n)
//{
//	for (int i = 0; i < n; i++)
//		cin >> arr[i];
//}
//void outputArr(int arr[], int n)
//{
//	for (int i = 0; i < n; i++)
//		cout << arr[i] << " ";
//}
//void swap(int* a, int* b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//int partion(int arr[], int l, int h)
//{
//	int pi = arr[h];
//	int i = l - 1;
//	for (int j = l; j < h; j++)
//	{
//		if (arr[i] < pi)
//		{
//			i++;
//			swap(&arr[i], &arr[j]);
//		}
//	}
//	swap(&arr[i + 1], &arr[h]);
//	return (i + 1);
//}
//void quickSort(int arr[], int l, int h)
//{
//	if (l < h)
//	{
//		int pi = partion(arr, l, h);
//		quickSort(arr, l, pi - 1);
//		quickSort(arr, pi + 1, h);
//	}
//}
//void merge(int arr[], int l, int m, int h)
//{
//	int k = l;
//	int n1 = m - l + 1;
//	int n2 = h - m;
//	int* L = new int[n1];
//	int* R = new int[n2];
//	for (int i = 0; i < n1; i++)
//		L[i] = arr[l + i];
//	for (int j = 0; j < n2; j++)
//		R[j] = arr[m + j + 1];
//	int i = 0, j = 0;
//	while (i < n1 && j < n2)
//		arr[k++] = (L[i] <= R[i]) ? L[i++] : R[j++];
//	while (i < n1)
//		arr[k++] = L[i++];
//	while (j < n2)
//		arr[k++] = R[j++];
//}
//void mergeSort(int arr[], int l, int h)
//{
//	if (l < h)
//	{
//		int m = l + (h - l) / 2;
//		mergeSort(arr, l, m);
//		mergeSort(arr, m + 1, h);
//		merge(arr, l, m, h);
//	}
//}
//int main()
//{
//	int a[100];
//	int n;
//	cin >> n;
//	inputArr(a, n);
//	mergeSort(a, 0, n - 1);
//	outputArr(a, n);
//	return 0;
//}