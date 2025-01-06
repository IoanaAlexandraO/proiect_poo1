#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"
#include <iostream>

class Manager : public Employee {
public:
    void work() const override;
};

#endif
