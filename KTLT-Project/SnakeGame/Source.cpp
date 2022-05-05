#include"Header.h"

int SIZE_GATE = 5;
POINT gate[5];
int GATE_STATE = 0;
void FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void GotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
bool isBiteItself()
{
	POINT head;
	head.x = snake[SIZE_SNAKE - 1].x;
	head.y = snake[SIZE_SNAKE - 1].y;
	for (int i = SIZE_SNAKE - 2; i > 0; i--)
		if (head.x == snake[i].x && head.y == snake[i].y)
			return true;
	return false;
}
bool IsValid(int x, int y) {
	for (int i = 0; i < SIZE_SNAKE; i++) {

		if (snake[i].x == x && snake[i].y == y) {

			return false;
		}
	}
	return true;
}


void GenerateFood() {

	int x, y;
	srand(time(NULL));
	for (int i = 0; i < MAX_SIZE_FOOD; i++) {
		do {
			x = rand() % (WIDTH_CONSOLE - 1) + 1;
			y = rand() % (HEIGH_CONSOLE - 1) + 1;

		} while (IsValid(x, y) == false);
		food[i] = { x,y };
	}
}
void DrawFood(char* str) {
	GotoXY(food[FOOD_INDEX].x, food[FOOD_INDEX].y);
	cout << str[SIZE_SNAKE];
}
void ResetData() {
	//Defaut values
	CHAR_LOCK = 'A', MOVING = 'D', SPEED = 1; FOOD_INDEX = 1, WIDTH_CONSOLE = 70,
		HEIGH_CONSOLE = 20, SIZE_SNAKE = 1; COUNT = 0;

	//Default snake values
	snake[0] = { 10, 5 };
	GenerateFood();
}
void LoadData() {

	CHAR_LOCK = 'A', MOVING = 'D'; FOOD_INDEX = 0, WIDTH_CONSOLE = 70,
		HEIGH_CONSOLE = 20; SIZE_SNAKE = 1; SPEED = SPEED++;

	snake[0] = { 10, 5 };
	/*snake[1] = { 11, 5 };
	snake[2] = { 12, 5 }; snake[3] = { 13, 5 };
	snake[4] = { 14, 5 }; snake[5] = { 15, 5 };*/
	GenerateFood();
}
void LOADING() {
	WIDTH_CONSOLE = 70,
		HEIGH_CONSOLE = 20;
}
void display()
{
	GotoXY(WIDTH_CONSOLE + 5, 2);
	cout << "Your score: " << score;
	GotoXY(WIDTH_CONSOLE + 5, 3);
	cout << "How to play:";
	GotoXY(WIDTH_CONSOLE + 5, 4);
	cout << "number attemps: " << LIFE;
	GotoXY(WIDTH_CONSOLE + 5, 5);
	cout << "   Press: " << endl;
	GotoXY(WIDTH_CONSOLE + 5, 6);
	cout << "W: to move on" << endl;
	GotoXY(WIDTH_CONSOLE + 5, 7);
	cout << "A: to move left" << endl;
	GotoXY(WIDTH_CONSOLE + 5, 8);
	cout << "D: to move right" << endl;
	GotoXY(WIDTH_CONSOLE + 5, 9);
	cout << "S: to move down" << endl;
}
void showStartMenu(char name[], char* str)
{
	system("cls");
	PlaySound(TEXT("pacman_beginning.wav"), NULL, SND_ASYNC);
	system("cls");
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "\t\t\t\t\tWelcome"; Sleep(500);
	cout << " to"; Sleep(500);
	cout << " snake"; Sleep(500);
	cout << " game!" << endl; Sleep(2000);
	system("cls");
	cout << "\t\t    ooooo      nnnnn      nnn       aaa       Kkk     kkkkk   eeeeeeeeeeee       \n";
	cout << "\t\tssss     ssss  nnnnnn     nnn     aaa aaa     Kkk    kkkk     Eeeeeeeeeeee       \n";
	cout << "\t\t ssss          nnn  nnn   nnn    aaa   aaa    Kkk   kkkk      Eee                \n";
	cout << "\t\t  sssss        nnn   nnn  nnn   aaa     aaa   Kkkkkk          Eeeeeeeeeeee       \n";
	cout << "\t\t    sssss      nnn    nnn nnn  aaaaaaaaaaaaa  Kkk   kkkk      Eee                \n";
	cout << "\t\tssss    ssss   nnn     nnnnnn  aaa       aaa  Kkk     kkk     Eeeeeeeeeeee       \n";
	cout << "\t\t   sssss       nnn      nnnnn  aaa       aaa  Kkk      kkkkk  eeeeeeeeeeee       \n";
	cout << endl;
	cout << endl;
	cout << endl;

	cout << "\t\t\t\t\tOptions:" << endl;
	cout << "\t\t\t\t\t1. Start" << endl;
	cout << "\t\t\t\t\t2. Load game" << endl;
	cout << "\t\t\t\t\t3. Quit" << endl;
	cout << "\t\t\t\t\t Press your choice: ";
	int option;
	cin >> option;
	if (option == 1)
	{
		system("cls");
		cout << "Tip: While playing game, you can press 'E' to quit";
		GotoXY(0, 3);
		cout << "Ready!";
		Sleep(1000);
		for (size_t i = 3; i > 0; i--)
		{
			GotoXY(0, 3);
			cout << i << "         ";
			Sleep(1000);
		}
		GotoXY(0, 3);
		cout << "GO!";
		Sleep(1000);
		StartGame();
	}
	else if (option == 2) {
		cout << "Enter your name:";
		cin.ignore();
		cin.getline(name, 50);
		LoadGame(name);
	}
	else if (option == 3)
		exit(1);
}

void StartGame() {
	system("cls");
	ResetData(); // Khởi tạo dữ liệu gốc
	DrawBoard(0, 0, WIDTH_CONSOLE, HEIGH_CONSOLE);
	display();
	STATE = 1;
}

void DrawBoard(int x, int y, int width, int height) {
	int curPosX = 0, curPosY = 0;
	GotoXY(x, y);
	cout << ' ';
	for (int i = 1; i < width; i++)cout << '_';
	cout << '_';
	GotoXY(x, height + y); cout << '_';
	for (int i = 1; i < width; i++)cout << '_';
	cout << '|';
	for (int i = y + 1; i < height + y; i++) {
		GotoXY(x, i); cout << '|';
		GotoXY(x + width, i); cout << '|';

	}
	GotoXY(curPosX, curPosY);
}

//quit func
void ExitGame(HANDLE t) {
	system("cls");
	CloseHandle(t);
	std::terminate();

}
//stop func
void PauseGame(HANDLE t) {
	SuspendThread(t);
}

void saveGame(HANDLE t, char name[]) {
	fstream fout;
	PauseGame(t);
	GotoXY(0, HEIGH_CONSOLE + 2);
	cout << "Enter your name:";
	cin.ignore();
	cin.getline(name, 50);
	fout.open(name, ios::app);
	fout << score << endl;
	fout << FOOD_INDEX << endl;
	fout << food[FOOD_INDEX].x << " " << food[FOOD_INDEX].y << endl;
	fout << SIZE_SNAKE << endl;
	for (int i = 0; i < SIZE_SNAKE; i++) {
		fout << snake[i].x << " " << snake[i].y << endl;
	}
	fout << GATE_STATE << endl;
	if (GATE_STATE == 1) {
		for (int i = 0; i < 5; i++) {
			fout << gate[i].x << " " << gate[i].y << endl;
		}
	}
	fout << COUNT << endl;
	fout << SPEED << endl;
	fout << MOVING << endl;
	fout.close();
	Sleep(1000);
	GotoXY(0, HEIGH_CONSOLE + 2);
	cout << " ";
	ResumeThread(t);
}
void LoadGame(char name[]) {
	fstream fout;
	fout.open(name);
	if (fout.fail()) {
		cout << "file khong he ton tai";
	}
	else {
		fout >> score;
		fout >> FOOD_INDEX;
		fout >> food[FOOD_INDEX].x >> food[FOOD_INDEX].y;
		fout >> SIZE_SNAKE;
		for (int i = 0; i < SIZE_SNAKE; i++) {
			fout >> snake[i].x >> snake[i].y;
		}
		fout >> GATE_STATE;
		if (GATE_STATE == 1) {
			for (int i = 0; i < 5; i++) {
				fout >> gate[i].x >> gate[i].y;
			}
		}
		fout >> COUNT;
		fout >> SPEED;
		fout >> MOVING;
		fout.close();
		system("cls");
		LOADING();
		DrawBoard(0, 0, 70, 20);
		display();
		STATE = 1;
		if (GATE_STATE == 1) {
			DrawGate();
		}
	}

}
//Updating func
void Eat() {
	snake[SIZE_SNAKE] = food[FOOD_INDEX];
	PlaySound(TEXT("pacman_eatfruit.wav"), NULL, SND_ASYNC);
	if (FOOD_INDEX == MAX_SIZE_FOOD - 1)
	{
		food[FOOD_INDEX].x = NULL;
		food[FOOD_INDEX].y = NULL;
		score++;
		SIZE_SNAKE++;
		COUNT = SIZE_SNAKE;
		if (SPEED == MAX_SPEED) {
			GotoXY(WIDTH_CONSOLE + 5, 2);
			cout << "Your score: " << score;
			Sleep(2000);
			system("cls");
			cout << "Chuc mung ban da chien thang!!!!!!!!!!!!!!" << endl;
			cout << "Nhan Y de bat dam choi game lai hoac nhan E de thoat";
		}
		else {
			CreateGate();
			DrawGate();
		}
	}
	else {
		FOOD_INDEX++;
		SIZE_SNAKE++;
		score++;
	}
	GotoXY(WIDTH_CONSOLE + 5, 2);
	cout << "Your score: " << score;
}

//Snake-dead function
void ProcessDead() {
	STATE = 0;
	score = 0;
	LIFE--;
	if (LIFE == 0) {
		PlaySound(TEXT("game_over.wav"), NULL, SND_ASYNC);
		GotoXY(0, HEIGH_CONSOLE + 2);
		printf("GAME OVER!!!!!!!!!!!");
		cout << endl;
		cout << "PRESS Y TO RESTART THE GAME, PRESS OTHER KEYS TO EXIT";
	}
	else StartGame();
}


// Draw whole snake
void drawSnake(char* str)
{
	for (int i = 0; i < SIZE_SNAKE; i++) {
		GotoXY(snake[i].x, snake[i].y);
		cout << str[i];
	}
}

// Redraw head & tail to make the snake move
void drawHeadnTail()
{
	for (int i = 0; i < SIZE_SNAKE; i++) {
		GotoXY(snake[i].x, snake[i].y);
		cout << ' ';
	}
}
//snake when touching gate
bool eatGate() {
	for (int i = 0; i < 5; i++) {
		if (snake[SIZE_SNAKE - 1].x == gate[i].x && snake[SIZE_SNAKE - 1].y == gate[i].y) {
			return true;
		}
	}
	return false;
}

//level-up
void levelup() {
	int count;
	if (snake[SIZE_SNAKE - 1].x == gate[2].x && snake[SIZE_SNAKE - 1].y == gate[2].y + 1) {
		SIZE_SNAKE--;
		count = SIZE_SNAKE;
		if (SIZE_SNAKE == 0) {
			Sleep(1000);
			CloseGate();
			LoadData();
		}
	}
}

void MoveRight() {
	if (snake[SIZE_SNAKE - 1].x + 1 == WIDTH_CONSOLE || isBiteItself() || eatGate()) {
		ProcessDead();
	}
	else {
		if (snake[SIZE_SNAKE - 1].x + 1 == food[FOOD_INDEX].x && snake[SIZE_SNAKE - 1].y == food[FOOD_INDEX].y) {
			Eat();
		}
		levelup();
		if (GATE_STATE == 0) {
			if (SIZE_SNAKE < COUNT) {
				snake[SIZE_SNAKE].x = snake[SIZE_SNAKE - 1].x + 1;
				snake[SIZE_SNAKE].y = snake[SIZE_SNAKE - 1].y;
				SIZE_SNAKE++;
			}
		}

		for (int i = 0; i < SIZE_SNAKE - 1; i++) {
			snake[i].x = snake[i + 1].x;
			snake[i].y = snake[i + 1].y;
		}
		snake[SIZE_SNAKE - 1].x++;
	}
}
void MoveLeft() {
	if (snake[SIZE_SNAKE - 1].x - 1 == 0 || isBiteItself() || eatGate()) {
		ProcessDead();
	}
	else {
		if (snake[SIZE_SNAKE - 1].x - 1 == food[FOOD_INDEX].x && snake[SIZE_SNAKE - 1].y == food[FOOD_INDEX].y) {
			Eat();

		}
		levelup();
		if (GATE_STATE == 0) {
			if (SIZE_SNAKE < COUNT) {
				snake[SIZE_SNAKE].x = snake[SIZE_SNAKE - 1].x - 1;
				snake[SIZE_SNAKE].y = snake[SIZE_SNAKE - 1].y;
				SIZE_SNAKE++;
			}
		}
		for (int i = 0; i < SIZE_SNAKE - 1; i++) {
			snake[i].x = snake[i + 1].x;
			snake[i].y = snake[i + 1].y;

		}
		snake[SIZE_SNAKE - 1].x--;

	}

}

void MoveDown() {
	if (snake[SIZE_SNAKE - 1].y == HEIGH_CONSOLE || isBiteItself() || eatGate()) {
		ProcessDead();
	}
	else {
		if (snake[SIZE_SNAKE - 1].x == food[FOOD_INDEX].x && snake[SIZE_SNAKE - 1].y + 1 == food[FOOD_INDEX].y) {
			Eat();

		}
		levelup();
		if (GATE_STATE == 0) {
			if (SIZE_SNAKE < COUNT) {
				snake[SIZE_SNAKE].x = snake[SIZE_SNAKE - 1].x;
				snake[SIZE_SNAKE].y = snake[SIZE_SNAKE - 1].y + 1;
				SIZE_SNAKE++;
			}
		}
		for (int i = 0; i < SIZE_SNAKE - 1; i++) {
			snake[i].x = snake[i + 1].x;
			snake[i].y = snake[i + 1].y;

		}
		snake[SIZE_SNAKE - 1].y++;
	}

}

void MoveUp() {
	if (snake[SIZE_SNAKE - 1].y - 1 == 0 || isBiteItself() || eatGate()) {
		ProcessDead();
	}
	else {
		if (snake[SIZE_SNAKE - 1].x == food[FOOD_INDEX].x && snake[SIZE_SNAKE - 1].y - 1 == food[FOOD_INDEX].y) {
			Eat();
		}
		levelup();
		if (GATE_STATE == 0) {
			if (SIZE_SNAKE < COUNT) {
				snake[SIZE_SNAKE].x = snake[SIZE_SNAKE - 1].x;
				snake[SIZE_SNAKE].y = snake[SIZE_SNAKE - 1].y - 1;
				SIZE_SNAKE++;
			}
		}
		for (int i = 0; i < SIZE_SNAKE - 1; i++) {
			snake[i].x = snake[i + 1].x;
			snake[i].y = snake[i + 1].y;
		}
		snake[SIZE_SNAKE - 1].y--;
	}
}

//Thủ tục cho thread
void ThreadFunc(char* str) {
	while (1) {
		if (STATE == 1) {//Nếu vẫn còn snake vẫn còn sống
			switch (MOVING) {
			case 'A':
				MoveLeft();
				break;
			case 'D':
				MoveRight();
				break;
			case 'W':
				MoveUp();
				break;
			case 'S':
				MoveDown();
				break;
			}
			DrawFood(str);
			drawSnake(str);
			Sleep(1000 / (SPEED * 5));//Hàm ngủ theo tốc độ SPEEED
			drawHeadnTail();
		}
	}
}

/*void sort(int arr[]) {
	for (int i = 0; i < 5;i++) {
		for (int j = 0; j < 5;j++) {
			if (arr[i] < arr[j]) {
				int temp = arr[j];
				 arr[j] = arr[i];
				 arr[i] = temp;
			}
		}
	}
}
void Save(int score) {
	int arr[4];
	fstream f;
	f.open("Text.txt", ios::in);
	for (int i = 0;i < 5;i++) {
		f >> arr[i];
	}
	sort(arr);
	for (int i = 0; i < 5;i++) {
		if (score > arr[i]) {
			int temp = arr[i];
			arr[i] = score;
			for (int j = i + 1;j < 5;i++) {
				int temp2 = arr[j];
				arr[j] = temp;

			}
		}
	}
	f.close();
}*/
void CreateGate()
{

	if (!GATE_STATE)
	{
		srand(time(NULL));
		do {
			gate[0].x = rand() % (WIDTH_CONSOLE - 6) + 2;
			gate[0].y = rand() % (HEIGH_CONSOLE - 6) + 2;
			gate[1] = { gate[0].x, gate[0].y - 1 };
			gate[2] = { gate[0].x + 1, gate[0].y - 1 };
			gate[3] = { gate[0].x + 2, gate[0].y - 1 };
			gate[4] = { gate[0].x + 2, gate[0].y };
		} while (!CheckGate());
		GATE_STATE = 1;
	}
}
//if coord same as coord snake
bool CheckGate()
{
	for (int i = 0; i < SIZE_GATE; ++i) {
		if (!IsValid(gate[i].x, gate[i].y))
			return false;
	}
	for (int i = 0; i < SIZE_GATE; ++i) {
		if (gate[i].x == food[FOOD_INDEX].x &&
			gate[i].y == food[FOOD_INDEX].y)
			return false;
	}
	return true;
}

void DrawGate()
{
	if (GATE_STATE)
	{
		for (int i = 0; i < SIZE_GATE; ++i)
		{
			GotoXY(gate[i].x, gate[i].y);
			printf("%c", 219);
		}
	}
}
//delete gate when snake is through
void CloseGate()
{
	if (GATE_STATE) {
		for (int i = 0; i < SIZE_GATE; ++i) {
			GotoXY(gate[i].x, gate[i].y);
			printf(" ");
			gate[i].x = NULL;
			gate[i].y = NULL;
		}
		GATE_STATE = 0;
	}
}
int main() {
	int temp;
	char* str;
	char b[] = "201273102012761620127913";
	str = b;
	char name[50];
	system(" color f5");
	FixConsoleWindow();
	showStartMenu(name, str);
	thread t1(ThreadFunc, str); //Tao thread cho snake
	HANDLE handle_t1 = t1.native_handle(); //Lay handle cua thread
	while (1) {
		temp = toupper(_getch());
		if (STATE == 1) {
			if (temp == 'P') {
				PauseGame(handle_t1);
			}
			else if (temp == 'E') {
				ExitGame(handle_t1);
				return 0;
			}
			else if (temp == 'L') {
				saveGame(handle_t1, name);
			}
			else {
				ResumeThread(handle_t1);
				if ((temp != CHAR_LOCK) && (temp == 'D' || temp == 'A' || temp ==
					'W' || temp == 'S'))
				{
					if (temp == 'D') CHAR_LOCK = 'A';
					else if (temp == 'W') CHAR_LOCK = 'S';
					else if (temp == 'S') CHAR_LOCK = 'W';
					else CHAR_LOCK = 'D';
					MOVING = temp;
				}
			}
		}
		else {
			if (temp == 'Y') StartGame();
			else {
				ExitGame(handle_t1);
				return 0;
			}
		}
	}
	int end_thread = clock();
	return 0;
}