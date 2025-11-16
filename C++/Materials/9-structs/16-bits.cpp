#include <iostream>

using namespace std;

int main()
{
	int y = 02, x = 03, z = 01, k;
	k = x | y & z; // Операція 1
	cout << k << " ";
	k = x | y & ~z; // Операція 2
	cout << k << " ";
	k = x ^ y & ~z; // Операція 3
	cout << k << " ";
	k = x & y && z; // Операція 4
	cout << k << " ";

	x = 1;
	y = -1;
	k = !x | x; // Операції 5 
	cout << k << " ";
	k = -x | x; // Операції 6 
	cout << k << " ";
	k = x ^ x; // Операції 7 
	cout << k << " ";
	x <<= 3; // Операції 8 
	cout << x << " ";
	y <<= 3; // Операції 9 
	cout << y << " ";
	y >>= 3; // Операції 10 
	cout << y << " ";

	return 0;
}