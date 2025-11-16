#include <iostream>
using namespace std;

bool isValid(const string& num) {
    if (num.length() != 4) return false;
    for (char c : num)
        if (c < '0' || c > '9') return false;
    for (int i = 0; i < 4; ++i)
        for (int j = i + 1; j < 4; ++j)
            if (num[i] == num[j])
                return false;
    return true;
}

void checkGuess(const string& secret, const string& guess, int& bulls, int& cows) {
    bulls = cows = 0;
    for (int i = 0; i < 4; ++i) {
        if (guess[i] == secret[i])
            bulls++;
        else
            for (int j = 0; j < 4; ++j)
                if (guess[i] == secret[j]) {
                    cows++;
                    break;
                }
    }
}

void play(const string& secret, int attempt = 1) {
    string guess;
    cout << "Attempt " << attempt << ". Enter your guess: ";
    cin >> guess;

    if (!isValid(guess)) {
        cout << "Invalid input. Enter 4 unique digits.\n";
        play(secret, attempt);
        return;
    }

    int bulls, cows;
    checkGuess(secret, guess, bulls, cows);

    if (bulls == 4) {
        cout << "You guessed it in " << attempt << " attempts!\n";
        return;
    }

    cout << "Bulls: " << bulls << ", Cows: " << cows << "\n";
    play(secret, attempt + 1);
}

int main() {
    string secret;
    cout << "Enter a 4-digit secret number with unique digits: ";
    cin >> secret;

    if (!isValid(secret)) {
        cout << "Invalid secret number. Exiting.\n";
        return 1;
    }

    cout << "Let the game begin!\n";
    play(secret);
    return 0;
}
