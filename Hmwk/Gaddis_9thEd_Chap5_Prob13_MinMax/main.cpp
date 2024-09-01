/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 2, 2019, 12:36 PM
 * Purpose:  Creation of Template to be used for all
 *           future projects
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    int     num,
            snum,
            Lnum;
    
    //Initialize or input i.e. set variable values
    cin >> num;
    snum = num;
    Lnum = num;
    
    
    while (num != -99) 
        {
            if (num < snum) 
                {
                    snum = num;
                }
            if (num > Lnum) 
                {
                    Lnum = num;
                }
            cin >> num;  // Read the next number
        }
    //Map inputs -> outputs
    
    //Display the outputs
    cout << "Smallest number in the series is " << snum << endl;
    cout << "Largest  number in the series is " << Lnum;
    //Exit stage right or left!
    return 0;
}