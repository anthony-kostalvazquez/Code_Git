#include <iostream>
#include "io.h"



int main()
{
    //get user input
    int in1{ readNumber() };
    int in2{ readNumber() };

    //output the integer
    writeAnswer(in1 + in2);


    return 0;
}