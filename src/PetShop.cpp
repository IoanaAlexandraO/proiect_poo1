#include "PetShop.h"
#include "CustomException.h"
#include <iostream> // Pentru afișare

int PetShop::totalSales = 0;

PetShop& PetShop::getInstance() {
    static PetShop instance;
    return instance;
}

void PetShop::addPet(const Pet& pet) {
    pets.push_back(pet);
}

void PetShop::addCustomer(const Customer& customer) {
    customers.push_back(customer);
}

void PetShop::sellPet(const Pet& pet) {
    if (pet.getAge() < 0) {
        throw CustomException();
    }
    // Sell the pet
    totalSales++;
}

int PetShop::getTotalSales() {
    return totalSales;
}

void PetShop::sortPetsByAge() {
    std::sort(pets.begin(), pets.end(), [](const Pet& a, const Pet& b) {
        return a.getAge() < b.getAge(); // Sortează după vârstă
    });

    // Afișează animalele sortate
    if (pets.empty()) {
        std::cout << "No pets in the shop to sort." << std::endl;
        return;
    }

    std::cout << "Pets sorted by age:" << std::endl;
    for (const auto& pet : pets) {
        std::cout << "Name: " << pet.getName() << ", Age: " << pet.getAge() << std::endl;
    }
}
