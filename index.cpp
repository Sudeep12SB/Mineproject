%%writefile MIN.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>  // Include this header for numeric_limits

using namespace std;

void showChoices() {
    cout << "Choose one:\n";
    cout << "1. Rock\n";
    cout << "2. Paper\n";
    cout << "3. Scissors\n";
}

string getChoiceName(int choice) {
    switch (choice) {
        case 1: return "Rock";
        case 2: return "Paper";
        case 3: return "Scissors";
        default: return "Invalid";
    }
}

void decideWinner(int userChoice, int computerChoice) {
    if (userChoice == computerChoice) {
        cout << "It's a tie!\n";
    } else if ((userChoice == 1 && computerChoice == 3) || 
               (userChoice == 2 && computerChoice == 1) || 
               (userChoice == 3 && computerChoice == 2)) {
        cout << "You win!\n";
    } else {
        cout << "Computer wins!\n";
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));  // Seed for random number

    int userChoice, computerChoice;
    char playAgain;

    do {
        showChoices();
        
        cout << "Enter your choice (1-3): ";
        cin >> userChoice;

        // Check for invalid input
        if (cin.fail()) {
            cin.clear();  // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore invalid input
            cout << "Invalid input! Please enter a number between 1 and 3.\n";
            continue;
        }

        if (userChoice < 1 || userChoice > 3) {
            cout << "Invalid choice! Please enter 1, 2, or 3.\n";
            continue;
        }

        computerChoice = rand() % 3 + 1;  // Random choice between 1 and 3

        cout << "You chose: " << getChoiceName(userChoice) << endl;
        cout << "Computer chose: " << getChoiceName(computerChoice) << endl;

        decideWinner(userChoice, computerChoice);

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}
