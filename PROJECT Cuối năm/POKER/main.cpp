#include "Header.h"
int main() {
	int deck[3][12];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			deck[i][j] = 0;
		}
	}
	shuffleCards(deck);
	const char* suits[4] = { "Hearts", "Diamonds", "Clubs", "Spades" }; //Tao bien khong doi
	const char* faces[13] = { "Ace", "Two", "Three", "Four", "Five","Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen" ,"King" };//Tao bien khong doi

	printCardsShuffling(deck, suits, faces);
	system("pause");
	return 0;
}