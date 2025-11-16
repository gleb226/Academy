#include <iostream>

#define SQR(X) ((X) * (X))
#define CUBE(X) (SQR(X)*(X))
#define ABS(X) (((X) < 0)? -(X) : X)

using namespace std;

int main()
{
	int y;
	int t = 10;
	y = SQR(t + 8) — CUBE(t - 8);
	cout << sqrt(ABS(y));
	return 0;
}