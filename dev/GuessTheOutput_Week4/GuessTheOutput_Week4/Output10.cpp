#include <iostream>

void Output10()
{
    int score = 85;

    if (score >= 70)
    {
        std::cout << "Pass ";
    }

    if (score >= 80)
    {
        std::cout << "Great ";
    }

    if (score >= 90)
    {
        std::cout << "Excellent";
    }
}
//A Pass
//B Great
//C Pass Great - THIS ONE
//D Excellent
//E The three independent if statements form a coven and print HEX HEX HEX.