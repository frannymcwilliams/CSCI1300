// CS1300 Spring 2018
// Author: Franny McWilliams
// Recitation: 205 – Harshini Muthukrishnan
// Cloud9 Workspace Editor Link: https://ide.c9.io/frannymcwilliams/csci1300fm
// Homework 3 - Problem #1

#include <iostream>
#include <string>
#include <cmath>
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

// CS1300 Spring 2018
// Author: Franny McWilliams
// Recitation: 205 – Harshini Muthukrishnan
// Cloud9 Workspace Editor Link: https://ide.c9.io/frannymcwilliams/csci1300fm
// Homework 3 - Problem #2

/**
 * Algorithm:
 *      1. Declare a variable for the calculated wind chill value
 *      2. If statement to check if the wind speed is a positive value
 *          3. Calculate the wind chill value
 *      4. Else if statement to check if the wind speed is negative
 *          5. Print that the value isn't applicable and set the value of wind chill to zero
 *      6. Return the calculated wind chill value
 * Parameters: Air temperature and wind speed
 * Output: Not applicable if the input is wrong
 * Returns: Wind chill temperature
 */
 float windChillCalculator(float t, float v) //function to calculate the wind chill
 {
     float windChill; //variable to hold calculated value of the wind chill
     
     if(v >= 0) //if statement to check its positive
     {
         windChill = 35.74 + 0.6215*t - 35.75*pow(v,0.16) + 0.4275*t*pow(v,0.16); //calculate the wind chill
     }
     else if(v < 0) //else if statement to check if it is negative
     {
         cout << "Not applicable" << endl; //print that it isn't applicable
         windChill = 0; //set the wind chill value equal to zero
     }
     return windChill; //return the calculated value
 }

/**
 * Algorithm:
 *      1. Declare a variable for the calcuated wind chill value
 *      2. If statement to make sure the inputs are valid
 *          3. Print that the input is invalid
 *      4. Else statement   
 *          5. While loop
 *              6. Set the low wind speed to the low wind speed + the step value to calculate each next wind chill value
 *              7. Calculate the wind chill value by calling the windChillCalculator function
 *              8. Print the wind chill values, the air temperature, and the wind speed for each value
 * Parameters: Air temperature, low wind speed, high wind speed, step value for wind speed
 * Output: The wind chill value for each temperature and wind speed in a full sentence
 * Returns: Nothing
 */
 void printWindChill(float t, float low_wind_speed, float high_wind_speed, float wind_speed_step) //function to calculate the wind chill for changing wind speeds
 {
     float wind_chill; //variable to hold calculated value of the wind chill
     
     if(low_wind_speed > high_wind_speed || wind_speed_step < 0) //if statement to check if the input is valid
     {
         cout << "Invalid input" << endl; //print that the input is invalid
     }
     else //else statement
     {
         while(low_wind_speed <= high_wind_speed) //while loop
         {
             wind_chill = windChillCalculator(t, low_wind_speed); //calculate the wind chill
             
             cout << "The wind chill is " << wind_chill;
             cout << " degrees F for an air temperature of " << t;
             cout << " degrees F and a wind speed of " << low_wind_speed << " mph." << endl; //print the values in a full sentence
             
             low_wind_speed += wind_speed_step; //calculate the new speed
         }
     }
     
 }

int main(){
    menu(); //call the menu method

    //windChillCalculator test cases
    float x = windChillCalculator(30.0,5.0);
    cout << x << endl;
    float y = windChillCalculator(32.0,-5.0);
    
    //printWindChill test cases
    printWindChill(30.0, 5.0, 8.0, 1.0);
    printWindChill(30.0, 5.0, 8.0, -2.0);

    
}