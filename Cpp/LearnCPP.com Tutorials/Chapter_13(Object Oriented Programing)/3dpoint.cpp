#include <iostream>

/*
Write a simple class named Point3d. The class should contain:

Three private member variables of type int named m_x, m_y, and m_z;
A public member function named setValues() that allows you to set values for m_x, m_y, and m_z.
A public member function named print() that prints the Point in the following format: <m_x, m_y, m_z>
*/

class Point3d
{
private:
    int m_x{};
    int m_y{};
    int m_z{};

public:
    void print()
    {
        std::cout << "<" << m_x << "," << m_y << "," << m_z << ">\n";
    }

    void setValues(int a, int b, int c)
    {
        m_x = a;
        m_y = b;
        m_z = c;
    }


};




int main()
{
    Point3d point;
    point.setValues(1, 2, 3);

    point.print();
    std::cout << '\n';

    return 0;
}