#include <iostream>
using namespace std;

// Author: Franny McWilliams
// Recitation: 205 – Harshini Muthukrishnan
// Cloud9 Workspace Editor Link: https://ide.c9.io/frannymcwilliams/csci1300fm
// Homework 2 - Problem 1

/** 
 * ALGORITHM:
 * 1. Declare and initialize int variables pop, yearSecs, births, deaths, and immigrants
 * 2. Calculate the values for births, deaths, and immigrants
 * 3. Add the values to get the new population value
 * 3. Return the new pop
 * Input parameters: current population size
 * Output: none
 * Return: the new population size
 */
 
 int population(int currentPop)
 {
     int pop; //variable for population value
     int yearSecs; //variable for one year in seconds
     int births; //variable for births per year
     int deaths; //variable for deaths per year
     int immigrants; //variable for immigrants per year
     
     yearSecs = 365*24*60*60; //calculate the value of a year in seconds
     
     births = (yearSecs/8); //calculate the births per year
     deaths = (yearSecs/-12); //calculate the deaths per year
     immigrants = (yearSecs/33); //calculate the immigrants per year
     
     pop = currentPop + births + deaths + immigrants; //calcuate the new population
     
     return pop; //return the final population value
 }
 
// Author: Franny McWilliams
// Recitation: 205 – Harshini Muthukrishnan
// Cloud9 Workspace Editor Link: https://ide.c9.io/frannymcwilliams/csci1300fm
// Homework 2 - Problem 2

/** 
 * ALGORITHM:
 * 1. Declare int variables days, hours, mins, secs
 * 2. Initialize variables through calculating their values
 * 3. Print out the numSeconds valued entered, followed by the conversion
 * Input parameters: number of seconds
 * Output: String with the new conversion
 * Return: Nothing
 */
 
 void howLong(int numSeconds)
 {
     int days; //variable for days
     int hours; //variable for hours
     int mins; //variable for minutes
     int secs; //variable for hours
     
     mins = numSeconds/60; //minutes value
     secs = numSeconds%60; //seconds value
     hours = mins/60; //hours value
     mins = mins%60; //minutes value
     days = hours/24; //days value
     hours = hours%24; //hours value
     
     //print statement that outputs a string
     cout << numSeconds << " seconds is " << days << " days, " << hours << " hours, " << mins << " minutes, and " << secs << " seconds.";
 }
 
// Author: Franny McWilliams
// Recitation: 205 – Harshini Muthukrishnan
// Cloud9 Workspace Editor Link: https://ide.c9.io/frannymcwilliams/csci1300fm
// Homework 2 - Problem 3

/** 
 * ALGORITHM:
 * 1. Declare a float variable n
 * 2. Compute the value for the carnot efficiency and set it equal to n
 * 3. Return n
 * Input parameters: a cold and hot integer temperature value
 * Output: Nothing
 * Return: Carnot effeciency
 */
 
 float carnot(int coldTemp, int hotTemp)
 {
     float n; //variable for carnot efficiency value
     
     n = 1 - ((float)coldTemp/(float)hotTemp); //carnot efficiency equation
     //cast coldTemp and hotTemp as a float so it returns a value w decimals
     
     return n; //return the carnot efficiency value
 }
 
 int main()
 {
     int pop1 = population(1000000); //call the function and store it in pop1
     cout << pop1; //should output 3269636
     
     int pop2 = population(12365478); //call the function and store it in pop2
     cout << pop2; //should output 14635114
     
     howLong(70000); //should output "70000 seconds is 0 days, 19 hours, 26 minutes, and 40 seconds."
     howLong(6000); // should output "6000 seconds is 0 days, 1 hours, 40 minutes, and 0 seconds."
    
     float x = carnot(294, 1089); //call the function and store it in x
     cout << x << "\n"; //should return 0.730028
     
     float y = carnot(160,1100); //call the funciton and store it in x
     cout << y; //should return 0.854545
 }