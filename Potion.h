#ifndef POTION_H
#define POTION_H
using namespace std;

#include<sstream>

#include "Point2d.h"
#include "Item.h"

#define Mana 0
#define Health 1

class Potion : public Item {
public:
    Potion(int type , int quality , Point2d* loc);
    Potion(const Potion& orig);
    int getType();
    int getQuality();
    string toString();
    virtual ~Potion();
private:
    //Point2d* _loc;
    int _quality;
    int _type;
};

#endif /* POTION_H */

