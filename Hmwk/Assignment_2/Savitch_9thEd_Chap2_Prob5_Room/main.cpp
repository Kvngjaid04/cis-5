/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 2, 2019, 12:36 PM
 * Purpose:  Creation of Template to be used for all
 *           future projects
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    unsigned int MaxCap,        //maximum capacity a room can hold
                 NumPep,        //Number of people in the room
                 MaxPep,        //Number of people required to reach maximum capacity
                 NumCap;        //Number of people above maximum capacity
    
    //Initialize or input i.e. set variable values
    cout << "Input the maximum room capacity and the number of people" << endl;
    cin >> MaxCap >> NumPep;
    
    //Map inputs -> outputs
    MaxPep = MaxCap - NumPep;
    NumCap = NumPep - MaxCap;
    
    //Display the outputs
    if ( NumPep <= MaxCap)
        {
            cout << "Meeting can be held." << endl;
            cout << "Increase number of people by " << MaxPep << " will be allowed without violation.";
        }
    else 
        {
            cout << "Meeting cannot be held." << endl;
            cout << "Reduce number of people by " << NumCap << " to avoid fire violation.";
        }
    //Exit stage right or left!
    return 0;
}