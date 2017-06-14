#include "Actors.h"

Actors::Actors() {
}

Actors::Actors(Point2d* start, Point2d* dest, const double hp, const string type) {
    this->_dest = dest;
    this->_start = start;
    this->_hp = hp;
    this->_type = type;
}

Actors::~Actors() {
    delete this->_dest;
    delete this->_start;
}

string Actors::getType(){
    return this->_type;
}

Point2d * Actors::getDestPoint()
{
	return this->_dest;
}

Point2d* Actors::getStartPoint()
{
	return this->_start;
}

double Actors::getHp(){
	return this->_hp;
}
