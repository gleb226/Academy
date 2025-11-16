#include <iostream>
using namespace std;

int main() {
    int target = 30;

    int array[30] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30};

    int left = 0;
    int right = 10 - 1;
    int mid = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (array[mid] == target) {
            cout << "Found at index " << mid << endl;
            break;
        } else if (array[mid] < target) {
            left = mid + 1;
            cout << "left = " << left << endl;
        } else {
            right = mid - 1;
            cout << "right = " << right << endl;
        }
    }
    return 0;
}
