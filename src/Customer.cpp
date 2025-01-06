#include "Customer.h"

Customer::Customer(const std::string& name, int age) : name(name), age(age) {}

Customer::Customer(const Customer& other) : name(other.name), age(other.age) {}

Customer& Customer::operator=(const Customer& other) {
    if (this != &other) {
        name = other.name;
        age = other.age;
    }
    return *this;
}

Customer::~Customer() {}

void Customer::speak() const {
    std::cout << "Customer " << name << " says: Hello!" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Customer& customer) {
    os << "Customer: " << customer.name << ", Age: " << customer.age;
    return os;
}

std::istream& operator>>(std::istream& is, Customer& customer) {
    is >> customer.name >> customer.age;
    return is;
}

bool Customer::operator==(const Customer& other) const {
    return name == other.name && age == other.age;
}
