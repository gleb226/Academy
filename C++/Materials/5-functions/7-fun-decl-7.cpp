#include <iostream>
#include <string>
using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int main()
{
	// Значення, яке повернув 
	// return, можна записати в змінну
	int result = max(10, 30);
	cout << "Maximum is: " << result << endl;
	// Значення, яке повернув
	// return, можна відразу вивести на екран
	cout << "Maximum is: " << max(42, 2);
	return 0;
}
