#include <iostream>
#include <string>

enum MonsterType {
    ogre,
    goblin,
    skeleton,
    orc,
    troll
};

struct Monster {
    MonsterType type;
    std::string name;
    int health;
};

void printMonster(const Monster &monster) {
    std::string typeName;

    if (monster.type == ogre) typeName = "Ogre";
    else if (monster.type == goblin) typeName = "Goblin";
    else if (monster.type == skeleton) typeName = "Skeleton";
    else if (monster.type == orc) typeName = "Orc";
    else if (monster.type == troll) typeName = "Troll";

    std::cout << "This " << typeName << " is named " << monster.name
            << " and has " << monster.health << " health.\n";
}

int main() {
    Monster m1 = {goblin, "John", 170};
    Monster m2 = {orc, "James", 35};

    printMonster(m1);
    printMonster(m2);

    return 0;
}
