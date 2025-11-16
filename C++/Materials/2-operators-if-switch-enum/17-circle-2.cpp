#include <iostream> 
#include <math.h> 
using namespace std;

int main() {
	// Оголошення змінних 
	int x0, y0, r1, r2, x, y;
	float L;
	// Запит на ввід необхідних даних
	cout << "Input the coordinates of the circle’s center (X0, Y0):";
	cin >> x0 >> y0;
	cout << "Input the circle’s radiuses R1 and R2:";
	cin >> r1 >> r2;
	cout << "Input the coordinates (X, Y) of the point:";
	cin >> x >> y;
	// Вивід формули
	L = sqrt(pow(x — x0, 2) + pow(y — y0, 2));

	// Аналіз результатів
	if ((r1 < L) && (L < r2)) {
		cout << "This point is inside "
			"the ring.\n";
	}
	else {
		cout << "This point is outside "
			"the ring.\n";
	}

	return 0;
}
