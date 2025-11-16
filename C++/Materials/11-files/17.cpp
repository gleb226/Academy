#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // для використання функції exit()

int main()
{
	using namespace std;

	// ifstream використовується для читання вмісту файла.
	// Спробуємо прочитати вміст файлу SomeText.txt
	ifstream inf("SomeText.txt");

	// Якщо ми не можемо відкрити цей файл для читання його вмісту,
	if (!inf)
	{
		// то виводимо наступне повідомлення про помилку і виконуємо функцію exit()
		cerr << "Uh oh, SomeText.txt could not be opened for reading!" << endl;
		exit(1);
	}

	// Поки є дані, які ми можемо прочитати,
	while(inf)
	{
		// то переміщуємо ці дані в рядок, який потім виводимо на екран
		string strInput;
		inf >> strInput;
		cout << strInput << endl;
	}

	return 0;

	// Коли inf вийде з області видимості, то деструктор класу ifstream автоматично закриє наш файл
}