#include "Character.h"
#include <iostream>
#include <string>
using namespace std;
// Default constructor -> create an empty character with empty name and dead already
Character::Character()
{
	name = "";
	status = false;
}
// Constructor -> takes name and status as parameters to create a customized character
Character::Character(string cName, bool cStatus)
{
	name = cName;
	status = cStatus;
}
//changing the status of the character
void Character::set_status(bool cStatus)
{
	status = cStatus;
}
// returning the status of character
bool Character::get_status()
{
	return status;
}
// returning the name of the character
string Character::get_name()
{
	return name;
}
// default destructor
Character::~Character()
{
}
