#ifndef PET_SHOP_H
#define PET_SHOP_H

#include "Pet.h"
#include "Customer.h"
#include <vector>
#include <list>
#include <algorithm>

class PetShop {
private:
    std::vector<Pet<int>> pets;
    std::list<Customer> customers;
    static int totalSales;
    PetShop() {}
public:
    static PetShop& getInstance();
    void addPet(const Pet<int>& pet);
    void addCustomer(const Customer& customer);
    void sellPet(const Pet<int>& pet);
    static int getTotalSales();
    void sortPetsByAge();
    void displayPets() const; // Metodă nouă pentru afișare
};

#endif

