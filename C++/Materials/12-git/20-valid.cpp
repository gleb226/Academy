#include <iostream>  
#include <cctype>
#include <string>  

int main()
{
	while (1)
	{
		// ѕросимо користувача ввести своЇ ≥м'€
		std::cout << "Enter your name: ";
		std::string strName;
		std::getline(std::cin, strName); // вилучаЇмо ц≥лий р€док, включаючи проб≥ли

		bool bRejected = false;

		// ѕеребираЇмо кожний символ р€дка до тих п≥р, поки не д≥йдемо до к≥нц€ р€дка або до в≥дхиленн€ символу
		for (unsigned int nIndex = 0; nIndex < strName.length() && !bRejected; ++nIndex)
		{
			// якщо поточний символ Ї буквою, то все ок
			if (isalpha(strName[nIndex]))
				continue;

			// якщо проб≥л, то також ок
			if (strName[nIndex] == ' ')
				continue;

			// ¬ протилежному випадку, в≥дхил€Їмо весь користувацький вв≥д
			bRejected = true;
		}

		// якщо користувацький вв≥д був прийн€тий, то ми виходимо з циклу while, ≥ програма завершуЇ своЇ виконанн€.
		// ¬ протилежному випадку, ми просимо користувача ввести своЇ ≥м'€ ще раз
		if (!bRejected)
			break;
	}
}