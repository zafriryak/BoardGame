#include "Point2d.h"
#include<sstream>

Point2d::Point2d() {
    _x = 0;
    _y = 0;
}

Point2d::Point2d(const int x,const int y){
    _x = x;
    _y = y;
}


Point2d::Point2d(const Point2d& orig) {
    _x = orig._x;
    _y = orig._y;
}

int Point2d::getX()
{
    return _x;
}

int Point2d::getY()
{
    return _y;
}

void Point2d::setX(const int x)
{
    _x=x;
}

void Point2d::setY(const int y)
{
    _y=y;
}


string Point2d::toString() {
    std::ostringstream oss;
    oss<< "("<<_x<<" "<<_y<<")";
    return oss.str();
}



Point2d* Point2d::operator =(const Point2d& p){
    this->_x = p._x;
    this->_y = p._y;
    return this;
}



bool Point2d::isEqual(const Point2d* p)
{
	if (this->_x == p->_x && this->_y == p->_y)return true;
	return false;
}
