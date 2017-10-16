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
#include <vector>
#include <math.h>

double norm(const std::vector<double> &x, const std::vector<double> &y)
{
    double result = 0;
    for (unsigned int i=0; i<x.size(); ++i)
    {
        result += (x[i] - y[i])*(x[i] - y[i]);
    }
    return sqrt(result);
}

std::ostream &operator<<(std::ostream &stream, const std::vector<std::vector<double>> &A)
{
    for (std::vector<double> tmp : A)
    {
        for (double i : tmp)
        {
            stream << i << '\t';
        }
        stream << '\n';
    }
    return stream;
}

std::ostream &operator<<(std::ostream &stream, const std::vector<double> &x)
{
    for (double i : x)
    {
        stream << i << '\n';
    }
    return stream;
}

std::vector<double> operator*(const std::vector<std::vector<double>> &A, const std::vector<double> &b)
{
    const size_t sizeOfA = A.size();
    std::vector<double> result(sizeOfA, 0.0);

    for (unsigned int i = 0; i < sizeOfA; ++i)
    {
        for (unsigned int j = 0; j < b.size(); ++j)
        {
            result[i] += A[i][j] * b[j];
        }
    }

    return result;
}

std::vector<double> operator+(const std::vector<double> &x, const std::vector<double> &y)
{
    const size_t sizeOfx = x.size();
    std::vector<double> result(sizeOfx, 0.0);    

    for (unsigned int i = 0; i < sizeOfx; ++i)
    {
        result[i] = x[i] + y[i];
    }
    return result;
}

std::vector<double> operator-(const std::vector<double> &x, const std::vector<double> &y)
{
    const size_t sizeOfx = x.size();
    std::vector<double> result(sizeOfx, 0.0);  

    for (unsigned int i = 0; i < sizeOfx; ++i)
    {
        result[i] = x[i] - y[i];
    }
    return result;
}

std::vector<double> operator*(const double x, const std::vector<double> &y)
{
    const size_t sizeOfy = y.size();
    std::vector<double> result(sizeOfy, 0.0);

    for (unsigned int i = 0; i < sizeOfy; ++i)
    {
        result[i] = x * y[i];
    }
    return result;
}

std::vector<double> steepestdescent(const std::vector<std::vector<double>> &A, const std::vector<double> &b,
    const double e = 0.00001, const double step = 0.1, const unsigned int IterMax = 1000000)
{
    std::vector<double> x(b.size(), 0.0);
    unsigned int k = 0;

    do
    {
        std::vector<double> xp = x;
        std::vector<double> residual = b - A * xp;
        x = x + step * residual;
        if (norm(x, xp) < e)
            break;
        k += 1;
    }
    while (k < IterMax);

    return x;
}

int main()
{
    const std::vector<std::vector<double>> A = {{1, -1}, {1, 1}};
    const std::vector<double> b = {9, 1};
    std::vector<double> x;

    x = steepestdescent(A, b);

    std::cout << A << '\n';
    std::cout << b << '\n';
    std::cout << x << '\n';

    return 0;
}