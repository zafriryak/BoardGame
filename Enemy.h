#ifndef ENEMY_H
#define ENEMY_H

using namespace std;

#include<string>
#include"Actors.h"
#include "Hero.h"
#include "Point2d.h"


class Hero;
class Enemy : public Actors{
public:
    Enemy(string type , double hp , double xp , Point2d* start , Point2d* dst);
    Enemy(const Enemy& orig);
    string toString();
    void attack(Hero* h);
    void damage (const double dam);
    virtual ~Enemy();
private:
    double _xp;
};

#endif /* ENEMY_H */

