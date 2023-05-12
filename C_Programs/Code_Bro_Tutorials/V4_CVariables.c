#include <stdio.h>

int main(){
    
    // variable =   Allocated space in memory to store a value.
    //              We refer to a variable's name to access the stored value.
    //              That variable now behaves as if it was the value it contains.
    //              BUT we need to declare what type of data we are storing.

    //Creating a variable is done in two steps
    //Declaration and Initialization
    //Look up c data types for a full list of these

    int x; //declaration
    x = 123; //initialization
    int y = 321; //Declaration + initialization

    int age = 22; //integer
    float gpa = 3.80; //floating point integer
    char grade = 'A'; //single character
    char name[] = "Anthony"; //an array of characters (basically a string)
    
    printf("Hello %s\n",name);
    printf("You are %d years old\n",age);
    printf("Your average age is %c\n", grade);
    printf("Your gpa is %f",gpa);

    return 0;
}