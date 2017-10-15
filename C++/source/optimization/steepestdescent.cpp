/*
The method of steepest descent
-------------------
An algorithm for finding the nearest local minimum of a function.
It solves an equation in quadratic form: Ax = b where x is the values we seek.
A is a matrix of size NxN, and b is a vector of N values.

Time complexity
---------------
O(e^-2), where e is an error we can accept (indicates how far we are from solution).

Space complexity
----------------
O(2*N), where N is a size of matrix
*/

#include <iostream>
#include <array>
#include <math.h>
#include "steepestdescent.h"


int main()
{
    const unsigned int S = 2;
    const std::array<const std::array<double, S>, S> A = {1, -1, 1, 1};
    const std::array<double, S> b = {9, 1};
    std::array<double, S> x;


    std::cout << "Maxtrix A:\n"<< A << '\n';
    std::cout << "Vector b:\n" << b << '\n';
    x = steepestdescent(A, b, 0.0000001);
    std::cout << "Result:\n"<< x << '\n';

    return 0;
}