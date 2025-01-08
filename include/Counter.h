#ifndef COUNTER_H
#define COUNTER_H

#include <iostream>

template<typename T>
class Counter {
private:
    T count;
    std::string type;
    
public:
    Counter(std::string animalType) : count(0), type(animalType) {}
    
    void increment() {
        count++;
    }
    
    T getCount() const {
        return count;
    }
    
    void display() const {
        std::cout << "Număr de " << type << ": " << count << std::endl;
    }
};

#endif
