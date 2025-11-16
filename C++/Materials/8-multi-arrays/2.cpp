#include <iostream>
using namespace std;

int main()
{
	int i, j;
	// «м≥нн≥ дл€ опису характеристик масив≥в. 
	// m1 Ч к≥льк≥сть р€дк≥в, m2 Ч к≥льк≥сть стовпц≥в
	int m1, m2;
	cout << "How many rows:\n";
	cin >> m1;
	int** pArr = new int* [m1];
	for (i = 0; i < m1; i++)
	{
		cout << "How many cells in the row-" << i << "?\n";
		cin >> m2;
		pArr[i] = new int[m2];
		// заповненн€ р€дка двовим≥рного динам≥чного масиву даними та вив≥д
		for (j = 0; j < m2; j++)
		{
			pArr[i][j] = i * j;
			cout << pArr[i][j] << " ";
		}
		cout << "\n";
	}
	// ѕосл≥довне знищенн€ двовим≥рного масиву... 
	for (i = 0; i < m1; i++)
	{
		delete[]pArr[i];
	}
	delete[]pArr;
	return 0;
}
