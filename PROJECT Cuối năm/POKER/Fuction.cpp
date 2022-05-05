#include "Header.h"
void shuffleCards(int deck[3][12]) {// Xao bai
	int count = 1; //Bien tao gia tri cho mang
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			deck[i][j] = count++;//Gan gia tri
			if (deck[i][j] < 10)// Khi gia tri nho hon 10 thi tang khoang cach
			{
				cout << " ";
			}
			cout << deck[i][j] << " ";
		}
		cout << endl;
	}
}
void printCardsShuffling(int deck[3][12], const char* suits[], const char* faces[]) {
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			cout << "(" << suits[i] << "," << faces[j] << ")" << endl;
		}
		cout << endl;
	}
}
