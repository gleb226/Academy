#include <iostream>
using namespace std;

void someFunc() {
	int a = 0;
	a++;
	cout << a << endl;
}

int main()
{
	someFunc();
	someFunc();
	someFunc();

	return 0;
}