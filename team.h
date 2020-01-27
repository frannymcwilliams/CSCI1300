#ifndef TEAM_H
#define TEAM_H

#include <string>
#include <iostream>
#include "player.h"
using namespace std;

class team
{
    public:
        team(); // default constructor
        team(player[], string, string, string, string, string); // constructor
        ~team(); // destructor
        
        void setPlayerAt(int, player); // setter for teamMembers
        player getPlayerAt(int); // getter for teamMembers
        void setTeamName(string); // setter for team name
        string getTeamName(); // getter for team name
        void setColor(string); // setter for color
        string getColor(); // getter for color
        void setMascot(string); // setter for mascot 
        string getMascot(); // getter for mascot
        void setLocation(string); // setter for city
        string getLocation(); // getter for city
        void setSport(string); // setter for sport
        string getSport(); // getter for sport
         
    private:
        player teamMembers[25]; // array of players on the team
        string teamName; // the team name
        string color; // the team color
        string mascot; // the team mascot
        string location; // the team location city (home field)
        string sport; // the sport that the team plays
};
#endif // TEAM_H