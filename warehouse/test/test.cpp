#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "include/catch.hpp"
#include "include/warehouse.hpp"
// Find all tests in test*.cpp in test/

TEST_CASE("Employee Tests") {
    Employee employee1("Bob", true);
    Employee employee2 ("Shakira", false);

    REQUIRE(employee1.getName() == "Bob");
    REQUIRE(employee1.getBusy() == false);
    REQUIRE(employee2.getName() == "Shakira");
    REQUIRE(employee2.getBusy() == true);

    employee1.setBusy(true);
    REQUIRE(employee1.getBusy() == true);
    employee2.setBusy(false);
    REQUIRE(employee2.getBusy() == false);

    employee1.setForkliftCertificate(false);
    REQUIRE(employee1.getForkliftCertificate() == false);
    employee2.setForkliftCertificate(true);
    REQUIRE(employee2.getForkliftCertificate() == true);
}

TEST_CASE("Pallet Tests") {
    Pallet pallet1("Books", 50, 30);

    REQUIRE(pallet1.getItemName() == "Books");
    REQUIRE(pallet1.getItemCount() == 50);
    REQUIRE(pallet1.getRemainingSpace() == 2);

    REQUIRE(pallet1.putOne() == true);
    REQUIRE(pallet1.getItemCount() == 4);
    REQUIRE(pallet1.isEmpty() == false);
    REQUIRE(pallet1.isFull() == false);

    REQUIRE(pallet1.takeOne() == true);
    REQUIRE(pallet1.getItemCount() == 3);
    REQUIRE(pallet1.takeOne() == true);
    REQUIRE(pallet1.takeOne() == true);
    REQUIRE(pallet1.isEmpty() == false);

    REQUIRE(pallet1.takeOne() == true);
    REQUIRE(pallet1.isEmpty() == true);
    REQUIRE(pallet1.isFull() == false);

    REQUIRE(pallet1.putOne() == true);
    REQUIRE(pallet1.putOne() == true);
    REQUIRE(pallet1.putOne() == true);
    REQUIRE(pallet1.putOne() == true);
    REQUIRE(pallet1.isFull() == true);
}

TEST_CASE("Shelf Tests") {
    Shelf shelf1;

    REQUIRE(shelf1.isEmpty() == true);
    REQUIRE(shelf1.isFull() == true);

    shelf1.swapPallet(0, 1);
    REQUIRE(shelf1.isEmpty() == true);
    REQUIRE(shelf1.isFull() == true);
}
