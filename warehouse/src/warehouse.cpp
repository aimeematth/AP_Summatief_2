#pragma once
#include <iostream>
#include <vector>
#include "include/warehouse.hpp"

Warehouse::Warehouse() {
}

void Warehouse::addEmployee(Employee employee) {
    employees.push_back(employee);
}

void Warehouse::addShelf(Shelf shelf) {
    shelves.push_back(shelf);
}

bool Warehouse::rearrangeShelf(Shelf& shelf) {
    bool employeeFound = false;
    for (Employee& employee : employees) {
        if (!employee.getBusy() && employee.getForkliftCertificate()) {
            employee.setBusy(true);
            employeeFound = true;
            break;
        }
    }

    if (!employeeFound) {
        return false;
    }

    
    for (int i = 0; i < shelf.pallets.size() - 1; i++) {
        for (int j = 0; j < shelf.pallets.size() - i - 1; j++) {
            if (shelf.pallets[j].getItemCount() > shelf.pallets[j + 1].getItemCount()) {
                shelf.swapPallet(j, j + 1);
            }
        }
    }

    for (Employee& employee : employees) {
        if (employee.getBusy()) {
            employee.setBusy(false);
            break;
        }
    }

    return true;
}

bool Warehouse::pickItems(std::string itemName, int itemCount) {
    int itemsLeft = itemCount;

    for (Shelf& shelf : shelves) {
        for (Pallet& pallet : shelf.pallets) {
            int availableItems = pallet.getItemCount();
            int itemsToPick = std::min(availableItems, itemsLeft);

            for (int i = 0; i < itemsToPick; i++) {
                if (!pallet.takeOne()) {
                    return false;
                }
                itemsLeft--;
            }

            if (itemsLeft == 0) {
                return true; 
            }
        }
    }

    return false;
}
