#include <iostream>
#include <string>
#include <fmt/core.h>
#include "contact_manager/contact.h"
#include "contact_manager/storage.h"

bool validateEmail(const std::string& email) {
    return email.find('@') != std::string::npos;
}

bool validatePhone(const std::string& phone) {
    return !phone.empty();
}

void printMenu() {
    fmt::print("\n=== Contact Manager ===\n");
    fmt::print("1. Add contact\n");
    fmt::print("2. View all contacts\n");
    fmt::print("3. Find contact\n");
    fmt::print("4. Remove contact\n");
    fmt::print("5. Exit\n");
    fmt::print("Choose option: ");
}

void addContact(ContactStorage& storage) {
    std::string name, phone, email;
    
    std::cin.ignore();
    
    fmt::print("Enter name: ");
    std::getline(std::cin, name);
    
    fmt::print("Enter phone: ");
    std::getline(std::cin, phone);
    
    fmt::print("Enter email: ");
    std::getline(std::cin, email);
    
    if (!validatePhone(phone)) {
        fmt::print("Error: Phone cannot be empty\n");
        return;
    }
    
    if (!validateEmail(email)) {
        fmt::print("Error: Email must contain @\n");
        return;
    }
    
    Contact contact(name, phone, email);
    storage.addContact(contact);
    fmt::print("Contact added successfully\n");
}

void viewAllContacts(const ContactStorage& storage) {
    auto contacts = storage.getAllContacts();
    
    if (contacts.empty()) {
        fmt::print("No contacts found\n");
        return;
    }
    
    fmt::print("\n=== All Contacts ===\n");
    for (const auto& contact : contacts) {
        fmt::print("Name: {}\n", contact.getName());
        fmt::print("Phone: {}\n", contact.getPhone());
        fmt::print("Email: {}\n", contact.getEmail());
        fmt::print("-------------------\n");
    }
}

void findContact(ContactStorage& storage) {
    std::string name;
    
    std::cin.ignore();
    fmt::print("Enter name to search: ");
    std::getline(std::cin, name);
    
    Contact* contact = storage.findContact(name);
    
    if (contact) {
        fmt::print("\n=== Contact Found ===\n");
        fmt::print("Name: {}\n", contact->getName());
        fmt::print("Phone: {}\n", contact->getPhone());
        fmt::print("Email: {}\n", contact->getEmail());
    } else {
        fmt::print("Contact not found\n");
    }
}

void removeContact(ContactStorage& storage) {
    std::string name;
    
    std::cin.ignore();
    fmt::print("Enter name to remove: ");
    std::getline(std::cin, name);
    
    if (storage.removeContact(name)) {
        fmt::print("Contact removed successfully\n");
    } else {
        fmt::print("Contact not found\n");
    }
}

int main() {
    ContactStorage storage("contacts.json");
    
    int choice;
    bool running = true;
    
    while (running) {
        printMenu();
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                addContact(storage);
                break;
            case 2:
                viewAllContacts(storage);
                break;
            case 3:
                findContact(storage);
                break;
            case 4:
                removeContact(storage);
                break;
            case 5:
                fmt::print("Goodbye!\n");
                running = false;
                break;
            default:
                fmt::print("Invalid option\n");
        }
    }
    
    return 0;
}