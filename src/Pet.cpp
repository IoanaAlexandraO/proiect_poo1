#include "Pet.h"

Pet::Pet(const std::string& name, int age) 
    : AbstractEntity(), name(name), age(age) {}

Pet::Pet(const Pet& other) 
    : AbstractEntity(other), name(other.name), age(other.age) {}

Pet& Pet::operator=(const Pet& other) {
    if (this != &other) {
        AbstractEntity::operator=(other);
        name = other.name;
        age = other.age;
    }
    return *this;
}

Pet::~Pet() override {}

void Pet::speak() const {
    std::cout << "Pet " << name << " says: Meow!" << std::endl;
}

int Pet::getAge() const {
    return age;
}
