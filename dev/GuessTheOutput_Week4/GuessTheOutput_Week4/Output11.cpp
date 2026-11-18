#include <vector>
#include <iostream>

void Output12()
{
    std::vector<int> values = { 3, 6, 9 };

    int total = 0;

    for (int value : values)
    {
        if (value > 5)
        {
            total += value;
        }
        else
        {
            total--;
        }
    }

    std::cout << total;
}

//A 14
//B 15
//C 18
//D 17
//E The vector opens a cursed abacus and prints THE VOID.