#ifndef ITEM_H
#define ITEM_H
using namespace std;

#include "Point2d.h"


class Item {
public:
    Item();
    Item(Point2d* loc,const string name);
    Item(const Item& orig);
    virtual string toString()=0;
    Point2d* getPoint();
    string getName();
    virtual ~Item();
protected:
    Point2d* _loc;
    string _name;
    
};

#endif /* ITEM_H */

