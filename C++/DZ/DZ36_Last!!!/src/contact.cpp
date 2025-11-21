#include "contact_manager/contact.h"

Contact::Contact(std::string name, std::string phone, std::string email)
    : name_(std::move(name)), phone_(std::move(phone)), email_(std::move(email)) {}

const std::string& Contact::getName() const {
    return name_;
}

const std::string& Contact::getPhone() const {
    return phone_;
}

const std::string& Contact::getEmail() const {
    return email_;
}

void Contact::setName(const std::string& name) {
    name_ = name;
}

void Contact::setPhone(const std::string& phone) {
    phone_ = phone;
}

void Contact::setEmail(const std::string& email) {
    email_ = email;
}

nlohmann::json Contact::toJson() const {
    return nlohmann::json{
            {"name", name_},
            {"phone", phone_},
            {"email", email_}
    };
}

Contact Contact::fromJson(const nlohmann::json& j) {
    return Contact(
        j.at("name").get<std::string>(),
        j.at("phone").get<std::string>(),
        j.at("email").get<std::string>()
    );
}