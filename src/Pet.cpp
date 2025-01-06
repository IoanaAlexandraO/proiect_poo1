#include "Pet.h"
#include <iostream>

// Constructor cu parametri
Pet::Pet(const std::string& name, int age) 
    : AbstractEntity(), name(name), age(age) {}

// Copy constructor
Pet::Pet(const Pet& other) 
    : AbstractEntity(other), name(other.name), age(other.age) {}

// Operator de atribuire
Pet& Pet::operator=(const Pet& other) {
    if (this != &other) {
        AbstractEntity::operator=(other); // Copiază partea din clasa de bază
        name = other.name;
        age = other.age;
    }
    return *this;
}

// Destructor
Pet::~Pet() {}

// Metoda pentru a face animalul să "vorbească"
void Pet::speak() const {
    std::cout << "Pet " << name << " says: Meow!" << std::endl;
}

// Getter pentru numele animalului
const std::string& Pet::getName() const {
    return name;
}

// Getter pentru vârsta animalului
int Pet::getAge() const {
    return age;
}
