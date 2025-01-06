#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "AbstractEntity.h"
#include <string>
#include <iostream>

class Customer : public AbstractEntity {
private:
    std::string name;
    int age;
public:
    Customer(const std::string& name, int age);
    Customer(const Customer& other);
    Customer& operator=(const Customer& other);
    ~Customer();
    void speak() const override;
    friend std::ostream& operator<<(std::ostream& os, const Customer& customer);
    friend std::istream& operator>>(std::istream& is, Customer& customer);
    bool operator==(const Customer& other) const;
};

#endif
