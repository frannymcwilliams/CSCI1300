// Author: Franny McWilliams
// Recitation: 205 – Harshini Muthukrishnan
// Cloud9 Workspace Editor Link: https://ide.c9.io/frannymcwilliams/csci1300fm
// Homework 2 - Problem 3

#include <iostream>
using namespace std;

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
     float x = carnot(294, 1089); //call the function and store it in x
     cout << x << "\n"; //should return 0.730028
     
     float y = carnot(160,1100); //call the funciton and store it in x
     cout << y; //should return 0.854545
 }