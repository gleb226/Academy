### Домашнє завдання: Проєкт з CMake та vcpkg — Система управління контактами

**Мета завдання:**  
Навчитися створювати C++ проєкти з використанням CMake та менеджера пакетів vcpkg. Опанувати базові навички інтеграції зовнішніх бібліотек через vcpkg, налаштування різних конфігурацій збірки (Debug/Release), та організації структури проєкту.

**Завдання:**  
Створити консольну програму "Contact Manager" (менеджер контактів), яка зберігає інформацію про контакти у JSON файлі.

---

## Частина 1: Налаштування середовища

### 1.1 Встановлення vcpkg

```bash
# Клонувати vcpkg (один раз для всіх проєктів)
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg

# Запустити bootstrap скрипт
# Windows:
.\bootstrap-vcpkg.bat
# Linux/Mac:
./bootstrap-vcpkg.sh

# Інтегрувати з системою (опційно)
.\vcpkg integrate install
```

### 1.2 Встановлення необхідних бібліотек

```bash
# Встановити потрібні пакети
.\vcpkg install nlohmann-json
.\vcpkg install fmt
```

**Що робить кожна бібліотека:**

-   **nlohmann-json** — зручна робота з JSON (серіалізація/десеріалізація)
-   **fmt** — сучасне форматування рядків (швидше за `std::stringstream`)

---

## Частина 2: Структура проєкту

Створіть наступну структуру:

```
ContactManager/
├── CMakeLists.txt              # Головний CMake файл
├── vcpkg.json                  # Маніфест залежностей vcpkg
├── README.md                   # Опис проєкту
│
├── include/                    # Заголовкові файли
│   └── contact_manager/
│       ├── contact.h           # Клас Contact
│       └── storage.h           # Клас для роботи з файлами
│
└── src/                        # Реалізація
    ├── contact.cpp
    ├── storage.cpp
    └── main.cpp                # Точка входу програми
```

---

## Частина 3: Реалізація функціоналу

### 3.1 Клас Contact (include/contact_manager/contact.h)

```cpp
#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <nlohmann/json.hpp>

class Contact {
public:
    Contact() = default;
    Contact(std::string name, std::string phone, std::string email);

    // Getters
    const std::string& getName() const;
    const std::string& getPhone() const;
    const std::string& getEmail() const;

    // Setters
    void setName(const std::string& name);
    void setPhone(const std::string& phone);
    void setEmail(const std::string& email);

    // Серіалізація в JSON
    nlohmann::json toJson() const;
    static Contact fromJson(const nlohmann::json& j);

private:
    std::string name_;
    std::string phone_;
    std::string email_;
};

#endif
```

### 3.2 Клас Storage (include/contact_manager/storage.h)

```cpp
#ifndef STORAGE_H
#define STORAGE_H

#include <vector>
#include <string>
#include "contact.h"

class ContactStorage {
public:
    explicit ContactStorage(const std::string& filename);

    // CRUD операції
    void addContact(const Contact& contact);
    std::vector<Contact> getAllContacts() const;
    bool removeContact(const std::string& name);
    Contact* findContact(const std::string& name);

    // Робота з файлом
    void save();
    void load();

private:
    std::string filename_;
    std::vector<Contact> contacts_;
};

#endif
```

### 3.3 Головний CMakeLists.txt

```cmake
cmake_minimum_required(VERSION 3.20)
project(ContactManager VERSION 1.0.0 LANGUAGES CXX)

# Налаштування C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Встановити CMAKE_TOOLCHAIN_FILE для vcpkg
# Шлях до вашого vcpkg
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "Vcpkg toolchain file")

# Знайти пакети через vcpkg
find_package(nlohmann_json CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

# Виведення інформації
message(STATUS "=================================")
message(STATUS "  ${PROJECT_NAME} v${PROJECT_VERSION}")
message(STATUS "=================================")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C++ standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "=================================")

# Бібліотека
add_library(ContactManagerLib
    src/contact.cpp
    src/storage.cpp
)

target_include_directories(ContactManagerLib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(ContactManagerLib
    PUBLIC
        nlohmann_json::nlohmann_json
        fmt::fmt
)

# Виконуваний файл
add_executable(ContactManager src/main.cpp)

target_link_libraries(ContactManager
    PRIVATE
        ContactManagerLib
)

# Налаштування компілятора
if(MSVC)
    target_compile_options(ContactManagerLib PRIVATE /W4)
    target_compile_options(ContactManager PRIVATE /W4)
else()
    target_compile_options(ContactManagerLib PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(ContactManager PRIVATE -Wall -Wextra -Wpedantic)
endif()
```

### 3.4 vcpkg.json (маніфест залежностей)

```json
{
    "name": "contact-manager",
    "version": "1.0.0",
    "dependencies": ["nlohmann-json", "fmt"]
}
```

---

## Частина 4: Вимоги до реалізації

### 4.1 Функціональні вимоги

**Основні можливості програми:**

1. Додавання нового контакту (ім'я, телефон, email)
2. Перегляд усіх контактів
3. Пошук контакту за ім'ям
4. Видалення контакту
5. Автоматичне збереження у JSON файл

**Приклад інтерфейсу в main.cpp:**

```
=== Contact Manager ===
1. Add contact
2. View all contacts
3. Find contact
4. Remove contact
5. Exit
Choose option:
```

### 4.2 Технічні вимоги

1. **JSON формат** для збереження контактів:

```json
{
    "contacts": [
        {
            "name": "Іван Петренко",
            "phone": "+380501234567",
            "email": "ivan@example.com"
        },
        {
            "name": "Марія Коваль",
            "phone": "+380672223344",
            "email": "maria@example.com"
        }
    ]
}
```

2. **Обробка помилок**:
    - Валідація email (перевірка наявності @)
    - Валідація телефону (не порожній)
    - Обробка відсутнього JSON файлу

---

## Частина 5: Збірка та запуск

### 5.1 Конфігурація проєкту

```bash
# Створити папку для збірки
mkdir build
cd build

# Згенерувати проєкт (вкажіть шлях до vcpkg toolchain)
cmake .. -DCMAKE_TOOLCHAIN_FILE=path/to/vcpkg/scripts/buildsystems/vcpkg.cmake

# Debug збірка
cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=...

# Release збірка
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=...
```

### 5.2 Компіляція

```bash
# Скомпілювати
cmake --build .

# Або з багатопотоковою компіляцією
cmake --build . -j4
```

### 5.3 Запуск програми

```bash
# Debug версія
./ContactManager

# або на Windows
.\Debug\ContactManager.exe
```

---

## Частина 6: Додаткові завдання (бонуси)

**Розширений функціонал (оберіть 1-2):**

-   Редагування існуючого контакту
-   Імпорт/експорт у CSV формат
-   Пошук за частковим збігом (contains)
-   Сортування контактів за ім'ям

---

## Підказки та поради

### Підказка 1: Якщо vcpkg не знаходить пакети

```cmake
# У CMakeLists.txt вкажіть точний шлях
set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake")

# Або через змінну середовища
# Windows PowerShell:
$env:VCPKG_ROOT = "C:\vcpkg"

# Linux/Mac:
export VCPKG_ROOT=/path/to/vcpkg
```

### Підказка 2: Приклад використання nlohmann-json

```cpp
#include <nlohmann/json.hpp>
using json = nlohmann::json;

// Створення JSON
json j = {
    {"name", "John"},
    {"age", 30}
};

// Читання JSON
std::string name = j["name"];
int age = j["age"];

// З файлу
std::ifstream file("data.json");
json j = json::parse(file);
```

### Підказка 3: Відладка CMake

```bash
# Виведення детальної інформації
cmake .. -DCMAKE_VERBOSE_MAKEFILE=ON

# Перевірка знайдених пакетів
cmake .. --debug-find

# Очистити кеш CMake
rm -rf CMakeCache.txt CMakeFiles/
```

---

## Корисні посилання

-   [CMake Documentation](https://cmake.org/documentation/)
-   [vcpkg Documentation](https://vcpkg.io/en/)
-   [nlohmann-json GitHub](https://github.com/nlohmann/json)
-   [fmt GitHub](https://github.com/fmtlib/fmt)
-   [Приклади CMake з vcpkg](https://github.com/microsoft/vcpkg#quick-start-windows)

---
