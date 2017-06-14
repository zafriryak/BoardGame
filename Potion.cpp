#include "Potion.h"

Potion::Potion(int type, int quality, Point2d* loc):Item(loc,"Potion") {
    this->_type = type;
    this->_quality = quality;
}

Potion::Potion(const Potion& orig) {
    this->_type = orig._type;
    this->_quality = orig._quality;
    this->_loc = orig._loc;
}

string Potion::toString(){
    std::ostringstream oss;
    oss<< "Potion - Type : "<<this->_type << " , Quality : "<<this->_quality<<" , Point : "<<this->_loc->toString();
    return oss.str();
}

int Potion::getType(){
    return this->_type;
}

int Potion::getQuality(){
    return this->_quality;
}

Potion::~Potion(){
    delete this->_loc;
}





