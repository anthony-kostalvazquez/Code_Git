#include <iostream>

int main()
{
    int count{0};
    char charater{'a'};

    while(count < 26)
    {
        std::cout << charater << " = " << static_cast<int>(charater) << '\n';
        ++charater;
        ++count;
    }

    




    return 0;
}