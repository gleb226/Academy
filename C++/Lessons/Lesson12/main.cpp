// #include <iostream>
// using namespace std;
//
// int main() {
//     int number;
//     cout << "Enter a number (0–255): ";
//    cin >> number;
//
//     if (cin.fail() || number < 0 || number > 255) {
//         cout << "Invalid input!\n";
//         return 1;
//     }
//
//     char binary[9];
//     for (int i = 7; i >= 0; --i) {
//         binary[i] = (number % 2) + '0';
//         number /= 2;
//     }
//     binary[8] = '\0';
//
//     for (int i = 0; i < 8; ++i) {
//         cout << binary[i];
//         if (i == 3) cout << ' ';
//     }
//
//     return 0;
// }
