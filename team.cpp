#include "team.h"

team::team(){ // default constructor
    teamMembers[0];
    teamName = "team name";
    color = "color";
    mascot = "mascot";
    location = "location";
    sport = "sport";
}
team::team(player p[25], string tN, string c, string m, string l, string s){ // constructor
    for(int i=0; i<25; i++){
        teamMembers[i] = p[i];
    }
    teamName = tN;
    color = c;
    mascot = m;
    location = l;
    sport = s;
}
team::~team(){
    // destructor
}
        
void team::setPlayerAt(int index, player p){ // setter for teamMembers
    teamMembers[index] = p;
}
player team::getPlayerAt(int index){ // getter for teamMembers
    return teamMembers[index];
}
void team::setTeamName(string tN){ // setter for team name
    teamName = tN;
}
string team::getTeamName(){ // getter for team name
    return teamName;
}
void team::setColor(string c){ // setter for color
    color = c;
}
string team::getColor(){ // getter for color
    return color;
}
void team::setMascot(string m){ // setter for mascot 
    mascot = m;
}
string team::getMascot(){ // getter for mascot
    return mascot;
}
void team::setLocation(string l){ // setter for city
    location = l;
}
string team::getLocation(){ // getter for city
    return location;
}
void team::setSport(string s){ // setter for sport
    sport = s;
}
string team::getSport(){ // getter for sport
    return sport;
}