#include "PetShop.h"
#include "CustomException.h"
#include <algorithm>

PetShop* PetShop::instance = nullptr;
int PetShop::totalSales = 0;

PetShop& PetShop::getInstance() {
    if (instance == nullptr) {
        instance = new PetShop();
    }
    return *instance;
}

void PetShop::addPet(const Pet& pet) {
    pets.push_back(pet);
}

// cppcheck-suppress unusedFunction
void PetShop::addCustomer(const Customer& customer) {
    customers.push_back(customer);
}

void PetShop::sellPet(const Pet& pet) {
    auto it = std::find_if(pets.begin(), pets.end(),
        [&pet](const Pet& p) { 
            return p.getName() == pet.getName(); 
        });
        
    if (it != pets.end()) {
        totalSales += 100;
        pets.erase(it);
    } else {
        throw CustomException("Pet not found!");
    }
}

// cppcheck-suppress unusedFunction
int PetShop::getTotalSales() {
    return totalSales;
}

// cppcheck-suppress unusedFunction
void PetShop::sortPetsByAge() {
    std::sort(pets.begin(), pets.end(),
        [](const Pet& a, const Pet& b) {
            return a.getAge() < b.getAge();
        });
}

const std::vector<Pet>& PetShop::getPets() const {
    return pets;
}

const std::vector<Customer>& PetShop::getCustomers() const {
    return customers;
}
