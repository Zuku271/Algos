/*
Integer to Bin binary conversion algorithm
-------------------
Integer to Bin binary conversion algorithm

Time complexity
---------------
O(logN), where N is converted integer   

Space complexity
----------------
O(logN), where <description of variable(s)>
*/
#include <vector>
#include <iostream>

char IntToBin(int integer)
{
    if (!integer)
        return 0;
    std::cout << integer%2 << '\n';
    IntToBin(integer/2);
}

int main()
{
    int a = 25;
    IntToBin(a);
    
    return 0;
}