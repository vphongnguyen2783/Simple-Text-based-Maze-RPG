//Test class Enemy
#include"Inventory_item_test.cpp"
#include <iostream>
#include <string>
using namespace std;
//Creating class
class Enemy : public Character
{
protected:
    Item exWeapon; 
public:
    Enemy(Item exWeapon, string name, bool status);
    void display();
    void showDetails();
    bool isDead(Item weapon);
    void setExWeapon(Item exWeapon);
    string getExWeaponName();
    ~Enemy();
};
//Enemy's functions
Enemy::Enemy(Item mWeapon, string mName, bool mStatus)
{
	exWeapon = mWeapon;
	name = mName;
	status = mStatus;
}
void Enemy::display()
{
	cout << name << ": Looks who's here" << endl;
}
void Enemy::showDetails()
{
	cout << "This is " << name << ". The only way to defeat him is: You have to use " << exWeapon.get_name() << "." << endl;
}
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
void Enemy::setExWeapon(Item weapon)
{
	exWeapon = weapon;
}
string Enemy::getExWeaponName()
{
	return exWeapon.get_name();
}
Enemy::~Enemy()
{
}
//No error appears, output is the same as expected
//Available to use
