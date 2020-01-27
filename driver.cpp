#include "nutrients.cpp"
#include "player.cpp"
#include "team.cpp"
#include "practice.cpp"
#include "game.cpp"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
    // upload players
    string pLine;
    int pIndex = 0;
    player roster[25];
    
    ifstream playstream;
    playstream.open("players.txt");
    
    if(playstream.is_open()){
        while(getline(playstream, pLine)){
            if(pLine.length() != 0){
                for(int i=0; i<pLine.length(); i++){
                    if(pLine[i] == ','){
                        player athlete = player();
                        athlete.setName(pLine.substr(0, i));
                        athlete.setBestSport(pLine.substr(i+1));
                        roster[pIndex] = athlete;
                        pIndex++;
                    }
                }
            }
        }
    }
    playstream.close();
    
    // upload teams
    string tLine;
    int tIndex = 0;
    team teams[8];
    
    ifstream teamstream;
    teamstream.open("teams.txt");
    
    if(teamstream.is_open()){
        while(getline(teamstream, tLine)){
            if(tLine.length() != 0){
                for(int j=0; j<tLine.length(); j++){
                    if(tLine[j] == ','){
                        team away = team();
                        away.setTeamName(tLine.substr(0, j));
                        away.setSport(tLine.substr(j+1));
                        teams[tIndex] = away;
                        tIndex++;
                    }
                }
            }
        }
    }
    teamstream.close();
    
    // ask user if it is practice or game
    string pracGame;
    cout << "Would you like to practice or play in a game?" << endl;
    cin >> pracGame;
    
    for(int i=0; i<pracGame.length(); i++){
        pracGame[i] = tolower(pracGame[i]);
    }
    
    // keep asking if incorrect input
    while(pracGame!="practice" && pracGame!="game"){
        cout << "Invalid input, please choose practice or game:" << endl;
        cin >> pracGame;
    }
    
    // if practice, check attendance and go through the goals
    if(pracGame == "practice"){
        practice userPrac;
        
        string teamNameInput;
        cout << "Please enter your team's name:" << endl;
        cin >> teamNameInput;
        
        int timeInput;
        cout << "Please enter the practice time represented on 24 hour clock (i.e. 400 is 4am, 1200 is 12pm, 1600 is 4pm):" << endl;
        cin >> timeInput;
        userPrac.setPracTime(timeInput);
        
        string locInput;
        cout << "Please enter the practice location:" << endl;
        cin >> locInput;
        userPrac.setPracLoc(locInput);
        
        string goalInput;
        int count=0;
        while(goalInput != "done" && count<10){
            cout << "Please enter a goal, or done if you have no more goals:" << endl;
            cin >> goalInput;
            for(int i=0; i<10; i++){
                userPrac.setAgendaListAt(i, goalInput);
            }
            count++;
        }
        
        string playerInput;
        int counter=0;
        while(playerInput != "done" && counter<25){
            cout << "Please enter the name of a present player, or done if there are no more present players:" << endl;
            cin >> playerInput;
            counter++;
        }
        
        string preparedInput;
        cout << "Is your team prepared for a game? Y/N:" << endl;
        cin >> preparedInput;
        
        while(preparedInput != "Y" && preparedInput != "N"){
            cout << "Please choose Y or N:" << endl;
            cin >> preparedInput;
        }
        if(preparedInput == "N"){
            cout << "Better luck next time." << endl;
        }
        else if(preparedInput == "Y"){
            string yInput;
            cout << "Would you like to play in a game? Y/N:" << endl;
            cin >> yInput;
            
            while(yInput != "Y"){
                cout << "Please choose Y or N:" << endl;
                cin >> yInput;
            }
            if(yInput == "N"){
                cout << "Thank you for practicing." << endl;
            }
            else if(yInput == "Y"){
                cout << "Good luck in your game!" << endl;
                pracGame = "game";
            }
        }
    }
    
    // if game, tell user to enter a team for home, and take away team from upload, play game
    else if(pracGame == "game"){
        game userGame = game();
        
        string teamNameInput;
        cout << "Please enter your team's name:" << endl;
        cin >> teamNameInput;
        
        string opp;
        cout << "Please choose a number from 0 and 7:" << endl;
        cin >> opp;
        
        int oppIndex = stoi(opp);
        string opponent = teams[oppIndex].getTeamName();
        string gameSport = teams[oppIndex].getSport();
        string entry;
        cout << "Welcome to the game, " << teamNameInput << "! Your opponent is the " << opponent 
        << ", and today you will be playing " << gameSport << ". Let's play! (Type any key to move on):" << endl;
        cin >> entry;
        
        //baseball game
        if(gameSport == "baseball"){
            string userHit;
            cout << "Hit the ball! (type 1, or 2):" << endl;
            cin >> userHit;
            if(userHit == "1"){
                cout << "Home run! (Type any key to move on):" << endl;
                cin >> entry;
                userGame.incHomeScore();
            }
            else if(userHit == "2"){
                cout << "Great hit! You are on second base now. (Type any key to move on):" << endl;
                cin >> entry;
                string userHit2;
                cout << "Your teammate hit the ball! Run! (type 1 or 2)" << endl;
                cin >> userHit2;
                if(userHit2 == "1"){
                    cout << "You and your teammate are out, it is the other team's turn to hit now. (Type any key to move on):" << endl;
                }
                else if(userHit2 == "2"){
                    cout << "You scored a run! (Type any key to move on):" << endl;
                    cin >> entry;
                    userGame.incHomeScore();
                }
            }
            cout << "The other team will hit now. (Type any key to move on):" << endl;
            cin >> entry;
            if(userGame.getHomeScore() < 1){
                userGame.setAwayScore(2);
            }
            else{
                userGame.setAwayScore(0);
            }
            cout << "The other team scored " << userGame.getAwayScore() << " hits. (Type any key to move on):" << endl;
            cin >> entry;
        }
        
        //soccer game
        else if(gameSport == "soccer"){
            string userPlay;
            cout << "Shoot the ball! (Type 1 or 2):" << endl;
            cin >> userPlay;
            if(userPlay == "1"){
                cout << "You scored! (Type any key to move on):" << endl;
                cin >> entry;
                userGame.incHomeScore();
                
                string userDefense;
                cout << "The other team has the ball! Defend! (type 1 or 2):" << endl;
                cin >> userDefense;
                if(userDefense == "1"){
                    cout << "The other team scored. (Type any key to move on)" << endl;
                    cin >> entry;
                    userGame.incAwayScore();
                }
                else if(userDefense == "2"){
                    cout << "You saved the goal! (Type any key to move on)" << endl;
                    cin >> entry;
                }
            }
            else if(userPlay == "2"){
                string userDefense;
                cout << "You lost the ball! Defend! (type 1 or 2):" << endl;
                cin >> userDefense;
                if(userDefense == "1"){
                    cout << "The other team scored. (Type any key to move on)" << endl;
                    cin >> entry;
                    userGame.incAwayScore();
                }
                else if(userDefense == "2"){
                    cout << "You saved the goal! (Type any key to move on)" << endl;
                    cin >> entry;
                }
            }
        }
        
        //result of the game
        string result = "tied";
        if(userGame.getAwayScore() > userGame.getHomeScore()){
            result = "lost";
        }
        else if(userGame.getAwayScore() < userGame.getHomeScore()){
            result = "won";
        }
        cout << "Your team " << result << ", and the final score was " << userGame.getHomeScore() 
        << " - " << userGame.getAwayScore() << "." << endl;
        
        //save scores to scores file
        ofstream scoresFile;
        scoresFile.open("scores.txt", ios::app);
        if(scoresFile.is_open()){
            scoresFile << "Your team " << result << ", and the final score was " << userGame.getHomeScore() 
            << " - " << userGame.getAwayScore() << "." << endl;
            scoresFile.close();
        }
        else{
            scoresFile << "" << endl;
            scoresFile.close();
        }
    }
}