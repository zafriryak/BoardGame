#include "Console.h"


#define EnemyDef 'E'
#define EliteDef 'L'
#define WarriorDef 'A'
#define ArcherDef 'R'
#define WizardDef 'Z'
#define PotionDef 'P'
#define WeaponDef 'W'
#define ArmorDef 'S'


Console::Console(map<Point2d*, Actors*>* playerList, vector<Item*>* itemsList,char** matP,int row,int col){
    this->itemsList=itemsList;
    this->matP=matP;
    this->playerList=playerList;
    this->row=row;
    this->col=col;
}

Console::Console(const Console& orig) {
    this->itemsList=orig.itemsList;
    this->matP=orig.matP;
    this->playerList=orig.playerList;
    this->row=orig.row;
    this->col=orig.col;
}

/*
 fillData - start with filling the matrix with '.'
			run over the actor's map and put them on the map only if they still alive
			run over the item list and put them on the map, if the potion has been used he wont be in the list.
*/

void Console::fillData(){
    int r,c;
    for (int i = 0 ; i < row ; i++) {
        for(int j = 0 ; j < col ; j++){
            matP[i][j] = '.';
        }
    }
    for(map<Point2d*,Actors*>::iterator it=this->playerList->begin(); it!=this->playerList->end(); ++it){
        r=it->first->getX();
        c=it->first->getY();
        string type=it->second->getType();
		if (it->second->getHp() > 0) {
			if (type.compare("Enemy") == 0) {
				matP[r][c] = EnemyDef;
			}
			else if (type.compare("Elite") == 0) {
				matP[r][c] = EliteDef;
			}
			else if (type.compare("Warrior") == 0) {
				matP[r][c] = WarriorDef;
			}
			else if (type.compare("Archer") == 0) {
				matP[r][c] = ArcherDef;
			}
			else if (type.compare("Wizard") == 0) {
				matP[r][c] = WizardDef;
			}
		}
    }
    for(int i=0;i<itemsList->size();i++){
        string name=itemsList->at(i)->getName();
        Point2d* p=itemsList->at(i)->getPoint();
        r=p->getX();
        c=p->getY();
        if(name.compare("Potion")==0){
            matP[r][c]= PotionDef;
        }
        else if(name.compare("Weapon")==0){
            matP[r][c]= WeaponDef;
        }
        else if(name.compare("Armor")==0){
            matP[r][c]= ArmorDef;
        }
    }
}

void Console::print(){
     for (int i=0 ;i<row;i++) {
      for (int j=0 ;j<col;j++) {
          printf("%c " , matP[i][j]);
        }
      printf("\n");
    }
}

Console::~Console() {
    delete this->itemsList;
    delete this->matP;
    delete this->playerList;
}

