#include <iostream>
#include <string>
#include <vector>

class Contact {
private:
    std::string name;
    std::string homePhone;
    std::string workPhone;
    std::string mobilePhone;
    std::string extraInfo;

public:
    Contact(const std::string& n, const std::string& home,
            const std::string& work, const std::string& mobile,
            const std::string& extra)
        : name(n), homePhone(home), workPhone(work), mobilePhone(mobile), extraInfo(extra) {}

    const std::string& getName() const { return name; }
    const std::string& getMobilePhone() const { return mobilePhone; }

    void show() const {
        std::cout << "Name: " << name << "\n";
        std::cout << "Home: " << homePhone << "\n";
        std::cout << "Work: " << workPhone << "\n";
        std::cout << "Mobile: " << mobilePhone << "\n";
        std::cout << "Extra: " << extraInfo << "\n";
        std::cout << "--------------------------\n";
    }
};

class PhoneBook {
private:
    std::vector<Contact> contacts;

public:
    void addContact(const Contact& c) {
        contacts.push_back(c);
    }

    void deleteContact(const std::string& name) {
        for (auto it = contacts.begin(); it != contacts.end(); ++it) {
            if (it->getName() == name) {
                contacts.erase(it);
                std::cout << "Contact deleted.\n";
                return;
            }
        }
        std::cout << "Contact not found.\n";
    }

    void searchContact(const std::string& name) const {
        for (const auto& c : contacts) {
            if (c.getName() == name) {
                c.show();
                return;
            }
        }
        std::cout << "Contact not found.\n";
    }

    void showAll() const {
        if (contacts.empty()) {
            std::cout << "Phone book is empty.\n";
            return;
        }
        for (const auto& c : contacts) {
            c.show();
        }
    }
};

bool isDigitChar(char ch) {
    return ch >= '0' && ch <= '9';
}

bool isValidName(const std::string& name) {
    if (name.empty()) return false;
    for (char ch : name) {
        if (isDigitChar(ch)) return false;
    }
    return true;
}

bool isValidPhone(const std::string& phone) {
    if (phone.size() != 10) return false;
    for (char ch : phone) {
        if (!isDigitChar(ch)) return false;
    }
    return true;
}

std::string inputName() {
    std::string name;
    do {
        std::cout << "Enter name: ";
        std::getline(std::cin, name);
        if (!isValidName(name)) {
            std::cout << "Invalid name! Must not be empty and contain no digits.\n";
        }
    } while (!isValidName(name));
    return name;
}

std::string inputPhone(const std::string& label) {
    std::string phone;
    do {
        std::cout << "Enter " << label << " phone (10 digits): ";
        std::getline(std::cin, phone);
        if (!isValidPhone(phone)) {
            std::cout << "Invalid phone number! Must contain exactly 10 digits.\n";
        }
    } while (!isValidPhone(phone));
    return phone;
}

int main() {
    PhoneBook pb;
    std::string choiceStr;
    int choice = -1;

    do {
        std::cout << "\n=== Phone Book Menu ===\n";
        std::cout << "1. Add contact\n";
        std::cout << "2. Delete contact\n";
        std::cout << "3. Search contact\n";
        std::cout << "4. Show all contacts\n";
        std::cout << "0. Exit\n";
        std::cout << "Your choice: ";

        std::getline(std::cin, choiceStr);
        if (choiceStr.empty()) {
            choice = -1;
        } else {
            choice = std::stoi(choiceStr);
        }

        if (choice == 1) {
            std::string name = inputName();
            std::string home, work, mobile, extra;
            std::string ans;

            std::cout << "Do you want to enter home phone? (y/n): ";
            std::getline(std::cin, ans);
            if (!ans.empty() && (ans[0] == 'y' || ans[0] == 'Y')) {
                home = inputPhone("home");
            }

            std::cout << "Do you want to enter work phone? (y/n): ";
            std::getline(std::cin, ans);
            if (!ans.empty() && (ans[0] == 'y' || ans[0] == 'Y')) {
                work = inputPhone("work");
            }

            std::cout << "Do you want to enter mobile phone? (y/n): ";
            std::getline(std::cin, ans);
            if (!ans.empty() && (ans[0] == 'y' || ans[0] == 'Y')) {
                mobile = inputPhone("mobile");
            } else {
                mobile = inputPhone("mobile");
            }

            std::cout << "Enter extra info (can be empty): ";
            std::getline(std::cin, extra);

            pb.addContact(Contact(name, home, work, mobile, extra));
        }
        else if (choice == 2) {
            std::string name;
            std::cout << "Enter name to delete: ";
            std::getline(std::cin, name);
            pb.deleteContact(name);
        }
        else if (choice == 3) {
            std::string name;
            std::cout << "Enter name to search: ";
            std::getline(std::cin, name);
            pb.searchContact(name);
        }
        else if (choice == 4) {
            pb.showAll();
        }
    } while (choice != 0);

    return 0;
}
