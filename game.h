//The game class will contain an array of 2 teams (one assigned to home and one assigned to away), 
//a game location, a game score, and a game time, 
//and a true or false variable for whether the game is to be played or is not based on rain delay or forfeit.

#ifndef GAME_H
#define GAME_H

#include <string>
#include <iostream>
#include "player.h"
#include "team.h"
using namespace std;

class game
{
    public:
        game(); // default constructor
        game(team[2], int, int, int, bool); // constructor
        ~game(); // destructor
        
        void setCompetitorAt(int, team); // setter for teams array
        team getCompetitorAt(int); // getter for teams array
        void setAwayScore(int); // setter for away team score
        int getAwayScore(); // getter for away team score
        void setHomeScore(int); // setter for home team score
        int getHomeScore(); // getter for home team score
        void setGameTime(int); // setter for game time
        int getGameTime(); // getter for game time
        void setIsPlayed(bool); //setter for isPlayed
        bool getIsPlayed(); // getter for isPlayed
        void incHomeScore(); // increase home score
        void incAwayScore(); // increase away score

    private:
        team competitors[2]; // array of two teams (index 0 is away team index 1 is home team)
        int awayScore; // away team score
        int homeScore; // home team score
        int gameTime; // time of the game
        bool isPlayed; // bool for potential forfeit
};
#endif // GAME_H