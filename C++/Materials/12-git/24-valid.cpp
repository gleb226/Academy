#include <iostream>  
#include <sstream> // для stringstream

int main()
{
	int nAge;

	while (1)
	{
		std::cout << "Enter your age: ";
		std::string strAge;
		std::cin >> strAge;

		// Переконуємося, що кожний символ є цифрою
		bool bValid = true;
		for (unsigned int nIndex = 0; nIndex < strAge.length(); nIndex++)
			if (!isdigit(strAge[nIndex]))
			{
				bValid = false;
				break;
			}
		if (!bValid)
			continue;

		// На даний момент у нас є щось, що ми можемо конвертувати в число,
		// тому ми використовуємо stringstream для виконання конвертації
		std::stringstream strStream;
		strStream << strAge;
		strStream >> nAge;

		if (nAge <= 0) // переконуємося, що nAge є додатнім числом
			continue;

		break;
	}

	std::cout << "You entered: " << nAge << std::endl;
}