/*
 * File:   
 * Author: 
 * Created on 
 * Purpose:  Creation of Template to be used for all
 *           future projects
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>   //Input/Output Manipulation Library
using namespace std;

//Function Prototypes
void Format(int ttlMin, int &hour12, int &minutes12, char &ampm);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    int mhour, minutes, wtHrs, wtMin, ttlWatT, tmem, ttim, tih, tim, newHour, newMin;
    char donoon, runAgin, newDnon;
    
    do {
        //Initialize or input i.e. set variable values
        cout << "Enter hour:" << endl << endl;
        cin >> mhour;
        cout << "Enter minutes:" << endl << endl;
        cin >> minutes;
        cout << "Enter A for AM, P for PM:" << endl << endl;
        cin >> donoon;
        cout << "Enter waiting time:" << endl << endl;
        cin >> wtHrs;  

        // Convert AM/PM to 24-hour format
        int hour = mhour;
        if (donoon == 'p' || donoon == 'P') {
            if (hour != 12) hour += 12;
        } else if (donoon == 'a' || donoon == 'A') {
            if (hour == 12) hour = 0; // Midnight case
        }

        // Calculate total waiting time in minutes
        ttlWatT = wtHrs;
        tmem = hour * 60 + minutes;
        ttim = ttlWatT + tmem;
        
        // Calculate new time in 24-hour format
        tih = (ttim / 60) % 24;
        tim = ttim % 60;

        // Convert back to 12-hour format
        Format(tih * 60 + tim, newHour, newMin, newDnon);

        // Display the outputs
        cout << "Current time = " << setw(2) << setfill('0') << 
                mhour << ":" << setw(2) << setfill('0') << minutes <<
                " " << (donoon == 'a' || donoon == 'A' ? "AM" : "PM") << endl;
        cout << "Time after waiting period = " << setw(2) << setfill('0') << newHour
             << ":" << setw(2) << setfill('0') << newMin<< " " << newDnon << "M" << endl;
        cout << endl;

        // Ask if the user wants to run the program again
        cout << "Again:" << endl;
        cin >> runAgin;
        
        if (runAgin == 'y' || runAgin == 'Y') {
            cout << endl;}
        
    } while (runAgin == 'y' || runAgin == 'Y');

    //Exit stage right or left!
    return 0;
}

// Function to convert total minutes to 12-hour format
void Format(int ttlMin, int &hour, int &minutes, char &ampm) {
    int ttlHrs = ttlMin / 60;
    minutes = ttlMin % 60;
    if (ttlHrs >= 12) {
        ampm = 'P';
        if (ttlHrs > 12) ttlHrs -= 12;
    } else {
        ampm = 'A';
        if (ttlHrs == 0) ttlHrs = 12; // Midnight case
    }
    hour = ttlHrs;
}
