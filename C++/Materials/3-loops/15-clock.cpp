#include <iostream>
using namespace std;

int main() {
	int sum = 0;
	for (int bom = 1; bom <= 12; bom++)
	{
		sum += bom; // накопичення суми ударів
	}
	// Годинник пробив 78 разів.
	cout << " Hours have punched " << sum
		<< " times.\n\n";
	return 0;
}