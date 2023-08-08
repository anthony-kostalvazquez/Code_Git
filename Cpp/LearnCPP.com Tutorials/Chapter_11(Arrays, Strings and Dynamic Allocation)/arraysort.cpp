#include <iostream>
#include <algorithm>

int main()
{
    //ask how many names they wish to enter
    std::cout << "How many names would you like to enter?";

    int number_of_names{};
    std::cin >> number_of_names;

    //Dynamically allocate std::string array
    std::string* array{ new std::string[number_of_names]{}};


    //ask the user for each name
    for (int i = 0; i < number_of_names; i++)
    {
        std::cout << "Enter name #" << i << ": ";
        std::cin >> array[i];
    }
    


    //sorts names std::sort
    std::sort(array, array + number_of_names);


    //prints names in sorted order
    std::cout << "Here is your sorted list: \n";
    for (int j = 0; j < number_of_names; j++)
    {
        std::cout << "Name #" << j << ": " << array[j] << '\n';
    }
    


    delete[] array;

    return 0;
}