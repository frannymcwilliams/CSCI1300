#include "game.h"

game::game(){ // default constructor
        competitors[2];
        awayScore = 0;
        homeScore = 0;
        gameTime = 0;
        isPlayed = false;
}
game::game(team c[2], int a, int h, int t, bool b){ // constructor
        for(int i=0; i<2; i++){
                competitors[i] = c[i];
        }
        awayScore = a;
        homeScore = h;
        gameTime = t;
        isPlayed = b;
}
game::~game(){
        // destructor
}

void game::setCompetitorAt(int index, team t){ // setter for teams array
        competitors[index] = t;
}
team game::getCompetitorAt(int index){ // getter for teams array
        return competitors[index];
}
void game::setAwayScore(int a){ // setter for away team score
        awayScore = a;
}
int game::getAwayScore(){ // getter for away team score
        return awayScore;
}
void game::setHomeScore(int h){ // setter for home team score
        homeScore = h;
}
int game::getHomeScore(){ // getter for home team score
        return homeScore;
}
void game::setGameTime(int t){ // setter for game time
        gameTime = t;
}
int game::getGameTime(){ // getter for game time
        return gameTime;
}
void game::setIsPlayed(bool b){  //setter for isPlayed
        isPlayed = b;
}
bool game::getIsPlayed(){ // getter for isPlayed
        return isPlayed;
}
void game::incHomeScore(){
        homeScore++;
} // increase home score
void game::incAwayScore(){
        awayScore++;
} // increase away score