class Enemy
{
public:
    Enemy()
    {
        health = 100;
    }

    void TakeDamage(int damage)
    {
        int health = health - damage;
    }

    int GetHealth()
    {
        return health;
    }

private:
    int health;
};
// What is the actual bug?
// A. The constructor always sets health to zero.
// B. `TakeDamage()` is never allowed to take parameters.
// C. The damage value is added to the member health.
// D. A local `health` variable shadows the member, so the member is not reduced.
// E. The enemy has purchased the deluxe immortality package from the Necromancer Health Network.