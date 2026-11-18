#include <fstream>
#include <iostream>

void Bug11()
{
	std::ifstream file("save.txt");

	std::string playerName;
	int level;

	file >> playerName;
	file >> level;

	std::cout << playerName << " Level " << level;
}
// What is the actual bug?
// A. The file is read without checking whether it opened or extraction succeeded.
// B. ifstream automatically creates a missing save file.
// C. The program is guaranteed to print Level 0.
// D. A file must always be opened with ofstream to read it.
// E. The save file has vanished into the catacombs, and the loader is reading its last will and testament.