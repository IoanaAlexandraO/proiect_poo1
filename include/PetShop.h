#ifndef PET_SHOP_H
#define PET_SHOP_H

#include "Pet.h"
#include "Customer.h"
#include <vector>
#include <list>
#include <algorithm>
#include <memory> // For smart pointers if needed

class PetShop {
private:
    std::vector<Pet> pets;
    std::list<Customer> customers;
    static int totalSales;
    static PetShop* instance; // Static instance for Singleton pattern

    // Private constructor to prevent instantiation
    PetShop() {}

public:
    // Deleted copy constructor and assignment operator for Singleton
    PetShop(const PetShop&) = delete;
    PetShop& operator=(const PetShop&) = delete;

    // Singleton accessor
    static PetShop& getInstance() {
        if (!instance) {
            instance = new PetShop();
        }
        return *instance;
    }

    // Destructor
    ~PetShop() {
        delete instance;
        instance = nullptr;
    }

    // Methods
    void addPet(const Pet& pet);
    void addCustomer(const Customer& customer);
    void sellPet(const Pet& pet);
    static int getTotalSales();
    void sortPetsByAge();

    // Accessors
    const std::vector<Pet>& getPets() const { return pets; }
    const std::list<Customer>& getCustomers() const { return customers; }
};

#endif // PET_SHOP_H

