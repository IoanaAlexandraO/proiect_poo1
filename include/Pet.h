#ifndef PET_H
#define PET_H

#include "AbstractEntity.h"
#include <string>
#include <iostream>

class Pet : public AbstractEntity {
private:
    std::string name;
    int age;

public:
    // Constructori
    Pet(const std::string& name, int age);
    Pet(const Pet& other);

    // Operator de atribuire
    Pet& operator=(const Pet& other);

    // Destructor
    ~Pet();

    // Metode
    void speak() const;

    // Getters
    const std::string& getName() const;
    int getAge() const;
};

#endif // PET_H
