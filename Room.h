#ifndef ROOM_H
#define ROOM_H
#include "Item.h"
#include "Enemy.h"
#include <iostream>
#include <string>
using namespace std;
class Room
{
protected:
	int numbers;				 // the number of Room
	Enemy *currentEnemy; // current enemy in this room
	Item *currentItem;		 // current item in this room
	int Doors_number;		 // current number of doors in this room
	string *Door_direction;	 // an array including all available directions from the doors
							 // all details of methos are in cpp file
public:
	Room();
	Room(int numbers);
	void setNumber(int numbers);
	void setCurrentEnemy(Enemy *Enemy);
	void setCurrentItem(Item *item);
	Enemy *getCurrentEnemy();
	Item *getCurrentItem();
	void removeEnemy();
	void removeItem();
	void showAvailableDirection();
	string *availableDirection();
	int getNumberOfDoors();
	~Room();
};

#endif
