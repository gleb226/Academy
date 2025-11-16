#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void generateNumbers(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100 + 1;
    }
}

bool checkGuess(int arr[], int size, int guess) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == guess) {
            return true;
        }
    }
    return false;
}

int closestNumber(int arr[], int size, int guess) {
    int closest = arr[0];
    int diff = arr[0] - guess;
    if (diff < 0) diff = -diff;

    for (int i = 1; i < size; i++) {
        int newDiff = arr[i] - guess;
        if (newDiff < 0) newDiff = -newDiff;

        if (newDiff < diff) {
            diff = newDiff;
            closest = arr[i];
        }
    }

    return closest;
}

void showResult(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int numbers[5];
    int guess;
    int tries = 7;

    srand(time(0));
    generateNumbers(numbers, 5);

    cout << "Guess the number game!" << endl;
    cout << "Correct numbers: ";
    showResult(numbers, 5);

    for (int i = 1; i <= tries; i++) {
        cout << "Try " << i << ". Enter number: ";
        cin >> guess;

        if (checkGuess(numbers, 5, guess)) {
            cout << "You guessed it! Congrats!" << endl;
            return 0;
        }

        int near = closestNumber(numbers, 5, guess);
        if (near < guess) {
            cout << "Wrong. Closest number is less than yours." << endl;
        } else {
            cout << "Wrong. Closest number is greater than yours." << endl;
        }
    }

    cout << "You didn't guess any number." << endl;
    cout << "Correct numbers: ";
    showResult(numbers, 5);

    return 0;
}
