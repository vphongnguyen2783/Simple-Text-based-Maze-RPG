#ifndef GAME_H
#define GAME_H
#include "Item.h"
#include "Inventory.h"
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Room.h"
#include <iostream>
#include <string>
using namespace std;

class Game
{

protected:
    Player *currentPlayer; // the current player playing
    Room *roomList[9];     // an array including all 9 rooms
    int currentRoomNumber; // the number of current room where the player is in
    bool isDone;
    // all method's details are in the cpp files
public:
    Game();
    void showLocation();
    void play();
    void lose();
    void win();
    void pick();
    void attack();
    void check();
    void move();
    void exitGame();
    ~Game();
};

#endif
