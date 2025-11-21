#include "contact_manager/storage.h"
#include <fstream>
#include <algorithm>
#include <nlohmann/json.hpp>

ContactStorage::ContactStorage(const std::string& filename)
    : filename_(filename) {
    load();
}

void ContactStorage::addContact(const Contact& contact) {
    contacts_.push_back(contact);
    save();
}

std::vector<Contact> ContactStorage::getAllContacts() const {
    return contacts_;
}

bool ContactStorage::removeContact(const std::string& name) {
    auto it = std::remove_if(contacts_.begin(), contacts_.end(),
        [&name](const Contact& c) {
            return c.getName() == name;
        });
    
    if (it != contacts_.end()) {
        contacts_.erase(it, contacts_.end());
        save();
        return true;
    }
    return false;
}

Contact* ContactStorage::findContact(const std::string& name) {
    auto it = std::find_if(contacts_.begin(), contacts_.end(),
        [&name](const Contact& c) {
            return c.getName() == name;
        });
    
    if (it != contacts_.end()) {
        return &(*it);
    }
    return nullptr;
}

void ContactStorage::save() {
    nlohmann::json j;
    j["contacts"] = nlohmann::json::array();
    
    for (const auto& contact : contacts_) {
        j["contacts"].push_back(contact.toJson());
    }
    
    std::ofstream file(filename_);
    if (file.is_open()) {
        file << j.dump(4);
        file.close();
    }
}

void ContactStorage::load() {
    std::ifstream file(filename_);
    if (!file.is_open()) {
        return;
    }
    
    try {
        nlohmann::json j;
        file >> j;
        file.close();
        
        contacts_.clear();
        if (j.contains("contacts") && j["contacts"].is_array()) {
            for (const auto& item : j["contacts"]) {
                contacts_.push_back(Contact::fromJson(item));
            }
        }
    } catch (...) {
        contacts_.clear();
    }
}