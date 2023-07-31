#include <iostream>

namespace Monster
{
    enum MonsterType
    {
        orcs,
        goblin,
        trolls,
        ogres,
        skeletons,
    };
} // namespace MonsterType


int main()
{

    Monster::MonsterType monster{Monster::trolls};

    return 0;
}