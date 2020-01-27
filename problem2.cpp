// Author: Franny McWilliams
// Recitation: 205 – Harshini Muthukrishnan
// Cloud9 Workspace Editor Link: https://ide.c9.io/frannymcwilliams/csci1300fm
// Homework 2 - Problem 2

#include <iostream>
using namespace std;

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
 
 int main()
 {
     howLong(70000); //should output "70000 seconds is 0 days, 19 hours, 26 minutes, and 40 seconds."
     howLong(6000); // should output "6000 seconds is 0 days, 1 hours, 40 minutes, and 0 seconds."
 }

