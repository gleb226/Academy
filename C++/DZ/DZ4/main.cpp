#include <iostream>
using namespace std;

int main() {
    const int MAX_STUDENTS = 30;
    int grades[MAX_STUDENTS];
    int count = 0;
    int grade;

    cout << "Enter the number of students (max " << MAX_STUDENTS << "): ";
    cin >> count;

    if (count <= 0 || count > MAX_STUDENTS) {
        cout << "Invalid number of students. Must be between 1 and " << MAX_STUDENTS << "." << endl;
        return 1;
    }

    for (int i = 0; i < count; i++) {
        cout << "Enter grade for student " << (i + 1) << " (0-100): ";
        cin >> grade;

        if (grade < 0 || grade > 100) {
            cout << "Grade must be between 0 and 100. Try again." << endl;
            i--;
            continue;
        }
        grades[i] = grade;
    }

    cout << "Entered grades: ";
    for (int i = 0; i < count; i++) {
        cout << grades[i] << " ";
    }
    cout << endl;

    if (count > 0) {
        int sum = 0;
        int min = grades[0];
        int max = grades[0];
        int failed = 0;
        int good = 0;
        int excellent = 0;

        for (int i = 0; i < count; i++) {
            sum += grades[i];
            if (grades[i] < min) min = grades[i];
            if (grades[i] > max) max = grades[i];

            if (grades[i] < 60) failed++;
            else if (grades[i] >= 60 && grades[i] <= 79) good++;
            else excellent++;
        }

        double average = static_cast<double>(sum) / count;

        cout << "\nStatistics:" << endl;
        cout << "Total students: " << count << endl;
        cout << "Average grade: " << average << endl;
        cout << "Minimum grade: " << min << endl;
        cout << "Maximum grade: " << max << endl;
        cout << "Failed (below 60): " << failed << endl;
        cout << "Good (60-79): " << good << endl;
        cout << "Excellent (80-100): " << excellent << endl;

        int sortedGrades[MAX_STUDENTS];
        for (int i = 0; i < count; i++) {
            sortedGrades[i] = grades[i];
        }

        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - i - 1; j++) {
                if (sortedGrades[j] > sortedGrades[j + 1]) {
                    int temp = sortedGrades[j];
                    sortedGrades[j] = sortedGrades[j + 1];
                    sortedGrades[j + 1] = temp;
                }
            }
        }

        cout << "\nSorted grades: ";
        for (int i = 0; i < count; i++) {
            cout << sortedGrades[i] << " ";
        }
        cout << endl;

        cout << "\nEnter a grade to search: ";
        int searchGrade;
        cin >> searchGrade;

        bool found = false;
        cout << "Grade " << searchGrade << " found at positions: ";
        for (int i = 0; i < count; i++) {
            if (grades[i] == searchGrade) {
                cout << i << " ";
                found = true;
            }
        }
        if (!found) {
            cout << "not found";
        }
        cout << endl;

        char editChoice;
        cout << "\nDo you want to edit a grade? (y/n): ";
        cin >> editChoice;

        if (editChoice == 'y' || editChoice == 'Y') {
            int position, newGrade;
            cout << "Enter student position (0-" << count - 1 << "): ";
            cin >> position;

            if (position >= 0 && position < count) {
                cout << "Current grade: " << grades[position] << endl;
                cout << "Enter new grade: ";
                cin >> newGrade;

                if (newGrade >= 0 && newGrade <= 100) {
                    grades[position] = newGrade;
                    cout << "Grade updated successfully!" << endl;

                    sum = 0;
                    min = grades[0];
                    max = grades[0];
                    failed = 0;
                    good = 0;
                    excellent = 0;

                    for (int i = 0; i < count; i++) {
                        sum += grades[i];
                        if (grades[i] < min) min = grades[i];
                        if (grades[i] > max) max = grades[i];

                        if (grades[i] < 60) failed++;
                        else if (grades[i] >= 60 && grades[i] <= 79) good++;
                        else excellent++;
                    }

                    average = static_cast<double>(sum) / count;

                    cout << "\nUpdated Statistics:" << endl;
                    cout << "Total students: " << count << endl;
                    cout << "Average grade: " << average << endl;
                    cout << "Minimum grade: " << min << endl;
                    cout << "Maximum grade: " << max << endl;
                    cout << "Failed (below 60): " << failed << endl;
                    cout << "Good (60-79): " << good << endl;
                    cout << "Excellent (80-100): " << excellent << endl;
                } else {
                    cout << "Invalid grade. Must be between 0 and 100." << endl;
                }
            } else {
                cout << "Invalid position." << endl;
            }
        }
    } else {
        cout << "No grades entered." << endl;
    }

    return 0;
}
