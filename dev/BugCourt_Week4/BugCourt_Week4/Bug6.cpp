#include <iostream>

void Bug6()
{
    int choice;
    std::string input;
    std::cout << "Enter a number: ";
    std::cin >> input;

    try
    {
        choice = std::stoi(input);
    }
    catch (...)
    {
        std::cout << "Invalid choice, try again: ";
    }

    while (choice < 1 || choice > 4)
    {
        std::cout << "Invalid choice. Try again: ";
        std::cin >> choice;
    }
}
// What's the actual bug?
// A.`std::cin` converts any word into an integer.
// B. The loop exits safely when a word is entered.
// C. Non - numeric input makes `std::cin` fail; the code does not handle that state.  - THIS ONE
// D. The range check automatically clears invalid input.
// E. The word banana has seized the input stream and declared itself supreme ruler of all menus.