#include "shelf.hpp"
#include "pallet.hpp"
#include "IContainer.hpp"


Shelf::Shelf() {
    // Zorg ervoor dat alle pallets worden geïnitialiseerd met een itemcount van 0
    for (int i = 0; i < pallets.size(); i++) {
        pallets[i] = Pallet("", 0, 0);
    }
}

bool Shelf::swapPallet(int slot, int slot2) {
    if (slot < 0 || slot >= pallets.size() || slot2 < 0 || slot2 >= pallets.size()) {
        return false; // Ongeldige slotnummers
    }

    std::swap(pallets[slot], pallets[slot2]);
    return true;
}
