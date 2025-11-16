#include <iostream>
#include <fstream>
#include <cstdlib> // для використання функції exit()

int main()
{
	using namespace std;

	// Клас ofstream використовується для запису даних в файл.
	// Створюємо файл SomeText.txt
	ofstream outf("SomeText.txt");

	// Якщо ми не можемо відкрити цей файл для запису даних,
	if (!outf)
	{
		// то виводимо повідомлення про помилку і виконуємо функцію exit()
		cerr << "Uh oh, SomeText.txt could not be opened for writing!" << endl;
		exit(1);
	}

	// Записуємо в файл наступні два рядки
	outf << "See line #1!" << endl;
	outf << "See line #2!" << endl;

	return 0;

	// Коли outf вийде з області видимості, то деструктор класу ofstream автоматично закриє наш файл
}