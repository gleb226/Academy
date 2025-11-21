#ifndef STORAGE_H
#define STORAGE_H

#include <vector>
#include <string>
#include "contact.h"

class ContactStorage {
public:
    explicit ContactStorage(const std::string& filename);

    void addContact(const Contact& contact);
    std::vector<Contact> getAllContacts() const;
    bool removeContact(const std::string& name);
    Contact* findContact(const std::string& name);

    void save();
    void load();

private:
    std::string filename_;
    std::vector<Contact> contacts_;
};

#endif