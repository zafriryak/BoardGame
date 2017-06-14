#ifndef WEAPON_H
#define WEAPON_H
using namespace std;

#include "Point2d.h"
#include "Item.h"
//#include<string>

#define oneHanded 1.2
#define twoHanded 1.6


class Weapon :public Item {
public:
    Weapon();
    Weapon(const double xp, Point2d* loc , string type);
    string toString();
    virtual double getXp();
    virtual string getType();
    virtual double getNumOfHandWep();
    virtual string getCanGet();
    virtual ~Weapon();
protected:
    double _xp;
    //const Point2d* _loc;
    string _type;  
    string canGet;
    double numOfHandWep;
};


class warriorWeapon : public Weapon{
public :
    warriorWeapon(double xp, Point2d* loc, string type);
    void Hammer(){numOfHandWep = twoHanded;};
    void Sword(){numOfHandWep = oneHanded;};
};

class archerWeapon : public Weapon{
public:
    archerWeapon(double xp, Point2d* loc, string type);
    void Bow(){numOfHandWep = twoHanded;};
    void CrossBow(){numOfHandWep = oneHanded;};
    
};

class wizardWeapon : public Weapon{
public:
    wizardWeapon(double xp, Point2d* loc, string type);
    void Staff(){numOfHandWep = twoHanded;};
    void Wand(){numOfHandWep = oneHanded;};
};
#endif /* WEAPON_H */

