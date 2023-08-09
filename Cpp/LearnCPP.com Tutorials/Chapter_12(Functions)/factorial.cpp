#include <iostream>
#include <vector>


int factorial(int n)
{
    static std::vector<int> fac_mem{0, 1};

    if (n < static_cast<int>(fac_mem.size()))
    {
        return fac_mem[n];
    }
    

    fac_mem.push_back(fac_mem[n-1] * n);
    return fac_mem[n];
}


int main()
{
    for (int i{0}; i < 7; i++)
    {
        std::cout << i << "! = " << factorial(i) << '\n'; 
    }
    


    return 0;
}