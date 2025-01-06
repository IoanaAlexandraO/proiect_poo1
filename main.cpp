#include "Pet.h"
#include "Customer.h"
#include "Employee.h"
#include "Cashier.h"
#include "Manager.h"
#include "CustomException.h"

int main() {
    PetShop& petShop = PetShop::getInstance();
    Cashier cashier("John", 30); // Adăugăm un casier
    int choice;
    
    do {
        std::cout << "\n=== Pet Shop Management System ===\n";
        std::cout << "1. Add Pet\n";
        std::cout << "2. Add Customer\n";
        std::cout << "3. Sell Pet\n";
        std::cout << "4. Get Total Sales\n";
        std::cout << "5. Sort Pets by Age\n";
        std::cout << "6. Make Pet Speak\n";    // Opțiune nouă
        std::cout << "7. Cashier Work\n";      // Opțiune nouă
        std::cout << "8. Exit\n";
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
                pet.speak(); // Folosim funcția speak() când adăugăm un nou animal
                break;
            }
            case 2: {
                // ... codul existent pentru adăugarea unui client ...
                break;
            }
            case 3: {
                std::string name;
                std::cout << "Enter pet name to sell: ";
                std::cin >> name;
                Pet pet(name, 0);
                try {
                    petShop.sellPet(pet);
                    cashier.work(); // Folosim funcția work() când vindem un animal
                } catch (const CustomException& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            }
            case 4: {
                // ... codul existent pentru afișarea vânzărilor totale ...
                break;
            }
            case 5: {
                // ... codul existent pentru sortarea animalelor după vârstă ...
                break;
            }
            case 6: {
                std::string name;
                std::cout << "Enter pet name to make it speak: ";
                std::cin >> name;
                Pet pet(name, 0);
                pet.speak();
                break;
            }
            case 7: {
                cashier.work();
                break;
            }
            case 8: {
                std::cout << "Exiting..." << std::endl;
                break;
            }
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }
    } while (choice != 8);
    
    return 0;
}
