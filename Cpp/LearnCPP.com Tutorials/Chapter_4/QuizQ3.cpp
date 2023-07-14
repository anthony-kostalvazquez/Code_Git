#include <iostream>

//Gets a double value from the user
double getUserDouble()
{
    std::cout << "Enter a Double Value: ";
    
    double value{};
    std::cin >> value;

    return value;
}

//Gets a Char value from the user
char getUserChar()
{
    std::cout << "Enter a Char Value: ";
    
    char value{};
    std::cin >> value;


    return value;
}



/*The user is asked to enter 2 floating point numbers (use doubles). The user is then asked to enter one of the following mathematical symbols: +, -, *, or /. 
The program computes the answer on the two numbers the user entered and prints the results. If the user enters an invalid symbol, the program should print nothing.*/
int main()
{
    //gets input from the user
    double in1{getUserDouble()};
    double in2{getUserDouble()};

    //User then chooses mathmatical symbol +, -, *, or /
    std::cout << "Enter one of the following: +, -, *, or /: ";
    char mathSymbol{getUserChar()};

    //We then calculate and return the result
    double calculatedValue{};
    if(mathSymbol == '+')
    {
        calculatedValue = in1 + in2;
    }
    else if(mathSymbol == '-')
    {
        calculatedValue = in1 - in2;
    }
    else if(mathSymbol == '*')
    {
        calculatedValue = in1 * in2;
    }
    else if(mathSymbol == '/')
    {
        calculatedValue = in1 / in2;
    }
    else
    {
        std::cout << "you did not enter a correct operator!!!!!" << '\n';
        return 1;
    }

    std::cout << in1 << mathSymbol << in2 << " is " << calculatedValue << '\n'; 



    return 0;
}