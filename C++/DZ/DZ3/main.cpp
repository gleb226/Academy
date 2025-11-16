#include <iostream>
using namespace std;

int main() {
    char surnames[20][31];
    float grades[20];
    int numStudents;

    cout << "How many students in the group (max. 20)? ";
    cin >> numStudents;

    if (numStudents <= 0 || numStudents > 20) {
        cout << "Invalid number of students. Please enter a number between 1 and 20." << endl;
        return 1;
    }

    for (int i = 0; i < numStudents; i++) {
        cout << "\nEnter surname of student " << i + 1 << ": ";
        cin >> surnames[i];

        cout << "Enter grade: ";
        cin >> grades[i];

        while (grades[i] < 0 || grades[i] > 12) {
            cout << "Grade must be between 0 and 12. Enter again: ";
            cin >> grades[i];
        }
    }

    cout << "\n--- All students ---" << endl;
    for (int i = 0; i < numStudents; i++) {
        cout << i + 1 << ". " << surnames[i] << " - " << grades[i] << endl;
    }

    int bestStudentIndex = 0;
    for (int i = 1; i < numStudents; i++) {
        if (grades[i] > grades[bestStudentIndex]) {
            bestStudentIndex = i;
        }
    }

    cout << "\n--- Best student ---" << endl;
    cout << surnames[bestStudentIndex] << " - " << grades[bestStudentIndex] << endl;

    float sum = 0;
    for (int i = 0; i < numStudents; i++) {
        sum += grades[i];
    }
    float average = sum / numStudents;

    cout << "\n--- Below average ---" << endl;
    for (int i = 0; i < numStudents; i++) {
        if (grades[i] < average) {
            cout << surnames[i] << " - " << grades[i] << endl;
        }
    }

    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = 0; j < numStudents - i - 1; j++) {
            if (grades[j] < grades[j + 1]) {
                float tempGrade = grades[j];
                grades[j] = grades[j + 1];
                grades[j + 1] = tempGrade;

                char tempSurname[31];
                for (int k = 0; k < 31; k++) {
                    tempSurname[k] = surnames[j][k];
                }
                for (int k = 0; k < 31; k++) {
                    surnames[j][k] = surnames[j + 1][k];
                }
                for (int k = 0; k < 31; k++) {
                    surnames[j + 1][k] = tempSurname[k];
                }
            }
        }
    }

    cout << "\n--- Sorted by grade ---" << endl;
    for (int i = 0; i < numStudents; i++) {
        cout << i + 1 << ". " << surnames[i] << " - " << grades[i] << endl;
    }

    return 0;
}
