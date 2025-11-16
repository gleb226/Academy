#include <iostream>
#include <fstream>
#include <cstdlib> // для використання функції exit()

int main()
{
	using namespace std;

	// Ми повинні вказати як in, так і out, оскільки використовуємо fstream
	fstream iofile("SomeText.txt", ios::in | ios::out);

	// Якщо ми не можемо відкрити iofile,
	if (!iofile)
	{
		// то виводимо повідомлення про помилку і виконуємо функцію exit()
		cerr << "Uh oh, SomeText.txt could not be opened!" << endl;
		exit(1);
	}

	char chChar;

	// Поки є дані для обробки
	while (iofile.get(chChar))
	{
		switch (chChar)
		{
			// Якщо ми знайшли голосну букву,
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':

			// то переміщаємося на один символ назад відносно поточного розташування файлового вказівника
			iofile.seekg(-1, ios::cur);

			// Оскільки ми виконали операцію пошуку, то тепер можемо переключитися на запис даних в файл.
			// Замінимо знайдену голосну букву символом #
			iofile << '#';

			// Тепер нам потрібно повернутися назад в режим читання файлу.
			// Виконуємо функцію seekg() до поточної позиції
			iofile.seekg(iofile.tellg(), ios::beg);

			break;
		}
	}

	return 0;
}