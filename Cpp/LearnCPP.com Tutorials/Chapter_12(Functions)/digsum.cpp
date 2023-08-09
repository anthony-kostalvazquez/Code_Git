/*Write a recursive function that takes an integer as input and returns the sum of each individual digit in the integer (e.g. 357 = 3 + 5 + 7 = 15). Print the answer for input 93427 (which is 25). Assume the input values are positive.*/
#include <iostream>
#include <vector>

int digitSum(int n)
{
    if (n < 10)
    {
        return 0;
    }
    
    return digitSum(n / 10) % 10;

}


int main()
{
    digitSum(34567);

    return 0;
}