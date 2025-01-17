#pragma once
#include "include/shelf.hpp"


Shelf::Shelf() {
    // Zorg ervoor dat alle pallets worden geïnitialiseerd met een itemcount van 0
    for (int i = 0; i < pallets.size(); i++) {
        pallets[i] = Pallet("", 0, 0);
    }
}

bool Shelf::swapPallet(int slot, int slot2) {
    Pallet pallet1 = this ->pallets[slot];
    Pallet pallet2 = this ->pallets[slot2];
    this->pallets[slot] = pallet2;
    this->pallets[slot2] = pallet1;
    return true;
}
bool Shelf::isEmpty() {
    for (Pallet& pallet : pallets) {
        if (!pallet.isEmpty()) {
            return false;
        }
    }
    return true;
}

bool Shelf::isFull() {
    for (Pallet& pallet : pallets) {
        if (!pallet.isFull()) {
            return false;
        }
    }
    return true;
}

