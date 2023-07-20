#include <iostream>

//Gets an int value from the user
int getUserint()
{
    std::cout << "Enter an int Value for FizzBuzz: ";
    
    int value{};
    std::cin >> value;

    return value;
}


int main()
{
    int input{ getUserint() };

    for (int i{1}; i <= input; i++)
    {
        if(i % 3 == 0)
        {
            std::cout << "Fizz";
        }
        if (i % 5 == 0)
        {
            std::cout << "Buzz";
        }
        else
        {
            std::cout << i;
        }
        
        std::cout << '\n';

    }
    
    




    return 0;
}