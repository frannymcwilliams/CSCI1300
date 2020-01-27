#include "nutrients.h"

nutrients::nutrients(){ // default constructor, set all values to 0.0
    food = 0.0;
    water = 0.0;
    proteinPowder = 0.0;
    energyBoost = 0.0;
} 
nutrients::nutrients(float f, float w, float p, float e){ // constructor
    food = f;
    water = w;
    proteinPowder = p;
    energyBoost = e;
}
nutrients::~nutrients(){
    // destructor
}
        
void nutrients::setFood(float f){ // setter for food
    food = f;
}
float nutrients::getFood(){ // getter for food
    return food;
}
void nutrients::setWater(float w){ // setter for water
    water = w;
}
float nutrients::getWater(){ // getter for water
    return water;
}
void nutrients::setProteinPowder(float p){ // setter for protein powder
    proteinPowder = p;
}
float nutrients::getProteinPowder(){ // getter for protein powder
    return proteinPowder;
}
void nutrients::setEnergyBoost(float e){ // setter for energy boost
    energyBoost = e;
}
float nutrients::getEnergyBoost(){ // getter for energy boost
    return energyBoost;
}
bool nutrients::eligible(string p){
    bool eligiblity = false;
    if(getFood()>4.0 && getWater()>4.0){
        if(getProteinPowder()>2.0 || getEnergyBoost()>4.0){
                eligiblity = true;
        }
    }
    return eligiblity;
}