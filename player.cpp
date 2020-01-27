#include "player.h"

player::player(){ // default constructor, set values to 0 or generic value
    name = "player";
    height = 0;
    weight = 0.0;
    age = 0;
    nutrients consumed[0];
    bestSport = "sport";
}
player::player(string n, int h, float w, int a, nutrients c[4], string s){ // constructor
    name = n;
    height = h;
    weight = w;
    age = a;
    for(int i=0; i<4; i++){
        consumed[i] = c[i];
    }
    bestSport = s;
}
player::~player(){
    // destructor
}
            
void player::setName(string n){ // setter for name
    name = n;
}
string player::getName(){ // getter for name
    return name;
}
void player::setHeight(int h){ // setter for height
    height = h;
}
int player::getHeight(){ // getter for height
    return height;
}
void player::setWeight(float w){ // setter for weight
    weight = w;
}
float player::getWeight(){ // getter for weight
    return weight;
}
void player::setAge(int a){ // setter for age
    age = a;
}
int player::getAge(){ // getter for age
    return age;
}
void player::setNutrientsConsumedAt(int index, nutrients n){ // setter for nutrients array at certain index
    consumed[index] = n;
}
nutrients player::getNutrientsConsumedAt(int index){ // getter for nutrients array at certain index
    return consumed[index];
}
void player::setBestSport(string sport){ // setter for favorite/best sport
    bestSport = sport;
}
string player::getBestSport(){ // getter for favorite/best sport
    return bestSport;
}