#ifndef GAME_H
#define GAME_H

using namespace std;
#include<map>
#include<vector>
#include<string>
#include<fstream>
#include "Point2d.h"
#include "Enemy.h"
#include "Potion.h"
#include "Actors.h"
#include "Hero.h"
#include"Item.h"
#include "Console.h"

class Console;
class Game {
public:
    Game(string path);
    void printMap();
    map<Point2d*, Actors*>* getPlayerlist();
    vector<Item*>* getItemlist();
    char** getMatP();
    int getRow();
    int getCol();
    virtual ~Game();
	
protected:
	bool isGameOver();
    void read();
    void update();
    void play();
    string _path;
    map<Point2d*,Actors*>* playerList;
    vector<Item*>* itemsList;
	vector<Hero*>* heroes;
	vector<Enemy*>* enemies;
    int row;
    int col;
    char** matP;
	Console* con;
	ofstream outFile;
};

#endif /* GAME_H */

