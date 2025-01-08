#include "PetShop.h"
#include "CustomException.h"

int PetShop::totalSales = 0;

PetShop& PetShop::getInstance() {
    static PetShop instance;
    return instance;
}

void PetShop::addPet(const Pet<int>& pet) {
    pets.push_back(pet);
}

void PetShop::addCustomer(const Customer<int>& customer) {  // Modificat pentru Customer template
    customers.push_back(customer);
}

void PetShop::sellPet(const Pet<int>& pet) {
    if (pet.getAge() < 0) {
        throw CustomException();
    }
    totalSales++;
}

int PetShop::getTotalSales() {
    return totalSales;
}

void PetShop::sortPetsByAge() {
    std::sort(pets.begin(), pets.end(), [](const Pet<int>& a, const Pet<int>& b) {
        return a.getAge() < b.getAge();
    });
    displayPets();
}

void PetShop::displayPets() const {
    std::cout << "\nLista animalelor sortate după vârstă:" << std::endl;
    for (const auto& pet : pets) {
        std::cout << "Nume: " << pet.getName() << ", Vârstă: " << pet.getAge() << std::endl;
    }
    std::cout << std::endl;
}

void PetShop::displayCustomers() const {
    std::cout << "\nLista clienților:" << std::endl;
    for (const auto& customer : customers) {
        std::cout << "Nume: " << customer.getName() << ", Vârstă: " << customer.getAge() << std::endl;
    }
    std::cout << std::endl;
}
