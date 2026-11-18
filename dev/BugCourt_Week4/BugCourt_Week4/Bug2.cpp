#include <iostream>
#include <vector>

void Bug2()
{
    std::vector<std::string> monsters =
    {
        "Goblin",
        "Skeleton",
        "Vampire"
    };

    for (int i = 0; i < monsters.size(); i++)
    {
        std::cout << monsters[i] << '\n';
    }
}

// What is the actual bug?
// A. The vector contains four elements.
// B. The code only prints the first monster.
// C. The loop uses `< = monsters.size()`, accessing an index beyond the vector.  - THIS ONE
// D. The loop never starts because `size()` is zero.
// E. A fourth monster has been summoned from the forbidden index dimension and demands dental insurance.