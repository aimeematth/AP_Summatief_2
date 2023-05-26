#include <iostream>
#include "src/include/warehouse.hpp"
int main() {
    // Creëer werknemers
    Employee employee1("Shakira", true);
    Employee employee2("Alice", false);

    // Creëer planken
    Shelf shelf1;
    Shelf shelf2;

    Pallet pallet1("ItemA", 20, 10);
    Pallet pallet2("ItemB", 8, 3);

    // Creëer een magazijn
    Warehouse warehouse;

    // Voeg werknemers toe aan het magazijn
    warehouse.addEmployee(employee1);
    warehouse.addEmployee(employee2);

    // Voeg planken toe aan het magazijn
    warehouse.addShelf(shelf1);
    warehouse.addShelf(shelf2);

    // Rearrange een plank
    std::cout << "Rearranging shelf 1..." << std::endl;
    bool rearrangeSuccess = warehouse.rearrangeShelf(shelf1);
    if (rearrangeSuccess) {
        std::cout << "Shelf 1 rearranged successfully." << std::endl;
    } else {
        std::cout << "Failed to rearrange shelf 1. No certified employee available." << std::endl;
    }

    // Pak items van de planken
    std::cout << "Picking 5 items..." << std::endl;
    bool pickSuccess = warehouse.pickItems("ItemA", 5);
    if (pickSuccess) {
        std::cout << "Items picked successfully." << std::endl;
    } else {
        std::cout << "Failed to pick items. Not enough items available." << std::endl;
    }

    return 0;
}
