#ifndef PET_H
#define PET_H
#include "AbstractEntity.h"
#include <string>
#include <iostream>

template<typename T>
class Pet : public AbstractEntity {
private:
    std::string name;
    T age;
public:
    Pet(const std::string& name, T age);
    Pet(const Pet& other);
    Pet& operator=(const Pet& other);
    ~Pet() override;
    void speak() const override;
    T getAge() const;
    std::string getName() const; // Metodă nouă pentru a obține numele
};

// Implementarea metodelor
template<typename T>
Pet<T>::Pet(const std::string& name, T age) : name(name), age(age) {}

template<typename T>
Pet<T>::Pet(const Pet& other) : name(other.name), age(other.age) {}

template<typename T>
Pet<T>& Pet<T>::operator=(const Pet& other) {
    if (this != &other) {
        name = other.name;
        age = other.age;
    }
    return *this;
}

template<typename T>
Pet<T>::~Pet() {}

template<typename T>
void Pet<T>::speak() const {
    std::cout << "Pet " << name << " says: Meow!" << std::endl;
}

template<typename T>
T Pet<T>::getAge() const {
    return age;
}

template<typename T>
std::string Pet<T>::getName() const {
    return name;
}

#endif
