#include <iostream>
using namespace std;

void printGrades(int* grades, int size) {
    cout << "Grades: ";
    for (int i = 0; i < size; ++i) {
        cout << *(grades + i) << " ";
    }
    cout << "\n";
}

void updateGrade(int* grades, int index, int newGrade) {
    if (index >= 0 && index < 5 && newGrade >= 2 && newGrade <= 5) {
        *(grades + index) = newGrade;
    } else {
        cout << "Invalid index or grade!\n";
    }
}

float calculateAverage(int* grades, int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += *(grades + i);
    }
    return static_cast<float>(sum) / size;
}

void boostGrades(int* grades, int size) {
    for (int i = 0; i < size; ++i) {
        if (*(grades + i) < 4) {
            *(grades + i) = (*(grades + i) + 1) > 5 ? 5 : (*(grades + i) + 1);
        }
    }
}

void resetGrades(int* grades, int size) {
    for (int i = 0; i < size; ++i) {
        *(grades + i) = 3;
    }
}

int main() {
    const int size = 5;
    int grades[size] = {3, 4, 2, 5, 3};

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Show grades\n";
        cout << "2. Update grade\n";
        cout << "3. Calculate average\n";
        cout << "4. Boost grades below 4\n";
        cout << "5. Reset all grades to 3\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";

        int choice;
        cin >> choice;

        if (choice == 0) break;

        switch (choice) {
            case 1:
                printGrades(grades, size);
                break;
            case 2: {
                cout << "Enter grade index (0-4): ";
                int idx; cin >> idx;
                cout << "Enter new grade (2-5): ";
                int newGrade; cin >> newGrade;
                updateGrade(grades, idx, newGrade);
                break;
            }
            case 3: {
                float avg = calculateAverage(grades, size);
                cout << "Average grade: " << avg << "\n";
                break;
            }
            case 4:
                boostGrades(grades, size);
                cout << "Grades boosted!\n";
                break;
            case 5:
                resetGrades(grades, size);
                cout << "Grades reset to 3.\n";
                break;
            default:
                cout << "Invalid choice, try again.\n";
        }
    }

    cout << "Goodbye!\n";
    return 0;
}
