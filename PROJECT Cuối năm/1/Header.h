#ifndef Header_h
#define Header_h
#endif 
#include<iostream>
#include<cstring>
#include<string.h>
#include<ctime>
using namespace std;
void shuffleCards(int deck[4][13]);
void printCardsShuffling(int deck[4][13], const char* suits[], const char* ranks[]);
int** dealingForHand(int deck[4][13]);
void printHand(int** hand, const char* suits[], const char* ranks[]);
int** createHandTest();
int  isStraightFlush(int** hand);
int isFourOfAKind(int** hand);
int isFullHouse(int** hand);
int isFlush(int** hand);
int isStraight(int** hand);
int isThreeOfAKind(int** hand);
int isPairs(int** hand);
int isTwoPairs(int** hand);
int getHighestCard(int** hand);
int*** dealingForHands(int deck[4][13], int n);
void printmulti(int*** hand, const char* suits[], const char* ranks[], int n);
int getStatusOfHand(int** hand);
//int** convert3dTo2d(int*** hand, int u);
void deleteHand(int** array);
int* evaluateHands(int*** hands, int n, int s, int deck[4][13], const char* suits[], const char* ranks[]);
int shuffleCardsAgains(int deck[4][13]);
int* rankingHands_2(int*** hands, int n);
int getHighestCardAgain(int** hand, int n);
int** get2Dfrom3D(int** hand);




