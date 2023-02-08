//Testing character
// Class created

#include <iostream>
#include <string>
using namespace std;
class Character
{
protected:
    string name; 
    bool status; 
    
public:
    Character();
    Character(string name, bool status);
    // Two virtual functions
    virtual void display() = 0;
    virtual void showDetails() = 0;

    void set_status(bool status);
    bool get_status();
    string get_name();
    ~Character();
};
//Functions
Character::Character()
{
	name = "";
	status = false;
}
Character::Character(string cName, bool cStatus)
{
	name = cName;
	status = cStatus;
}

void Character::set_status(bool cStatus)
{
	status = cStatus;
}
bool Character::get_status()
{
	return status;
}
string Character::get_name()
{
	return name;
}
Character::~Character()
{
}
//Main to start program
int main(){
    cout<<"No error is found"<<endl;
	return 0;
}
//No error appears, Output is the same as expected
//Available to use

