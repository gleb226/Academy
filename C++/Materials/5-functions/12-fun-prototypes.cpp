#include <iostream>
using namespace std;

// прототипи 
void myFunc();
void myFuncNext();

int main() {
	myFunc(); // myFunc
	myFuncNext(); // myFuncNext
	return 0;
}

// описи
void myFunc() {
	cout << "MyFunc\n";
}

void myFuncNext() {
	cout << "MyFuncNext\n";
}