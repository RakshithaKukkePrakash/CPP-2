#include <iostream>
#include <cstdlib>
#include <memory>
#include <set>
#include <cmath>
#include <stdexcept>

#include "FixedDiscount.h"
#include "ShoppingList.h"
#include "ShopDb.h"
#include "Shop.h"
#include "Item.h"
#include "QuantityDiscount.h"

using namespace std;

/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
void assertTrue(bool condition, string failedMessage) {
    if (!condition) {
        cout << failedMessage << endl;
    }
}

/**
 * Tests for the shopping list classes. (XX points)
 */
void shoppingListTests() {
	/*
	 * Create a shopping list with 2 (l) of milk, 250 (g) butter,
	 * and 1.5 (kg) bread. Use ShoppingList::items to retrieve
	 * the items and assert that for each that they have the
	 * expected name and quantity. (12 points)
	 */
	std::map<std::string, float> neededItems = {{"milk", 2},{"butter", 250},{"bread", 1.5}};
	ShoppingList sList;
	sList.addItem("milk", 2);
	sList.addItem("butter", 250);
	sList.addItem("bread", 1.5);

	std::list<Item>::const_iterator begin, end;
	sList.items(begin, end);
	for(auto items= begin; items != end; items++)
	{
		assertTrue(items->getQuantity()== neededItems[items->getName()], "Failed");
	}


}

/**
 * Tests for the shop db classes. (XX points)
 */
void shopDbTests() {
    /*
     * (1) Test the methods of class ShopDb using the names given below.
     * Proceed as follows:
     *   * Create a ShopDb and add shops with the given names to it.
     *   * Use ShopDb::shops to get pointers to the shops in the database.
     *   * For each shop,
     *       * assert that that the shop's name is in the set "names".
     *       * assert that that the pointer that you got from ShopDb::shops
     *         is equal to the pointer that you get from ShopDb::shopByName
     *       * remove the shop's name from the set "names".
     *   * Finally assert that that you got all shops by checking that the
     *     set "names" is empty.
     *   (7 points)
     */
	set<string> names = { "Foodie1", "Bakers4less", "Spiceology", "Grainfruit",
			"Sweetteas", "Savorystyle", "TheSpiceHouse", "FoodieFun",
			"FlavorStation", "DoughLife", "INGredientsOnly", "FreshFix",
			"Tastync", "FlavorFile", "BiteMe", "TheFlavorSpot",
			"AtisfyMyCravings", "TastyTreats", "TheFoodFactor", "MunchiesLand",
			"TheSnackCave", "FoodieFrenzy", "TheMorselMansion", "BiteClub",
			"TheSavorStore", "TheFoodieFactor", "FlavorfulFinds",
			"TheTastyTrove" };
	ShopDb shopDb;
	for(auto& name: names){
		shopDb.addShop(make_unique<Shop>(name));
	}

	for(auto& shop: shopDb.shops()){
			assertTrue(names.find(shop->getName()) != names.end(), "Name not present");
	}

	for(auto& shop: shopDb.shops()){
		assertTrue(shop == shopDb.shopByName(shop->getName()), "Pointer incorrect");
		names.erase(shop->getName());
	}
	assertTrue(names.empty() == true, "Items still in set");



	/*
	 * (2) Test LinearDiscount by creating an instance for 5% (0.05) and
	 * another one for 10% (0.1) and then asserting for each of the
	 * two that you get the expected result when invoking
	 * LinearDiscount::discountFor with arguments 0, 10 and 100. (6 points)
	 */
	FixedDiscount fixDisc1(0.05);
	FixedDiscount fixDisc2(0.1);
	assertTrue(fixDisc1.discountFor(0) == 0.05,"discount for 0");
	assertTrue(fixDisc1.discountFor(10) == 0.05,"discount for 10");
	assertTrue(fixDisc1.discountFor(100) == 0.05,"discount for 100");

	assertTrue(fixDisc2.discountFor(0) == 0.1,"discount for 0");
	assertTrue(fixDisc2.discountFor(10) == 0.1,"discount for 10");
	assertTrue(fixDisc2.discountFor(100) == 0.1,"discount for 100");

	/*
	 * (3) Test QuantityDiscount by creating an instance for the
	 * following rules:
	 *   * A discount of 5% (0.05) starting with a quantity of 10
	 *   * A discount of 10% (0.1) starting with a quantity of 50
	 *   * A discount of 15% (0.15) starting with a quantity of 100
	 *
	 * Assert that that QuantityDiscount::discountFor returns the expected
	 * values for quantities 0, 9, 10, 11, 49, 50, 51, 99, 100 and 101.
	 * (8 points)
	 */
	QuantityDiscount qDisc;
	qDisc.addLimit(10, 0.05);
	qDisc.addLimit(50, 0.1);
	qDisc.addLimit(100, 0.15);
    assertTrue(qDisc.discountFor(0) == 0, "Incorrect assert for 0");
    assertTrue(qDisc.discountFor(9) == 0, "Incorrect assert for 9");
    assertTrue(qDisc.discountFor(10) == 0.05, "Incorrect assert for 10");
    assertTrue(qDisc.discountFor(11) == 0.05, "Incorrect assert for 11");
    assertTrue(qDisc.discountFor(49) == 0.05, "Incorrect assert for 49");
    assertTrue(qDisc.discountFor(50) == 0.1, "Incorrect assert for 50");
    assertTrue(qDisc.discountFor(51) == 0.1, "Incorrect assert for 51");
    assertTrue(qDisc.discountFor(99) == 0.1, "Incorrect assert for 99");
    assertTrue(qDisc.discountFor(100) == 0.15, "Incorrect assert for 100");
    assertTrue(qDisc.discountFor(101) == 0.15, "Incorrect assert for 101");


	/*
	 * (4) Create a shop "Bakers4less" that sells bread at
	 * 5.6 per unit (kg). Assert that changing the base price
	 * (price per unit) for milk (!) at Bakers4less throws an
	 * invalid_argument exception (because they don't offer milk)
	 * (5 points)
	 */
    ShopDb shop;
    shop.addShop(make_unique<Shop>("Bakers4less"));
    shop.shopByName("Bakers4less")->setBasePrice("bread", 5.6);
    try{
    	shop.shopByName("Bakers4less")->setBasePrice("milk", 5);
    }
    catch(invalid_argument& e )
    {
    	assertTrue(std::string(e.what())== "Product not available at shop", "Incorrect exception message");
    }
}

void evalTests() {
	/*
	 * Create a shop db. Add the shop "Bakers4less" from the
	 * function shopDbTests. Add another shop "Foodie1" that
	 * sells "Milk" at 2.1 per unit, "Bread" at 5.8 per unit
	 * and "Butter" at 0.00996 per unit.
	 *
	 * Copy the shopping list from function shoppingListTests.
	 *
	 * (1) Assert that purchasing everything from the shopping
	 * list at Foodie1 costs 15.39 and that they have everything
	 * available.
	 *
	 * (2) Assert that the purchase at Bakers4less amounts to
	 * 8.40 only and that the method reports that the shop does not
	 * provide milk and butter.
	 *
	 * (19 points)
	 */
    ShopDb shop;
    shop.addShop(make_unique<Shop>("Bakers4less"));
    shop.shopByName("Bakers4less")->setBasePrice("bread", 5.6);
    shop.addShop(make_unique<Shop>("Foodie1"));
    shop.shopByName("Foodie1")->setBasePrice("Milk", 2.1);
    shop.shopByName("Foodie1")->setBasePrice("Bread", 5.8);
    shop.shopByName("Foodie1")->setBasePrice("Butter", 0.00996);

	ShoppingList sList;
	sList.addItem("milk", 2);
	sList.addItem("butter", 250);
	sList.addItem("bread", 1.5);

    std::set<const Item*> notAvailable;

    // Test for Foodie1
    float costFoodie1 = shop.shopByName("Foodie1")->calculatePurchase(sList, notAvailable);
    assertTrue(costFoodie1 == 15.39, "Incorrect cost for Foodie1");
    assertTrue(notAvailable.empty(), "Some items are not available at Foodie1");

    // Test for Bakers4less
    float costBakers4less = shop.shopByName("Bakers4less")->calculatePurchase(sList, notAvailable);
    assertTrue(costBakers4less == 8.40, "Incorrect cost for Bakers4less");
    assertTrue(notAvailable.size() == 2, "Incorrect number of unavailable items at Bakers4less");

}

void allTests() {
    shoppingListTests();
    shopDbTests();
    evalTests();
}
