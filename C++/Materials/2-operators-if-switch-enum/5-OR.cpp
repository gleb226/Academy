#include <iostream>
using namespace std;

int main()
{
	int N;
	cout << "Enter your number:\n";
	cin >> N;

	cout << ((N < 1) || (N > 10));

	cout << "\n\nIf you see 0, your number is in the range\n\n";
	cout << "\n\nIf you see 1, your number is out of the range\n\n";

	return 0;
}