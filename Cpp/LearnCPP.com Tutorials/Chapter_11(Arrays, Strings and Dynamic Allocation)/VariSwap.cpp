#include <iostream>

template <typename T>
void swapVari(T& var1, T& var2)
{
    T temp{var1};

    var1 = var2;
    var2 = temp;

}



int main()
{
    int a{10};
    int b{15};

    std::cout << "before swap a = " << a << " b = " << b << '\n';

    swapVari(a, b);

    std::cout << "after swap a = " << a << " b = " << b << '\n';

    return 0;
}