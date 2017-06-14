#ifndef ARMOR_H
#define ARMOR_H
using namespace std;

#include "Point2d.h"
#include "Item.h"



class Armor : public Item {
public:
    Armor(double armor , Point2d* loc);
    Armor();
    virtual string toString()=0;
    virtual double getArmor()=0;
    virtual void setArmor(double num)=0;
protected:
	double _armor;

};

class BodyArmor : public Armor{
public:
    BodyArmor(double arm , Point2d* loc);
    virtual void setArmor(double num);
    virtual string toString();
    virtual double getArmor();
};

class ShieldArmor : public Armor{
public:
    ShieldArmor(double arm , Point2d* loc);
    virtual void setArmor(double num);
    virtual string toString();
    virtual double getArmor();
};

#endif /* ARMOR_H */

