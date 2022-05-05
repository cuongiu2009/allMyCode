#pragma once
#ifndef Function_h
#define Function_h
#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<iostream>
#include<conio.h>
#include<thread>
#include<fstream>
#include<MMsystem.h>
using namespace std;
#define MAX_SIZE_FOOD 8
#define MAX_SPEED 3

POINT snake[24];
POINT food[8];
int CHAR_LOCK;
int MOVING;
int SPEED;
int HEIGH_CONSOLE, WIDTH_CONSOLE;
int FOOD_INDEX; 
int SIZE_SNAKE;
int STATE; 
int curPosX;
int curPosY;
int score;
int COUNT;
int LIFE = 3;
void FixConsoleWindow();
void GotoXY(int x, int y);
bool IsValid(int x, int y);
void GenerateFood();
void ResetData();
void StartGame();
void DrawBoard(int x, int y, int width, int height);
void ExitGame(HANDLE t);
void PauseGame(HANDLE t);
void Eat();
void ProcessDead();
void MoveRight();
void MoveLeft();
void MoveDown();
void MoveUp();
void ThreadFunc(char* str);
void DrawGate();
bool CheckGate();
void CreateGate();
void CloseGate();
bool eatGate();
void LoadGame(char name[]);
#endif
