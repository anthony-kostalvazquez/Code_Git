// h/t to reader yellowEmu for the idea of adding a counter
#include <iostream>

int g_counter{ 0 };

void eatStack(int useless)
{
    int *doub_useless{new int};
    doub_useless = &useless;

    std::cout << ++g_counter << ' ';

    // We use a conditional here to avoid compiler warnings about infinite recursion
    if (g_counter > 0)
        eatStack(useless); // note that eatStack() calls itself

    // Needed to prevent compiler from doing tail-call optimizations
    std::cout << "hi";
}

int main()
{
    eatStack(55);

    return 0;
}