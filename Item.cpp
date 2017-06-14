#include "Item.h"

Item::Item(){
    
}

Item::Item(Point2d* loc, const string name) {
    this->_loc = loc;
	this->_name = name;
}

Item::Item(const Item& orig) {
    this->_loc = orig._loc;
}

string Item::getName(){
    return this->_name;
}

Point2d* Item::getPoint(){
    return this->_loc;
}

Item::~Item(){
    delete this->_loc;
}

