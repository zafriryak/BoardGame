
#include<cstring>
#include<iostream>
#include <stdlib.h>
#include "Game.h"


/*
	get the file name, read the data and use the console and than run play.
*/
Game::Game(string path){
	string outFileName = path.substr(0, path.length() - 7);
    this->_path = path;
	std::ostringstream oss;
	oss << outFileName << "_out.csv";
	this->outFile.open(oss.str());
	this->heroes = new vector<Hero*>();
	this->enemies=new vector<Enemy*>();
    this->itemsList = new vector<Item*>();
    this->playerList = new map<Point2d* , Actors*>();
    read();
    con = new Console(this->playerList, this->itemsList, this->matP, this->row, this->col);
	con->fillData();
	con->print();
    printMap();
	play();
}

/*
	getNumberFromIndex - return only the number between the ','
*/

string getNumberFromIndex(int index, string line) {
    bool flag = false;
    size_t temp = index;
    string num = "";
    for ( temp = index + 1; !flag && temp < line.length(); temp++) {
        if (line.at(temp) == ',') {
            flag = true;
        }
        else{
            num = num+line.at(temp);
        }
    }
    
    return num;
}

/*
	getFirstWordIndex - return the first word in the line
*/

string getFirstWordIndex(string line) {
    size_t i = 0;
    bool flag = false;
    while (!flag && i < line.length()) {
        if (line.at(i) == ',') {
            flag = true;
        }
        i++;
    }
    return line.substr(0, i -1);
}

/*
	read - read the file and fill the map and the vector
*/

void Game::read() {
    std::ifstream filein(this->_path.c_str());
    string line;
     int index=0;
    string quality = "", x = "", y = "";
    int  xNum, yNum , gendrNum;
    double qualityNum;
    Point2d* p = new Point2d();
    Point2d* dst = new Point2d();
    string word = "";
    string gender = "";
    string row = "";
    string col = "";
    string item = "";
    while (std::getline(filein, line)) {
        word = getFirstWordIndex(line);
        if (word.compare("matrix") == 0) {
            index = word.length();
            row = getNumberFromIndex(index, line);
			index = index + row.length() +1;
            col = getNumberFromIndex(index, line);
            this->row = atoi(row.c_str());
            this->col = atoi(col.c_str());
            matP = new char*[this->row];
            for(int i = 0 ; i < this->row ; i++){
                matP[i] = new char[this->col];
            }
        }
        if (word.compare("mana") == 0) {
            index = word.length();
            quality = getNumberFromIndex(index, line);
			index = index + quality.length()+1 ;
            x = getNumberFromIndex(index, line);
			index = index  +x.length()+1;
            y = getNumberFromIndex(index, line);
            qualityNum = atoi(quality.c_str());
            xNum = atoi(x.c_str());
            yNum = atoi(y.c_str());
            p = new Point2d(xNum, yNum);
            Potion* pot=new Potion(0, qualityNum, p);
            Item* m = pot;
            itemsList->push_back(m);
        } else if (word.compare("health") == 0) {
            index = word.length();
            quality = getNumberFromIndex(index, line);
			index = index + quality.length() + 1;
            x = getNumberFromIndex(index, line);
			index = index + x.length() +1;
            y = getNumberFromIndex(index, line);
            qualityNum = atof(quality.c_str());
            xNum = atoi(x.c_str());
            yNum = atoi(y.c_str());
            p = new Point2d(xNum, yNum);
            Potion* pot=new Potion(1, qualityNum, p);
            Item* m = pot;
            itemsList->push_back(m);
        }else if (word.compare("bodyarmor") == 0) {
            index = word.length();
            quality = getNumberFromIndex(index, line);
			index = index + quality.length() +1;
			x = getNumberFromIndex(index, line);
			index = index + x.length() +1;
			y = getNumberFromIndex(index, line);
            qualityNum = atof(quality.c_str());
            xNum = atoi(x.c_str());
            yNum = atoi(y.c_str());
            p = new Point2d(xNum, yNum);
            BodyArmor* ba=new BodyArmor(qualityNum, p);
            Item* m = ba;
            itemsList->push_back(m);
        }
        else if (word.compare("shieldarmor") == 0) {
            index = word.length();
            quality = getNumberFromIndex(index, line);
			index = index + quality.length() + 1;
			x = getNumberFromIndex(index, line);
			index = index + x.length() + 1;
			y = getNumberFromIndex(index, line);
            qualityNum = atof(quality.c_str());
            xNum = atoi(x.c_str());
            yNum = atoi(y.c_str());
            p = new Point2d(xNum, yNum);
            ShieldArmor* sa=new ShieldArmor(qualityNum, p);
            Item* m = sa;
            itemsList->push_back(m);
        }
        else if (word.compare("enemy") == 0) {
            index = word.length();
			quality = getNumberFromIndex(index, line); 
			index = index + quality.length() + 1;
			x = getNumberFromIndex(index, line);
			index = index  + x.length() + 1;
			y = getNumberFromIndex(index, line);
            qualityNum = atof(quality.c_str());
            xNum = atoi(x.c_str());
            yNum = atoi(y.c_str());
            p = new Point2d(xNum, yNum);
			index = index + y.length() + 1;
			x = getNumberFromIndex(index, line);
			index = index + x.length() + 1;
			y = getNumberFromIndex(index, line);
            xNum = atoi(x.c_str());
            yNum = atoi(y.c_str());
            dst = new Point2d(xNum,yNum);
            Enemy* e= new Enemy("Enemy" , 100 , qualityNum ,p , dst);
			this->enemies->push_back(e);
            Actors* m =e;
            playerList->insert(std::make_pair(p,m));
        }
        else if (word.compare("elite") == 0) {
            index = word.length();
            quality = getNumberFromIndex(index, line); 
			index = index + quality.length() + 1;
			x = getNumberFromIndex(index, line);
			index = index   + x.length() + 1;
			y = getNumberFromIndex(index, line);
            qualityNum = atof(quality.c_str());
            xNum = atoi(x.c_str());
            yNum = atoi(y.c_str());
            p = new Point2d(xNum, yNum);
			index = index + y.length() + 1;
			x = getNumberFromIndex(index, line);
			index = index + x.length() + 1;
			y = getNumberFromIndex(index, line);
            xNum = atoi(x.c_str());
            yNum = atoi(y.c_str());
            dst = new Point2d(xNum,yNum);
            Enemy* e= new Enemy("Elite" , 100 , qualityNum ,p , dst);
			enemies->push_back(e);
            Actors* m =e;
            playerList->insert(std::make_pair(p,m));
        }
        else if (word.compare("archer") == 0) {
            index = word.length();
            quality = getNumberFromIndex(index, line); 
			index = index + quality.length() + 1;
			x = getNumberFromIndex(index, line);
			index = index  + x.length() + 1;
			y = getNumberFromIndex(index, line);
            qualityNum = atof(quality.c_str());
            xNum = atoi(x.c_str());
            yNum = atoi(y.c_str());
            p = new Point2d(xNum, yNum);
			index = index + y.length() + 1;
			x = getNumberFromIndex(index, line);
			index = index + x.length() + 1;
			y = getNumberFromIndex(index, line);
            xNum = atoi(x.c_str());
            yNum = atoi(y.c_str());
            dst = new Point2d(xNum,yNum);
            gender = getNumberFromIndex(index , line);
            gendrNum = atoi(gender.c_str());
            Archer* a= new Archer(qualityNum , p , dst , gendrNum );
			Actors* m = a;
			playerList->insert(std::make_pair(p,m));
			heroes->push_back(a);
		
        }
        else if (word.compare("warrior") == 0) {
            index = word.length();
            quality = getNumberFromIndex(index, line);
			index = index + quality.length() + 1;
			x = getNumberFromIndex(index, line);
			index = index  + x.length() + 1;
			y = getNumberFromIndex(index, line);
            qualityNum = atof(quality.c_str());
            xNum = atoi(x.c_str());
            yNum = atoi(y.c_str());
            p = new Point2d(xNum, yNum);
			index = index + y.length() + 1;
			x = getNumberFromIndex(index, line);
			index = index + x.length() + 1;
			y = getNumberFromIndex(index, line);
            xNum = atoi(x.c_str());
            yNum = atoi(y.c_str());
            dst = new Point2d(xNum,yNum);
            gender = getNumberFromIndex(index , line);
            gendrNum = atoi(gender.c_str());
			Warrior* w = new Warrior(qualityNum , p , dst , gendrNum );
			Actors* m = w;
            playerList->insert(std::make_pair(p,m));
			heroes->push_back(w);

        }
        else if (word.compare("wizard") == 0) {
            index = word.length();
            quality = getNumberFromIndex(index, line); 
			index = index + quality.length() + 1;
			x = getNumberFromIndex(index, line);
			index = index + x.length() + 1;
			y = getNumberFromIndex(index, line);
            qualityNum = atof(quality.c_str());
            xNum = atoi(x.c_str());
            yNum = atoi(y.c_str());
            p = new Point2d(xNum, yNum);
			index = index + y.length() + 1;
			x = getNumberFromIndex(index, line);
			index = index + x.length() + 1;
			y = getNumberFromIndex(index, line);
            xNum = atoi(x.c_str());
            yNum = atoi(y.c_str());
            dst = new Point2d(xNum,yNum);
            gender = getNumberFromIndex(index , line);
            gendrNum = atoi(gender.c_str());
			Wizard* w = new Wizard(qualityNum , p , dst , gendrNum );
			Actors* m = w;
			playerList->insert(std::make_pair(p,m));
			heroes->push_back(w);
        }
        else if (word.compare("sword") == 0) {
            index = word.length();				
            quality = getNumberFromIndex(index, line);
			index = index + quality.length() + 1;
			x = getNumberFromIndex(index, line);
			index = index  + x.length() + 1;
			y = getNumberFromIndex(index, line);
            qualityNum = atof(quality.c_str());
            xNum = atoi(x.c_str());
            yNum = atoi(y.c_str());
            p = new Point2d(xNum, yNum);
			warriorWeapon* m = new warriorWeapon(qualityNum , p , "sword");
			m->Sword();
			itemsList->push_back(m);
        }
		else if (word.compare("hammer") == 0) {
			index = word.length();						
			quality = getNumberFromIndex(index, line);
			index = index + quality.length() + 1;
			x = getNumberFromIndex(index, line);
			index = index + x.length() + 1;
			y = getNumberFromIndex(index, line);
			qualityNum = atof(quality.c_str());
			xNum = atoi(x.c_str());
			yNum = atoi(y.c_str());
			p = new Point2d(xNum, yNum);
			warriorWeapon* m = new warriorWeapon(qualityNum, p, "hammer");
			m->Hammer();
			itemsList->push_back(m);
		}
		else if (word.compare("bow") == 0) {
			index = word.length();
			quality = getNumberFromIndex(index, line);
			index = index + quality.length() + 1;
			x = getNumberFromIndex(index, line);
			index = index + x.length() + 1;
			y = getNumberFromIndex(index, line);
			qualityNum = atof(quality.c_str());
			xNum = atoi(x.c_str());
			yNum = atoi(y.c_str());
			p = new Point2d(xNum, yNum);
			archerWeapon* m = new archerWeapon(qualityNum, p, "bow");
			m->Bow();
			itemsList->push_back(m);
		}
		else if (word.compare("crossbow") == 0) {
			index = word.length();
			quality = getNumberFromIndex(index, line);
			index = index + quality.length() + 1;
			x = getNumberFromIndex(index, line);
			index = index + x.length() + 1;
			y = getNumberFromIndex(index, line);
			qualityNum = atof(quality.c_str());
			xNum = atoi(x.c_str());
			yNum = atoi(y.c_str());
			p = new Point2d(xNum, yNum);
			archerWeapon* m = new archerWeapon(qualityNum, p, "crossbow");
			m->CrossBow();
			itemsList->push_back(m);
		}
		else if (word.compare("staff") == 0) {
			index = word.length();
			quality = getNumberFromIndex(index, line);
			index = index + quality.length() + 1;
			x = getNumberFromIndex(index, line);
			index = index + x.length() + 1;
			y = getNumberFromIndex(index, line);
			qualityNum = atof(quality.c_str());
			xNum = atoi(x.c_str());
			yNum = atoi(y.c_str());
			p = new Point2d(xNum, yNum);
			wizardWeapon* m = new wizardWeapon(qualityNum, p, "staff");
			m->Staff();
			itemsList->push_back(m);
		}
		else if (word.compare("wand") == 0) {
			index = word.length();
			quality = getNumberFromIndex(index, line);
			index = index + quality.length() + 1;
			x = getNumberFromIndex(index, line);
			index = index + x.length() + 1;
			y = getNumberFromIndex(index, line);
			qualityNum = atof(quality.c_str());
			xNum = atoi(x.c_str());
			yNum = atoi(y.c_str());
			p = new Point2d(xNum, yNum);
			wizardWeapon* m = new wizardWeapon(qualityNum, p, "wand");
			m->Wand();
			itemsList->push_back(m);
		}
    }
	filein.close();
}

/*
	update - call too the console.
*/

void Game::update()
{
	this->con->fillData();
	this->con->print();
	printMap();

}

/*
	isGameOver - the game finish in two ways:
				* a hero reach to his destanation point.
				* all the heroes are dead.
				when the game is finish print to file actors conditions.
				if the game isnt finish continue to play.
*/

bool Game::isGameOver() {
	size_t deathCount = 0;
	for (size_t i=0;i < this->heroes->size() ;i++)
	{
		Hero* curHero = heroes->at(i);
		if (curHero->getStartPoint()->isEqual( curHero->getDestPoint())) {

			for (map<Point2d*, Actors*>::iterator it = this->playerList->begin(); it != this->playerList->end(); ++it) {
				outFile << it->second->toString();
				outFile << '\n';
			}
			outFile.close();
			delete this->con;
			return true;
		}
		if (curHero->getHp() <= 0)deathCount++;
	}
	if (deathCount == this->heroes->size()) {
		std::ostringstream oss;
		for (map<Point2d*, Actors*>::iterator it = this->playerList->begin(); it != this->playerList->end(); ++it) {
			outFile << it->second->toString();
			outFile << '\n';
		}
		outFile.close();
		delete this->con;
		return true;
	}
	return false;
}

/*
	play - first check if the game is over.
			run over the heroes so each one will do his move
			check in the radous of the hero if there is a item or enemy to fight
			if there is nothing move.
*/


void Game::play()
{
	bool flag = true;
	while (!isGameOver()) {
		for (size_t z = 0; z < heroes->size(); z++)
		{
			Hero* curHero = heroes->at(z);
			Point2d* p = curHero->getStartPoint();
			for (int i = p->getX() - curHero->getRad(); flag && i < p->getX() + curHero->getRad(); i++)//Find item in radius
			{
				for (int j = p->getY() - curHero->getRad(); flag && i>0 && j <p->getY()+ curHero->getRad() ; j++)
				{
					if (i >= 0 && j >= 0 && i <this->row && j <this->col) {//check if the rad still in the map
						if (this->matP[i][j] == 'P' || this->matP[i][j] == 'S' || this->matP[i][j] == 'W')//found item
						{
							for (size_t k = 0; k < itemsList->size(); k++)
							{
								Point2d* itemPoint = new Point2d(i, j);
								if (itemsList->at(k)->getPoint()->isEqual(itemPoint)) {
									bool didUse=curHero->use(itemsList->at(k));
									if (didUse) {//if the item has been used remove it from the list
										this->itemsList->erase(this->itemsList->begin() + k);
									}
								}
							}

						}

						else if (this->matP[i][j] == 'L' || this->matP[i][j] == 'E')//found enemy
						{
							Point2d* enemyPoint = new Point2d(i, j);
							for (size_t k = 0; k < enemies->size(); k++)
							{
								Enemy* curEnemy = enemies->at(k);
								if (curEnemy->getHp() <= 0) {
									this->matP[i][j] = '.';
								}
								else if (curEnemy->getStartPoint()->isEqual(enemyPoint)) {//attack each other
									curHero->attack(enemies->at(k));
									curEnemy->attack(curHero);
									flag = false;
								}
							}
						}
						
					}

				}

			}
			if (flag)
			{
				curHero->move(curHero->getDestPoint());
			}
			flag = true;
		}
		this->update();

	}
		//delete this;
}
 

void Game::printMap(){
	for (map<Point2d*, Actors*>::iterator it = this->playerList->begin(); it != this->playerList->end(); ++it) {
		cout << it->first->toString() << " => " << it->second->toString() << '\n';
	}
}

int Game::getRow()
{
    return this->row;
}
int Game::getCol()
{
    return this->col;
}

map<Point2d*,Actors*>* Game::getPlayerlist(){
    return playerList;
}

vector<Item*>* Game::getItemlist(){
    return itemsList;
}

char** Game::getMatP(){
    return matP;
}

Game::~Game() {
	for (int i = 0; i < this->row; i++) {
		delete this->matP[i];
	}
	delete this->matP;
	for (size_t i = 0; i < this->itemsList->size(); i++)
	{
		delete itemsList->at(i);
	}
	delete this->itemsList;
	for (map<Point2d*, Actors*>::iterator it = this->playerList->begin(); it != this->playerList->end(); ++it) {
		delete it->first;
		delete it->second;
	}
	delete this->playerList;
	for (size_t i = 0; i < this->heroes->size(); i++)
		{
			delete heroes->at(i);
		}

	delete this->heroes;
for (size_t i = 0; i < this->enemies->size(); i++)
		{
			delete enemies->at(i);
		}
	delete this->enemies;
}

