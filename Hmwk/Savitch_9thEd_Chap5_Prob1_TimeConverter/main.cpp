/*
 * Author: Ireoluwa
 * Created on June 18, 2024, 12:19 PM
 * Purpose:  Time converter
 */


// System Libraries
#include <iostream>  // Input/Output Library
#include <iomanip>   // Input/Output Manipulation Library
using namespace std;

// Function Prototypes
void Fmt(int ttlMin, int &hour, int &minutes, char &ampm);
bool IsVTime(int hour, int minute);

// Execution Begins Here!
int main(int argc, char** argv) {
    // Declare Variables
    int hour, minutes, newHour, newMin;
    char colon, runAgain, newDnon;
    
    cout << "Military Time Converter to Standard Time" << endl;
    cout << "Input Military Time hh:mm" << endl;

    do {
        // Input time
        
        cin >> hour >> colon >> minutes;

        // Validate time
        if (!IsVTime(hour, minutes)) {
            cout << setw(2) << hour << ":" << setw(2) << minutes 
                 << " is not a valid time" << endl;
        } else {
            // Convert and display the time
            Fmt(hour * 60 + minutes, newHour, newMin, newDnon);
            cout << setw(2) << setfill('0') << hour << ":" << setw(2) << minutes
                 << " = " <<newHour << ":" << setw(2) << newMin 
                 << " " << newDnon << "M" << endl;
        }

        // Ask if the user wants to convert another time
        cout << "Would you like to convert another time (y/n)" << endl;
        cin >> runAgain;

    } while (runAgain == 'y' || runAgain == 'Y');

    return 0;
}

// Function to convert total minutes to 12-hour format
void Fmt(int ttlMin, int &hour, int &minutes, char &ampm) {
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

// Function to check if time is valid
bool IsVTime(int hour, int minute) {
    return (hour >= 0 && hour < 24 && minute >= 0 && minute < 60);
}
