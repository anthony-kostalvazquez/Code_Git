#include <iostream>
#include <cassert>


/*The class should be named Stack, and should contain:

A private array of integers of length 10.
A private integer to keep track of the size of the stack.
A public member function named reset() that sets the size to 0.
A public member function named push() that pushes a value on the stack. push() should return false if the array is already full, and true otherwise.
A public member function named pop() that pops a value off the stack and returns it. If there are no values on the stack, the code should exit via an assert.
A public member function named print() that prints all the values in the stack.*/


class Stack
{
private:
    int array[10]{}; 
    int size{};

public:
    //A public member function named reset() that sets the size to 0.
    void reset()
    {
        size = 0;
    }

    //A public member function named push() that pushes a value on the stack. push() should return false if the array is already full, and true otherwise.
    bool push(int a)
    {
        if (size > 9)
        {
            std::cout << "The stack is full \n";
            return false;
        }

        array[size] = a;
        size++;

        return true;
        
    }

    //A public member function named pop() that pops a value off the stack and returns it. If there are no values on the stack, the code should exit via an assert.
    int pop()
    {
        assert(size > 0);
        int ret_val = array[size];
        array[size] = 0;
        size--;
        return ret_val;
    }

    //A public member function named print() that prints all the values in the stack.
    void print()
    {
        std::cout << "(";
        for (int i = 0; i < size; i++)
        {
            std::cout << array[i] << " "; 
        }
        std::cout << ")";


    }


};





int main()
{
	Stack stack;
	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();

	return 0;
}