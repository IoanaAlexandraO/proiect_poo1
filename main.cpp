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
    
    do {
        std::cout << "1. Add Pet\n";
        std::cout << "2. Add Customer\n";
        std::cout << "3. Sell Pet\n";
        std::cout << "4. Get Total Sales\n";
        std::cout << "5. Sort Pets by Age\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        
        switch (choice) {
            case 1: {
                std::string name;
                int age;
                std::cout << "Enter pet name: ";
                std::cin >> name;
                std::cout << "Enter pet age: ";
                std::cin >> age;
                Pet pet(name, age);
                petShop.addPet(pet);
                break;
            }
            case 2: {
                std::string name;
                int age;
                std::cout << "Enter customer name: ";
                std::cin >> name;
                std::cout << "Enter customer age: ";
                std::cin >> age;
                Customer customer(name, age);
                petShop.addCustomer(customer);
                break;
            }
            case 3: {
    std::string name;
    std::cout << "Enter pet name to sell: ";
    std::getline(std::cin, name);
    try {
        Pet pet(name, 0);
        petShop.sellPet(pet);
        cashier.work();  // Asigură-te că această linie există
    } catch (const CustomException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    break;
}
            case 4:
                std::cout << "Total sales: " << PetShop::getTotalSales() << std::endl;
                break;
            case 5:
                petShop.sortPetsByAge();
                break;
            case 6: {
    std::string name;
    std::cout << "Enter pet name to make it speak: ";
    std::getline(std::cin, name);
    try {
        Pet pet(name, 0);
        pet.speak();  // Asigură-te că această linie există
    } catch (const CustomException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    break;
}
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }
    } while (choice != 6);
    
    return 0;
}
