#include "Pet.h"
#include "Customer.h"
#include "Employee.h"
#include "Cashier.h"
#include "Manager.h"
#include "CustomException.h"
#include "PetShop.h"
#include <iostream>
#include <string>
#include <limits>

void clearInputStream() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    try {
        PetShop& petShop = PetShop::getInstance();
        Cashier cashier;  // Remove constructor parameters since they're not properly defined
        int choice;
        std::string name;
        
        do {
            std::cout << "\n=== Pet Shop Management System ===\n";
            std::cout << "1. Add Pet\n";
            std::cout << "2. Add Customer\n";
            std::cout << "3. Sell Pet\n";
            std::cout << "4. Get Total Sales\n";
            std::cout << "5. Sort Pets by Age\n";
            std::cout << "6. Make Pet Speak\n";
            std::cout << "7. Cashier Work\n";
            std::cout << "8. Exit\n";
            std::cout << "Enter your choice: ";
            
            if (!(std::cin >> choice)) {
                std::cout << "Invalid input. Please enter a number.\n";
                clearInputStream();
                continue;
            }
            
            clearInputStream();  // Clear any leftover newline
            
            switch (choice) {
                case 1: {
                    int age;
                    std::cout << "Enter pet name: ";
                    std::getline(std::cin, name);
                    
                    std::cout << "Enter pet age: ";
                    if (!(std::cin >> age)) {
                        std::cout << "Invalid age input.\n";
                        clearInputStream();
                        break;
                    }
                    clearInputStream();
                    
                    try {
                        Pet pet(name, age);
                        petShop.addPet(pet);
                        pet.speak();
                    } catch (const CustomException& e) {
                        std::cout << "Error: " << e.what() << std::endl;
                    }
                    break;
                }
                case 2: {
                    std::cout << "Enter customer name: ";
                    std::getline(std::cin, name);
                    try {
                        Customer customer(name);
                        petShop.addCustomer(customer);
                        std::cout << "Customer added successfully.\n";
                    } catch (const CustomException& e) {
                        std::cout << "Error: " << e.what() << std::endl;
                    }
                    break;
                }
                case 3: {
                    std::cout << "Enter pet name to sell: ";
                    std::getline(std::cin, name);
                    try {
                        Pet pet(name, 0);  // Age isn't needed for search
                        petShop.sellPet(pet);
                        cashier.work();
                        std::cout << "Pet sold successfully.\n";
                    } catch (const CustomException& e) {
                        std::cout << "Error: " << e.what() << std::endl;
                    }
                    break;
                }
                case 4: {
                    std::cout << "Total sales: $" << petShop.getTotalSales() << std::endl;
                    break;
                }
                case 5: {
                    petShop.sortPetsByAge();
                    std::cout << "Pets sorted by age.\n";
                    break;
                }
                case 6: {
                    std::cout << "Enter pet name to make it speak: ";
                    std::getline(std::cin, name);
                    try {
                        Pet pet(name, 0);  // Age isn't needed for speak
                        pet.speak();
                    } catch (const CustomException& e) {
                        std::cout << "Error: " << e.what() << std::endl;
                    }
                    break;
                }
                case 7: {
                    cashier.work();
                    break;
                }
                case 8: {
                    std::cout << "Exiting...\n";
                    break;
                }
                default:
                    std::cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 8);
        
    } catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
