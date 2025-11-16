#include <iostream>  

int main()
{
	int nAge;

	while (1)
	{
		std::cout << "Enter your age: ";
		std::cin >> nAge;

		if (std::cin.fail()) // якщо ніякого вилучення не відбулося
		{
			std::cin.clear(); // то скидаємо всі поточні флаги стану і встановлюємо goodbit, щоб мати можливість використати функцію ignore()
			std::cin.ignore(32767, '\n'); // очищаємо потік від сміття
			continue; // просимо користувача ввести свій вік ще раз
		}

		std::cin.ignore(32767, '\n'); // очищаємо все сміття, яке залишилося в потоці після вилучення
		if (std::cin.gcount() > 1) // якщо ми очистили більше одного символу
			continue; // то цей ввід вважається некоректним, і ми просимо користувача ввести свій вік ще раз

		if (nAge <= 0) // переконуємося, що nAge є додатнім числом
			continue;

		break;
	}

	std::cout << "You entered: " << nAge << std::endl;
}