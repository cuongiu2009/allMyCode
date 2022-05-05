#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
#include <iostream>
#include <vecto>
#pragma warning(disable : 4996)
using namespace std;

void buff_clr(void)
{
    char junk;
    do {
        junk = getchar();
    } while (junk != '\n');
}
struct coord
{
    int y;
    int x;

}coords;
void ship1x1(int** ships_ptr, int i, int j)
{
    ships_ptr[i][j] = 1;
}

void ship1x2(int** ships_ptr, int i, int j, char c)
{
    ships_ptr[i][j] = 1;
    if (c = 'D')
    {
        ships_ptr[i][j] = 1;
        ships_ptr[i][j + 1] = 1;
    }
    if (c = 'N')
    {
        ships_ptr[i][j] = 1;
        ships_ptr[i + 1][j] = 1;
    }
}
int randgen(int** ships_ptr, int n)
{
    int i, j, count = 0;
    srand((unsigned)time(NULL));
    //cout << "Input Ship: ";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            //cout << "Input (" << i + 1 << "," << j + 1 << "): ";
            ships_ptr[i][j] = rand() % 2;
            if (ships_ptr[i][j] == 1)
            {
                count++;
            }
        }
    }
    return count;
}
void draw_gui(char** pseudo_gui_ptr, int**& pos, int n)
{
    int i, j;

    pseudo_gui_ptr[0][0] = ' ';
    for (i = 1; i < (n + 1); i++)
    {
        pos[0][i] = i;
        pos[i][0] = i;
    }

    for (i = 1; i < (n + 1); i++)
    {
        for (j = 1; j < (n + 1); j++)
        {
            pseudo_gui_ptr[i][j] = '.';
        }
    }
}
int IscheckRight(vector<vector<int>>& Ships, vector<vector<char>>& Pseudo_gui, int i, int j, int count, int n) {
    if ((i >= n  i <= 0  j >= n  j <= 0))
    {
        return count;
    }
    if (Ships[i][j] != 1)
    {
        return count;
    }
    // Right = j+1

    return IscheckRight(Ships, Pseudo_gui, i, j + 1, count + 1, n);
}
int IscheckLeft(vector<vector<int>>& Ships, vector<vector<char>>& Pseudo_gui, int i, int j, int count, int n) {
    if ((i >= n  i <= 0  j >= n  j <= 0))
    {
        return count;
    }
    if (Ships[i][j] != 1)
    {
        return count;
    }
    // Left = j-1

    return IscheckLeft(Ships, Pseudo_gui, i, j - 1, count + 1, n);
}
int IscheckUp(vector<vector<int>>& Ships, vector<vector<char>>& Pseudo_gui, int i, int j, int count, int n) {
    if ((i >= n  i <= 0  j >= n  j <= 0))
    {
        return count;
    }
    if (Ships[i][j] != 1)
    {
        return count;
    }
    // Up = i-1

    return IscheckUp(Ships, Pseudo_gui, i - 1, j, count + 1, n);
}
int IscheckDown(vector<vector<int>>& Ships, vector<vector<char>>& Pseudo_gui, int i, int j, int count, int n) {
    if ((i >= n  i <= 0  j >= n  j <= 0))
    {
        return count;
    }
    if (Ships[i][j] != 1)
    {
        return count;
    }
    // Down = i+1
    return IscheckDown(Ships, Pseudo_gui, i + 1, j, count + 1, n);
}

void Ischeck(vector<vector<int>>& Ships, vector<vector<char>>& Pseudo_gui, int i, int j, int n) {
    int R = IscheckRight(Ships, Pseudo_gui, i, j, 0, n) - 1;

    int L = IscheckLeft(Ships, Pseudo_gui, i, j, 0, n) - 1;

    int U = IscheckUp(Ships, Pseudo_gui, i, j, 0, n) - 1;

    int D = IscheckDown(Ships, Pseudo_gui, i, j, 0, n) - 1;

    for (int row = j - L; row <= j + R; row++)
    {
        for (int col = i - U; col <= i + D; col++)
        {
            Pseudo_gui[row + 1][col + 1] = 'O';
        }
    }
    return;
}
void battle(int** ships_ptr, char** pseudo_gui_ptr, int n, struct coord x, int* count, int* miss)
{

    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (x.x - 1 == i && x.y - 1 == j)
            {
                if (ships_ptr[i][j] == 1)
                {
                    if (pseudo_gui_ptr[i + 1][j + 1] == 'O')
                    {
                        printf("\nYou've already uncovered this field!\n");
                        break;
                    }
                    printf("\nHit!\n");
                    pseudo_gui_ptr[i + 1][j + 1] = 'O';
                    (*count)--;
                }
                else
                {
                    if (pseudo_gui_ptr[i + 1][j + 1] == 'X')
                    {
                        printf("\nYou've already uncovered this field!\n\n");
                        break;
                    }
                    printf("\nMiss!\n");
                    pseudo_gui_ptr[i + 1][j + 1] = 'X';
                    (*miss)++;
                }

            }
        }
    }


}
void result(char** pseudo_gui_ptr, int** pos, int n)
{
    int i, j;

    for (i = 0; i < (n + 1); i++)
    {
        for (j = 0; j < (n + 1); j++)
        {

            if (i == 0 && j == 0)
            {
                printf("%6c", pseudo_gui_ptr[i][j]);
                continue;
            }
            if (i == 0 || j == 0)
            {
                printf("%6d", pos[i][j]);
            }
            else
            {
                printf("%6c", pseudo_gui_ptr[i][j]);
            }
        }
        printf("\n\n");
    }
}
//check user
struct Account
{
    char* username;
    char* password;
};

bool checkAccount(Account acc, char* user_check, char* filename)
{
    FILE* f;
    f = fopen(filename, "r");
    if (f == NULL)
    {
        puts("Khong the mo file nay");
        exit(1);
    }
    user_check = (char*)malloc(25);
    while (feof(f) != 0)
    {
        fscanf(f, "%c", user_check);
        if (user_check == acc.username)
        {
            return true;
        }
    }
    fclose(f);
    free(user_check);
    return false;
}
int main() {

    int** ships;
    char** pseudo_gui;
    int i, j;
    int n = 20;
    char switch_size, switch_difficulty;
    int difficulty = 0;
    int shipcount = 0;
    int x_count = 0;


    printf("\t\t\tSink the ships v0.1b");
    buff_clr();
    printf("\nChoose difficulty(E,H):");
    scanf("%c", &switch_difficulty);
    buff_clr();

    switch (switch_difficulty)
    {
    case 'e':
    case 'E':difficulty = (n * 2) - 2; break;
    case 'h':
    case 'H':difficulty = (n / 2); break;
    default:printf("\nYou've choosen poorly!");
        system("pause");
        exit(EXIT_FAILURE);
    }

    ships = (int**)malloc(n * sizeof(int*));

    for (i = 0; i < n; i++)
    {
        ships[i] = (int*)malloc(n * sizeof(int));
    }

    pseudo_gui = (char**)malloc((n + 1) * sizeof(char*));

    for (i = 0; i < (n + 1); i++)
    {
        pseudo_gui[i] = (char*)malloc((n + 1) * sizeof(char));
    }
    int** pos = (int**)malloc((n + 1) * sizeof(int*));
    for (i = 0; i < (n + 1); i++)
    {
        pos[i] = new int[n + 1];
    }
    shipcount = randgen(ships, n);

    printf("\n\nNumber of ships to be sunk:%d", shipcount);
    printf("\nNumber of misses allowed: %d\n\n", difficulty);
    for (i = 1; i < (n + 1); i++)
    {
        pos[0][i] = i;
        pos[i][0] = i;
    }
    draw_gui(pseudo_gui, pos, n);
    result(pseudo_gui, pos, n);

    while (shipcount != 0 && x_count != difficulty)
    {

        printf("\nEnter coordinates (x,y):");
        scanf("%d,%d", &coords.x, &coords.y);
        buff_clr();

        system("cls");

        battle(ships, pseudo_gui, n, coords, &shipcount, &x_count);
        result(pseudo_gui, pos, n);

        printf("Number of ships to be sunk:%d", shipcount);
        printf("\nNumber of misses(out of %d): %d\n\n", difficulty, x_count);

    }
    if (shipcount == 0)
    {
        printf("\nWinner!\n\n");
        system("pause");
    }
    else if (x_count == difficulty)
    {
        printf("\nYou Lose!\n\n");
        system("pause");
    }
    return 0;
}