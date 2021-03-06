#include "NET.h"

NET::NET(int id, std::string name): id(id), name(name){
	this->pinNum = 0;
	this->pathNum = 0;
	this->overflow = 0;
}

void NET::addPin(int x, int y){
	++this->pinNum;

	this->pinX.push_back(x);
	this->pinY.push_back(y);
}

void NET::addPath(int x, int y){
	++this->pathNum;

	this->pathX.push_back(x);
	this->pathY.push_back(y);
}

void NET::ripoff(){
	this->pathNum = 0;
	this->overflow = 0;

	this->pathX.clear();
	this->pathY.clear();
	this->pathX.shrink_to_fit();
	this->pathY.shrink_to_fit();
}
void NET::resetOverflow(){ this->overflow = 0; }
void NET::addOverflow(int o){ this->overflow += o; }
int  NET::getOverflow(){ return this->overflow; }

int NET::getID(){ return this->id; }
std::string NET::getName(){ return this->name; }

int NET::getPinX(int i){ return this->pinX[i]; }
int NET::getPinY(int i){ return this->pinY[i]; }
int NET::getPinNum(){ return this->pinNum; }

int NET::getPathX(int i){ return this->pathX[i]; }
int NET::getPathY(int i){ return this->pathY[i]; }
int NET::getPathNum(){ return this->pathNum; }

int NET::getBoundBox(){
	return abs(this->pinX[0]-this->pinX[1]) + abs(this->pinY[0]-this->pinY[1]);
}