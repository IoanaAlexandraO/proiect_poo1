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
    Pet(const std::string& name, int age);
    Pet(const Pet& other);
    Pet& operator=(const Pet& other);
    ~Pet() override;
    // cppcheck-suppress unusedFunction
    void speak() const override;
    int getAge() const;
     const std::string& getName() const { return name; }

};
#endif
