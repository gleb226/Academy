#include <iostream>
using namespace std;

#define FIRST_VAL 3
#define SECOND_VAL 3

#if FIRST_VAL*SECOND_VAL == 9
int main() {
	cout << "9\n";
	return 0;
}
#elif FIRST_VAL*SECOND_VAL == 15
int main() {
	cout << "15\n";
	return 0;
}
#else
int main() {
	cout << "Not 9 or 15\n";
	return 0;
}
#endif