#include <iostream> 
using namespace std;
int main()
{
	// Ласкаво просимо. Три випробування честі. Лихий маг викрав принцесу і її доля у твоїх руках. 
	// Він пропонує тобі пройти 3 випробування честі в його лабіринті. 
	cout << "Welcome. Three Tests of Honor. A beautiful princess was spirited off by a wicked magician,\n\n";
	cout << "\nand her fate is in your hands now. He proposed you\n";
	cout << "\nto pass Three Tests of Honor in his maze.\n";

	bool goldTaken, diamondsTaken, killByDragon;
	// Ти входиш у першу кімнату, тут дуже багато золота.
	cout << "You enter the first room with lots of gold scattered all over the place.\n\n";
	// Ти візьмеш його?
	cout << "Will you take it?(1-yes, 0-no)\n\n";
	cin >> goldTaken;

	if (goldTaken) // якщо візьмеш,
	{ 
		// золото залишається тобі, але ти провалив випробування. ГРУ ЗАКІНЧЕНО!!! 
		cout << "The gold is yours, but you have failed the test. GAME OVER\n\n";
	}
	else // якщо ні,
	{
		// Вітаю! Ти пройшов перше випробування честі!
		cout << "Congratulations! You have passed the First Test of Honor!\n\n";
		// Ти переходиш до наступної кімнати. Вона сповнена діамантів
		cout << "You enter the next room. It is full of diamonds \n\n";
		// Ти візьмеш діаманти? 
		cout << "Will you take the diamonds? (1-yes,0-no)\n\n";
		cin >> diamondsTaken;
		
		if (diamondsTaken)// якщо візьмеш
		{
			// Діаманти залишаються тобі, але ти провалив друге випробування 
			cout << "The diamonds are yours, but you have failed the Second Test \n\n";
			// ГРУ ЗАКІНЧЕНО!!!
			cout << "GAME OVER\n\n";
		}
		else // якщо ні
		{
			// Вітаю, ти пройшов друге випробування честі!!!
			cout << "Congratulations! You have passed the Second Test of Honor!\n\n";
			// Ти входиш у третю кімнату.
			cout << "You enter the third room. \n\n";
			// На селянина напав дракон!
			// Рухатися далі,
			cout << "A peasant is attacked by a dragon! Move along \n\n";
			// не звертаючи на них уваги 
			cout << "and ignore them (1-yes,0-no)?\n\n";
			cin >> killByDragon;
			if (killByDragon)// якщо так
			{
				// Ти намагаєшся прослизнути повз, але дракон
				cout << "You try to sneak past them, but the dragon \n\n";
				// помічає тебе. 
				cout << "notices you\n\n";
				// Він перетворює тебе на попіл. 
				// Ти мертвий!!! 
				cout << "It burns you to ashes. You died!\n\n";
				// ГРУ ЗАКІНЧЕНО!!!
				cout << "GAME OVER\n\n";
			}
			else// якщо ні
			{
				// Вітаю, ти з честю пройшов усі
				// випробування!!!
				cout << "Congratulations! You have passed all Tests of Honor! \n\n";

				// Принцеса дістається тобі!!! 
				cout << "You get the princess!\n\n";
			}
		}
	}

	return 0;
}