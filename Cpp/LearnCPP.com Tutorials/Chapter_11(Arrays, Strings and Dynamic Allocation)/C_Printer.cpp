#include <iostream>




int main()
{
    char c_string[] = {"Hello, World"};

    for (char *i = c_string; *i != '\0'; i++)
    {
        std::cout << *i;
    }
    
    



    return 0;
}