/*
Integer to Binary conversion algorithm
*/
#include <vector>

std::vector<char> IntToBin(int integer)
{
    std::vector<char> tmp;
    while (!integer)
    {
        tmp.push_back(integer%2);
        integer /= 2;
    }
    return tmp;
}