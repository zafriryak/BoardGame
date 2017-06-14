#include<string>
#include "Weapon.h"
#include<sstream>

using namespace std;

Weapon::Weapon(){
    
}

Weapon::Weapon(const double xp,  Point2d* loc, string type):Item(loc, "Weapon") {
    this->_xp = xp ;
    this->_type = type;
}

string Weapon::getType(){
    return this->_type;
}

double Weapon::getNumOfHandWep(){
    return this->numOfHandWep;
}

double Weapon::getXp(){
    return this->_xp;
}

string Weapon::toString(){
    int hand = 0 ;
    if(this->numOfHandWep == twoHanded){
        hand = 2 ;
    }
    else{
        hand = 1;
    }
    std::ostringstream oss;
    oss << "Weapon - "<<this->_type<<" , Power : "<<this->_xp<<" , NumOfHand"<<hand << " , Point : ";
    return oss.str();
}

Weapon::~Weapon(){
    delete this->_loc;
}

warriorWeapon::warriorWeapon(double xp, Point2d* loc, string type) :Weapon(xp, loc, type) {
    this->canGet = "warrior";
}

wizardWeapon::wizardWeapon(double xp, Point2d* loc, string type) :Weapon(xp, loc, type) {
    this->canGet = "wizard";
}

archerWeapon::archerWeapon(double xp, Point2d* loc, string type):Weapon( xp,  loc,  type){
    this->canGet = "archer";
}

string Weapon::getCanGet(){
    return this->canGet;
}



