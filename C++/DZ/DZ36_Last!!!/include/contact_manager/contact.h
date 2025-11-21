#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <nlohmann/json.hpp>

class Contact {
public:
    Contact() = default;
    Contact(std::string name, std::string phone, std::string email);

    const std::string& getName() const;
    const std::string& getPhone() const;
    const std::string& getEmail() const;

    void setName(const std::string& name);
    void setPhone(const std::string& phone);
    void setEmail(const std::string& email);

    nlohmann::json toJson() const;
    static Contact fromJson(const nlohmann::json& j);

private:
    std::string name_;
    std::string phone_;
    std::string email_;
};

#endif