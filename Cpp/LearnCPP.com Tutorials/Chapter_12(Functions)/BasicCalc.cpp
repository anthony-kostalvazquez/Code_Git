#include <iostream>
#include <functional>



//returns validated int from user
int getInt()
{
    int in_int{};

    std::cout << "Please Enter an integer ";
    std::cin >> in_int;
    

    return in_int;


}

//will return an operator char of (‘+’, ‘-‘, ‘*’, ‘/’) from user
char getOperator()
{
    char opp{};
    do
    {
        std::cout << "Please Enter an operator (+, -, *, /)";
        std::cin >> opp;


    } while (opp != '+' && opp != '-' && opp != '*'  && opp != '/');
    

    return opp;
}

//1b) Write functions named add(), subtract(), multiply(), and divide(). These should take two integer parameters and return an integer.
int add(int a, int b)
{
    return(a + b);
}

int multiply(int a, int b)
{
    return(a * b);
}


int divide(int a, int b)
{
    return(a / b);
}


int subtract(int a, int b)
{
    return(a - b);
}

//1c) Create a type alias named ArithmeticFunction for a pointer to a function that takes two integer parameters and returns an integer. Use std::function, and include the appropriate header.

using ArithmeticFunction = std::function<int(int, int)>;



//1d) Write a function named getArithmeticFunction() that takes an operator character and returns the appropriate function as a function pointer.
ArithmeticFunction getArithmeticFunction(char opp)
{
    switch (opp)
    {
    case '+':
        return ArithmeticFunction(add);
        break;
    
    case '-':
        return ArithmeticFunction(subtract);
        break;
    
    case '/':
        return ArithmeticFunction(divide);
        break;
    
    case '*':
        return ArithmeticFunction(multiply);
        break;
    }

    return nullptr;

}







//1a) Create a short program asking the user for two integer inputs and a mathematical operation (‘+’, ‘-‘, ‘*’, ‘/’). Ensure the user enters a valid operation.
int main()
{
    //get operator
    char opp{getOperator()};

    //get two integers
    int in_int1{getInt()};
    int in_int2{getInt()};

    //call getarthfcn
    ArithmeticFunction arith_fun = getArithmeticFunction(opp);
    std::cout << arith_fun(in_int1, in_int2 );




    return 0;
}