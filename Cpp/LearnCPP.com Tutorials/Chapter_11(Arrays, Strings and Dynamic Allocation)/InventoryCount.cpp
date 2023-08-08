/*Pretend you’re writing a game where the player can hold 3 types of items: health potions, torches, and arrows. Create an enum to identify the different types of items, and a std::array to store the number of each item the player is carrying (the enumerators are used as indexes of the array). The player should start with 2 health potions, 5 torches, and 10 arrows. Write a function called countTotalItems() that returns how many items the player has in total. Have your main() function print the output of countTotalItems() as well as the number of torches.*/

#include <algorithm> // std::shuffle
#include <array>
#include <iostream>
#include <numeric> // std::reduce

enum inventory
{
    health_potions = 0,
    torches = 1,
    arrows = 2,
};

int countTotalItems(std::array<int, 3> inventory_array)
{

    return std::reduce(inventory_array.begin(), inventory_array.end());
}


int main()
{
    //starts player out with 2 health pots, 5 torches and 10 arrows
    std::array<int,3> inventory_array{2,5,10};

    //prints out sun and number of torches
    std::cout << "you have " << countTotalItems(inventory_array) << " items total\n";
    std::cout << "you have " << inventory_array[torches] << " torches\n";


    return 0;
}