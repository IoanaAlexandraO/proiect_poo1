#ifndef CASHIER_H
#define CASHIER_H

#include "Employee.h"
#include <iostream>

class Cashier : public Employee {
public:
// cppcheck-suppress unusedFunction
    void work() const override;
};

#endif
