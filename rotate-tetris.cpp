// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int const numOfRow = 4;
int const numOfColumn = 4;

using namespace std;

void rotate90(char arr[numOfRow][numOfColumn]) {
	
	// tao mot mang phu luu thong tin mang cu

	char tempArr[numOfRow][numOfColumn];
	for (int r = 0; r < numOfRow; r += 1) {
		for (int c = 0; c < numOfColumn; c += 1) {
			tempArr[r][c] = arr[r][c];
		}
	}

	// Duyet hang, cot
	// r viet tat cua row
	// c viet tat cua column


	for (int r = 0; r < numOfRow; r += 1) {
		for (int c = 0; c < numOfColumn; c += 1) {
			// Ap dung cong thuc
			// (r,c) -> (c, chi so cot max - r)
			// Toa do sau khi chuyen
			int convertR = c;
			// Chi so cot max = So cot - 1 = numOfColumn - 1
			int convertC = (numOfColumn - 1) - r;
			arr[convertR][convertC] = tempArr[r][c];
		}
	}
}

void print(char arr[numOfColumn][numOfColumn]) {
	for (int r = 0; r < numOfRow; r += 1) {		
		for (int c = 0; c < numOfColumn; c += 1) {
			cout << arr[r][c];
		}
		// In xong mot hang thi xuong dong
		cout << endl;
	}
	// In het roi thi xuong dong
	cout << endl;	
}

int main()
{
    std::cout << "Hello World!\n";
	char a[4][4] = { {' ', 'X', ' ', ' '},
				   {' ', 'X', ' ', ' '},
				   {' ', 'X', ' ', ' '},
				   {' ', 'X', ' ', ' '}};

	// In A
	print(a);
	// Xoay 90 do #1
	rotate90(a);	
	// In A sau khi xoay 90 do #1
	print(a);	
	// Xoay 90 do #2
	rotate90(a);
	// In A sau khi xoay 90 do #2
	print(a);

	char b[4][4] = { {' ', ' ', ' ', ' '},
				   {' ', 'X', ' ', ' '},
				   {' ', 'X', 'X', ' '},
				   {' ', 'X', ' ', ' '} };

	// In B
	print(b);
	// Xoay 90 do #1
	rotate90(b);
	// In B sau khi xoay 90 do #1
	print(b);
	// Xoay 90 do #2
	rotate90(b);
	// In B sau khi xoay 90 do #2
	print(b);
}

