#include <iostream>
#include <string>
#include<time.h>
using namespace std;

// відображення матриці 
void showMatrix(int matr[][3], int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << matr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

/* ініціалізуємо матрицю всередині функції випадковими
 числами на відміну від звичайних змінних, зміни
 елементів масиву, що відбуваються всередині
 функції, при виході з функції зберігаються
*/
void initMatrix(int matr[][3], int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			matr[i][j] = rand() % 10;
		}
	}
	cout << endl;
}

int main()
{
	srand(time(NULL));

	const int mRows = 3;
	const int mCols = 3;

	int iMatr[mRows][mCols];
	initMatrix(iMatr, mRows, mCols);
	showMatrix(iMatr, mRows, mCols);

	return 0;
}