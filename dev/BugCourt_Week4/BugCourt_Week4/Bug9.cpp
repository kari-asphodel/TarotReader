#include <vector>
#include <string>
class Inventory
{
public:
    void AddItem(std::string item)
    {
        items.push_back(item);
    }

private:
    std::vector<std::string> items;
};

// What's the actual bug?
// A. Vectors cannot store strings.
// B. The code refers to `items`, but the declared member is `Items`.  - THIS ONE
// C. `AddItem()` must return an integer.
// D. Private members cannot be used by class methods.
// E. The uppercase I has staged a coup and exiled its lowercase twin to the crypt.