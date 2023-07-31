#include <iostream>

namespace Monster
{
    enum MonsterType
    {
        ogre,
        dragon,
        orc,
        giant,
        spider,
        slime,
    };
} // namespace MonsterType

struct Character
{
    std::string name{};
    int health{};
    Monster::MonsterType type{};
};

void printMonster(Character &character)
{
    std::cout << "This " << character.type << " is named " << character.name << " and has " << character.health << " health.\n";
}


int main()
{
    Character c1{"Torg",145, Monster::ogre};


    printMonster(c1);

    return 0;
}