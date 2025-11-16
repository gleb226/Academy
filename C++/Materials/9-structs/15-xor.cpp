#include <iostream>

using namespace std;

int main()
{
	int x, y, z, k;
	x = 5;
	y = 6;
	k = x | y; // Операція 5 | 6
	cout << k << " ";
	x = 1;
	y = 4;
	z = 6;
	k = x | y | z; // Операція 1 | 4 | 6
	cout << k << " ";
	x = 5;
	y = 6;
	k = x & y; // Операція 5 & 6
	cout << k << " ";
	x = 1;
	y = 3;
	z = 7;
	k = x & y & z; // Операція 1 & 3 & 7
	cout << k << " ";
	x = 6;
	y = 3;
	k = x ^ y; // Операція 6 ^ 3
	cout << k << " ";

	return 0;
}