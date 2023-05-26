#include <iostream>
#include <vector>
#include "employee.hpp"
#include "shelf.hpp"
#include "pallet.hpp"

class Warehouse{

    public:
        std::vector<Employee> employees;
        std::vector<Shelf> shelves;
        Warehouse();
        void addEmployee(Employee employee);
        void addShelf(Shelf shelf);
        bool rearrangeShelf(Shelf& shelf);
        bool pickItems(std::string ItemName, int ItemCount);




};