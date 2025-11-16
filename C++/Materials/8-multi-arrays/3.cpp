#include <iostream>
using namespace std;

int main()
{
	// m1 Ч к≥льк≥сть р€дк≥в, m2 Ч к≥льк≥сть стовпц≥в
	int m1 = 5, m2 = 5;
	int i, j, k;
	int** pXArr = new int* [m1];
	k = m2;
	// ќрган≥зац≥€ двовим≥рного динам≥чного масиву
	for (i = 0; i < m1; i++, k--)
	{
		pXArr[i] = new int[k];
	}
	for (i = 0; i < m1; i++, m2--)
	{
		for (j = 0; j < m2; j++)
		{
			// заповненн€ р€дка двовим≥рного 
			// динам≥чного масиву даними та вив≥д
			pXArr[i][j] = 5;
			cout << pXArr[i][j] << " ";
		}
		cout << "\n";
	}

	// ѕосл≥довне знищенн€ двовим≥рного масиву...
	for (i = 0; i < m1; i++)
	{
		delete[]pXArr[i];
	}

	delete[]pXArr;
	return 0;
}