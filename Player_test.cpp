//Test class Player

#include"Inventory_item_test.cpp"
#include <iostream>
#include <string>
using namespace std;
//Creating class
class Player : public Character
{
protected:
    Inventory playerInventory; 
public:
    Player(Inventory pInventory, string name, bool status);
    void display();
    void showDetails();
    void set_name(string name);
    void set_inventory(Inventory *pInventory);
    Inventory *get_inventory();
    ~Player();
};
//Player's functions
Player::Player(Inventory pInventory, string pName, bool pStatus)
{
	playerInventory = pInventory;
	name = pName;
	status = pStatus;
}
void Player::display()
{
	cout << name << ": Release Robin and Nami" << endl;
}
void Player::showDetails()
{	
	
	cout << endl << "Your name is: " << get_name() << endl;
	cout << "Your inventory includes: " << endl;
	Item *itemList;
	itemList = get_inventory()->getItemList();
	int sum = 0;
	
	for (int i = 0; i < 7; i++)
	{
		if (itemList[i].get_name() != "")
		{
			cout << "      " << itemList[i].get_name() << ": " << itemList[i].get_value() << " coins." << endl;
		}
	}
	
	cout << "Total value: " << get_inventory()->getTotalValue() << " coins." << endl;
}

void Player::set_name(string pName)
{
	name = pName;
}

void Player::set_inventory(Inventory *pInventory)
{
	playerInventory = *pInventory;
}

Inventory *Player::get_inventory()
{
	return &playerInventory;
}

Player::~Player()
{
}
//No error appears, output is the same as expected
//Available to use

