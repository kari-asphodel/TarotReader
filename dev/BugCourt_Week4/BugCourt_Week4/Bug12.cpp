#include <string>

class Weapon
{
public:
    Weapon(std::string name, int damage);

    std::string GetName();
    int GetDamage();

private:
    std::string name;
    int damage;
};
// What is the actual bug ?
// A. Header declarations automatically create method definitions.
// B. The class cannot contain two getter methods.
// C. The constructor must be written entirely inside the header.
// D. The member functions are declared but lack definitions, causing link errors if used. - THIS ONE
// E. Weapon.cpp fled the kingdom, leaving the header to fight the final boss with a strongly worded declaration.