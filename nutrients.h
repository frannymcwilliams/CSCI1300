#ifndef NUTRIENTS_H
#define NUTRIENTS_H

#include <iostream>
using namespace std;

class nutrients
{
    public:
        nutrients(); // default constructor
        nutrients(float, float, float, float); // constructor
        ~nutrients(); // destructor
        
        void setFood(float); // setter for food
        float getFood(); // getter for food
        void setWater(float); // setter for water
        float getWater(); // getter for water
        void setProteinPowder(float); // setter for protein powder
        float getProteinPowder(); // getter for protein powder
        void setEnergyBoost(float); // setter for energy boost
        float getEnergyBoost(); // getter for energy boost
        bool eligible(string); // bool if player has enough nutrients to play

    private:
        float food; // amount of cups of food consumed
        float water; // amount of cups of water consumed
        float proteinPowder; // amount of cups of protein powder consumed
        float energyBoost; // amount of cups of energy boost consumed
};
#endif // NUTRIENTS_H