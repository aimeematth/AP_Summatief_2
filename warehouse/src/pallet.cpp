#include "pallet.hpp"

Pallet::Pallet(std::string ItemName, int ItemCapacity, int ItemCount){
    this->ItemName = ItemName;
    this->ItemCapacity = ItemCapacity;
    this->ItemCount = ItemCount;
    }

Pallet::Pallet() : ItemCount(0), ItemCapacity(0) {}

std::string Pallet::getItemName() {
    return ItemName;
}

int Pallet::getItemCount() {
    return ItemCount;
}

int Pallet::getRemainingSpace() {
   return ItemCapacity - ItemCount;
}

bool Pallet::reallocateEmptyPallet(std::string ItemName, int ItemCapacity){ 
    if (ItemCount == 0) {
        this->ItemName = ItemName;
        this->ItemCapacity = ItemCapacity;
        return true;
    }
    return false;
}

bool Pallet::takeOne() {
    if (ItemCount > 0){
        ItemCount --;
        return true;
    }
    return false;
}

bool Pallet::putOne() {
    if (ItemCount < ItemCapacity) {
        ItemCount++;
        return true;
    }
    return false;
}