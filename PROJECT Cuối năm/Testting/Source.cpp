//#include <iostream>
//#include <cstdlib>
//#include <string>
//#include <ctime>
//using namespace std;
//
//int main()
//{
//    srand(time(0));
//    int deck[52];
//    int i;
//    string suitnames[4] = { "spades", "diamonds", "clubs", "hearts" };
//    string ranknames[13] = { "ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "jack", "queen", "king" };
//
//    // tao ban` moi'
//    for (i = 0; i < 52; i++)
//    {
//        deck[i] = i;
//    }
//
//    // shuffle bai`
//    for (i = 0; i < 52; i++)
//    {
//        // moi lan` la 1 random bai` khac
//        int j = rand() % 52;
//        int temp = deck[i];
//        deck[i] = deck[j];
//        deck[j] = temp;
//    }
//
//
//    // print cards
//    for (i = 0; i < 52; i++)
//    {
//        int suitnumber = deck[i]/13; // 0 - 3
//        int rank = deck[i] % 13;
//        cout <<"[" <<ranknames[rank] << "," << suitnames[suitnumber] <<"]"<< "\n";
//    }
//
//    // Check first 5 cards for an ace
//    cout << endl;
//    for (i = 0; i < 5; i++)
//    {
//        int acerank = 0;
//        int currentCardRank = deck[i] % 13;
//        if (currentCardRank == acerank)
//        {
//            cout << "Got an ace!" << endl;
//        }
//    }
//
//    // Get the rank of the first 5 cards
//    int R[5]; // = {4, 7, 6, 3, 5}; // rank of the first 5 cards
//    int S[5];
//    for (i = 0; i < 5; i++)
//    {
//        R[i] = deck[i] % 13;
//        S[i] = deck[i] / 13;
//    }
//
//    // Sort the R array
//    bool swapped = false;
//    do
//    {
//        // 1 pass of the bubble sort
//        swapped = false;
//        for (int i = 0; i < 4; i++)
//        {
//            if (R[i] > R[i + 1])
//            {
//                int temp = R[i];
//                R[i] = R[i + 1];
//                R[i + 1] = temp;
//                swapped = true;
//            }
//        }
//    }     while (swapped == true);
//
//    // print the sorted ranks and suits
//    for (i = 0; i < 5; i++)
//    {
//        cout << ranknames[R[i]] << " of " << suitnames[S[i]] << "\n";
//    }
//
//    // Check coi co thung` pha sanh khong
//    if (R[1] == R[0] + 1 && R[2] == R[1] + 1 && R[3] == R[2] + 1 && R[4] == R[3] + 1)
//    {
//        cout << "You got a straight!" << endl;\
//    }
//    else
//    {
//        cout << "No straight" << endl;
//    }
//
//    // check coi co' doi khong
//    if (R[0] == R[1] || R[1] == R[2] || R[2] == R[3] || R[3] == R[4])
//    {
//        cout << "You got a pair!" << endl;
//    }
//    else
//    {
//        cout << "No pair" << endl;
//    }
//
//    // Check for a flush (all the same suit)
//    if (S[0] == S[1] && S[1] == S[2] && S[2] == S[3] && S[3] == S[4])
//    {
//        cout << "You got a flush!" << endl;
//    }
//    else
//    {
//        cout << "No flush" << endl;
//    }
//    // Check for straight flush
//    if ((R[1] == R[0] + 1 && R[2] == R[1] + 1 && R[3] == R[2] + 1 && R[4] == R[3] + 1) && (S[0] == S[1] && S[1] == S[2] && S[2] == S[3] && S[3] == S[4]))
//    {
//        cout << "You got a straight flush" << endl;
//    }
//    else
//    {
//        cout << "No straight flush" << endl;
//    }
//    // Check for 4 of a kind
//  //  if (R[0]==R[1]&&R[1]==R[2]&&R[2]==R[3])||
//    // Check for full house
//    if (R[0] == R[1] && R[1] == R[2] && R[3] == R[4])
//    {
//        cout << "You got Full flush" << endl;
//    }
//    else
//    {
//        cout << "No full flush" << endl;
//    }
//    system("pause");
//    return 0;
//}