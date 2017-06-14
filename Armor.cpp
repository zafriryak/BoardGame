#include "Armor.h"
#include<assert.h>
#include<sstream>

#define ceil 1
#define floor 0.65

Armor::Armor()
{

}

Armor::Armor(double armor, Point2d* loc):Item(loc,"Armor"){
	this->_armor = armor;
}

BodyArmor::BodyArmor(double armor, Point2d* loc):Armor(armor,loc) {
    assert(armor >= floor && armor <= ceil);
}

double BodyArmor::getArmor(){
    return this->_armor;
}

void BodyArmor::setArmor(double num){
    this->_armor = num;
}

string BodyArmor::toString(){
    std::ostringstream oss;
    oss << "BodyArmor - Power :"<<this->_armor<<" , Point : "<<this->_loc->toString();
    return oss.str();
}

ShieldArmor::ShieldArmor(double armor, Point2d* loc) :Armor(armor, loc) {
	assert(armor >= floor && armor <= ceil);

}

void ShieldArmor::setArmor(double num){
    this->_armor = num;
}

double ShieldArmor::getArmor(){
    return this->_armor;
}

string ShieldArmor::toString(){
    std::ostringstream oss;
    oss << "ShieldArmor - Power :"<<this->_armor<<" , Point : "<<this->_loc->toString();
    return oss.str();
}