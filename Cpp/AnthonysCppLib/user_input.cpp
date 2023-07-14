#include <iostream>

//Gets a double value from the user
double getUserDouble()
{
    std::cout << "Enter a Double Value: ";
    
    double value{};
    std::cin >> value;

    return value;
}

//Gets a double value from the user
int getUserInt()
{
    std::cout << "Enter a int Value: ";
    
    int value{};
    std::cin >> value;

    return value;
}