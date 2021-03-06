#include "EDGE.h"
// #include <iostream>

EDGE::EDGE(int s): supply(s){
    this->demand = 0;
    this->congestion = 0;
    this->history = 1;
}

void EDGE::addNet(int id){
    this->demand++;
    this->netID.push_back(id);
    // std::cout<<"xx "<<id<<std::endl;
}

void EDGE::addHistory(){ 
    if( overflow() ) ++this->history; 
}
int EDGE::getHistory(){ return this->history; }

void EDGE::subDemand(int s, int id){ 
    this->demand -= s; 
    for(std::vector<int>::iterator it = this->netID.begin(); it != this->netID.end(); ++it){
        if( *it == id){
            this->netID.erase(it);
            break;
        }
    }
}

bool EDGE::overflow(){
    if(this->demand > this->supply) return true;
    return false;
}

void EDGE::calCongestion(){ this->congestion = pow(1.0 * this->demand + 1 / this->supply, 5); }
double EDGE::getCongestion(){ return this->congestion; }

int EDGE::getNetNum(){ return this->netID.size(); }
int EDGE::getNetID(int i) { return this->netID[i]; }

int EDGE::getDemand(){ return this->demand; }
int EDGE::getSupply(){ return this->supply; }