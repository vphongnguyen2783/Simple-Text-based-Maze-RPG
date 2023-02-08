#include <iostream>
#include "Character.h"
#include "Player.h"
#include "Inventory.h"
#include "Enemy.h"
#include "Room.h"
#include "Game.h"
#include <cstdlib>
using namespace std;
int main()
{
	// Create a pointer
	Game *mainGame;
	// new game by constructor of object Game
	mainGame = new Game();
	// use method play() to play the game
	mainGame->play();
	return 0;
}
