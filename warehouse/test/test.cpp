#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "include/catch.hpp"
#include "include/warehouse.hpp"
// Find all tests in test*.cpp in test/

TEST_CASE("Employee Tests") {
    SECTION("Checking initial state of employees") {
        Employee employee1("Bob", true);
        Employee employee2("Shakira", false);

        REQUIRE(employee1.getBusy() == false);
        REQUIRE(employee2.getBusy() == false);
        REQUIRE(employee1.getForkliftCertificate() == true);
        REQUIRE(employee2.getForkliftCertificate() == false);
    }

    SECTION("Setting busy state of employees") {
        Employee employee1("Bob", true);
        Employee employee2("Shakira", false);

        employee1.setBusy(true);
        employee2.setBusy(true);

        REQUIRE(employee1.getBusy() == true);
        REQUIRE(employee2.getBusy() == true);
    }
}

TEST_CASE("Pallet Tests") {
    SECTION("Checking remaining space") {
        Pallet pallet1("Books", 80, 20);
        Pallet pallet2("Mascara", 50, 40);

        REQUIRE(pallet1.getRemainingSpace() == 60);
        REQUIRE(pallet2.getRemainingSpace() == 10);
    }

    SECTION("Taking items from pallet") {
        Pallet pallet1("Books", 5, 3);
        Pallet pallet2("Mascara", 5, 2);

        bool result1 = pallet1.takeOne();
        bool result2 = pallet2.takeOne();

        REQUIRE(result1 == true);
        REQUIRE(result2 == true);
        REQUIRE(pallet1.getItemCount() == 2);
        REQUIRE(pallet2.getItemCount() == 1);
    }
}

TEST_CASE("Warehouse pickItems Test") {
    Warehouse warehouse;
    Employee employee("Bob", true);
    Shelf shelf;
    Pallet pallet1("Books", 5, 3);
    Pallet pallet2("Mascara", 5, 2);
    shelf.pallets[0] = pallet1;
    shelf.pallets[1] = pallet2;
    warehouse.addEmployee(employee);
    warehouse.addShelf(shelf);

    SECTION("Picking items from the shelf") {
        bool itemsPicked = warehouse.pickItems("Books", 2);

        REQUIRE(itemsPicked == true);
        REQUIRE(shelf.pallets[0].getItemCount() == 1);
    }
}

TEST_CASE("Warehouse pickItems Test") {
    Warehouse warehouse;
    Employee employee("Bob", true);
    Shelf shelf;
    Pallet pallet1("Books", 5, 3);
    Pallet pallet2("Mascara", 5, 2);
    shelf.pallets[0] = pallet1;
    shelf.pallets[1] = pallet2;
    warehouse.addEmployee(employee);
    warehouse.addShelf(shelf);

    SECTION("Picking items from the shelf") {
        bool itemsPicked = warehouse.pickItems("Books", 2);

        REQUIRE(itemsPicked == true);
        REQUIRE(shelf.pallets[0].getItemCount() == 1);
    }
}

TEST_CASE("Warehouse pickItems Test - Valid Item") {
    Warehouse warehouse;
    Shelf shelf;
    Pallet pallet1("Books", 5, 3);
    shelf.pallets[0] = pallet1;

    GIVEN("A shelf with items and picking a valid item") {
        std::string itemName = "Books";
        int itemCount = 2;

        WHEN("Picking items from the shelf") {
            bool itemsPicked = warehouse.pickItems(itemName, itemCount);

            THEN("Items are successfully picked") {
                REQUIRE(itemsPicked == true);
                REQUIRE(shelf.pallets[0].getItemCount() == 1);
            }
        }
    }
}

TEST_CASE("Warehouse pickItems Test - Invalid Item") {
    Warehouse warehouse;
    Shelf shelf;
    Pallet pallet1("Books", 5, 3);
    shelf.pallets[0] = pallet1;

    GIVEN("A shelf with items and picking an invalid item") {
        std::string itemName = "Chairs";
        int itemCount = 2;

        WHEN("Picking items from the shelf") {
            bool itemsPicked = warehouse.pickItems(itemName, itemCount);

            THEN("Items cannot be picked") {
                REQUIRE(itemsPicked == false);
                REQUIRE(shelf.pallets[0].getItemCount() == 3);
            }
        }
    }
}
