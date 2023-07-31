#ifndef TRIAD_H
#define TRIAD_H

#include <iostream>


template <typename T>
struct Triad
{
    T x{};
    T y{};
    T z{};
};

template <typename T>
void print(const Triad<T> triad_in)
{
	std::cout << "[" << triad_in.x << triad_in.y << triad_in.z << "]\n";

}



#endif