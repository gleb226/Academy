#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // для використання функції exit()

int main()
{
	using namespace std;

	ifstream inf("SomeText.txt");

	// Якщо ми не можемо відкрити файл для читання його вмісту,
	if (!inf)
	{
		// то виводимо повідомлення про помилку і виконуємо функцію exit()
		cerr << "Uh oh, SomeText.txt could not be opened for reading!" << endl;
		exit(1);
	}

	string strData;

	inf.seekg(6); // переміщаємося до 6-го символу першого рядка
	// Отримуємо решту рядка і виводимо на екран
	getline(inf, strData);
	cout << strData << endl;

	inf.seekg(9, ios::cur); // переміщаємося вперед на 9 байтів відносно поточного розташування файлового вказівника
	// Отримуємо решту рядка і виводимо на екран
	getline(inf, strData);
	cout << strData << endl;

	inf.seekg(-14, ios::end); // переміщаємося на 14 байтів назад відносно кінця файлу
	// Отримуємо решту рядка і виводимо на екран
	getline(inf, strData);
	cout << strData << endl;

	return 0;
}