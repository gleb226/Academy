#include <iostream>
using namespace std;

void someFunc() {
	/*
	 Змінна створюється при першому виклику функції
	 Після виходу з функції вона не знищується
	 і зберігає своє значення
	 */
	static int a = 0;
	a++;
	cout << a << endl;
}

int main()
{
	// 1
	someFunc();
	// 2
	someFunc();
	// 3
	someFunc();
	return 0;
}