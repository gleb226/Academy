#include <iostream>
using namespace std;

int main() {
	// create a digit value array of three elements
	int train[3];
	// fill the array
	train[0] = 3;
	train[1] = 1;
	train[2] = 4;
	// output the array address
	cout << "Start address: " << train << endl;
	cout << "Array values: " << endl;
	cout << "train[0] = " << train[0] << endl;
	cout << "train[1] = " << train[1] << endl;
	cout << "train[2] = " << train[2] << endl;
	cout << endl;
	return 0;
}