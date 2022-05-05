#include "Header.h"
int main() {
    srand(time(0));
    int deck[4][13];
    const char* suits[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };
    const char* ranks[13] = { "Two", "Three", "Four", "Five",
    "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen","King" ,"Ace" };
    int n;
    while (1 > 0)
    {
        cout << "                                    WELCOME TO OUR DECK                                      " << endl;
        cout << "=============================================================================================" << endl;
        cout << "==                                  Choose Game mode                                       ==" << endl;
        cout << "==                                  1-Single player                                        ==" << endl;
        cout << "==                                  2-Multiplayer                                          ==" << endl;
        cout << "==                                  10-Quit game                                           ==" << endl;
        cout << "=============================================================================================" << endl;
        cin >> n;
        if (n == 1)
        {
            int k;
            system("cls");
            cout << "Choose the next action" << endl;
            cout << "1-Auto dealing" << endl;
            cout << "2-Create your handtest " << endl;
            cout << "0-Back to previous home page" << endl;
            cout << endl;
            cout << "=============================================================================================" << endl;
            cin >> k;
            if (k == 1)
            {
                system("cls");
                shuffleCards(deck);
                int** hand = dealingForHand(deck);
                cout << "This is 5 card of you" << endl; cout << endl;
                printHand(hand, suits, ranks); cout << endl; cout << endl;
                cout << "Choose the next action" << endl;
                cout << "1-Check your hand-ranking" << endl;
                cout << "2-Get a highest value of your hand" << endl;
                cout << "0-Back to previous page" << endl;
                cout << ">10-Quit game" << endl;
                cout << endl;
                cout << "=============================================================================================" << endl;
                while (2 > 1) {
                    int u;
                    cin >> u;
                    if (u == 1)
                    {
                        int val = getStatusOfHand(hand);
                        cout << "The hand-ranking of you is : " << val << endl;

                    }
                    else if (u == 2)
                    {
                        int val = getHighestCard(hand);
                        cout << "The value of the highest card is : " << val << endl;
                    }
                    else if (u == 0)
                    {
                        break;
                    }
                    else {
                        cout << "Game over" << endl;
                        return 0;
                    }
                }
            }
            else if (k == 2)
            {
                system("cls");
                shuffleCards(deck);
                cout << endl;
                cout << "Now you will input your card trong khoang 0-51" << endl;
                int** hand = createHandTest(); cout << endl;
                cout << "This is 5 card of you" << endl;
                cout << endl;
                printHand(hand, suits, ranks); cout << endl; 
                cout << endl;
                cout << "Choose the next action" << endl;
                cout << "1-Check your hand-ranking" << endl;
                cout << "2-Get a highest value of your hand" << endl;
                cout << "0-Back to previous home page" << endl;
                cout << ">10-Quit game" << endl;
                cout << endl;
                cout << "=============================================================================================" << endl;
                while (1 > 0)
                {
                    int u;
                    cin >> u;
                    if (u == 1)
                    {
                        int val = getStatusOfHand(hand);
                        cout << "The hand-ranking of you is : " << val << endl;
                    }
                    else if (u == 2)
                    {
                        int val = getHighestCard(hand);
                        cout << "The value of the highest card is : " << val << endl;
                    }
                    else if (u == 0)
                    {
                        break;
                    }
                    else {
                        cout << "Game over" << endl;
                        return 0;
                    }
                }
            }
        }
        else if (n == 2)
        {
            int k, numPlayer;
            system("cls");
            cout << "Input the number of player" << endl;
            cin >> numPlayer; cout << endl;
            cout << "Choose the next action" << endl;
            cout << "1-One round" << endl;
            cout << "2-Multi round " << endl;
            cout << "0-Back to previous home page" << endl;
            cout << ">10-Quit game" << endl;
            cout << endl;
            cout << "=============================================================================================" << endl;
            cin >> k;
            system("cls");
            if (k == 1)
            {
                shuffleCards(deck);
                int*** hands = dealingForHands(deck, numPlayer);
                cout << "This is 5 card for each player" << endl; cout << endl;
                printmulti(hands, suits, ranks, numPlayer); cout << endl;
                cout << "Choose the next action" << endl;
                cout << "1-Check hand-ranking one player " << endl;
                cout << "2-Check ranking of all players" << endl;
                cout << "0-Back to previous page" << endl;
                cout << ">10-Quit game" << endl;
                cout << endl;
                cout << "=============================================================================================" << endl;
                while (2 > 1) {
                    int u;
                    cin >> u;
                    if (u == 1)
                    {
                        while (1 > 0)
                        {
                            int p;
                            cout << "The player you want to check is (" << numPlayer << "-1)" << endl;
                            cout << "100-Back to previous page" << endl;
                            cout << endl;
                            cout << "=============================================================================================" << endl;
                            cin >> p;
                            if (p == 100)
                            {
                                system("cls");
                                cout << "This is 5 card for each player" << endl; cout << endl;
                                printmulti(hands, suits, ranks, numPlayer); cout << endl;
                                cout << "Choose the next action" << endl;
                                cout << "1-Check hand-ranking one player " << endl;
                                cout << "2-Check ranking of all players" << endl;
                                cout << "0-Back to previous page" << endl;
                                cout << ">10-Quit game" << endl;
                                cout << endl;
                                cout << "=============================================================================================" << endl;
                                break;
                            }
                            else if (p > numPlayer && p < 1)
                            {
                                cout << "Error!! Enter another number" << endl;
                                cin >> p;
                            }
                            p = p - 1;
                            int val = getStatusOfHand(hands[p]);
                            cout << "The hand-ranking of you is : " << val << endl;
                        }
                    }
                    else if (u == 2)
                    {
                        int* playerRank = rankingHands_2(hands, numPlayer);
                        for (int i = 0; i < numPlayer; i++)
                        {
                            cout << "Top [" << i + 1 << "] :" << "Player" << playerRank[i] + 1 << " " << endl;

                        }
                    }
                    else if (u > 2 && u < 10)
                    {
                        cout << "Error!! Enter another number" << endl;
                    }
                    else if (u == 0)
                    {
                        break;
                    }
                    else {
                        cout << "Game over" << endl;
                        return 0;
                    }
                }
            }
            else if (k == 2) {
                system("cls");
                int s;
                shuffleCards(deck);
                int*** hands = dealingForHands(deck, numPlayer);
                cout << "Find who are  the winner after many round " << endl;
                cout << "Input s times of dealing card" << endl;
                cout << "=============================================================================================" << endl;
                cin >> s;
                int* FinalRank = evaluateHands(hands, numPlayer, s, deck, suits, ranks);
                for (int i = 0; i < numPlayer; i++)
                {
                    cout << "rank of player[" << i + 1 << "] :" << FinalRank[i] << endl;

                }
            }
            else if (k > 2 && k < 10)
            {
                cout << "Error!! Enter another number" << endl;
            }
            else if (k == 0)
            {
                break;
            }
            else {
                cout << "Game over" << endl;
                return 0;
            }
        }
        else
        {
            cout << "Game over" << endl;
            return 0;
        }

    }




    system("pause");
    return 0;
}
