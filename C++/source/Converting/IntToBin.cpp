/*
Integer to Binary conversion algorithm
*/
#include <vector>
#include <iostream>

void IntToBin(int _integer, std::vector<char> &bin)
{
    if (!_integer)
        return;
    bin.push_back(_integer%2);
    IntToBin(_integer/2, bin);
}

int main()
{
    std::vector<char> temp;
    int a = 10;
    IntToBin(a, temp);

    std::cout << temp[0]+0x30 << '\n';

    return 0;
}