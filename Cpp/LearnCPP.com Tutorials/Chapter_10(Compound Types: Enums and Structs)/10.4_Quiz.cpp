#include <iostream>

enum class Animal
{
    pig,
    chicken,
    goat,
    cat,
    dog,
    duck,
};

std::string_view getAnimalName(Animal in_name)
{

    switch (in_name)
    {
    case Animal::pig: return "pig";
    case Animal::chicken: return "chicken";
    case Animal::goat: return "goat";
    case Animal::cat: return "cat";
    case Animal::dog: return "dog";
    case Animal::duck: return "duck";
    default: return "No Match Found";
    }
}

void printNumberOfLegs(Animal in_name)
{
    std::cout << "A " << getAnimalName(in_name) << " has ";

    switch (in_name)
    {
    case Animal::pig: 
        std::cout << "4";
        break; 
    case Animal::chicken:  
        std::cout << "2";
        break; 
    case Animal::goat:
        std::cout << "4";
        break; 
    case Animal::cat:
        std::cout << "4";
        break; 
    case Animal::dog:
        std::cout << "4";
        break; 
    case Animal::duck:
        std::cout << "2";
        break; 
    default:
        std::cout << "UNKOWN";
        break; 
    }

    std::cout << " legs.\n";

}




int main()
{
    printNumberOfLegs(Animal::cat);
    printNumberOfLegs(Animal::chicken);

    return 0;
}