#include <iostream>
#include <fstream>
#include "PetShop.h"
#include "Pet.h"
#include "Customer.h"
#include "Statistics.h"
#include "CustomException.h"

int main() {
    PetShop& petShop = PetShop::getInstance();
    Statistics<int> humanAgeStats("Vârste oameni");     // Pentru vârstele clienților
    Statistics<float> petAgeStats("Vârste animale");    // Pentru vârstele animalelor
    int choice;
    std::ifstream inputFile("tastatura.txt");
    
    if (!inputFile) {
        std::cout << "Failed to open input file." << std::endl;
        return 1;
    }
    
    do {
        std::cout << "\n=== Pet Shop Menu ===\n";
        std::cout << "1. Add Pet\n";
        std::cout << "2. Add Customer\n";
        std::cout << "3. Sell Pet\n";
        std::cout << "4. Get Total Sales\n";
        std::cout << "5. Sort Pets by Age\n";
        std::cout << "6. Exit\n";
        std::cout << "7. Show All Statistics\n";
        std::cout << "==================\n";
        std::cout << "Enter your choice: ";
        inputFile >> choice;
        
        switch (choice) {
            case 1: {
                std::string name;
                float age;  // Folosim float pentru vârsta animalelor
                std::cout << "\nEnter pet name: ";
                inputFile >> name;
                std::cout << "Enter pet age: ";
                inputFile >> age;
                Pet<float> pet(name, age);
                petShop.addPet(pet);
                petAgeStats.addValue(age);
                std::cout << "Pet " << name << " added successfully!\n";
                break;
            }
            case 2: {
                std::string name;
                int age;    // Folosim int pentru vârsta oamenilor
                std::cout << "\nEnter customer name: ";
                inputFile >> name;
                std::cout << "Enter customer age: ";
                inputFile >> age;
                Customer customer(name, age);
                petShop.addCustomer(customer);
                humanAgeStats.addValue(age);
                std::cout << "Customer " << name << " added successfully!\n";
                break;
            }
            case 3: {
                std::string name;
                std::cout << "\nEnter pet name to sell: ";
                inputFile >> name;
                Pet<float> pet(name, 0);
                try {
                    petShop.sellPet(pet);
                    std::cout << "Pet " << name << " sold successfully!\n";
                } catch (const CustomException& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 4: {
                std::cout << "\nTotal sales: " << PetShop::getTotalSales() << std::endl;
                break;
            }
            case 5: {
                std::cout << "\nSorting and displaying pets by age...\n";
                petShop.sortPetsByAge();
                break;
            }
            case 6: {
                std::cout << "\nThank you for using Pet Shop Management System!\n";
                std::cout << "Exiting...\n";
                break;
            }
            case 7: {
                std::cout << "\n=== STATISTICI GENERALE ===\n";
                humanAgeStats.displayStatistics();
                petAgeStats.displayStatistics();
                break;
            }
            default: {
                std::cout << "\nInvalid choice. Please try again.\n";
            }
        }
    } while (choice != 6);
    
    inputFile.close();
    return 0;
}
