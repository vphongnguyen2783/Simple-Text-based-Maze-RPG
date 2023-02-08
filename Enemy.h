#ifndef MONSTER_H
#define MONSTER_H
#include "Character.h"
#include "Item.h"
#include <iostream>
#include <string>
using namespace std;
class Enemy : public Character
{
protected:
    Item exWeapon; // this is the item that can defeat admiral
    // All details of method are in cpp file
public:
    Enemy(Item exWeapon, string name, bool status);
    void display();
    void showDetails();
    bool isDead(Item weapon);
    void setExWeapon(Item exWeapon);
    string getExWeaponName();
    ~Enemy();
};

#endif
