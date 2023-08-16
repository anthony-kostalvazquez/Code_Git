#include <iostream>
#include <cmath>

class Point2d
{
private:
    /* data */
    double m_x{};
    double m_y{};

public:
    //constuctor
    Point2d(double x = 0.0, double y = 0.0): m_x{x}, m_y{y}
    {
    }
    
    
    //destructor
    //~Point2d();

    //functions
    void print()
    {
        std::cout << "Point2d(" << m_x << "," <<  m_y << ")\n"; 
    }

    double distanceTo(Point2d otherpoint)
    {
        double x1{this->m_x};
        double y1{this->m_y};

        double x2{otherpoint.m_x};
        double y2{otherpoint.m_y};

        return(std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
    }
};



int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };
    first.print();
    second.print();
    std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';

    return 0;
}
