#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ValidationException {
private:
    vector<string> errors;

public:
    ValidationException(const vector<string> &errs) : errors(errs) {
    }

    const char *what() const {
        static string msg;
        msg = "Validation errors:\n";
        for (const auto &e: errors) msg += "- " + e + "\n";
        return msg.c_str();
    }

    const vector<string> &getErrors() const { return errors; }
};

class Author {
    string name;
    int birthYear;
    string country;

public:
    Author(const string &n, int by, const string &c)
        : name(n), birthYear(by), country(c) {
        vector<string> errs;
        if (name.empty()) errs.push_back("Author name cannot be empty.");
        if (birthYear < 1500 || birthYear > 2025) errs.push_back("Invalid birth year (must be between 1500 and 2025).");
        if (country.empty()) errs.push_back("Country cannot be empty.");
        if (!errs.empty()) throw ValidationException(errs);
    }

    const string &getName() const { return name; }
    int getBirthYear() const { return birthYear; }
    const string &getCountry() const { return country; }
};

class Book {
    string title;
    Author author;
    int publicationYear;
    string genre;
    vector<string> allowedGenres{"Fantasy", "Sci-Fi", "Mystery", "Romance", "Thriller"};

public:
    Book(const string &t, const Author &a, int py, const string &g)
        : title(t), author(a), publicationYear(py), genre(g) {
        vector<string> errs;
        if (title.empty()) errs.push_back("Book title cannot be empty.");
        if (publicationYear < 1500 || publicationYear > 2025) errs.push_back("Invalid publication year.");
        if (publicationYear < author.getBirthYear()) errs.push_back(
            "Publication year cannot be before author's birth year.");
        if (genre.empty()) errs.push_back("Genre cannot be empty.");
        else {
            bool valid = false;
            for (auto &ag: allowedGenres) if (genre == ag) valid = true;
            if (!valid) errs.push_back("Invalid genre.");
        }
        if (!errs.empty()) throw ValidationException(errs);
    }

    const string &getTitle() const { return title; }
    const Author &getAuthor() const { return author; }
    int getPublicationYear() const { return publicationYear; }
    const string &getGenre() const { return genre; }
};

void addBook(vector<Book> &library, const string &title, const Author &author, int year, const string &genre) {
    try {
        Book b(title, author, year, genre);
        library.push_back(b);
        cout << "Book added: " << title << " by " << author.getName() << endl;
    } catch (const ValidationException &e) {
        cout << e.what();
    }
}

int main() {
    vector<Book> library;

    try {
        Author validAuthor("J.K. Rowling", 1965, "UK");
        addBook(library, "Harry Potter", validAuthor, 1997, "Fantasy");

        Author invalidAuthor("", 1000, "");
        addBook(library, "Invalid Book", invalidAuthor, 1400, "Unknown");
    } catch (const ValidationException &e) {
        cout << e.what();
    }

    try {
        Author anotherAuthor("George Orwell", 1903, "UK");
        addBook(library, "", anotherAuthor, 1949, "Dystopia");
    } catch (const ValidationException &e) {
        cout << e.what();
    }

    cout << "\nLibrary contents:\n";
    for (const auto &book: library) {
        cout << book.getTitle() << " by " << book.getAuthor().getName()
                << " (" << book.getPublicationYear() << ") Genre: " << book.getGenre() << endl;
    }

    return 0;
}
