/*Ask the user for a number between 1 and 9. If the user does not enter a number between 1 and 9, repeatedly ask for an integer value until they do. If the user enters a number followed by extraneous input, ignore the extraneous input. Once they have entered a number between 1 and 9, print the array. Then search the array for the value that the user entered and print the index of that element.*/

#include <iostream>
#include <iterator> // for std::size
#include <limits>


//Returns the index of where the value is
//RETURNS -1 if it is not found
int arraySearch(const int array[], int size, int valueToFind)
{
    for (int i{0}; i < size; i++)
    {
        if (array[i] == valueToFind)
        {
            return(i);
        }
        
    }
    


    return(-1);
}

int main()
{
    constexpr int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };

    //get user input (has to be between 1 and 9)
    int userInput{};
    do
    {
        std::cout << "Enter a number between 1 and 9: \n";
        std::cin >> userInput; 

        if (std::cin.fail())
        {
            std::cin.clear(); // reset any error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any characters in the input buffer
        }


    } while (userInput != 1 && userInput != 2 && userInput != 3 && userInput != 4 && userInput != 5 && userInput != 6 && userInput != 7 && userInput != 8 && userInput != 9);


    //find out if its in the array
    std::cout << "The Number " << userInput << " has index " << arraySearch(array, sizeof(array)/sizeof(array[0]), userInput);



    return 0;
}