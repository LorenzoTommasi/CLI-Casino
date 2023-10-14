#include <iostream>
#include <iomanip>
#include <string>
#include "Tools.h"
#include "Games.h"
using namespace std;

const int INITIAL_BALANCE = 1000;

int main() {
    bool quit = false;
    int balance = INITIAL_BALANCE;

    while (!quit) {

        displayMainMenu(balance);
        int choice;
        cin >> choice;

        switch (choice) {
        case 1: // Coinflip
            playCoinflip(balance);
            break;

        case 2: // Blackjack
            playBlackjack(balance);
            break;

        case 3: // Roulette
            playRoulette(balance);
            break;

        case 4: // Exit
            quit = true; 
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
            }
        }

        // Exit
        cout << endl << "Thanks for playing at Lorenzo's Grand Casino!" << endl;
        return 0;
}
