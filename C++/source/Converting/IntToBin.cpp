/*
Integer to Binary conversion algorithm
*/
#include <vector>
#include <iostream>

std::vector<char> IntToBin(int integer)
{
    std::vector<char> tmp;
    while (integer)
    {
        tmp.push_back(integer%2);
        integer /= 2;
    }
    return tmp;
}

int main()
{
    int a = 255;
    std::vector<char> temp = IntToBin(a);
    
    for (char i : temp)
    {
        std::cout << (char) i + 0x00 << '\n';
    }

    return 0;
}