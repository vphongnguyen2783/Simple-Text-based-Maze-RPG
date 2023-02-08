#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>
using namespace std;
class Item
{
protected:
    string name; // name of the item
    int value;   // value of the item
                 // All details of method are in the cpp file
public:
    Item();
    Item(string name, int value);
    void set_name(string name);
    void set_value(int value);
    string get_name();
    int get_value();
    ~Item();
};

#endif
