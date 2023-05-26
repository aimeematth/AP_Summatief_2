#pragma once
#include "include/pallet.hpp"

Pallet::Pallet(std::string ItemName, int ItemCapacity, int ItemCount){
    this->ItemName = ItemName;
    this->ItemCapacity = ItemCapacity;
    this->ItemCount = ItemCount;
    }

Pallet::Pallet() : ItemCount(0), ItemCapacity(0) {}

std::string Pallet::getItemName() {
    return this->ItemName;
}

int Pallet::getItemCount() {
    return this->ItemCount;
}

int Pallet::getRemainingSpace() {
   return this->ItemCapacity - this->ItemCount;
}

bool Pallet::reallocateEmptyPallet(std::string ItemName, int ItemCapacity){ 
    if (this->ItemCount == 0) {
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
    if (this->ItemCount < this->ItemCapacity) {
        this->ItemCount++;
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
    if(this->ItemCount == this->ItemCapacity){
        return true;
    }
    return false;
}