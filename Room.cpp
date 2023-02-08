#include "Item.h"
#include "Enemy.h"
#include "Room.h"
#include <iostream>
#include <string>
using namespace std;
// default constructor which will not be use
Room::Room()
{
}
// constructor taking a number a parameter
Room::Room(int rNumber)
{
	// create an array storing available directions
	Doors_number = 0;
	numbers = rNumber;
	Door_direction = new string[4];
	// use if else to check where is room in the castle and change the number of doors
	if ((numbers) % 3 != 0)
	{
		Door_direction[Doors_number] = "East";
		Doors_number++;
	}
	if ((numbers) % 3 != 1)
	{
		Door_direction[Doors_number] = "West";
		Doors_number++;
	}
	if (numbers <= 6)
	{
		Door_direction[Doors_number] = "South";
		Doors_number++;
	}
	if ((numbers) >= 4)
	{
		Door_direction[Doors_number] = "North";
		Doors_number++;
	}
	// create 5 items in this game
	Item *Item1, *Item2, *Item3, *Item4, *Item5;
	Item1 = new Item("The gloves of Frozen Queen", 100);
	Item2 = new Item("The shoes of speed ", 200);
	Item3 = new Item("", 0);
	Item4 = new Item("The Devil Fruit", 300);
	Item5 = new Item("The Treasure", 350);
	// assign them to specific items in each room, and empty items for others
	if (numbers == 3)
	{
		currentItem = new Item("The gloves of Frozen Queen", 100);
	}
	else if (numbers == 7)
	{
		currentItem = new Item("The shoes of speed", 200);
	}
	else if (numbers == 2)
	{
		currentItem = new Item("The Devil Fruit", 300);
	}
	else if (numbers == 4)
	{
		currentItem = new Item("The Treasure", 10001);
	}
	else
	{
		currentItem = new Item("", 0);
	}
	// create alive enemys for the room 6 and 8, and default ( dead) enemys for other rooms
	if (numbers == 8)
	{
		currentEnemy = new Enemy(*Item1, "Akainu", true);
	}
	else if (numbers == 6)
	{
		currentEnemy = new Enemy(*Item2, "Kizaru", true);
	}
	else
	{
		currentEnemy = new Enemy(*Item3, "", false);
	}
	// Deallocate
	delete Item1;
	delete Item2;
	delete Item3;
	delete Item4;
	delete Item5;
}
// method changing the number(id) of room
void Room::setNumber(int rNumber)
{
	numbers = rNumber;
}
// method changing enemy of room, taking a enemy pointer as parameter
void Room::setCurrentEnemy(Enemy *rEnemy)
{
	currentEnemy = rEnemy;
}
// method  changing item in the room, taking an item as parameter
void Room::setCurrentItem(Item *rItem)
{
	currentItem = rItem;
}
// method returning the enemy in the room
Enemy *Room::getCurrentEnemy()
{
	return currentEnemy;
}
// method returning the item in the room
Item *Room::getCurrentItem()
{
	return currentItem;
}
// method to remove the current enemy
void Room::removeEnemy()
{
	delete currentEnemy;
}
// method removing the current item
void Room::removeItem()
{
	delete currentItem;
}
// method showing the available directions in rooms
void Room::showAvailableDirection()
{
	cout << "There are " << Doors_number << " doors on your ";
	// use if else to display the right msg for each condition
	for (int i = 0; i < Doors_number; i++)
	{
		if (i == Doors_number - 1)
		{
			cout << "and ";
		}
		cout << Door_direction[i];
		if (Doors_number > 2 && i != Doors_number - 1)
		{
			cout << ", ";
		}
		else
		{
			cout << " ";
		}
	}
	cout << "." << endl;
}
// method returning a string array of directions available
string *Room::availableDirection()
{
	return Door_direction;
}
// method returning the number of doors
int Room::getNumberOfDoors()
{
	return Doors_number;
}
// destructor
Room::~Room()
{
	delete currentItem;
	delete currentEnemy;
	delete Door_direction;
}
