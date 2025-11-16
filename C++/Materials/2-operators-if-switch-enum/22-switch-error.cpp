#include <iostream> 
using namespace std;

int main() {
    // реалізація програмного меню 
    int action;
    cout << "\nSelect action:\n";
    cout << "\n Press 1 if you want to see the dollar rate.\n";
    cout << "\n Press 2 if you want to see the euro rate.\n";
    cout << "\n Press 3 if you want to see the ruble rate.\n";
    // очікування вибору користувача 
    cin >> action;

    // перевіряється значення змінної action 
    switch (action) {
    case 1: // якщо користувач вибрав долар 
        cout << "\nThe rate is 28 UAH.\n";
        break; // зупинка switch
    case 2: // якщо користувач вибрав євро 
        cout << "\nThe rate is 30 UAH.\n";
        // break; закоментована зупинка switch 
    case 3: // якщо користувач вибрав рублі
        cout << "\nThe rate is 0.44 UAH.\n";
        break; // зупинка switch
    default: // якщо вибір не є коректним 
        cout << "\nError! Invalid "
            " value\n";
        break; // зупинка switch
    }
    return 0;
}