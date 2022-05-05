#include "Header.h"
void shuffleCards(int deck[4][13]) {
    int next = 0;
    int tmpdeck[52];
    for (int i = 0; i < 52; i++)
    {
        tmpdeck[i] = i;//gan gia tri tmpdeck[]
    }
    for (int i = 0; i < 4; i++)
    {
        for (int k = 0; k < 13; k++)
        {
            deck[i][k] = next;//gan gia tri tmpdeck[]
            next++;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int k = 0; k < 13; k++)
        {
            int value = rand() % 52;
            int tmp = deck[i][k];
            for (int u = 0; u < 4; u++)
            {
                for (int t = 0; t < 13; t++)
                {
                    if (deck[u][t] == value)
                    {
                        deck[u][t] = tmp;// tim vi tri co gia tri bang bien value 
                    }
                }
            }
            deck[i][k] = value;
        }
    }

}
void printCardsShuffling(int deck[4][13], const char* suits[], const char* ranks[]) {
    for (int i = 0; i < 4; i++)
    {
        for (int k = 0; k < 13; k++)
        {
            int suitsNumber = deck[i][k] % 4; // 0 - 3
            int ranksNumber = deck[i][k] % 13;//0-12
            cout << "[" << suits[suitsNumber] << "," << ranks[ranksNumber] << "]" << " ";
            if (k == 6)
            {
                cout << endl;
                cout << endl;
            }
            if (k == 12)
            {
                cout << endl;
            }
        }
        cout << endl;
    }
}
int** dealingForHand(int deck[4][13]) {
    int** result = new int* [5];
    for (int i = 0; i < 5; i++)//khoi tao gia tri 
    {
        result[i] = new int[2];
        result[i][0] = -1;
        result[i][1] = -1;
    }
    for (int i = 0; i < 5; i++)
    {
        result[i][0] = deck[0][i] % 4;
        result[i][1] = deck[0][i] % 13;
    }
    return result;
}
void printHand(int** hand, const char* suits[], const char* ranks[]) {
    for (int i = 0; i < 4; i++)
    {
        for (int u = 0; u < 4; u++)//sap xep theo rank tu lon den nho
        {
            if (hand[u + 1][1] > hand[u][1])
            {
                int tmp = hand[u][1];
                int tpm = hand[u][0];
                hand[u][1] = hand[u + 1][1];
                hand[u][0] = hand[u + 1][0];
                hand[u + 1][1] = tmp;
                hand[u + 1][0] = tpm;
            }
        }
    }
    for (int i = 0; i < 4; i++)//sap xep theo rank va suit tu lon den nho
    {
        for (int u = 0; u < 4; u++) {
            if (hand[u + 1][0] > hand[u][0] && hand[u + 1][0] == hand[u][0])
            {
                int tmp = hand[u][1];
                int tpm = hand[u][0];
                hand[u][1] = hand[u + 1][1];
                hand[u][0] = hand[u + 1][0];
                hand[u + 1][1] = tmp;
                hand[u + 1][0] = tpm;
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        int suitsNumber = hand[i][0];
        int ranksNumber = hand[i][1];
        cout << "[" << suits[suitsNumber] << "," << ranks[ranksNumber] << "]" << " ";
    }
}
int** createHandTest() {
    cout << " Input 0-51" << endl;
    int a[6];
    for (int i = 0; i < 5; i++)
    {
        cin >> a[i];
        while (a[i] > 51 && a[i] < 0)
        {
            cout << "Form 0 to 51 please " << endl;
            cin >> a[i];
        }
    }
    int** handTest = new int* [5];
    for (int i = 0; i < 5; i++)//khoi tao gia tri 
    {
        handTest[i] = new int[2];
        handTest[i][0] = -1;
        handTest[i][1] = -1;
    }
    for (int i = 0; i < 5; i++)
    {
        handTest[i][0] = a[i] / 13;
        handTest[i][1] = a[i] % 13;

    }
    return handTest;
}
int isStraightFlush(int** hand) {
    int counter = 0;
    for (int i = 0; i < 4; i++)
    {
        if (hand[i][0] == hand[i + 1][0] && hand[i][1] - hand[i + 1][1] == 1)
        {
            counter++;
        }
    }
    if (counter == 4)
    {
        return 8;
    }
    return 0;
}
int isFourOfAKind(int** hand) {
    int counter = 0;
    for (int i = 0; i < 4; i++)
    {
        if (hand[i][1] == hand[i + 1][1])
        {
            counter++;
        }
    }
    if (counter == 3)
    {
        return 7;
    }
    return 0;
}
int isFlush(int** hand) {
    int counter = 0;
    for (int i = 0; i < 4; i++)
    {
        if (hand[i][0] != hand[i + 1][0])
            return 0;
    }
    return 6;
}
int isStraight(int** hand) {
    for (int i = 0; i < 4; i++)
    {
        for (int u = 0; u < 4; u++)
        {
            if (hand[u][1] - hand[u + 1][1] != 1) {
                return 0;
            }
        }
    }
    return 5;
}
int isFullHouse(int** hand) {
    if (hand[0][1] == hand[1][1] && hand[0][1] == hand[2][1] && hand[3][1] == hand[4][1])
    {
        return 4;
    }
    else if (hand[0][1] == hand[1][1] && hand[2][1] == hand[3][1] && hand[3][1] == hand[4][1])
    {
        return 4;
    }
    return 0;

}
int isThreeOfAKind(int** hand) {
    if (hand[0][1] == hand[1][1] && hand[0][1] == hand[2][1] && hand[3][1] != hand[4][1])
    {
        return 3;
    }
    else if (hand[0][1] != hand[1][1] && hand[2][1] == hand[3][1] && hand[3][1] == hand[4][1])
    {
        return 3;
    }
    else if (hand[0][1] != hand[4][1] && hand[1][1] == hand[2][1] && hand[2][1] == hand[3][1])
    {
        return 3;
    }
    return 0;
}
int isTwoPairs(int** hand) {
    if (hand[0][1] == hand[1][1] && hand[2][1] == hand[3][1] || hand[0][1] == hand[1][1] && hand[3][1] == hand[4][1])
    {
        return 2;
    }
    else if (hand[1][1] == hand[2][1] && hand[3][1] == hand[4][1])
    {
        return 2;
    }
    return 0;
}
int isPairs(int** hand) {
    if (hand[0][1] == hand[1][1] || hand[1][1] == hand[2][1] || hand[2][1] == hand[3][1] || hand[3][1] == hand[4][1])
    {
        return 1;
    }
    return 0;
}
int getHighestCard(int** hand) {// sua int thanh void de xuat ra la bai lon nhat trong tay
    return hand[0][1];
}
int getHighestSuit(int** hand) {// sua int thanh void de xuat ra la bai lon nhat trong tay
    return hand[0][0];
}
int getHighestCardAgain(int** hand, int n) {
    return hand[n][1];
}
int** get2Dfrom3D(int** hand) {
    return hand;
}
void deleteHand(int** array) {
    for (int i = 0; i < 5; i++)
    {
        delete array[i];
    }
    delete[] array;
}
int*** dealingForHands(int deck[4][13], int n) {
    int*** result = new int** [n];
    for (int i = 0; i < n; i++)//khoi tao gia tri 
    {
        result[i] = new int* [5];
        for (int j = 0; j < 5; j++)
        {
            result[i][j] = new int[2];
            result[i][j][0] = -1;
            result[i][j][1] = -1;
        }
    }
    int col = 0, row = 0;
    for (int j = 0; j < 5; j++)// chia la bai thu j cho moi nguoi
    {
        for (int i = 0; i < n; i++)// toi nguoi thu i nhan la bai
        {
            result[i][j][0] = deck[row][col] % 4;
            result[i][j][1] = deck[row][col] % 13;
            col++;
            if (col > 12)
            {
                col = 0;
                row++;
            }
            if (row > 3)
            {
                row = 0;
            }
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int u = 0; u < 4; u++) {
                if (result[k][u + 1][1] > result[k][u][1])//sap xep theo rank lon den nho
                {
                    int tmp = result[k][u][1];
                    int tpm = result[k][u][0];
                    result[k][u][1] = result[k][u + 1][1];
                    result[k][u][0] = result[k][u + 1][0];
                    result[k][u + 1][1] = tmp;
                    result[k][u + 1][0] = tpm;
                }
                if (result[k][u + 1][0] > result[k][u][0] && result[k][u + 1][1] == result[k][u][1])//sap xep theo rank va suit tu lon den nho
                {
                    int tmp = result[k][u][1];
                    int tpm = result[k][u][0];
                    result[k][u][1] = result[k][u + 1][1];
                    result[k][u][0] = result[k][u + 1][0];
                    result[k][u + 1][1] = tmp;
                    result[k][u + 1][0] = tpm;
                }
            }
        }
    }
    return result;
}
void printmulti(int*** hand, const char* suits[], const char* ranks[], int n) {

    cout << endl;
    for (int k = 0; k < n; k++)
    {
        cout << "The Player " << k + 1 << endl;
        for (int i = 0; i < 5; i++)
        {
            int suitsNumber = hand[k][i][0];
            int ranksNumber = hand[k][i][1];
            cout << "[" << suits[suitsNumber] << "," << ranks[ranksNumber] << "]" << " ";
        }
        cout << endl;
    }
}
int getStatusOfHand(int** hand) {
    if (isStraightFlush(hand) > 0)
    {
        return isStraightFlush(hand);
    }
    else if (isFourOfAKind(hand) > 0)
    {
        return isFourOfAKind(hand);
    }
    else if (isFullHouse(hand) > 0)
    {
        return isFullHouse(hand);
    }
    else if (isFlush(hand) > 0)
    {
        return isFlush(hand);
    }
    else if (isStraight(hand) > 0)
    {
        return isStraight(hand);
    }
    else if (isThreeOfAKind(hand) > 0)
    {
        return isThreeOfAKind(hand);
    }
    else if (isTwoPairs(hand) > 0)
    {
        return isTwoPairs(hand);
    }
    else if (isPairs(hand) > 0)
    {
        return isPairs(hand);
    }
    else
    {
        return 0;
    }
}
int** convert3dTo2d(int*** hand, int u) {//Convert con tro 3 chieu thanh con tro 2 chieu mang gia tri cua 3 chieu 
    int** handTest = new int* [5];//tao mang con tro 2 chieu moi
    for (int i = 0; i < 5; i++)//khoi tao gia tri 
    {
        handTest[i] = new int[2];
        handTest[i][0] = -1;
        handTest[i][1] = -1;
    }
    for (int k = 0; k < 5; k++)
    {
        handTest[k][0] = hand[u][k][0];
        handTest[k][1] = hand[u][k][1];
    }
    return handTest;
}
int* rankingHands_2(int*** hands, int n) {

    int** hand_player = new int* [n];
    int* rank = new int[n];
    for (int i = 0; i < n; i++)
    {
        hand_player[i] = new int[4];
        hand_player[i][0] = 0;
        hand_player[i][1] = 0;
        hand_player[i][2] = -1;
        hand_player[i][3] = -1;
        rank[i] = 0;
    }
    for (int player = 0; player < n; player++)
    {
        hand_player[player][0] = getStatusOfHand(hands[player]); // lấy bài lớn nhất trong tay người chơi
        hand_player[player][1] = getHighestCard(hands[player]);
        hand_player[player][2] = player;
        hand_player[player][3] = getHighestSuit(hands[player]);
        int** counter = get2Dfrom3D(hands[player]);
        if (hand_player[player][1] > 0 && hand_player[player][1] < 4 || hand_player[player][1] == 7) {
            int count = 0;
            int val = 1;
            for (int j = 0; j < n - 1; j++)
            {
                for (int i = val; i < n; i++)
                {
                    if (hand_player[player][1] == counter[i][1])
                    {
                        count++;
                    }
                }
                if (count == 0)
                {
                    hand_player[player][1] = getHighestCardAgain(hands[player], val);
                    val++;
                }
                else
                {
                    break;
                }
            }
        }
        else if (hand_player[player][1] == 6)
        {
            int count = 0;
            int val = 1;
            for (int i = 0; i < n; i++)
            {
                if (hand_player[player][1] == counter[i][1])
                {
                    count++;
                }
            }
            if (count < 2)
            {
                hand_player[player][1] = getHighestCardAgain(hands[player], 4);
            }
            else
            {
                break;
            }
        }
        else
        {
            hand_player[player][1] = getHighestCard(hands[player]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << "stus is" << hand_player[i][0] << "   ";
        cout << "P" << i + 1 << ":" << hand_player[i][1] << endl;;

    }
    cout << endl;
    for (int k = 0; k < n - 1; k++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (hand_player[i][0] < hand_player[i + 1][0]) {
                int tmp0 = hand_player[i][0];
                int tmp1 = hand_player[i][1];
                int tmp2 = hand_player[i][2];
                int tmp3 = hand_player[i][3];
                hand_player[i][0] = hand_player[i + 1][0];
                hand_player[i][1] = hand_player[i + 1][1];
                hand_player[i][2] = hand_player[i + 1][2];
                hand_player[i][3] = hand_player[i + 1][3];
                hand_player[i + 1][0] = tmp0;
                hand_player[i + 1][1] = tmp1;
                hand_player[i + 1][2] = tmp2;
                hand_player[i + 1][3] = tmp3;
            }
            else if (hand_player[i][0] == hand_player[i + 1][0] && hand_player[i][1] < hand_player[i + 1][1])
            {
                int tmp0 = hand_player[i][0];
                int tmp1 = hand_player[i][1];
                int tmp2 = hand_player[i][2];
                int tmp3 = hand_player[i][3];
                hand_player[i][0] = hand_player[i + 1][0];
                hand_player[i][1] = hand_player[i + 1][1];
                hand_player[i][2] = hand_player[i + 1][2];
                hand_player[i][3] = hand_player[i + 1][3];
                hand_player[i + 1][0] = tmp0;
                hand_player[i + 1][1] = tmp1;
                hand_player[i + 1][2] = tmp2;
                hand_player[i + 1][3] = tmp3;
            }
            else if (hand_player[i][0] == hand_player[i + 1][0] && hand_player[i][2] < hand_player[i + 1][2])
            {
                int tmp0 = hand_player[i][0];
                int tmp1 = hand_player[i][1];
                int tmp2 = hand_player[i][2];
                int tmp3 = hand_player[i][3];
                hand_player[i][0] = hand_player[i + 1][0];
                hand_player[i][1] = hand_player[i + 1][1];
                hand_player[i][2] = hand_player[i + 1][2];
                hand_player[i][3] = hand_player[i + 1][3];
                hand_player[i + 1][0] = tmp0;
                hand_player[i + 1][1] = tmp1;
                hand_player[i + 1][2] = tmp2;
                hand_player[i + 1][3] = tmp3;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        rank[i] = hand_player[i][2];

    }
    return rank;
}
int shuffleCardsAgains(int deck[4][13]) {
    int next = 0;
    int tmpdeck[52];
    for (int i = 0; i < 52; i++)
    {
        tmpdeck[i] = i;//gan gia tri tmpdeck[]
    }
    for (int i = 0; i < 4; i++)
    {
        for (int k = 0; k < 13; k++)
        {
            deck[i][k] = next;//gan gia tri deck[]
            next++;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int k = 0; k < 13; k++)
        {
            int value = rand() % 52;
            int tmp = deck[i][k];
            for (int u = 0; u < 4; u++)
            {
                for (int t = 0; t < 13; t++)
                {
                    if (deck[u][t] == value)
                    {
                        deck[u][t] = tmp;// tim vi tri co gia tri bang bien value 
                    }
                }
            }
            deck[i][k] = value;
        }
    }
    return 0;
}
int* evaluateHands(int*** hands, int n, int s, int deck[4][13], const char* suits[], const char* ranks[]) {
    int* sum = new int[n];
    for (int i = 0; i < n; i++)//khoi tao gia tri cho sum
    {
        sum[i] = 0;
    }
    for (int h = 0; h < s; h++)
    {
        for (int i = 0; i < n; i++)
        {
            int** new2dArray = get2Dfrom3D(hands[i]);//convert sang mang 2D
            int rankHands = getStatusOfHand(new2dArray);//tim gia tri hand-ranking lon nhat trong tay nguoi thu i, roi gan vao mang a[i]
            sum[i] = sum[i] + rankHands;//sum cong don gia tri hand-ranking cua tung nguoi choi 
        }
        shuffleCardsAgains(deck);
        hands = dealingForHands(deck, n);
        printmulti(hands, suits, ranks, n);
    }
    int* playerRanks = new int[n];
    int val = 0;
    int counter = 1;
    for (int j = 0; j < n; j++)
    {
        int max = INT_MIN;
        for (int i = 0; i < n; i++)//tim gia tri lon nhat trong mang
        {
            if (sum[i] >= max)
            {
                max = sum[i];
                val = i;
            }
        }
        playerRanks[val] = counter;//xep hang cho nguoi choi
        sum[val] = -1;//gan vi tri co gia tri cao nhat trong mang bang -1
        counter++;
        if (counter > n)
        {
            return playerRanks;
        }
    }
    return playerRanks;
}

