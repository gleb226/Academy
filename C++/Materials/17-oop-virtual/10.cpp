#include <vector>
#include <functional> // для std::reference_wrapper

int main()
{
    std::vector<std::reference_wrapper<Parent> > v;
    Parent p(7); // p і ch не можуть бути анонімними об'єктами
    Child ch(8);
    v.push_back(p); // додаємо об'єкт класу Parent в наш вектор
    v.push_back(ch); // додаємо об'єкт класу Child в наш вектор

    // Виводимо всі елементи нашого вектора
    for (int count = 0; count < v.size(); ++count)
        std::cout << "I am a " << v[count].get().getName() << " with value " << v[count].get().getValue() << "\n"; // використовуємо .get() для отримання елементів з std::reference_wrapper


    return 0;
}