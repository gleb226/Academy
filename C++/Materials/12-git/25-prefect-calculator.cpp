#include <iostream>

double getValue()
{
    while (true) // цикл продовжується до тих пір, поки користувач не введе коректне значення
    {
        std::cout << "Enter a double value: ";
        double a;
        std::cin >> a;

        // Перевірка попереднього вилучення
        if (std::cin.fail()) // якщо попереднє вилучення виявилося невдалим
        {
            std::cin.clear(); // то повертаємо cin в 'звичайний' режим роботи
            std::cin.ignore(32767, '\n'); // і видаляємо значення попереднього вводу з вхідного буферу
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else
        {
            std::cin.ignore(32767, '\n'); // видаляємо зайві значення

            return a;
        }
    }
}

char getOperator()
{
    while (true) // цикл продовжується до тих пір, поки користувач не введе коректне значення 
    {
        std::cout << "Enter one of the following: +, -, *, or /: ";
        char sm;
        std::cin >> sm;

        // Змінні типу char можуть приймати будь-які символи з користувацького вводу, тому нам не варто турбуватися щодо виникнення невдалого вилучення

        std::cin.ignore(32767, '\n'); // видаляємо зайвий баласт

        // Виконуємо перевірку користувацького вводу
        if (sm == '+' || sm == '-' || sm == '*' || sm == '/')
            return sm; // повертаємо назад в викликаючий об'єкт
        else // в протилежному випадку, повідомляємо користувачеві, що щось пішло не так
            std::cout << "Oops, that input is invalid.  Please try again.\n";
    }
}

void printResult(double a, char sm, double b)
{
    if (sm == '+')
        std::cout << a << " + " << b << " is " << a + b << '\n';
    else if (sm == '-')
        std::cout << a << " - " << b << " is " << a - b << '\n';
    else if (sm == '*')
        std::cout << a << " * " << b << " is " << a * b << '\n';
    else if (sm == '/')
        std::cout << a << " / " << b << " is " << a / b << '\n';
    else
        std::cout << "Something went wrong: printResult() got an invalid operator.";

}

int main()
{
    double a = getValue();
    char sm = getOperator();
    double b = getValue();

    printResult(a, sm, b);

    return 0;
}