#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include "nutrients.h"
using namespace std;

class player
{
    public:
        player(); // default constructor
        player(string, int, float, int, nutrients[], string); // constructor
        ~player(); // destructor
            
        void setName(string); // setter for name
        string getName(); // getter for name
        void setHeight(int); // setter for height
        int getHeight(); // getter for height
        void setWeight(float); // setter for weight
        float getWeight(); // getter for weight
        void setAge(int); // setter for age
        int getAge(); // getter for age
        void setNutrientsConsumedAt(int, nutrients); // setter for nutrients array at certain index
        nutrients getNutrientsConsumedAt(int); // getter for nutrients array at certain index
        void setBestSport(string); // setter for favorite/best sport
        string getBestSport(); // getter for favorite/best sport
        
    private:
        string name; // player name
        int height; // player height in inches
        float weight; // player weight in pounds
        int age; // player age
        nutrients consumed[4]; // nutrients the player has consumed
        string bestSport; // player's favorite/best sport
};
#endif // PLAYER_H