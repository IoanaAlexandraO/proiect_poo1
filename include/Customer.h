#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "AbstractEntity.h"
#include <string>
#include <iostream>

template<typename T>
class Customer : public AbstractEntity {
private:
    std::string name;
    T age;
public:
    Customer(const std::string& name, T age) : name(name), age(age) {}
    
    void speak() const override {
        std::cout << "Customer " << name << " says: Hello!" << std::endl;
    }
    
    T getAge() const {
        return age;
    }
    
    std::string getName() const {
        return name;
    }
};

#endif
