#include <iostream>
#include <string>

// Визначаємо класс enum з типами монстрів
enum class MonsterType
{
	OGRE,
	GOBLIN,
	SKELETON,
	ORC,
	TROLL
};

// Наша структура представляє одного монстра
struct Monster
{
	MonsterType type;
	std::string name;
	int health;
};

// Повертаємо тип монстра у вигляді рядка
std::string getMonsterTypeString(Monster monster)
{
	if (monster.type == MonsterType::OGRE)
		return "Ogre";
	if (monster.type == MonsterType::GOBLIN)
		return "Goblin";
	if (monster.type == MonsterType::SKELETON)
		return "Skeleton";
	if (monster.type == MonsterType::ORC)
		return "Orc";
	if (monster.type == MonsterType::TROLL)
		return "Troll";

	return "Unknown";
}

// Виводимо інформацію про монстра
void printMonster(Monster monster)
{
	std::cout << "This " << getMonsterTypeString(monster);
	std::cout << " is named " << monster.name << " and has " << monster.health << " health.\n";
}

int main()
{
	Monster goblin = { MonsterType::GOBLIN, "John", 170 };
	Monster orc = { MonsterType::ORC, "James", 35 };

	printMonster(goblin);
	printMonster(orc);

	return 0;
}