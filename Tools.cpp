#include <iostream>
#include <iomanip>
#include <string>
#include "tools.h"

using namespace std;

// Function to center-align text
void centerText(const string& text) {
    int width = 50;  
    int padding = (width - text.length()) / 2;
    cout << setw(padding + text.length()) << text << endl;
}
