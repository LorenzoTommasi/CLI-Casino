#include <iostream>
#include <iomanip>
#include "Tools.h"
#include "Games.h"
using namespace std;

int main() {
    bool quit = false;
    int balance = 1000; // Player's balance of $1000


    while (!quit) {
        // Display the main menu
        system("cls");
        cout << "--------------------------------------------------" << endl;
        centerText("Welcome to Lorenzo's Command Line Casino!");
        centerText("Developed by Lorenzo Tommasi");
        cout << "--------------------------------------------------" << endl << endl;
        cout << "Current Balance: $" << balance << endl << endl;
        cout << "What Game Would You Like to Play?" << endl << endl;
        cout << "1. Coinflip" << endl;
        cout << "2. Blackjack" << endl;
        cout << "3. Roulette" << endl;
        cout << "4. Close Application" << endl << endl;
        cout << "Enter Your Choice: ";

        int choice;
        cin >> choice;

        // Process user's choice
        switch (choice) {
        case 1:
            system("cls");
            while (true) {
                // Display the Coinflip game
                
                cout << "--------------------------------------------------" << endl;
                centerText("Coinflip");
                cout << setw(35) << "Current Balance: $" << balance << endl;
                cout << "--------------------------------------------------" << endl << endl;
                int bet;
                cout << "Enter Bet Amount (0 to quit): $";
                cin >> bet;

                if (bet == 0) {
                    break; // Exit the inner loop and return to the main menu
                }
                else if (bet <= balance) {
                    balance -= bet; // Deducts bet from balance;

                    // Coinflip begins
                    int coinResult = simulateCoinflip();
                    int playerChoice;
                    cout << "Choose your side (0 - Heads | 1 - Tails): ";
                    cin >> playerChoice;

                    if (playerChoice == coinResult) {
                        // Player wins
                        cout << endl << "You Win! +$" << bet << endl;
                        balance += 2 * bet;
                    }
                    else {
                        // Player loses
                        cout << endl << "You lose! -$" << bet << endl;
                    }

                    // Wait for the user to press any key to continue
                    cout << endl << "Press any key to continue...";
                    cin.get();
                    cin.get(); // Use two cin.get() calls to wait for the user to press any key

                    system("cls");
                }
                else {
                    cout << "Invalid bet. You don't have enough money." << endl;
                }
            }
            break;

        case 2:
            // Blackjack
            break;

        case 3:
            // Roulette
            break;

        case 4:
            quit = true; // Exit
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
