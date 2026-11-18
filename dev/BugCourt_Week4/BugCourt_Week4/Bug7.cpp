bool IsAlive(int health)
{
    if (health > 0)
    {
        return true;      
    }
}
// What is the actual bug?
// A. The function does not return a `bool` when `health <= 0`.
// B. The function always returns `false` for zero health.
// C. `bool` functions cannot contain `if` statements.
// D. The function must be declared `void` to return `true`.
// E. The function returned to the void to consult an oracle who only answers in ominous shrugs.