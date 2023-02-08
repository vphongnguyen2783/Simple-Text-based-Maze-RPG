#include "Item.h"
#include "Inventory.h"
#include <iostream>
#include <string>
using namespace std;
// Default constructor which will create an inventory storing items for players
Inventory::Inventory()
{
	item_list = new Item[7]; // an array of length 7
	itemNumber = 0;			 // initially there is no item so number of item = 0
}
// Method to pickup an item takes an Item object as parameter
void Inventory::pick_item(Item theItem)
{
	item_list[itemNumber] = theItem; // assign this item to the next empty element in inventory
	itemNumber++;					 // increase 1 to the number of items
}
// Method to use an item, which will make this item disappeared
void Inventory::use_item(Item item)
{
	for (int i = 0; i < itemNumber; i++)
	{
		// Check if it is the index of this item in the array
		if (item.get_name() == item_list[i].get_name())
		{
			// remove this item and assign every next item to the current one
			for (int j = i; j < itemNumber - 1; j++)
			{
				item_list[i] = item_list[i + 1];
			}
		}
	}
	itemNumber--; // decrease 1 to the number of items
}
// Method checking if inventory has any item or not, return as bool
bool Inventory::check_item()
{
	if (itemNumber > 0)
		return true;
	return false;
}
// Method returning the list of items
Item *Inventory::getItemList()
{
	return item_list;
}
// Method returning the total value of items
int Inventory::getTotalValue()
{
	int Total_value = 0;
	if (itemNumber > 0)
	{
		// use for loop to iterate every element and add the value to the variable Total_value
		for (int i = 0; i < itemNumber; i++)
		{
			Total_value += item_list[i].get_value();
		}
	}
	return Total_value;
}
// Destructor
Inventory::~Inventory()
{
	delete[] item_list;
}
