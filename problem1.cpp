// CS1300 Spring 2018
// Author: Franny McWilliams
// Recitation: 205 – Harshini Muthukrishnan
// Cloud9 Workspace Editor Link: https://ide.c9.io/frannymcwilliams/csci1300fm
// Homework 3 - Problem #1

#include <iostream>
#include <string>
using namespace std;

/**
 * Algorithm:
 *      1. Declare variables
 *      2. Prompt the user to enter values and store the values in each variable
 *      3. Use the given values to create a story
 * Parameters: None
 * Output: A short mad libs story
 * Returns: Nothing
 */
 void story1() //function for mad libs story 1 
 {
     string pluralNoun; //variable for plural noun to be inputed by user
     string occupation; //variable for occupation to be inputed by user
     string animal; //variable for animal inputed to be by user
     string place; // variable for place inputed to be by user
     
     cout << "Enter a plural noun: \n"; //ask the user to enter a plural noun
     cin >> pluralNoun; //initialize the entered value to the variable
     cout << "Enter an occupation: \n"; //ask the user to enter an occupation
     cin >> occupation; //initialize the entered value to the variable
     cout << "Enter an animal name: \n"; //ask the user to enter an animal
     cin >> animal; //initialize the entered value to the variable
     cout << "Enter a place: \n"; //ask the user to enter a place
     cin >> place; //initialize the entered value to the variable
     
     cout << "In the book War of the " << pluralNoun;
     cout << ", the main character is an anonymous " << occupation;
     cout << " who records the arrival of the " << animal;
     cout << "s in " << place << "." << endl; //print the story with the entered values
 }
 
 /**
 * Algorithm:
 *      1. Declare variables
 *      2. Prompt the user to enter values and store the values in each variable
 *      3. Use the given values to create a story
 * Parameters: None
 * Output: A short mad libs story
 * Returns: Nothing
 */
 void story2() //function for mad libs story 1
 {
     string name; //variable for name to be entered by user
     string state_country; //variable for state/country to be entered by user
     
     cout << "Enter a name: \n"; //prompt the user to enter a name
     cin >> name; //initialize the entered value to the variable
     cout << "Enter a state/country: \n"; //prompt the user to enter a state/country
     cin >> state_country; //initialize the entered value to the variable
     
     cout << name << ", I've got a feeling we're not in ";
     cout << state_country << " anymore." << endl; //print the story with the entered values
 }
 
 /**
 * Algorithm:
 *      1. Declare variables
 *      2. Prompt the user to enter values and store the values in each variable
 *      3. Use the given values to create a story
 * Parameters: None
 * Output: A short mad libs story
 * Returns: Nothing
 */
 void story3() //function for mad libs story 3
 {
     string firstName; //variable for first name to be entered by user
     string relative; //variable for relative to be entered by user
     string verb; //variable for verb to be entered by user
     
     cout << "Enter a first name: \n"; //prompt the user to enter a first name
     cin >> firstName; //initialize the entered value to the variable
     cout << "Enter a relative: \n"; //prompt the user to enter a relative
     cin >> relative; //initialize the entered value to the variable
     cout << "Enter a verb: \n"; //prompt the user to enter a verb
     cin >> verb; //initialize the entered value to the variable
     
     cout << "Hello. My name is " << firstName;
     cout << ". You killed my " << relative;
     cout << ". Prepare to " << verb << "." << endl; //print the story with the entered values
 }
 
 /**
 * Algorithm:
 *      1. Declare a variable for the user's response
 *      2. While loop
 *          3. Prompt the user which game they want to play or if they want to quit and store the value in q
 *          4. If the user choose to quit, print good bye and the loop ends
 *          5. If the user chooses story 1, call the story1 method
 *          6. If the user chooses story 2, call the story2 method
 *          7. If the user chooses story 3, call the story3 method
 *          8. If the user doesnt choose a valid choice print that and reenter the loop
 * Parameters: None
 * Output: The users choice of story, prompts them to continue playing until they quit
 * Returns: Nothing
 */
 void menu() //function that calls story1, story2, story3
 {
     string response; //variable to store the user's response
     while (response != "q") //while loop that executes until the user quits
     {
         cout << "Which story would you like to play? Enter the number of the story (1, 2, or 3) or type q to quit: \n"; //prompt the user to choose a story or quit
         cin >> response; //initialize the entered value to the variable
         if(response == "q") //if the user quits
         {
             cout << "good bye"; //print good bye
             
         }
         else if(response == "1") //if the user chooses story 1
         {
             story1(); //do the story1 function
             
         }
         else if(response == "2") //if the user chooses story 2
         {
             story2(); //do the story2 function
             
         }
         else if(response == "3") //if the user chooses story 3
         {
             story3(); //do the story2 function
             
         }
         else //otherwise
         {
         cout << "Valid choice not selected. \n"; //print that the option isnt valid
             
         }
         
     }
     
 }

int main(){
    menu(); //call the menu method
}