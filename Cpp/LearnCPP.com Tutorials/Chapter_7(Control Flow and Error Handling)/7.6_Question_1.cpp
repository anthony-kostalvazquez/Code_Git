#include <iostream>

//Gets a double value from the user
int getUserint()
{
    std::cout << "Enter an int Value: ";
    
    int value{};
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



/*Write a function called calculate() that takes two integers and a char representing one of the following mathematical operations: +, -, *, /, or % (remainder). Use a switch statement to perform the appropriate mathematical operation on the integers, and return the result. If an invalid operator is passed into the function, the function should print an error message. For the division operator, do an integer division.*/
int main()
{
    //gets input from the user
    int in1{getUserint()};
    int in2{getUserint()};

    //User then chooses mathmatical symbol +, -, *, or /
    std::cout << "Enter one of the following: +, -, *, /, or %: ";
    char mathSymbol{getUserChar()};

    //We then calculate and return the result
    int calculatedValue{};
    switch (mathSymbol)
    {
        case '+':
            calculatedValue = in1 + in2;
            break;
        case '-':
            calculatedValue = in1 - in2;
            break;
        case '*':
            calculatedValue = in1 * in2;
            break;
        case '/':
            calculatedValue = in1 / in2;
            break;
        case '%':
            calculatedValue = in1 % in2;
            break;
        default:
            std::cout << "you did not enter a correct operator!!!!!" << '\n';
            return 1;
            break;

    }

    std::cout << in1 << mathSymbol << in2 << " is " << calculatedValue << '\n'; 



    return 0;
}