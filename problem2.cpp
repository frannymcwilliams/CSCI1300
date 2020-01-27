// CS1300 Spring 2018
// Author: Franny McWilliams
// Recitation: 205 – Harshini Muthukrishnan
// Cloud9 Workspace Editor Link: https://ide.c9.io/frannymcwilliams/csci1300fm
// Homework 3 - Problem #2

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

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
    //windChillCalculator test cases
    float x = windChillCalculator(30.0,5.0);
    cout << x << endl;
    float y = windChillCalculator(32.0,-5.0);
    
    //printWindChill test cases
    printWindChill(30.0, 5.0, 8.0, 1.0);
    printWindChill(30.0, 5.0, 8.0, -2.0);
}