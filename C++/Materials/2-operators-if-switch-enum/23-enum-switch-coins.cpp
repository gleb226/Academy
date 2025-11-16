#include <iostream> 
using namespace std;

int main() {
	// Оголошення перерахування монет США
	enum coins {
		penny = 1, nickel = 5, dime = 10,
		quarter = 25, half = 50,
		large_dollar = 100
	};
	// Оголошення змінної для монети 
	int coin;
	cout << "Please enter the value of an American coin" << endl;
	cin >> coin;
	switch (coin) {
	case penny:
		// Виводимо на екран, що пенні відповідає одному центу
		cout << "penny = 1 cent " << endl;
		// Доповнюємо вивід описом монети
		// На одній стороні є Авраам Лінкольн,а Меморіал Лінкольна — на іншій. 
		cout << "The obverse depicts Abraham Lincoln, and the reverse pictures the Lincoln Memorial." << endl;
		break;
	case nickel:
		// Виводимо на екран, що нікель відповідає 5 центам
		cout << "nickel = 5 cents" << endl;
		// Доповнюємо вивід описом монети
		// На лицьовій стороні монети зображений Томас Джефферсон, і Монтічелло на  зворотному боці. 
		cout << "The obverse depicts Thomas Jefferson, and the reverse pictures Monticello."<< endl;
		break;
	case dime:
		// Виводимо на екран, що дайм 
		// відповідає 10 центам
		cout << "dime = 10 cents" << endl;
		// Доповнюємо вивід описом монети
		// На лицьовій стороні монети зображений Франклін Д. Рузвельт, і факел на зворотному боці
		cout << "The obverse depicts Franklin D. Roosevelt and the reverse pictures a torch oak and olive branches." << endl;
		break;
	case quarter:
		// Виводимо на екран, що 1/4 долара
		// складає 25 центів
		cout << "quater = 25 cents" << endl;
		// Доповнюємо вивід описом монети
		// На лицьовій стороні монети зображений Джордж Вашингтон, і на зворотному боці - або емблема Сполучених Штатів, 
		// або дизайн одного з 50 штатів
		cout << "The obverse depicts George Washington, and the reverse pictures either America the Beautiful Quarters or State Quarter Series." << endl;
		break;
	case half:
		// Виводимо на екран, що 1/2 долара
		// складає 50 центів
		cout << "half = 50 cents " << endl;
		// Доповнюємо вивід описом монети
		// На лицьовій стороні монети зображений Джон Ф. Кеннеді, а на зворотному боці - велика печатка США.
		cout << "The obverse depicts John F. Kennedyand the reverse pictures the Seal of the President of the United States." << endl;
		break;
	case large_dollar:
		// Виводимо на екран, що 1 доларова монета
		// становить 100 центів
		cout << "large dollar = 100 cents" << endl;
		// Доповнюємо вивід описом монети
		// На ній зображена рідна американська героїня Сакаджавея на лицьовій стороні і білоголовий орлан — на зворотній.
		cout << "The obverse depicts Sacagawea, who is now an American symbol, and the reverse pictures a bald eagle." << endl;
		break;
	default:
		cout << "not found" << endl;
	}
	return 0;
}