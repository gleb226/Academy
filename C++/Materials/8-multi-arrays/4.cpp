#include <iostream>

using namespace std;

int main()
{
	// m1 Ч к≥льк≥сть р€дк≥в (висота), 
	// m2 Ч к≥льк≥сть стовпц≥в (ширина), m3 Ч глибина
	int m1 = 5, m2 = 3, m3 = 2;
	int i, j;
	// покажчик на покажчик на покажчик :)
	int*** pXArr = new int** [m1];

	// ќрган≥зац≥€ тривим≥рного динам≥чного масиву
	for (i = 0; i < m1; i++)
	{
		pXArr[i] = new int* [m2];
		for (j = 0; j < m2; j++)
		{
			pXArr[i][j] = new int[m3];
		}
	}
	// ƒоступ до елемент≥в масиву 
	pXArr[1][2][3] = 750;
	cout << pXArr[1][2][3] << "\n";
	// ¬идаленн€ в посл≥довност≥, зворотн≥й створенню 
	for (i = 0; i < m1; i++)
	{
		for (j = 0; j < m2; j++)
		{
			delete[]pXArr[i][j];
		}
		delete[]pXArr[i];
	}
	delete[] pXArr;
	return 0;
}
