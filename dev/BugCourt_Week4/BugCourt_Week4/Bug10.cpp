#include <vector>
#include <iostream>

void Bug10()
{
    std::vector<std::string> enemies;
    if (!enemies.empty())
    {
        std::cout << "First enemy: "
            << enemies[0]
            //<< enemies.at(0)
            << '\n';

    }
    else
    {
        std::cout << "There are no enemies";
    }
}

// What is the actual bug?
// A. The empty vector automatically creates a first element.
// B. The output is always an empty string.
// C. `enemies[0]` accesses an element of an empty vector, causing undefined behavior.  - THIS ONE
// D. `std::cout` prevents out - of - range indexing.
// E. The program is interrogating a ghost who refuses to appear without a valid index warrant.