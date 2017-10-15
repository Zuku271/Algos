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

template <unsigned int S>
double norm(const std::array<double, S> &x, const std::array<double, S> &y)
{
    double result = 0;
    for (unsigned int i=0; i<S; ++i)
    {
        result += (x[i] - y[i])*(x[i] - y[i]);
    }
    return sqrt(result);
}

template <unsigned int S>
std::array<double, S> steepestdescent(const std::array<const std::array<double, S>, S> &A, const std::array<double, S> &b,
    const double e = 0.00001, const double step = 0.1, const unsigned int IterMax = 1000000)
{
    std::array<double, S> x = {0.0};
    unsigned int k = 0;

    do
    {
        std::array<double, S> xp = x;
        std::array<double, S> residual = b - A * xp;
        x = x + step * residual;
        if (norm(x, xp) < e)
            break;
        k += 1;
    }
    while (k < IterMax);

    return x;
}

template <unsigned int S>
std::ostream &operator<<(std::ostream &stream, const std::array<const std::array<double, S>, S> &A)
{
    for (std::array<double, S> tmp : A)
    {
        for (double i : tmp)
        {
            stream << i << '\t';
        }
        stream << '\n';
    }
    return stream;
}

template <unsigned int S>
std::ostream &operator<<(std::ostream &stream, const std::array<double, S> &x)
{
    for (double i : x)
    {
        stream << i << '\n';
    }
    return stream;
}

template <unsigned int S>
std::array<double, S> operator*(const std::array<const std::array<double, S>, S> &A, const std::array<double, S> &b)
{
    std::array<double, S> result = {0.0};

    for (unsigned int i = 0; i < S; ++i)
    {
        for (unsigned int j = 0; j < S; ++j)
        {
            result[i] += A[i][j] * b[j];
        }
    }

    return result;
}

template <unsigned int S>
std::array<double, S> operator+(const std::array<double, S> &x, const std::array<double, S> &y)
{
    std::array<double, S> result;

    for (unsigned int i = 0; i < S; ++i)
    {
        result[i] = x[i] + y[i];
    }
    return result;
}

template <unsigned int S>
std::array<double, S> operator-(const std::array<double, S> &x, const std::array<double, S> &y)
{
    std::array<double, S> result;

    for (unsigned int i = 0; i < S; ++i)
    {
        result[i] = x[i] - y[i];
    }
    return result;
}

template <unsigned int S>
std::array<double, S> operator*(const double x, const std::array<double, S> &y)
{
    std::array<double, S> result;

    for (unsigned int i = 0; i < S; ++i)
    {
        result[i] = x * y[i];
    }
    return result;
}

int main()
{
    const unsigned int S = 2;
    const std::array<const std::array<double, S>, S> A = {1, -1, 1, 1};
    const std::array<double, S> b = {9, 1};
    std::array<double, S> x;



    return 0;
}