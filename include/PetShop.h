#ifndef PET_SHOP_H
#define PET_SHOP_H

#include "Pet.h"
#include "Customer.h"
#include <vector>
#include <list>
#include <algorithm>
#include <memory>

class PetShop {
private:
    static PetShop* instance;
    std::vector<Pet> pets;
    std::list<Customer> customers;
    static int totalSales;
    
    // Private constructor for Singleton
    PetShop() = default;
    
    // Delete copy constructor and assignment operator
    PetShop(const PetShop&) = delete;
    PetShop& operator=(const PetShop&) = delete;

public:
    // Singleton instance getter
    static PetShop& getInstance() {
        if (instance == nullptr) {
            instance = new PetShop();
        }
        return *instance;
    }
    
    // Destructor
    ~PetShop() {
        delete instance;
    }

    // Pet management
    void addPet(const Pet& pet);
    void sellPet(const Pet& pet);
    const std::vector<Pet>& getPets() const { return pets; }
    void sortPetsByAge();

    // Customer management
    void addCustomer(const Customer& customer);
    const std::list<Customer>& getCustomers() const { return customers; }

    // Sales management
    static int getTotalSales() { return totalSales; }

    // Optional: Search functionality
    Pet* findPetByName(const std::string& name);
    Customer* findCustomerByName(const std::string& name);
};

// Define static members
inline PetShop* PetShop::instance = nullptr;
inline int PetShop::totalSales = 0;

#endif // PET_SHOP_H
