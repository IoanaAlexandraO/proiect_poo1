#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include "PetShop.h"
#include "Pet.h"
#include "Customer.h"
#include "Counter.h"

int main() {
    PetShop& petShop = PetShop::getInstance();
    Counter<int> petCounter("Număr animale: ");
    Counter<int> clientCounter("Număr clienți: ");
    
    std::ifstream inputFile("tastatura.txt");
    if (!inputFile) {
        std::cout << "Error opening file tastatura.txt!" << std::endl;
        return 1;
    }

    int choice;
    do {
        inputFile >> choice;
        std::cout << "\n--- Pet Shop Menu ---\n";
        std::cout << "1. Add Pet\n";
        std::cout << "2. Add Customer\n";
        std::cout << "3. Sell Pet\n";
        std::cout << "4. Get Total Sales\n";
        std::cout << "5. Sort Pets by Age\n";
        std::cout << "6. Exit\n";
        std::cout << "Entered choice: " << choice << "\n";

        switch (choice) {
            case 1: {
                std::string name;
                int age;
                inputFile >> name >> age;
                Pet pet(name, age);
                petShop.addPet(pet);
                petCounter.increment();
                std::cout << "Pet added successfully.\n";
                break;
            }
            case 2: {
                std::string name;
                int age;
                inputFile >> name >> age;
                Customer customer(name, age);
                petShop.addCustomer(customer);
                clientCounter.increment();
                std::cout << "Customer added successfully.\n";
                break;
            }
            case 3: {
                std::string name;
                inputFile >> name;
                try {
                    auto& pets = petShop.getPets();
                    auto it = std::find_if(pets.begin(), pets.end(),
                                           [&name](const Pet& pet) { return pet.getName() == name; });
                    if (it != pets.end()) {
                        petShop.sellPet(*it);
                        std::cout << "Pet sold successfully.\n";
                    } else {
                        std::cout << "Pet not found in inventory.\n";
                    }
                } catch (const std::runtime_error& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            }
            case 4:
                std::cout << "Total sales: " << petShop.getTotalSales() << std::endl;
                break;
            case 5:
                petShop.sortPetsByAge();
                std::cout << "Pets sorted by age.\n";
                break;
            case 6:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    inputFile.close();
    return 0;
}
