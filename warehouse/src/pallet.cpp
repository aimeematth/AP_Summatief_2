#pragma once
#include "include/pallet.hpp"

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
    if (this->ItemCount > 0){
        this->ItemCount --;
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

bool Pallet::isEmpty(){
    if(getItemCount() == 0){
        return true;
    }
    return false;
    
}

bool Pallet::isFull(){
    if(ItemCount == ItemCapacity){
        return true;
    }
    return false;
}