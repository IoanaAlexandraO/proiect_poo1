#ifndef COUNTER_H
#define COUNTER_H

#include <iostream>
#include <string>

template<typename T>
class Counter {
private:
    T count;
    std::string message;
    
public:
    explicit Counter(const std::string& msg) : count(0), message(msg) {}
    
    void increment() {
        ++count;
        std::cout << message << count << std::endl;
    }
};

#endif
