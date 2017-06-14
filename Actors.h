#ifndef ACTORS_H
#define ACTORS_H

#include "Point2d.h"



class Actors {
public:
    Actors();
    Actors(Point2d* start , Point2d* dest, const double hp, const string type);
    virtual ~Actors();
	double getHp();
    virtual string getType();
	Point2d* getStartPoint();
	Point2d* getDestPoint();
    virtual string toString()=0;
protected:
    Point2d* _start;
    Point2d* _dest;
    string _type;
	double _hp;
};

#endif /* ACTORS_H */
                                                                                                                                                                                                                                                                                                                                                                                                                             