#include <iostream>
#include <fstream>
#include "PetShop.h"
#include "Pet.h"
#include "Customer.h"
#include "Employee.h"
#include "Cashier.h"
#include "Manager.h"
#include "CustomException.h"

int main() {
    PetShop& petShop = PetShop::getInstance();
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
        std::cout << "==================\n";
        std::cout << "Enter your choice: ";
        inputFile >> choice;
        
        switch (choice) {
            case 1: {
                std::string name;
                int age;
                std::cout << "\nEnter pet name: ";
                inputFile >> name;
                std::cout << "Enter pet age: ";
                inputFile >> age;
                Pet<int> pet(name, age);
                petShop.addPet(pet);
                std::cout << "Pet " << name << " added successfully!\n";
                break;
            }
            case 2: {
                std::string name;
                int age;
                std::cout << "\nEnter customer name: ";
                inputFile >> name;
                std::cout << "Enter customer age: ";
                inputFile >> age;
                Customer<int> customer(name, age);  // Modificat pentru Customer template
                petShop.addCustomer(customer);
                std::cout << "Customer " << name << " added successfully!\n";
                break;
            }
            case 3: {
                std::string name;
                std::cout << "\nEnter pet name to sell: ";
                inputFile >> name;
                Pet<int> pet(name, 0);
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
            default: {
                std::cout << "\nInvalid choice. Please try again.\n";
            }
        }
    } while (choice != 6);
    
    inputFile.close();
    return 0;
}
