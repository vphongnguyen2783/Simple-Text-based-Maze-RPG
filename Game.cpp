#include "Item.h"
#include "Inventory.h"
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Room.h"
#include "Game.h"
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

// Default constructor for object Game
Game::Game()
{
	// create the inventory for player and the attribute isDone to false, means the game is not done
	Inventory *playerInventory;
	playerInventory = new Inventory();
	isDone = false;
	// Game description
	cout << "                                    -------------------------------------------" << endl;
	cout << "                                                  | Pirate Kings |" << endl;
	cout << "                                    -------------------------------------------" << endl;
	cout << " There are 9 secret rooms in naval headquarters. You are Monkey.D.Luffy, in the first room, which is the entrance.\n And your mission is to rescue Nami and Robin who are currently trapped in the last room, which is room 9. These rooms\n will be arranged as a 3x3 matrix and have some items and enemies located in certain fixed rooms. You will have\n an inventory to keep the items you collect during the adventure, each item will have its own value. The gloves \n of Frozen Queen in room 3 will help you kill  Akainu the lava man in room 8 while the shoes of speed in room 7 will\n help you defeat the light man Kizaru in room 6. With simple given commands on the screen , you will have chances\n to overcome obstacles, and once reach room number 9, you will successfully rescue your friends and be the winner!" << endl;
	string input;

	// first loop for display the main menu after each play command -> After each movements, the main menu will display
	while (isDone == false)
	{
		cout << "\nMAIN MENU:\n   1.New Game\n   2.Exit Game\n\nYour choice: ";
		// second loop for typing the option again if invalid
		while (true)
		{
			cin >> input; // Get input and check as below
			if (input == "1")
			{
				break; // not an invalid input so break the second loop
			}
			else if (input == "2")
			{
				exitGame();
				break; // not an invalid input so break the second loop
			}
			else
			{
				cout << "Invalid input! Type again!" << endl; // invalid so not break and take the input again
			}
		}
		// if player selects 1 ( new game) then break the first loop to go the next code to play a new game
		if (input == "1")
		{
			break;
		}
	}

	// get the name and create the player, assign to the first room
	if (isDone == false)
	{
		string playerName;
		cout << "Enter your name: ";
		cin >> playerName;
		cin.ignore();
		currentPlayer = new Player(*playerInventory, playerName, true);
		for (int i = 0; i < 9; i++)
		{
			roomList[i] = new Room(i + 1); // assign every specific room using new with the constructor take the number as parameter to each element of the roomList
		}
		currentRoomNumber = 1; // set the current number of room where the player in to 1
	}
}

// the function that runs one time through the game
void Game::play()
{
	// first loop to show the location of the player and display the command options
	while (isDone == false)
	{
		showLocation();
		cout << endl
			 << "Type command's number: \n    1. Move\n    2. Check\n    3. Pick\n    4. Attack\n    5. Exit";

		string cmd;
		//  second loop for typing the choice again if invalid
		while (true)
		{
			cout << "\n\nYour choice (From 1 to 5): ";
			cin >> cmd;
			if (cmd == "1")
			{
				move();
				if (currentRoomNumber == 9)
				{
					win();
				}
				cin.ignore();
				break;
			}
			else if (cmd == "5")
			{
				exitGame();
				break;
			}
			else if (cmd == "3")
			{
				pick();
				break;
			}
			else if (cmd == "4")
			{
				attack();
				break;
			}
			else if (cmd == "2")
			{
				check();
				break;
			}
			else
			{
				cout << "Invalid input! Type again!";
			}
		}
	}
}

// the function using to attack anything in the current room
void Game::attack()
{
	// get the name and status of the current monster in this room
	string monsterName = roomList[currentRoomNumber - 1]->getCurrentEnemy()->get_name();
	bool monsterStatus = roomList[currentRoomNumber - 1]->getCurrentEnemy()->get_status();
	// if the monster is alive
	if (monsterStatus)
	{
		// get the list of items in the inventory of the player
		Inventory *invent;
		invent = currentPlayer->get_inventory();
		Item *itemList;
		itemList = invent->getItemList();
		// check if the player has the right weapon to defeat enemy
		bool check = false;
		for (int i = 0; i < 7; i++)
		{
			if (roomList[currentRoomNumber - 1]->getCurrentEnemy()->isDead(itemList[i]))
			{
				check = true;
				cout << "You have killed " << monsterName << " successfully!" << endl;
				roomList[currentRoomNumber - 1]->getCurrentEnemy()->set_status(false);
			}
		}
		// lose if the player doesnt have this weapon
		if (!check)
		{
			lose();
		}
	}
	// announce if no enemy has been found in the room
	else
	{
		cout << "Nothing can be attacked!" << endl;
	}
	cout << "\nEnter to continue...";
	cin.ignore();
	cin.ignore();
}

// function using to pick up any item in the room
void Game::pick()
{
	// check if there is any item then store it
	if (roomList[currentRoomNumber - 1]->getCurrentItem()->get_value() != 0)
	{
		Inventory *invent;
		invent = currentPlayer->get_inventory();
		// pick up the item
		invent->pick_item(*roomList[currentRoomNumber - 1]->getCurrentItem());
		currentPlayer->set_inventory(invent);
		// announce the result
		cout << "Stored " << roomList[currentRoomNumber - 1]->getCurrentItem()->get_name() << " successfully!" << endl;
		roomList[currentRoomNumber - 1]->getCurrentItem()->set_name("");
		roomList[currentRoomNumber - 1]->getCurrentItem()->set_value(0);
	}
	// announce if there is nothing can be found
	else
	{
		cout << "Nothing can be picked!" << endl;
	}
	cout << "\nEnter to continue...";
	cin.ignore();
	cin.ignore();
}

// show the current location of the player with the detail of this room
void Game::showLocation()
{
	// display the name and the location
	cout << endl
		 << currentPlayer->get_name() << ", you are in Room " << currentRoomNumber << "." << endl;
	// display item and enemy in the room
	if (roomList[currentRoomNumber - 1]->getCurrentItem()->get_value() != 0)
	{
		cout << "There is " << roomList[currentRoomNumber - 1]->getCurrentItem()->get_name() << " in this room!" << endl;
	}
	else
	{
		cout << "There is nothing valuable in this room!" << endl;
	}
	// if the enemy is alive then announce a msg about the enemy
	if (roomList[currentRoomNumber - 1]->getCurrentEnemy()->get_status())
	{
		cout << "WATCH OUT!" << endl;
		roomList[currentRoomNumber - 1]->getCurrentEnemy()->display();
		currentPlayer->display();
		roomList[currentRoomNumber - 1]->getCurrentEnemy()->showDetails();
	}
	else
	{
		cout << "There is nothing dangerous in this room!" << endl;
	}
	cout << "\nEnter to continue...";
	cin.ignore();
}

// function using to check the status of the player
void Game::check()
{
	// display the name and the detail of inventory
	currentPlayer->showDetails();
	cout << "\nEnter to continue...";
	cin.ignore();
	cin.ignore();
}

// function using to move vertically and horizontally the player between rooms
void Game::move()
{
	// get the available moves from this room
	string *move_list = roomList[currentRoomNumber - 1]->availableDirection();
	bool canMove = 0;
	string move;
	int numOfDoors = roomList[currentRoomNumber - 1]->getNumberOfDoors();
	// get the input move from player
	string transformMove;
	while (true)
	{
		roomList[currentRoomNumber - 1]->showAvailableDirection();
		cout << endl
			 << "Enter your move (N,S,W,E): ";
		cin >> move;
		cout << endl;
		// check if player can move with this input move, if yes then move the player, if no then announce a msg
		// case 1: player moves to the west
		if (move == "West" || move == "west" || move == "w" || move == "W")
		{
			transformMove = "West";
			for (int i = 0; i < numOfDoors; i++)
			{
				if (transformMove == move_list[i])
				{
					currentRoomNumber -= 1;
					canMove = 1;
					break;
				}
			}
			if (canMove)
				break;
			else
			{
				cout << "There is no door on the west!" << endl;
			}
		}
		// case 2: player moves to the east
		else if (move == "East" || move == "east" || move == "e" || move == "E")
		{
			transformMove = "East";
			if (currentRoomNumber == 8 && roomList[currentRoomNumber - 1]->getCurrentEnemy()->get_status() == true)
			{
				lose();
			}
			for (int i = 0; i < numOfDoors; i++)
			{
				if (transformMove == move_list[i])
				{
					currentRoomNumber++;
					canMove = 1;
					break;
				}
			}
			if (canMove)
				break;
			else
			{
				cout << "There is no door on the east!" << endl;
			}
		}
		// case 3: player moves to the north
		else if (move == "North" || move == "north" || move == "n" || move == "N")
		{
			transformMove = "North";
			for (int i = 0; i < numOfDoors; i++)
			{
				if (transformMove == move_list[i])
				{
					currentRoomNumber -= 3;
					canMove = 1;
					break;
				}
			}
			if (canMove)
				break;
			else
			{
				cout << "There is no door on the north!" << endl;
			}
		}
		// case 4: player moves to the south
		else if (move == "South" || move == "south" || move == "s" || move == "S")
		{
			transformMove = "South";
			if (currentRoomNumber == 6 && roomList[currentRoomNumber - 1]->getCurrentEnemy()->get_status() == true)
			{
				lose();
			}
			for (int i = 0; i < numOfDoors; i++)
			{
				if (transformMove == move_list[i])
				{
					currentRoomNumber += 3;
					canMove = 1;
					break;
				}
			}
			if (canMove)
				break;
			else
			{
				cout << "There is no door on the south!" << endl;
			}
		}
		// case 5: player refuses to move
		else if (move == "Refuse" || move == "refuse" || move == "r" || move == "R")
		{
			break;
		}
		// case 6: type the wrong input then type again
		else
		{
			cout << "Your move is invalid! Lets move again!" << endl;
		}
	}
}

// function using when player wins the game ( reach room 9)
void Game::win()
{

	cout << "Congratulation! Nami and Robin are here and still safe! You are the winner!" << endl;
	isDone = true;
}

// function using when player loses
void Game::lose()
{

	cout << "Your are killed by " << roomList[currentRoomNumber - 1]->getCurrentEnemy()->get_name() << "! You lose!" << endl;
	isDone = true;
}

// function using when player selects to leave the game
void Game::exitGame()
{

	while (1)
	{
		string choice;
		// announce the confirmative question
		cout << "Are you sure to leave the game? (Y/N): ";
		cin >> choice;
		if (choice == "y" || choice == "Y")
		{
			isDone = true;
			break;
		}
		else if (choice == "n" || choice == "N")
			break;
		else
			cout << "Invalid input! Confirm again!" << endl;
	}
}
Game::~Game()
{
	delete currentPlayer;
	for (int i = 0; i < 9; i++)
	{
		delete roomList[i];
	}
}
