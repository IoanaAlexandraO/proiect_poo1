#ifndef STATISTICS_H
#define STATISTICS_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>

template<typename T>
class Statistics {
private:
    std::vector<T> data;
    std::string category;  // pentru a ști ce tip de date conține

public:
    Statistics(const std::string& cat) : category(cat) {}

    void addValue(T value) {
        data.push_back(value);
    }

    void displayStatistics() const {
        if(data.empty()) {
            std::cout << "\nNu există date pentru " << category << "!\n";
            return;
        }

        std::cout << "\n=== Statistici pentru " << category << " ===\n";
        std::cout << "Număr total: " << data.size() << "\n";
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Media: " << getAverage() << "\n";
        std::cout << "Minim: " << getMin() << "\n";
        std::cout << "Maxim: " << getMax() << "\n";
        std::cout << "========================\n";
    }

    double getAverage() const {
        if (data.empty()) return 0;
        T sum = 0;
        for (const T& value : data) {
            sum += value;
        }
        return static_cast<double>(sum) / data.size();
    }

    T getMax() const {
        if (data.empty()) return T();
        return *std::max_element(data.begin(), data.end());
    }

    T getMin() const {
        if (data.empty()) return T();
        return *std::min_element(data.begin(), data.end());
    }

    size_t getCount() const {
        return data.size();
    }

    void clear() {
        data.clear();
    }
};

#endif
