#include "Hero.h"
#include "Potion.h"

Hero::Hero(){
    
}

Hero::Hero(string type, double xp, Point2d* startLoc , Point2d* dest , int gender) :Actors(startLoc,dest,fullHeal,type) {
    this->_xp = xp;
    this->_gender = gender;
    this->_wep = new Weapon(1 , startLoc , "none");
}

Hero::Hero(const Hero& orig){
    this->_type = orig._type;
    this->_xp = orig._xp;
    this->_gender = orig._gender;
    this->_start = orig._start;
    this->_dest = orig._dest;
    this->_wep = new Weapon(1 , orig._start , "none");
}


/*
  Attack - use the enemy demage. 
 */
void Hero::attack(Enemy* e){
	if (this->_wep == nullptr) {
		e->damage(this->_xp);
	}
	else {
		double damage = this->_xp * this->_wep->getXp();
		e->damage(damage);
	}
}
/*
  damegae - calculate the damage with the armor.
*/


void Hero::damage(const double dam){
	if (this->_Bodyarm == nullptr && this->_Shieldarm == nullptr) {
		this->_hp = this->_hp - dam;
	}
	else if (this->_Bodyarm == nullptr)
	{
		this->_hp = this->_hp - this->_Shieldarm->getArmor()*dam;
	}
	else if (this->_Shieldarm == nullptr)
	{
		this->_hp = this->_hp - this->_Bodyarm->getArmor()*dam;
	}
	else {
		this->_hp = this->_hp - (this->_Bodyarm->getArmor()*this->_Shieldarm->getArmor()*dam);
	}
}

/*
 move- if he can he will move in diagonal until he have to move in straight line
*/

void Hero::move( Point2d* dest){
	int x = dest->getX() - this->_start->getX();
	int y = dest->getY() - this->_start->getY();
	if(x<0 && y<0){
		this->_start->setX(this->_start->getX() - 1);
		this->_start->setY(this->_start->getY() - 1);
	}
	else if (x > 0 && y > 0) {
		this->_start->setX(this->_start->getX() +1);
		this->_start->setY(this->_start->getY() + 1);
	}
	else if (x > 0 && y < 0) {
		this->_start->setX(this->_start->getX() + 1);
		this->_start->setY(this->_start->getY() - 1);
	}
	else if (x < 0 && y > 0) {
		this->_start->setX(this->_start->getX() - 1);
		this->_start->setY(this->_start->getY() + 1);
	}
	else if(y>0)this->_start->setY(this->_start->getY() + 1);
	else if(y<0)this->_start->setY(this->_start->getY() - 1);
	else if(x>0)this->_start->setX(this->_start->getX() + 1);
	else if(x<0)this->_start->setX(this->_start->getX() - 1);


}

/*
 use - check which item has been collected.
	   check if the hero can use this item.
	   return if he use it or not.
*/

bool Hero::use(Item* i){
	bool didUse = false;
		if (Weapon* wep = dynamic_cast<Weapon*>(i)) { //derived from weapon
			if (warriorWeapon* wep1 = dynamic_cast<warriorWeapon*>(wep)) {
				if (Warrior* war = dynamic_cast<Warrior*>(this)) { // if the hero is warrior
					if (this->_wep == NULL || this->_wep->getXp() < wep->getXp()) {
						this->_wep = wep;
						if (wep->getNumOfHandWep() == twoHanded) {
							this->_Shieldarm->setArmor(1);
						}
						return true;
					}
				}
			}
			else if (wizardWeapon* wep1 = dynamic_cast<wizardWeapon*>(wep)) {
				if (Wizard* wiz = dynamic_cast<Wizard*>(this)) { // if the hero is wizard
					if (this->_wep == NULL || this->_wep->getXp() < wep->getXp()) {
						this->_wep = wep;
						if (wep->getNumOfHandWep() == twoHanded) {
							this->_Shieldarm->setArmor(1);
						}
						return true;
					}
				}
			}
			else if (archerWeapon* wep1 = dynamic_cast<archerWeapon*>(wep)) {
				if (Archer* war = dynamic_cast<Archer*>(this)) { // if the hero is archer
					if (this->_wep == NULL || this->_wep->getXp() < wep->getXp()) {
						this->_wep = wep;
						if (wep->getNumOfHandWep() == twoHanded && this->_Shieldarm!=nullptr) {
							this->_Shieldarm->setArmor(1);
						}
						return true;
					}
				}
			}
		}

		else if (Armor* arm = dynamic_cast<Armor*>(i)) { //derived from armor
			if (BodyArmor* bodyarm = dynamic_cast<BodyArmor*>(arm)) {
				if (this->_Bodyarm == nullptr) {
					this->_Bodyarm = bodyarm;
					return true;
				}
				else if (this->_Bodyarm->getArmor() < bodyarm->getArmor()) {
					this->_Bodyarm = bodyarm;
					return true;
				}
			}
			if (ShieldArmor* shieldarm = dynamic_cast<ShieldArmor*>(arm)) {
				if (this->_Shieldarm == nullptr) {
					this->_Shieldarm = shieldarm;
					return true;
				}
				else if (this->_wep->getNumOfHandWep() == oneHanded && this->_Shieldarm->getArmor() < shieldarm->getArmor()) {
					this->_Shieldarm = shieldarm;
					return true;
				}
			}
		}

		else if (Potion* pot = dynamic_cast<Potion*>(i)) { //derived from potion
			if (pot->getType() == Health) {
				this->_hp = this->_hp + pot->getQuality();
				if (this->_hp > fullHeal) {
					this->_hp = fullHeal;
				}
				return true;
			}
			else if (Wizard* wiz = dynamic_cast<Wizard*>(this)) {
				if (pot->getType() == Mana) {
					this->_hp = this->_hp + pot->getQuality();
					if (this->_hp > fullHeal) {
						this->_hp = fullHeal;
					}
					return true;
				}
			}
		}
		return didUse;
}

string Hero::toString(){
    std::ostringstream oss;
    oss << this->_type << ": "<< "," <<"Point : "<<this->_start->toString() <<" , Health : "<<this->_hp<<" , Power : "<<this->_xp;
    return oss.str();
}

int Hero::getRad()
{
	return this->_rad;
}

Hero::~Hero(){
    delete this->_start;
    delete this->_dest;
    delete this->_Bodyarm;
    delete this->_Shieldarm;
    delete this->_wep;
}


