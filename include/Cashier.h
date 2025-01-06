#ifndef CASHIER_H
#define CASHIER_H

#include "Employee.h"
#include <iostream>

class Cashier : public Employee {
public:
    void work() const override;
};

#endif
