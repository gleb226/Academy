#include <iostream>
using namespace std;

int main() {
	// кількість якісних деталей
	int amount = 0;
	// цикл для перебору 4 деталей
	for (int d = 1; d <= 4; d++)
	{
		// сумарний час виготовлення деталі
		int alltime = 0;
		// змінна для зберігання часу на верстаті
		int time = 0;
		// запитуємо час на першому верстаті 
		cout << "How much time the first machine spends for " << d << " part\n";
		cin >> time;
		alltime += time;
		// перевіряємо, чи не перевищено ліміт часу
		if (alltime > 120)
		{
			cout << "That part is defective. The time limit exceeded\n";
			continue;
		}
		// запитуємо час на другому верстаті
		cout << "How much time the second machine spends for " << d << " part\n";
		cin >> time;
		alltime += time;
		// перевіряємо, чи не перевищено ліміт часу
		if (alltime > 120)
		{
			cout << "That part is defective. The time limit exceeded\n";
			continue;
		}
		// якщо час не було превищено на обох верстатах, збільшуємо кількість правильно виготовленої деталі 
		amount++;
	}
	cout << "\nThe factory manufactured " << amount << " parts\n\n";

	return 0;
}