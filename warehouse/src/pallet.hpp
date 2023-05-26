#include <iostream>

class Pallet{
    private:
        int ItemCount;
        std::string ItemName;
        int ItemCapacity;

    public:
        Pallet(std::string ItemName, int ItemCapacity, int ItemCount);
        Pallet();
        std::string getItemName();
        int getItemCount();
        int getRemainingSpace();
        bool reallocateEmptyPallet(std::string ItemName, int ItemCapacity);
        bool takeOne();
        bool putOne();
};