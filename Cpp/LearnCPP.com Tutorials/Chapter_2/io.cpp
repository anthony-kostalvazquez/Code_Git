#include <iostream>
#include "io.h"

//returns the intger entered into the consol by the user
int readNumber()
{
    std::cout << "Enter An Integer" << '\n';

    int input{};
    std::cin >> input;

    return input;
}

//prints out the integer its given
void writeAnswer(int answer)
{
    std::cout << "The Answer is : " << answer << '\n';
}