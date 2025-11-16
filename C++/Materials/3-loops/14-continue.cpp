#include <iostream>
using namespace std;

int main()
{
	for (int i = 0; i < 26; i++)
	{
		if (i % 2 == 0) // якщо число ділиться на два без залишку
		{
			continue; // зупинити ітерацію циклу і перейти до i++
		}
		cout << i << " ";
	}
	cout << endl;
	return 0;
}
