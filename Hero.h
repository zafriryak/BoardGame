#ifndef HERO_H
#define HERO_H
using namespace std;

#include<string>
#include<math.h>
#include<sstream>
#include "Enemy.h"
#include "Point2d.h"
#include"Actors.h"
#include "Weapon.h"
#include "Armor.h"

//#define Mana 1
//#define Health 0
#define oneHanded 1.2
#define twoHanded 1.6
#define fullHeal 100
//#define dead 0 

class Enemy;
class Hero : public Actors{
public:
    Hero();
    Hero(string type , double xp , Point2d* startLoc  , Point2d* dst , int gender);
    Hero(const Hero& orig);
    string toString();
	int getRad();

     void damage (const double dam);
	 void move( Point2d* dest);
	 void attack(Enemy* e);
	 bool use(Item* i);
    virtual ~Hero();
    
protected:
    int _gender;
	int _rad;
    double _xp;
    Weapon* _wep;
    BodyArmor* _Bodyarm;
    ShieldArmor* _Shieldarm;
};

class Archer : public Hero{
public:
    Archer(double xp , Point2d* startLoc , Point2d* dest , int gender):Hero("Archer",xp,startLoc,dest,gender){
        _xp = xp;
        _rad = 5;
        _gender = gender;
    };
private:
    archerWeapon* wep;
};


class Warrior : public Hero{
public:
    Warrior(double xp , Point2d* startLoc , Point2d* dest , int gender) :Hero("Warrior", xp, startLoc, dest, gender) {
        _xp = xp;
		_gender = gender;
		_rad = sqrt(2);
    };
private:
    warriorWeapon* wep;
};


class Wizard : public Hero{
public:
    Wizard(double xp , Point2d* startLoc , Point2d* dest , int gender) : Hero("Wizard", xp, startLoc, dest, gender) {
        _xp = xp;
		_rad = 3;
		_gender = gender;
    };
private:
    wizardWeapon* wep;
};

#endif /* HERO_H */

