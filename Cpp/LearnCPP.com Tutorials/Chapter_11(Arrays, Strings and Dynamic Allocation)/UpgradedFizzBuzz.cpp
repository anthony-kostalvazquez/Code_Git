#include <iostream>
#include <iterator> // for std::size
#include <string_view>
#include <limits>




int main()
{
    int divisors[]{3,5,7,11,13,17,19};
    std::string_view words[]{ "fizz", "buzz", "pop", "bang", "jazz", "pow", "boom"};
    
    //this will make the program not compile if the size of divisors or words dont match
    static_assert(std::size(divisors) == std::size(words), "Not Enough Words or Divisors");

    //take user input
    int userInput{};
    do
    {
        std::cin.clear(); // reset any error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any characters in the input buffer

        std::cout << "Enter a number between 1 and 9: \n";
        std::cin >> userInput; 

    } while (std::cin.fail());



    //print out the fizzbuzz
    bool is_divisable{};
    for (int current_number = 0; current_number < userInput; current_number++)//iterate the number of times the user inputs
    {
        is_divisable = false;

        //check divisibility and prints word if so
        for (int divisor_index = 0; divisor_index < std::size(divisors); divisor_index++)
        {
            if (current_number % divisors[divisor_index] == 0)
            {
                std::cout << words[divisor_index];
                is_divisable = true;
            }
            
        }

        if (!is_divisable)
        {
            std::cout << current_number;
        }
        
        //always print a new line here
        std::cout << '\n';

    }
    


    return 0;
}

