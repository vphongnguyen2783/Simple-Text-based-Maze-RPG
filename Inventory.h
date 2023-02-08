#ifndef INVENTORY_H
#define INVENTORY_H
#include "Item.h"
#include <iostream>
#include <string>
using namespace std;
class Inventory
{
protected:
	Item *item_list; // an array including all the items in the player bag
	int itemNumber;	 // the number of these items
					 // All details of method are in the cpp file
public:
	Inventory();
	Item *getItemList();
	void pick_item(Item item);
	void use_item(Item item);
	bool check_item();
	int getTotalValue();
	~Inventory();
};

#endif
