#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <optional>

using namespace std;

// Клас Car
class Car {
private:
    string brand;
    string model;
    int year;
    double price;

public:
    // Конструктор
    Car(string b, string m, int y, double p) : brand(move(b)), model(move(m)), year(y), price(p) {}

    // Метод друку інформації про автомобіль
    void print() const {
        cout << "Brand: " << brand << ", Model: " << model << ", Year: " << year << ", Price: $" << price << endl;
    }

    // Гетери для полів
    string getBrand() const { return brand; }
    string getModel() const { return model; }
    int getYear() const { return year; }
    double getPrice() const { return price; }

    // Метод перевірки типу автомобіля
    bool isBrand(const string& queryBrand) const {
        return brand == queryBrand;
    }

    bool isOlderThan(int yearLimit) const {
        return year < yearLimit;
    }
};

// Функція для перевірки наявності автомобіля конкретного бренду
bool hasBrand(const vector<Car>& cars, const string& queryBrand) {
    return any_of(cars.begin(), cars.end(), [&queryBrand](const Car& car) {
        return car.getBrand() == queryBrand;
        });
}

// Функція для перевірки наявності старого автомобіля
bool hasOldCar(const vector<Car>& cars, int yearLimit) {
    return any_of(cars.begin(), cars.end(), [yearLimit](const Car& car) {
        return car.isOlderThan(yearLimit);
        });
}

// Функція для пошуку першого автомобіля конкретного бренду
optional<Car> findFirstBrand(const vector<Car>& cars, const string& queryBrand) {
    auto it = find_if(cars.begin(), cars.end(), [&queryBrand](const Car& car) {
        return car.isBrand(queryBrand);
        });

    if (it != cars.end()) {
        return *it;
    }
    else {
        return nullopt; // повертаємо порожній об'єкт, якщо не знайдено
    }
}

// Функція для підрахунку автомобілів конкретного бренду
int countBrand(const vector<Car>& cars, const string& queryBrand) {
    return count_if(cars.begin(), cars.end(), [&queryBrand](const Car& car) {
        return car.isBrand(queryBrand);
        });
}

int main5() {
    // Створення вектора автомобілів
    vector<Car> cars{
        {"Toyota", "Camry", 2010, 12000.0},
        {"Honda", "Accord", 2015, 15000.0},
        {"Honda", "Civic", 2010, 19000.0},
        {"Ford", "Focus", 2018, 18000.0},
        {"BMW", "X5", 2020, 50000.0},
        {"Nissan", "Altima", 2012, 13000.0}
    };

    // Виведення інформації про всі автомобілі
    cout << "List of cars:" << endl;
    for (const auto& car : cars) {
        car.print();
    }

    // Перевірка наявності автомобілів конкретного бренду
    string targetBrand = "BMW";
    if (hasBrand(cars, targetBrand)) {
        cout << "\nThere is at least one car of brand " << targetBrand << "." << endl;
    }
    else {
        cout << "\nThere are no cars of brand " << targetBrand << "." << endl;
    }

    // Перевірка наявності старих автомобілів
    int yearLimit = 2015;
    if (hasOldCar(cars, yearLimit)) {
        cout << "There is at least one car older than " << yearLimit << "." << endl;
    }
    else {
        cout << "There are no cars older than " << yearLimit << "." << endl;
    }

    // Пошук першого автомобіля BMW
    string searchBrand;
    cin >> searchBrand;
    auto foundCar = findFirstBrand(cars, searchBrand);
    if (foundCar) {
        cout << "\nFirst " << searchBrand << " car found:" << endl;
        foundCar->print();
    }
    else {
        cout << "\nNo " << searchBrand << " car found." << endl;
    }

    int brandCount = countBrand(cars, searchBrand);
    std::cout << "\nNumber of " << searchBrand << " cars: " << brandCount << std::endl;


    return 0;
}
