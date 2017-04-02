/*******************************************************
 Anmol Jain (504625831)
 Jan 8, 2016.
 This program calculates the distance left to reach the 
 destination and the time it will take to do so rounded
 off to the neares second.
 *******************************************************/
#include <iostream>
using namespace std;

int main ()
{
    double distancetraveled, distanceleft, time;
    int days, hours, minutes, seconds;
    
    cout << "Enter a decimal between 0 and 377.6: ";
    cin >> distancetraveled; //accepts a double value for the distance traveled
    
    distanceleft = 377.6 - distancetraveled; //calculates the distance left to reach the destination
    
    cout << "You still have to travel " <<distanceleft << " Km to reach your destination.\n";
    
    time = distanceleft / 5; //calculates time it will take to cover the distance left
    time *= 3600; //converts the time from hours to seconds
    time += 0.5; //add 0.5 to round off time in seconds to the nearest second
    
    seconds = time; //since the variable seconds is of int data type, it only takes up the integer value of time
    days = seconds / 86400; //divides by 86400 to determine number of days
    seconds %= 86400; //stores left over time in seconds in variable seconds
    hours = seconds / 3600; //divides by 3600 to determine number of hours
    seconds %= 3600; //stores left over time in seconds in variable seconds
    minutes = seconds / 60; //divides by 3600 to determine number of minutes
    seconds %= 60; //stores left over time in seconds in variable seconds
    
    cout << "Traveling at a speed of 5 Km/hr, you will reach it in:\n";
    cout << days << " days, " << hours << " hours, " << minutes << " minutes and about " << seconds << " seconds.";
    //displays the time taken in day, hours, minutes and seconds (rounded off to the nearest second)
    return 0;
}