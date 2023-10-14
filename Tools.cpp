#include <iostream>
#include <iomanip>
#include <string>
#include "Tools.h"

using namespace std;

// Function to center-align text
void centerText(const string& text) {
    int width = 50;  
    int padding = (width - text.length()) / 2;
    cout << setw(padding + text.length()) << text << endl;
}

void displayMainMenu(int balance) {
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
}

void displayRouletteHeader(int balance) {
    cout << "--------------------------------------------------" << endl;
    centerText("Roulette");
    cout << setw(35) << "Current Balance: $" << balance << endl;
    cout << "--------------------------------------------------" << endl << endl;
}

void displayBlackjackHeader(int balance) {
    cout << "--------------------------------------------------" << endl;
    centerText("Blackjack");
    cout << setw(35) << "Current Balance: $" << balance << endl;
    cout << "--------------------------------------------------" << endl << endl;
}
