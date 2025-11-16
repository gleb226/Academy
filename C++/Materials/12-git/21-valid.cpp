#include <iostream>  
#include <string>  

bool InputMatches(std::string strUserInput, std::string strTemplate)
{
	if (strTemplate.length() != strUserInput.length())
		return false;

	// Перебираємо кожний символ користувацького вводу
	for (unsigned int nIndex = 0; nIndex < strTemplate.length(); nIndex++)
	{
		switch (strTemplate[nIndex])
		{
		case '#': // = цифра
			if (!isdigit(strUserInput[nIndex]))
				return false;
			break;
		case '_': // = пробіл
			if (!isspace(strUserInput[nIndex]))
				return false;
			break;
		case '@': // = буква
			if (!isalpha(strUserInput[nIndex]))
				return false;
			break;
		case '?': // = взагалі будь-який символ
			break;
		default: // = точний збіг з символом
			if (strUserInput[nIndex] != strTemplate[nIndex])
				return false;
		}
	}

	return true;
}

int main()
{
	std::string strValue;

	while (1)
	{
		std::cout << "Enter a phone number (###) ###-####: ";
		std::getline(std::cin, strValue); // вилучаємо цілий рядок, включаючи пробіли
		if (InputMatches(strValue, "(###) ###-####"))
			break;
	}

	std::cout << "You entered: " << strValue << std::endl;
}