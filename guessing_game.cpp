// Task 2: Number Guessing Game
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>
using namespace std;

const int MIN_NUM = 1, MAX_NUM = 100;

int readGuess() {
    int g;
    while (true) {
        cout << "Your guess (" << MIN_NUM << "-" << MAX_NUM << "): ";
        if (cin >> g) {
            if (g >= MIN_NUM && g <= MAX_NUM) return g;
            cout << "  Out of range! Pick between " << MIN_NUM << " and " << MAX_NUM << ".\n";
        } else {
            if (cin.eof()) exit(0);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  Please enter a valid number.\n";
        }
    }
}

int calcScore(int attempts) {           // 100 points max, -10 per extra attempt after the first
    int s = 110 - attempts * 10;
    return s < 0 ? 0 : s;
}

int main() {
    srand(static_cast<unsigned>(time(0)));
    int bestAttempts = 0, gamesPlayed = 0;
    char again;
    cout << "=== NUMBER GUESSING GAME ===\n";
    do {
        int target = rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;
        int attempts = 0, guess;
        cout << "\nI'm thinking of a number between " << MIN_NUM << " and " << MAX_NUM << ".\n";
        do {
            guess = readGuess();
            attempts++;
            if (guess > target) cout << "  Too High!\n";
            else if (guess < target) cout << "  Too Low!\n";
        } while (guess != target);

        gamesPlayed++;
        if (bestAttempts == 0 || attempts < bestAttempts) bestAttempts = attempts;
        cout << "\nCorrect! The number was " << target << ".\n"
             << "Attempts: " << attempts << " | Score: " << calcScore(attempts) << "/100\n"
             << "Best (fewest attempts) so far: " << bestAttempts << " | Games played: " << gamesPlayed << "\n";

        cout << "Play again? (y/n): ";
        cin >> again;
    } while (again == 'y' || again == 'Y');
    cout << "Thanks for playing!\n";
    return 0;
}
