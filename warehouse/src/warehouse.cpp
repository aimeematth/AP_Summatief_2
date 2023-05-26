#include <iostream>
#include <vector>
#include "employee.hpp"
#include "shelf.hpp"
#include "pallet.hpp"
#include "warehouse.hpp"

Warehouse::Warehouse() {
    // Lege constructor
}

void Warehouse::addEmployee(Employee employee) {
    employees.push_back(employee);
}

void Warehouse::addShelf(Shelf shelf) {
    shelves.push_back(shelf);
}

bool Warehouse::rearrangeShelf(Shelf& shelf) {
    // Controleer of er een medewerker met een heftruckcertificaat beschikbaar is
    bool employeeFound = false;
    for (Employee& employee : employees) {
        if (!employee.getBusy() && employee.getForkliftCertificate()) {
            employee.setBusy(true);
            employeeFound = true;
            break;
        }
    }

    if (!employeeFound) {
        return false; // Geen geschikte medewerker gevonden
    }

    // Sorteer de pallets oplopend op volgorde van itemcount
    for (int i = 0; i < shelf.pallets.size() - 1; i++) {
        for (int j = 0; j < shelf.pallets.size() - i - 1; j++) {
            if (shelf.pallets[j].getItemCount() > shelf.pallets[j + 1].getItemCount()) {
                shelf.swapPallet(j, j + 1);
            }
        }
    }

    // Geef de medewerker vrij
    for (Employee& employee : employees) {
        if (employee.getBusy()) {
            employee.setBusy(false);
            break;
        }
    }

    return true;
}

bool Warehouse::pickItems(std::string itemName, int itemCount) {
    // Verdeel het aantal items over alle pallets op de planken
    int itemsLeft = itemCount;

    for (Shelf& shelf : shelves) {
        for (Pallet& pallet : shelf.pallets) {
            int availableItems = pallet.getItemCount();
            int itemsToPick = std::min(availableItems, itemsLeft);

            for (int i = 0; i < itemsToPick; i++) {
                if (!pallet.takeOne()) {
                    return false; // Niet genoeg items op de pallet
                }
                itemsLeft--;
            }

            if (itemsLeft == 0) {
                return true; // Alle items zijn opgehaald
            }
        }
    }

    return false; // Niet genoeg items beschikbaar op de planken
}
