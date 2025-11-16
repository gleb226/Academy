// примітивна гра для малюків
#include <iostream>
using namespace std;

int main()
{
	int buddies; // кількість піратів до битви
	int afterFight; // кількість піратів після битви

	// Ви пірат. Скільки людей у вашій команді, якщо не брати до уваги вас?
	cout << "You are a pirate. How many people are there in your squad, excluding you?\n\n";
	cin >> buddies;

	// Раптово на вас нападає 10 мушкетерів
	cout << "Suddenly you are attacked by 10 musketeers \n\n";
	// 10 мушкетерів і 10 піратів гинуть у сутичці.
	cout << "10 musketeers and 10 pirates are killed in the fight.\n\n";
	// підрахунок тих, хто залишився в живих
	afterFight = 1 + buddies - 10;
	// Залишилося лише ... піратів
	cout << "There are only " << afterFight << " pirates left\n\n";
	// Стан убитих налічує 107 золотих монет
	cout << "The killed ones have a total of 107 gold coins \n\n";
	// Це по ... монет на кожного
	cout << "Which is " << (107 / afterFight) << "coins per person";
	// Пірати влаштовують велику бійку через
	cout << "Pirates put up a big fight because of the remained\n\n";
	// ... монет, що залишилися
	cout << (107 % afterFight) << "coins \n\n";

	return 0;
}
