class Player
{
public:
    void Player()
    {
        health = 100;
    }

    int GetHealth()
    {
        return health;
    }

private:
    int health;
};

// What is the actual bug ?
// A. The supposed constructor has a `void` return type, which is invalid for a constructor.
// B. The class has no private fields.
// C. `GetHealth()` must be declared static.
// D. The member variable must be a string.
// E. The constructor is a vampire in a trench coat impersonating legitimate initialization.