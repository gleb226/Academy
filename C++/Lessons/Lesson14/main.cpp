#include <iostream>
#include <vector>
#include <fstream>
#include <limits>

struct Book {
    int id;
    std::string title;
    std::string author;
    int year;
};

std::vector<Book> books;
int nextId = 1;

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void addBook() {
    Book book;
    book.id = nextId++;

    std::cout << "Enter title: ";
    std::getline(std::cin, book.title);
    std::cout << "Enter author: ";
    std::getline(std::cin, book.author);
    std::cout << "Enter year: ";
    while (!(std::cin >> book.year)) {
        std::cout << "Invalid input. Try again: ";
        clearInput();
    }
    clearInput();

    books.push_back(book);
    std::cout << "Book added!\n";
}

void listBooks() {
    if (books.empty()) {
        std::cout << "No books in library.\n";
        return;
    }
    for (const auto& book : books) {
        std::cout << "ID: " << book.id
                  << " | Title: " << book.title
                  << " | Author: " << book.author
                  << " | Year: " << book.year << "\n";
    }
}

void deleteBook() {
    int id;
    std::cout << "Enter ID to delete: ";
    while (!(std::cin >> id)) {
        std::cout << "Invalid input. Try again: ";
        clearInput();
    }
    clearInput();

    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->id == id) {
            books.erase(it);
            std::cout << "Book deleted.\n";
            return;
        }
    }
    std::cout << "Book not found.\n";
}

void searchBook() {
    std::string query;
    std::cout << "Enter title to search: ";
    std::getline(std::cin, query);

    bool found = false;
    for (const auto& book : books) {
        if (book.title.find(query) != std::string::npos) {
            std::cout << "ID: " << book.id
                      << " | Title: " << book.title
                      << " | Author: " << book.author
                      << " | Year: " << book.year << "\n";
            found = true;
        }
    }
    if (!found) std::cout << "No books found.\n";
}

void saveToFile() {
    std::ofstream file("books.txt");
    for (const auto& book : books) {
        file << book.id << "|" << book.title << "|" << book.author << "|" << book.year << "\n";
    }
    std::cout << "Saved to file.\n";
}

void loadFromFile() {
    std::ifstream file("books.txt");
    if (!file.is_open()) return;

    books.clear();
    std::string line;
    while (std::getline(file, line)) {
        Book book;
        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);
        size_t pos3 = line.find('|', pos2 + 1);

        book.id = std::stoi(line.substr(0, pos1));
        book.title = line.substr(pos1 + 1, pos2 - pos1 - 1);
        book.author = line.substr(pos2 + 1, pos3 - pos2 - 1);
        book.year = std::stoi(line.substr(pos3 + 1));

        books.push_back(book);
        if (book.id >= nextId) nextId = book.id + 1;
    }
    std::cout << "Loaded from file.\n";
}

void menu() {
    std::cout << "\n=== Mini Library ===\n"
              << "1. Add Book\n"
              << "2. Delete Book\n"
              << "3. Search Book\n"
              << "4. List All Books\n"
              << "5. Save to File\n"
              << "6. Load from File\n"
              << "0. Exit\n"
              << "Choose: ";
}

int main() {
    loadFromFile();
    int choice;
    while (true) {
        menu();
        std::cin >> choice;
        clearInput();

        switch (choice) {
            case 1: addBook(); break;
            case 2: deleteBook(); break;
            case 3: searchBook(); break;
            case 4: listBooks(); break;
            case 5: saveToFile(); break;
            case 6: loadFromFile(); break;
            case 0: saveToFile(); std::cout << "Goodbye!\n"; return 0;
            default: std::cout << "Invalid option.\n";
        }
    }
}
