#include <iostream>

void LevelUp(Player& player)
{
    player.SetLevel(player.GetLevel() + 1);
}

void Bug8()
{
    Player hero;

    LevelUp(hero);

    std::cout << hero.GetLevel();
}
// What's the actual bug?
// A. The original object is modified because it is passed by value.
// B. The `SetLevel()` call cannot change any object.
// C. `GetLevel()` automatically returns a reference to the hero.
// D. `Player` is passed by value, so only a copy levels up.  - THIS ONE
// E. The hero gained a level in an alternate timeline and their original self is suing for experience points.