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
    std::list<Customer<int>> customers;  // Modificat pentru Customer template
    static int totalSales;
    PetShop() {}
public:
    static PetShop& getInstance();
    void addPet(const Pet<int>& pet);
    void addCustomer(const Customer<int>& customer);  // Modificat pentru Customer template
    void sellPet(const Pet<int>& pet);
    static int getTotalSales();
    void sortPetsByAge();
    void displayPets() const;
    void displayCustomers() const;  // Opțional: pentru a vedea lista de clienți
};

#endif
