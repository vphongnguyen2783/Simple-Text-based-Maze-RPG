//Test inventory and item class
// Creating classes

#include"Character_test.cpp"
#include <iostream>
#include <string>
using namespace std;
//Item class
class Item
{
protected:
    string name; 
    int value;   
                 
public:
    Item();
    Item(string name, int value);
    void set_name(string name);
    void set_value(int value);
    string get_name();
    int get_value();
    ~Item();
};

//Item's functiom
Item::Item()
{
	name = "";
	value = 0;
}
Item::Item(string iName, int iValue)
{
	name = iName;
	value = iValue;
}
void Item::set_name(string iName)
{
	name = iName;
}
void Item::set_value(int iValue)
{
	value = iValue;
}
string Item::get_name()
{
	return name;
}
int Item::get_value()
{
	return value;
}
Item::~Item()
{
}
//Before adding inventory class testing. The item class runs as expected
//Inventory class
class Inventory
{
protected:
	Item *item_list; 
	int itemNumber;	 
					 
public:
	Inventory();
	Item *getItemList();
	void pick_item(Item item);
	void use_item(Item item);
	bool check_item();
	int getTotalValue();
	~Inventory();
};

//Inventory's function
Inventory::Inventory()
{
	item_list = new Item[7]; 
	itemNumber = 0;			 
}
void Inventory::pick_item(Item theItem)
{
	item_list[itemNumber] = theItem;
	itemNumber++;					 
}
void Inventory::use_item(Item item)
{
	for (int i = 0; i < itemNumber; i++)
	{
		if (item.get_name() == item_list[i].get_name())
		{
			for (int j = i; j < itemNumber - 1; j++)
			{
				item_list[i] = item_list[i + 1];
			}
		}
	}
	itemNumber--; 
}
bool Inventory::check_item()
{
	if (itemNumber > 0)
		return true;
	return false;
}
Item *Inventory::getItemList()
{
	return item_list;
}
int Inventory::getTotalValue()
{
	int Total_value = 0;
	if (itemNumber > 0)
	{
		for (int i = 0; i < itemNumber; i++)
		{
			Total_value += item_list[i].get_value();
		}
	}
	return Total_value;
}
Inventory::~Inventory()
{
	delete[] item_list;
}

//No error appears, output is the same as expected
//Available to use
