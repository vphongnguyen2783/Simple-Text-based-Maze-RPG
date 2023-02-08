#include "Character.h"
#include "Player.h"
#include "Inventory.h"
#include <iostream>
#include <string>
using namespace std;
// Constructor taking inventory, name, status as paramters to create object
Player::Player(Inventory pInventory, string pName, bool pStatus)
{
	playerInventory = pInventory;
	name = pName;
	status = pStatus;
}
// method displaying the voice of player
void Player::display()
{
	cout << name << ": Release Robin and Nami" << endl;
}
// method displaying info and tutorials for player
void Player::showDetails()
{	
	// display the name and what are in inventory
	cout << endl << "Your name is: " << get_name() << endl;
	cout << "Your inventory includes: " << endl;
	Item *itemList;
	itemList = get_inventory()->getItemList();
	int sum = 0;
	// list the items in the inventory
	for (int i = 0; i < 7; i++)
	{
		if (itemList[i].get_name() != "")
		{
			cout << "      " << itemList[i].get_name() << ": " << itemList[i].get_value() << " coins." << endl;
		}
	}
	// display the total value of this inventory
	cout << "Total value: " << get_inventory()->getTotalValue() << " coins." << endl;
}
// method changing the name of player
void Player::set_name(string pName)
{
	name = pName;
}
// method changing the inventory
void Player::set_inventory(Inventory *pInventory)
{
	playerInventory = *pInventory;
}
// method returning the inventory of player
Inventory *Player::get_inventory()
{
	return &playerInventory;
}
// destructor
Player::~Player()
{
}
