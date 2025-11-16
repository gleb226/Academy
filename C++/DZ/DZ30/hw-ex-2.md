### Домашнє завдання: cистема управління бібліотекою книг

#### Мета завдання:

Створити просту систему для управління бібліотекою книг на мові C++, де буде продемонстровано використання винятків (exceptions) для обробки помилок валідації даних. Ви повинні створити власні класи винятків, які наслідують від `std::exception` або `std::runtime_error`. Класи об'єктів (наприклад, книга або автор) повинні мати валідацію полів у конструкторах. Якщо валідація не проходить (наприклад, некоректні значення), конструктор повинен викидати виняток, який містить колекцію (наприклад, вектор) помилок для кожного невалідного поля. Це дозволить користувачеві зрозуміти всі проблеми одразу, а не по одній.

уявіть, що ви розробляєте систему для маленької онлайн-бібліотеки, де книги мають авторів, жанри, рік видання тощо. Використовуйте це для демонстрації реального сценарію, де валідація важлива (наприклад, щоб уникнути додавання книг з негативним роком видання або порожнім назвою).

#### Вимоги до реалізації:

1. **Створіть клас винятку для валідації:**

    - Назвіть його `ValidationException`.
    - Він повинен наслідувати від `std::runtime_error` (або `std::exception`, якщо хочете перевизначити `what()`).
    - У класі додайте приватне поле: `std::vector<std::string> errors;` — це колекція повідомлень про помилки для кожного невалідного поля.
    - Конструктор: `ValidationException(const std::vector<std::string>& errs);` — він приймає вектор помилок і формує повідомлення для `what()` (наприклад, з'єднайте помилки через "\n").
    - Перевизначте метод `what()` для повернення з'єднаного рядка з усіма помилками.
    - Додатково: додайте метод `const std::vector<std::string>& getErrors() const;` для доступу до колекції помилок.

2. **Створіть класи для моделювання даних:**

    - **Клас `Author` (Автор):**

        - Поля: `std::string name;` (ім'я, не може бути порожнім), `int birthYear;` (рік народження, повинен бути між 1500 і поточним роком, наприклад, 2025), `std::string country;` (країна, не порожня).
        - Конструктор: `Author(const std::string& name, int birthYear, const std::string& country);`
        - У конструкторі перевірте валідацію:
            - Якщо name порожнє — додайте помилку "Author name cannot be empty."
            - Якщо birthYear < 1500 або > 2025 — додайте "Invalid birth year (must be between 1500 and 2025)."
            - Якщо country порожнє — додайте "Country cannot be empty."
        - Якщо є хоча б одна помилка, киньте `ValidationException` з вектором помилок.
        - Додайте геттери для полів (опціонально сеттери з повторною валідацією).

    - **Клас `Book` (Книга):**
        - Поля: `std::string title;` (назва, не порожня), `Author author;` (об'єкт автора), `int publicationYear;` (рік видання, між 1500 і 2025, повинен бути >= birthYear автора), `std::string genre;` (жанр, наприклад, "Fantasy", "Sci-Fi" — перевірте на порожність або додайте список дозволених жанрів для валідації).
        - Конструктор: `Book(const std::string& title, const Author& author, int publicationYear, const std::string& genre);`
        - У конструкторі перевірте валідацію:
            - Якщо title порожнє — "Book title cannot be empty."
            - Якщо publicationYear < 1500 або > 2025 — "Invalid publication year."
            - Якщо publicationYear < author.birthYear — "Publication year cannot be before author's birth year."
            - Якщо genre порожнє — "Genre cannot be empty." (опціонально: перевірте, чи genre є в списку дозволених, наприклад, {"Fantasy", "Sci-Fi", "Mystery"}, інакше "Invalid genre.")
        - Якщо є помилки, киньте `ValidationException`.
        - Додайте геттери.

3. **Основна програма (main):**

    - Створіть вектор книг (`std::vector<Book> library;`).
    - Спробуйте створити кілька об'єктів `Author` і `Book` з різними даними:
        - Один валідний приклад (без помилок).
        - Один з помилками (наприклад, порожнє ім'я автора, невалідний рік).
    - Обробіть винятки за допомогою `try-catch`:
        - У `catch (const ValidationException& e)` виведіть `e.what()` і перелічіть всі помилки з `e.getErrors()` (наприклад, циклом for).
    - Додайте функцію для додавання книги до бібліотеки, яка використовує конструктор і ловить винятки.
    - Виведіть інформацію про успішно додані книги (наприклад, "Book added: [title] by [author name]").

4. **Додаткові вимоги:**
    - Використовуйте `#include <exception>`, `<vector>`, `<string>`, `<iostream>`.
    - Забезпечте, щоб виняток містив **колекцію помилок**, а не просто одне повідомлення — це ключовий момент.
    - Зробіть код чистим: використовуйте const де можливо, уникайте глобальних змінних.
    - Опціонально: додайте ще один клас винятку, наприклад, `LibraryException` для помилок на рівні бібліотеки (наприклад, якщо книга вже існує).
    - Тестуйте на edge-кейсах: негативні роки, порожні рядки, невалідні жанри.

#### Приклад коду (скелет, не повний):

```cpp
#include <exception>
#include <vector>
#include <string>
#include <iostream>

class ValidationException : public std::runtime_error {
private:
    std::vector<std::string> errors;
public:
    ValidationException(const std::vector<std::string>& errs)
        : std::runtime_error("Validation failed"), errors(errs) {}

    const char* what() const noexcept override {
        // З'єднайте помилки в один рядок
        static std::string msg;
        msg = "Validation errors:\n";
        for (const auto& err : errors) {
            msg += "- " + err + "\n";
        }
        return msg.c_str();
    }

    const std::vector<std::string>& getErrors() const {
        return errors;
    }
};

// Клас Author...
// Клас Book...

int main() {
    try {
        Author invalidAuthor("", 1000, "");  // Повинен викинути виняток
    } catch (const ValidationException& e) {
        std::cout << e.what() << std::endl;
    }
    // Інші тести...
    return 0;
}
```
