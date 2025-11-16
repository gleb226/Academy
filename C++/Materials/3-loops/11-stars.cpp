#include <iostream> 
using namespace std;

int main() {
	const int COUNT = 5; // кількість зірочок (довжина лінії)
	int i = 0; // керуюча змінна циклу

	while (i <= COUNT) { // перевірка умови
		cout << "*"; // вивід зірочки
		i++; // зміна керуючої змінної
	}

	cout << "\n\n";

	return 0;
}