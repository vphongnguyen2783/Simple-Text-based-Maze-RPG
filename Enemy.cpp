#include "Character.h"
#include "Enemy.h"
#include "Item.h"
#include <iostream>
#include <string>
using namespace std;
// Constructor taking an item, name, and bool as parameters to create object
Enemy::Enemy(Item mWeapon, string mName, bool mStatus)
{
	exWeapon = mWeapon;
	name = mName;
	status = mStatus;
}
// method displaying voice of admiral
void Enemy::display()
{
	cout << name << ": Looks who's here" << endl;
}
// method displaying stats of admiral
void Enemy::showDetails()
{
	cout << "This is " << name << ". The only way to defeat him is: You have to use " << exWeapon.get_name() << "." << endl;
}
// method checking if admiral is dead by an item ( taking as parameter) or not, return a bool
bool Enemy::isDead(Item weapon)
{
	if (exWeapon.get_name() == weapon.get_name() && exWeapon.get_name() != "")
	{
		return true;
	}
	else
	{
		return false;
	}
}
// method set an item from parameter to be the exWeapon for enemies
void Enemy::setExWeapon(Item weapon)
{
	exWeapon = weapon;
}
// method returning the name of the exclusive weapon
string Enemy::getExWeaponName()
{
	return exWeapon.get_name();
}
// Destructor
Enemy::~Enemy()
{
}
