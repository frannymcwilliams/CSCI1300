#ifndef PRACTICE_H
#define PRACTICE_H

#include <string>
#include <iostream>
#include "player.h"
using namespace std;

class practice
{
    public:
        practice(); // default constructor
        practice(int, string, string[], bool, player[]); // constructor
        ~practice(); // destructor
        
        void setPracTime(int); // setter for practice time
        int getPracTime(); // getter for practice time
        void setPracLoc(string); // setter for practice location
        string getPracLoc(); // getter for practice location
        void setAgendaListAt(int, string); // setter for agenda
        string getAgendaListAt(int); // getter for agenda
        void setPrepared(bool); // setter for preparedness
        bool getPrepared(); // getter for preparedness
        void setPresentAt(int, player); // setter for present players
        player getPresentAt(int); // getter for present players
    
    private:
        int pracTime; // time represented on 24 hour clock (i.e. 400 is 4am, 1200 is 12pm, 1600 is 4pm)
        string pracLoc; // location of practice
        string agendaList[10]; // an array of goals list
        bool prepared; // represents if the team is prepared or not
        player present[25]; // array of present players at practice
};
#endif // PRACTICE_H