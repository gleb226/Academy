// Dependencies:
#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

int main() {
    // Init program
    clrscr();

    // Vars:
    int lengthOfArrays = 0;
    int arrayA[1000];
    int arrayB[1000];
    // --Initialize arrays state
    for (int i = 0; i < 1000; i++) {
        arrayA[i] = 0;
        arrayB[i] = 0;
    }

    // Print out program's description:
    cout << endl << "***************************";
    cout << endl << "";
    cout << endl << "";
    cout << endl << "";
    cout << endl << "***************************";

    // Initialize program's state using user input from stdin.
    cout << endl << "Please enter length of array to randomize." << endl << "Arrays length: ";
    cin >> lengthOfArrays;

    if (lengthOfArrays > 1000) {
        cout << endl << "Array's length can not be more than 1000";
        cout << endl << "Press any key to exit.";
        getch();
        return 1;
    }

    // Begin processing:
    //  --randomize each array
    for (int i = 0; i < lengthOfArrays; i++) {
        arrayA[i] = rand();
        arrayB[i] = rand();
        cout << endl << "A[" << i << "] = " << arrayA[i];
        cout << endl << "B[" << i << "] = " << arrayB[i];
    }
    // --sum all of ints in each array
    int sumA = 0;
    int sumB = 0;
    for (int i = 0; i < lengthOfArrays; i++) {
        sumA += arrayA[i];
        sumB += arrayB[i];
    }

    cout << endl << "Sum of A is: " << sumA;
    cout << endl << "And sum of B is: " << sumB;

    // Print exit message
    cout << endl << "";
    cout << endl << "Thank you!";
    cout << endl << "Press any key to exit.";

    // Exit cleanly.
    getch();
    return 0;
}