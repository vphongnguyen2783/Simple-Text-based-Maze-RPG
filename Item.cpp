#include "Item.h"
#include <iostream>
#include <string>
using namespace std;
// Default constructor which will create an empty item which no name and value 0
Item::Item()
{
	name = "";
	value = 0;
}
// Constructor which will take name, value as parameters to create object based on these parameters
Item::Item(string iName, int iValue)
{
	name = iName;
	value = iValue;
}
// Method will change the name of the item
void Item::set_name(string iName)
{
	name = iName;
}
// Method will change the value of the item
void Item::set_value(int iValue)
{
	value = iValue;
}
// Method will return the name of the item
string Item::get_name()
{
	return name;
}
// Method will return the value of the item
int Item::get_value()
{
	return value;
}
// Destructor
Item::~Item()
{
}
