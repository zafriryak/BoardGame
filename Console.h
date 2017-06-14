#ifndef CONSOLE_H
#define CONSOLE_H

#include "Game.h"
#include <stdlib.h>
#include<stdio.h>


class Console {
public:
    Console(map<Point2d*, Actors*>* playerList, vector<Item*>* itemsList,char** matP,int row,int col);
    Console(const Console& orig);
    virtual ~Console();
    void fillData();
    void print();
protected:
    map<Point2d*, Actors*>* playerList; 
    vector<Item*>* itemsList;
    char** matP;
    int row;
    int col;
};

#endif /* CONSOLE_H */

