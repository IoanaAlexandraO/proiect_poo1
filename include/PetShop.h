#ifndef PET_SHOP_H
#define PET_SHOP_H

#include "Pet.h"
#include "Customer.h"
#include <vector>
#include <list>
#include <algorithm>

class PetShop {
private:
    std::vector<Pet> pets;
    std::list<Customer> customers;
    static int totalSales;
    PetShop() {}

public:
    static PetShop& getInstance(); // metoda de instanțiere unică
    void addPet(const Pet& pet);   // adăugarea unui animal
    void addCustomer(const Customer& customer); // adăugarea unui client
    void sellPet(const Pet& pet);  // vânzarea unui animal
    static int getTotalSales();    // obținerea vânzărilor totale
    void sortPetsByAge();         // sortarea animalelor după vârstă
    
    // metoda pentru a obține lista de animale
    std::vector<Pet>& getPets() { return pets; }
};

#endif // PET_SHOP_H

