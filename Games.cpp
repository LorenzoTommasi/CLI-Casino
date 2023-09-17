#include <cstdlib> // For rand() function
#include "Games.h"


// Function to simulate a coinflip
int simulateCoinflip() {
	int result = rand() % 2;
	return result;
}
