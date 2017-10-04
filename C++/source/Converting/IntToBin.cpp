/*
Integer to Binary conversion algorithm
*/
#include <vector>

void IntToBin(int _integer, std::vector<char> &bin)
{
    if (!_integer)
        return;
    bin.push_back(_integer%2);
    IntToBin(_integer/2, bin);
}