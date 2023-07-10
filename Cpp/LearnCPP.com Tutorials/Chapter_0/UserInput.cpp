#include <iostream>

int main()
{
    std::cout << "Enter a number"; 

    int x{};
    std::cin >> x;

    std::cout << "You Entered: " << x << '\n';

    return 0;
}