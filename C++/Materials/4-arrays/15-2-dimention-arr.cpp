#include<iostream>
// у цьому файлі містяться rand і srand
#include<stdlib.h>
// у цьому файлі міститься функція time
#include<time.h>
using namespace std;

int main()
{
	const int row = 3; // рядки 
	const int col = 3; // стовпці
	int mr[row][col]; // масив розміром row на col
	/* перебираємо окремі рядки (одновимірні масиви в сукупності) */
	for (int i = 0; i < row; i++)
	{
		// перебираємо окремі елементи кожного рядка 
		for (int j = 0; j < col;j++)
		{
			//ініціалізація елементів значеннями у діапазоні від 0 до 100
			mr[i][j] = rand() % 100;
			// вивід значень на екран 
			cout << mr[i][j] << " ";
		}
		/* перехід на інший рядок матриці */
		cout << "\n\n";
	}
	return 0;
}