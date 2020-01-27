#include "practice.h"

practice::practice(){ // default constructor
    pracTime = 0;
    pracLoc = "location";
    agendaList[0];
    prepared = false;
    present[0];
}
practice::practice(int t, string l, string a[10], bool b, player p[25]){ // constructor
    pracTime = 0;
    pracLoc = "location";
    for(int i=0; i<10; i++){
        agendaList[i] = a[i];
    }
    prepared = b;
    for(int j=0; j<25; j++){
        present[j] = p[j];
    }
} 
practice::~practice(){
    // destructor
} 
        
void practice::setPracTime(int t){ // setter for practice time
    pracTime = t;
}
int practice::getPracTime(){ // getter for practice time
    return pracTime;
}
void practice::setPracLoc(string l){ // setter for practice location
    pracLoc = l;
}
string practice::getPracLoc(){ // getter for practice location
    return pracLoc;
}
void practice::setAgendaListAt(int index, string goal){ // setter for agenda
    agendaList[index] = goal;
}
string practice::getAgendaListAt(int index){ // getter for agenda
    return agendaList[index];
}
void practice::setPrepared(bool b){ // setter for preparedness
    prepared = b;
}
bool practice::getPrepared(){ // getter for preparedness
    return prepared;
}
void practice::setPresentAt(int index, player member){ // setter for present players
    present[index] = member;
}
player practice::getPresentAt(int index){ // getter for present players
    return present[index];
}