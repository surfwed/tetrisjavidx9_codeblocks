#include<iostream>
// Nho include thu vien nay
#include<Windows.h>
#include<thread>

using namespace std;

const int8_t NUM_OF_ROW = 4;
const int8_t NUM_OF_COL = 4;
const int8_t NUM_OF_TETROMINO = 5;

enum TetrominoType
{
	STRAIGHT_TYPE = 0,
	SQUARE_TYPE,
	T_TYPE,
	L_TYPE,
	SKEW_TYPE
};


struct Tetromino {
	char data[NUM_OF_COL][NUM_OF_COL];

	Tetromino() {

	}

	Tetromino(char inputData[NUM_OF_ROW][NUM_OF_COL]) {
		for (int r = 0; r < NUM_OF_ROW; r += 1) {
			for (int c = 0; c < NUM_OF_COL; c += 1) {
				data[r][c] = inputData[r][c];
			}
		}
	}
};



char Straighttetromino[NUM_OF_ROW][NUM_OF_COL] = { {' ', 'X', ' ', ' '},
				 {' ', 'X', ' ', ' '},
				 {' ', 'X', ' ', ' '},
				 {' ', 'X', ' ', ' '} };

char Squaretetromino[NUM_OF_ROW][NUM_OF_COL] = { {' ', ' ', ' ', ' '},
				   {' ', 'X', 'X', ' '},
				   {' ', 'X', 'X', ' '},
				   {' ', ' ', ' ', ' '} };
char Ttetromino[NUM_OF_ROW][NUM_OF_COL] = { {' ', ' ', 'X', ' '},
			{' ', 'X', 'X', ' '},
			{' ', ' ', 'X', ' '},
			{' ', ' ', ' ', ' '} };
char Ltetromino[NUM_OF_ROW][NUM_OF_COL] = { {' ', 'X', ' ', ' '},
			  {' ', 'X', ' ', ' '},
			  {' ', 'X', 'X', ' '},
				  {' ', ' ', ' ', ' '} };
char ReverseLtetromino[NUM_OF_ROW][NUM_OF_COL] = { {' ', ' ', 'X', ' '},
				 {' ', ' ', 'X', ' '},
				 {' ', 'X', 'X', ' '},
				 {' ', ' ', ' ', ' '} };
char SkewLefttetromino[NUM_OF_ROW][NUM_OF_COL] = { {' ', ' ', 'X', ' '},
				 {' ', 'X', 'X', ' '},
				 {' ', 'X', ' ', ' '},
				 {' ', ' ', ' ', ' '} };
char SkewRighttetromino[NUM_OF_ROW][NUM_OF_COL] = { {' ', 'X', ' ', ' '},
				  {' ', 'X', 'X', ' '},
				  {' ', ' ', 'X', ' '},
				  {' ', ' ', ' ', ' '} };

// global tetrominos 
// bien global 
// s o sau de chi so nhieu
Tetromino gTetrominos[NUM_OF_TETROMINO];

Tetromino STRAIGHT_TETROMINO = Straighttetromino;
Tetromino SQUARE_TETROMINO = Squaretetromino;
Tetromino T_TETROMINO = Ttetromino;
Tetromino L_TETROMINO = Ltetromino;
Tetromino SKEW_TETROMINO = SkewLefttetromino;


// In ra mot tetromino
void print(Tetromino tetromino) {
	for (int r = 0; r < NUM_OF_COL; r += 1) {
		for (int c = 0; c < NUM_OF_COL; c += 1) {
			cout << tetromino.data[r][c];
		}
		cout << endl;
	}
	cout << endl;
}


// Viet nhu nay thi no se chay khong dung ne
// thu viet xem sao

// void rotate90ClockWise(Tetromino tetromino) {

void rotate90ClockWise(Tetromino &tetromino) {
	char tempArr[NUM_OF_ROW][NUM_OF_COL];

	for (int r = 0; r < NUM_OF_ROW; r += 1) {
		for (int c = 0; c < NUM_OF_COL; c += 1) {
			tempArr[r][c] = tetromino.data[r][c];
		}
	}
	for (int r = 0; r < NUM_OF_ROW; r += 1) {
		for (int c = 0; c < NUM_OF_COL; c += 1) {
			int convertR = c;
			int convertC = (NUM_OF_COL - 1) - r;
			tetromino.data[convertR][convertC] = tempArr[r][c];
		}
	}	
}

// xoay theo chieu kiem dong ho 90 do, time la so lan xoay
// Thu ngoi voc may tham so nay xem nha
Tetromino rotateTetrominoClockWise(Tetromino tetromino, int times) {
	Tetromino rotatedTetromino = tetromino;
	for (int i = 0; i < times; i += 1) {
		rotate90ClockWise(rotatedTetromino);
	}
	return rotatedTetromino;
}


void initTetromino() {
	gTetrominos[STRAIGHT_TYPE] = Straighttetromino;
	gTetrominos[SQUARE_TYPE] = Squaretetromino;
	gTetrominos[T_TYPE] = Ttetromino;
	gTetrominos[L_TYPE] = Ltetromino;
	gTetrominos[SKEW_TYPE] = SkewLefttetromino;
}


int main() {
	// Co 5 tetromino	
	initTetromino();	

	Tetromino skew = SKEW_TETROMINO;
	// 1000 ms = 1 s
	chrono::milliseconds delay = 1000ms;
	// chuong trinh lap vo han -> khong bao gio dung
	while (true) {
		// Xoa man hinh
		system("cls");
		// xoay hinh 90 do 1 lan
		skew = rotateTetrominoClockWise(skew, 1);
		// print hinh
		print(skew);
		// nghi 1s
		this_thread::sleep_for(delay);
		// xoa man hinh
		system("cls");
		// xoay hinh cu 90 do 1 lan
		skew = rotateTetrominoClockWise(skew, 1);
		// print hinh
		print(skew);
		// nghi 1s
		this_thread::sleep_for(delay);
		// xoa man hinh
		system("cls");
		// xoay hinh 90 do 1 lan
		skew = rotateTetrominoClockWise(skew, 1);
		// print hinh
		print(skew);
		// nghi 1s
		this_thread::sleep_for(delay);
	}
	

}
