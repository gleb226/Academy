#include <iostream>

using namespace std;

void reverse_stack(int pancakes[], int index, int size) {
    int left = 0;
    int right = index;
    while (left < right) {
        int temp = pancakes[left];
        pancakes[left] = pancakes[right];
        pancakes[right] = temp;
        left++;
        right--;
    }
}

int find_max_index(int pancakes[], int size) {
    int max_index = 0;
    for (int i = 1; i < size; i++) {
        if (pancakes[i] > pancakes[max_index]) {
            max_index = i;
        }
    }
    return max_index;
}

int main() {
    int n;
    cin >> n;

    int pancakes[n];
    for (int i = 0; i < n; i++) {
        cin >> pancakes[i];
    }

    for (int size = n; size > 1; size--) {
        int max_index = find_max_index(pancakes, size);
        if (max_index != size - 1) {
            if (max_index != 0) {
                reverse_stack(pancakes, max_index, size);
            }
            reverse_stack(pancakes, size - 1, size);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << pancakes[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}
