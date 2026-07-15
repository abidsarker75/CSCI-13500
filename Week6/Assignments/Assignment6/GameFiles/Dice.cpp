#include "Dice.h"
#include <cstdlib>
#include <ctime>
 
// TODO: Implement rollDice().
// - Should return a random integer between 1 and 6, inclusive.
// - Think carefully about where to seed the random number generator.
//   If you seed it INSIDE this function, what happens every time it's called?

// This will keep track of whether the random number generator has seeded.
bool dice_seeded = false;

// This will roll a random number between 1 to 6.
int RollDice() {
    // Only seeds the random number generator once.
    if (dice_seeded == false) {
        std::srand(std::time(nullptr));
        dice_seeded = true;
    }
    return (std::rand() % 6) + 1;
}