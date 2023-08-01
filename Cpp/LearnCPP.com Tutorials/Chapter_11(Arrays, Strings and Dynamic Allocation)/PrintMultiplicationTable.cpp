#include <iostream>
#include <iterator> // for std::size
#include <limits>


int main()
{
    constexpr int numRows{ 10 };
    constexpr int numCols{ 10 };

    //calculate into an array
    int table[numRows][numCols]{};

    for (int row = 0; row < numRows; row++)
    {
        for (int col = 0; col < numCols; col++)
        {
            table[row][col] = row * col;
        }
    }

    //print the array
    for (int row = 0; row < numRows; row++)
    {
        for (int col = 0; col < numCols; col++)
        {
            std::cout << table[row][col] << "\t";
        }

        std::cout << '\n';
    }


    return 0;
}