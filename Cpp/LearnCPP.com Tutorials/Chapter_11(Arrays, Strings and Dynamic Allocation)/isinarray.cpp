#include <iostream>
#include <string>
#include <string_view>

int main()
{
    constexpr std::string_view names[]{ "Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly" };
    
    
    //get name from user
    std::cout << "Enter a name: \n";
    
    std::string lookingfor{};
    std::cin >> lookingfor;


    for(auto name: names)
    {
        if (lookingfor == name)
        {
            std::cout << name << "was found\n";
            return 0;
        }
        
    }

    //will exicute if th ename is not found
    std::cout << lookingfor << "was NOT found\n";




    return 0;
}