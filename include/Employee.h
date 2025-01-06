#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {
protected:
    Employee() {}
public:
    virtual ~Employee() {}
    virtual void work() const = 0;
};

#endif
