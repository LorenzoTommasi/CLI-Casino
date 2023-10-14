#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <ctime>
#include "Games.h"
#include "Tools.h"

using namespace std;

// Function to simulate a coinflip
int simulateCoinflip() {
	int result = rand() % 2;
	return result;
}

void playCoinflip(int& balance) {
    system("cls");
    while (true) {
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
}

int spinRouletteWheel() {
    return rand() % 37; 
}

string spinRouletteWheelColor() {
    int randomNumber = rand() % 38; // Generate a random number between 0 and 37

    if (randomNumber == 0) {
        return "green"; // Represents 0
    }
    else if (randomNumber % 2 == 0) {
        return "red";
    }
    else {
        return "black";
    }
}


void playRoulette(int& balance) {
    system("cls");
    while (true) {

        int chosenNumber;

        displayRouletteHeader(balance);

        int bet;
        cout << "Enter Bet Amount (0 to quit): $";
        cin >> bet;

        if (bet == 0) {
            break; // Return to the main menu
        }
        else if (bet <= balance) {
            balance -= bet; // Deducts bet from balance;
        }
        else if (bet > balance) {
            cout << "Insufficient Funds. Please try again" << endl << endl;
            cin.ignore();
            cout << "Enter Bet Amount (0 to quit): $";
            cin.get();
            break;
        }
        system("cls");
        displayRouletteHeader(balance);

        cout << "Available Bets:" << endl << endl;
        cout << "1. Bet on Number" << endl;
        cout << "2. Bet on Color" << endl << endl;
        cout << "Enter Your Choice: ";

        int betChoice;
        cin >> betChoice;

        system("cls");
        displayRouletteHeader(balance);

        if (betChoice == 1) {
            // Bet on number
            cout << "Enter the number you want to bet on (0-36): ";
            cin >> chosenNumber;

            if (chosenNumber < 0 || chosenNumber > 36) {
                cout << "Invalid number. Must be between 0 - 36." << endl << endl;
                cin.ignore();
                cout << "Enter the number you want to bet on (0-36): ";
                cin.get();
                break;
            }

            int spinResult = spinRouletteWheel();
            if (spinResult == chosenNumber) {
                cout << endl << "You Win! +$" << bet << endl;
                balance += bet * 36;
            }
            else {
                cout << endl << "You lose! -$" << bet << endl;
            }

            cout << endl << "Press any key to continue...";
            cin.get();
            cin.get(); 

            system("cls");
        }
        else if (betChoice == 2) {
            // Bet on color
            cout << "Choose a color (1 - Red | 2 - Black | 3 - Green): ";
            int colorChoice;
            string chosenColor;
            cin >> colorChoice;

            if (colorChoice == 1) {
                chosenColor = "red";
            }
            else if (colorChoice == 2) {
                chosenColor = "black";
            }
            else if (colorChoice == 3) {
                chosenColor = "green";
            }
            else {
                cout << "Invalid choice. Please try again." << endl;
                cin.ignore();
                cout << "Choose a color (1 - Red | 2 - Black | 3 - Green): ";
                cin.get();
                break;
            }

            string spinResult = spinRouletteWheelColor();
            if (spinResult == chosenColor) {
                cout << endl << "You Win! +$" << bet << endl;
                if (chosenColor == "green") {
                    // Adjust the payout for green
                    balance += bet * 36; 
                }
                else {
                    balance += bet * 2;
                }
            }
            else {
                cout << endl << "You lose! -$" << bet << endl;
            }

            cout << endl << "Press any key to continue...";
            cin.get();
            cin.get();

            system("cls");
        }
                
    }
}

// Function to shuffle a deck of cards
void shuffleDeck(int deck[], int deckSize) {
    for (int i = 0; i < deckSize; i++) {
        int j = rand() % deckSize;
        swap(deck[i], deck[j]);
    }
}

// Function to deal a card from the deck
int dealCard(int deck[], int& deckIndex) {
    return deck[deckIndex++];
}

// Function to calculate the total value of a hand
int calculateHandValue(const int hand[], int handSize) {
    int value = 0;
    int numAces = 0;

    for (int i = 0; i < handSize; i++) {
        int cardValue = hand[i] % 13 + 1;
        if (cardValue > 10) {
            value += 10; // Face cards have a value of 10
        }
        else if (cardValue == 1) {
            value += 11; // Ace can be 11 or 1, start with 11
            numAces++;
        }
        else {
            value += cardValue;
        }
    }

    while (value > 21 && numAces > 0) {
        value -= 10; // Convert an Ace from 11 to 1 if needed
        numAces--;
    }

    return value;
}

// Function to display a hand
void displayHand(const int hand[], int handSize) {
    for (int i = 0; i < handSize; i++) {
        int cardValue = hand[i] % 13 + 1;
        string cardName;

        if (cardValue == 1) cardName = "Ace";
        else if (cardValue == 11) cardName = "Jack";
        else if (cardValue == 12) cardName = "Queen";
        else if (cardValue == 13) cardName = "King";
        else cardName = to_string(cardValue);

        string suit;

        switch (hand[i] / 13) {
        case 0: suit = "Hearts"; break;
        case 1: suit = "Diamonds"; break;
        case 2: suit = "Clubs"; break;
        case 3: suit = "Spades"; break;
        }

        cout << cardName << " of " << suit << endl;
    }
}

// Function to play the blackjack game
void playBlackjack(int& balance) {
    int deck[52];
    int deckIndex = 0;
    int playerHand[10];
    int dealerHand[10];
    int playerHandSize = 0;
    int dealerHandSize = 0;

    // Initialize the deck
    for (int i = 0; i < 52; i++) {
        deck[i] = i;
    }

    // Shuffle the deck
    shuffleDeck(deck, 52);

    int bet = 0;
    bool betPlaced = false;

    // Get the bet amount
    while (!betPlaced) {
        system("cls");
        displayBlackjackHeader(balance); // Display the header
        cout << "Enter Bet Amount (0 to quit): $";
        cin >> bet;

        if (bet == 0) {
            break; // Return to the main menu
        }
        else if (bet <= balance) {
            balance -= bet; // Deducts bet from balance;
            betPlaced = true;
        }
        else {
            cout << "Insufficient Funds. Please try again" << endl << endl;
            cin.ignore();
            cout << "Press any key to continue...";
            cin.get();
        }
    }

    // Deal two cards to the player
    playerHand[playerHandSize++] = dealCard(deck, deckIndex);
    playerHand[playerHandSize++] = dealCard(deck, deckIndex);

    // Deal one card face up to the dealer
    dealerHand[dealerHandSize++] = dealCard(deck, deckIndex);

    // Display the initial hands
    system("cls");
    displayBlackjackHeader(balance); 
    cout << "Player's Hand:" << endl;
    displayHand(playerHand, playerHandSize);
    cout << "Total Value: " << calculateHandValue(playerHand, playerHandSize) << endl << endl;

    cout << "Dealer's Hand:" << endl;
    cout << "Face-up card:" << endl;
    displayHand(dealerHand, 1);
    cout << endl;

    // Player's turn
    int playerValue = 0;
    // Player's turn
    bool playerTurnOver = false;
    while (!playerTurnOver) {
        cout << "Choose your action (1 - Hit | 2 - Stand): ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            // Hit
            playerHand[playerHandSize++] = dealCard(deck, deckIndex);
            cout << "Player's Hand:" << endl;
            displayHand(playerHand, playerHandSize);
            playerValue = calculateHandValue(playerHand, playerHandSize);
            cout << "Total Value: " << playerValue << endl << endl;

            if (playerValue > 21) {
                cout << "Bust! You lose." << endl;
                balance -= bet; // Deduct the bet
                playerTurnOver = true; // End the player's turn
            }
        }
        else if (choice == 2) {
            // Stand
            playerTurnOver = true; // End the player's turn
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }


    // Dealer's turn
    while (true) {
        cout << "Dealer's Hand:" << endl;
        displayHand(dealerHand, dealerHandSize);
        int dealerValue = calculateHandValue(dealerHand, dealerHandSize);
        cout << "Total Value: " << dealerValue << endl << endl;

        if (dealerValue >= 17) {
            // Dealer stands
            if (dealerValue > playerValue || playerValue > 21) {
                cout << "Dealer wins!" << endl;
                balance -= bet; // Deduct the bet
            }
            else if (dealerValue < playerValue) {
                cout << "Player wins!" << endl;
                balance += bet; // Add the bet
            }
            else {
                cout << "It's a tie!" << endl;
            }

            break;
        }
        else {
            dealerHand[dealerHandSize++] = dealCard(deck, deckIndex);
        }
    }
}
