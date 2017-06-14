#include "Enemy.h"
#include<sstream>
#define dead 0

Enemy::Enemy(string type, double hp, double xp, Point2d* start , Point2d* dest):Actors(start,dest,100,type){
    this->_xp = xp ;
}

Enemy::Enemy(const Enemy& orig) {
    this->_type = orig._type;
    this->_hp = orig._hp;
    this->_xp = orig._xp ;
    this->_start = orig._start;
    this->_dest = orig._dest;
}

void Enemy::attack(Hero* h){
    h->damage(this->_xp);
}

void Enemy::damage(const double dam){
    this->_hp = this->_hp - dam;
	if (this->_hp < dead)this->_hp = dead;
}

string Enemy::toString(){
    std::ostringstream oss;
    oss<< this->_type << " :" << "," <<" Point : "<<this->_start->toString() << "," << " Health : "<< this->_hp <<" , Power : "<<this->_xp ;
    return oss.str();
}

Enemy::~Enemy(){
    delete this->_start;
    delete this->_dest;
}



