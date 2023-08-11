#include <iostream>

/*Question #1

a) Create a class called IntPair that holds two integers. This class should have two member variables to hold the integers. You should also create two member functions: one named “set” that will let you assign values to the integers, and one named “print” that will print the values of the variables.*/

class IntPair
{
public:
    int p1{};
    int p2{};

    void print()
    {
        std::cout << "Pair (" << p1 << "," << p2 << ")\n";
    }

    void set(int a, int b)
    {
        p1 = a;
        p2 = b;
    }


};





int main()
{
	IntPair p1;
	p1.set(1, 1); // set p1 values to (1, 1)

	IntPair p2 { 2, 2 }; // initialize p2 values to (2, 2)

	p1.print();
	p2.print();

	return 0;
}