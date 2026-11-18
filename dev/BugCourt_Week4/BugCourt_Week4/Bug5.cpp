#include <fstream>
void SavePlayer(std::string name, int level)
{
    std::ofstream file("player.txt");

    file << name << '\n';
    file << level << '\n';
}

void SaveScore(int score)
{
    std::ofstream file("player.txt");

    file << score << '\n';
}
// What's the actual bug?
// A. The second function appends to the original save automatically.
// B. Opening `player.txt` again with `std::ofstream` truncates the earlier save.
// C. The first function cannot write a string to a file.
// D. The two functions write to different files.
// E. The file goblin ate the player data and left behind one suspiciously smug score.