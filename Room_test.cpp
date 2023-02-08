//Test class Room
#include "Item.h"
#include "Enemy.h"
#include "Room.h"
#include <iostream>
#include <string>
using namespace std;
//Room's function
Room::Room()
{
}
Room::Room(int rNumber)
{
	Doors_number = 0;
	numbers = rNumber;
	Door_direction = new string[4];
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
	Item *Item1, *Item2, *Item3, *Item4, *Item5;
	Item1 = new Item("The gloves of Frozen Queen", 100);
	Item2 = new Item("The shoes of speed ", 200);
	Item3 = new Item("", 0);
	Item4 = new Item("The Devil Fruit", 300);
	Item5 = new Item("The Treasure", 350);
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
	
	delete Item1;
	delete Item2;
	delete Item3;
	delete Item4;
	delete Item5;
}
void Room::setNumber(int rNumber)
{
	numbers = rNumber;
}
void Room::setCurrentEnemy(Enemy *rEnemy)
{
	currentEnemy = rEnemy;
}
void Room::setCurrentItem(Item *rItem)
{
	currentItem = rItem;
}
Enemy *Room::getCurrentEnemy()
{
	return currentEnemy;
}
Item *Room::getCurrentItem()
{
	return currentItem;
}
void Room::removeEnemy()
{
	delete currentEnemy;
}
void Room::removeItem()
{
	delete currentItem;
}
void Room::showAvailableDirection()
{
	cout << "There are " << Doors_number << " doors on your ";
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
string *Room::availableDirection()
{
	return Door_direction;
}
int Room::getNumberOfDoors()
{
	return Doors_number;
}
Room::~Room()
{
	delete currentItem;
	delete currentEnemy;
	delete Door_direction;
}
//No error appears, output is the same as expected
//Available to use
