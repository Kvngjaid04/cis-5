/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 2, 2019, 12:36 PM
 * Purpose:  Creation of Template to be used for all
 *           future projects
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include  <iomanip>
#include <cmath>

using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float   Angl, //angle in degrees
            sine,
            cosi,
            Angle,
            tang;
    //Initialize or input i.e. set variable values
    cout << "Calculate trig functions" << endl;
    cout << "Input the angle in degrees." << endl;
    cin >> Angl;
    
    //Map inputs -> outputs
    Angle = Angl * M_PI / 180;
    sine = sin(Angle);
    cosi = cos(Angle);
    tang = tan(Angle);
    
    //Display the outputs
    cout << "sin(" << Angl << ") = " << setprecision(4) << fixed << sine << endl;
    cout << setprecision(0) << "cos(" << Angl << ") = " << setprecision(4) << fixed << cosi << endl;
    cout << setprecision(0) << "tan(" << Angl << ") = " << setprecision(4) << fixed << tang; 
    
    //Exit stage right or left!
    return 0;
}