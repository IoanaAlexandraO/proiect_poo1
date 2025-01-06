#include "Pet.h"

Pet::Pet(const std::string& name, int age) : name(name), age(age) {}

Pet::Pet(const Pet& other) : name(other.name), age(other.age) {}

Pet& Pet::operator=(const Pet& other) {
    if (this != &other) {
        name = other.name;
        age = other.age;
    }
    return *this;
}

Pet::~Pet() {}

void Pet::speak() const {
    std::cout << "Pet " << name << " says: Meow!" << std::endl;
}

int Pet::getAge() const {
    return age;
}
