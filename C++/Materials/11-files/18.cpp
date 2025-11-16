#include <iostream>
#include <cstdlib> // для використання функції exit()
#include <fstream>

int main()
{
	using namespace std;

	// Передаємо флаг ios:app, щоб повідомити fstream, що ми збираємося додати свої дані до вже існуючих даних файлу.
	// Ми не збираємося перезаписувати файл.
	// Нам не потрібно передавати флаг ios::out, оскільки ofstream за замовчуванням працює в режимі ios::out
	ofstream outf("SomeText.txt", ios::app);

	// Якщо ми не можемо відкрити файл для запису даних,
	if (!outf)
	{
		// то виводимо наступне повідомлення про помилку і виконуємо функцію exit()
		cerr << "Uh oh, SomeText.txt could not be opened for writing!" << endl;
		exit(1);
	}

	outf << "See line #3!" << endl;
	outf << "See line #4!" << endl;

	return 0;

	// Коли outf вийде з області видимості, то деструктор класу ofstream автоматично закриє наш файл
}