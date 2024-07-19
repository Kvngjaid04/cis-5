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
    float PayRate,  //pay rate in $
          Hours,    //number of hours worked.
          GrosPay;   //gross pay in $
    
    //Initialize or input i.e. set variable values
    cout << "This program calculates the gross paycheck." << endl;
    cout << "Input the pay rate in $'s/hr and the number of hours." << endl;
    cin >> PayRate >> Hours;
    
    //Map inputs -> outputs
    if      ( Hours <= 40)
        {
        GrosPay = PayRate * Hours;
        }
    else
        {
        GrosPay = ( PayRate * 40) + ((2 * PayRate) * (Hours - 40));
        }
    //Display the outputs
    cout << "Paycheck = $" << setw(7) << setprecision(2) << fixed << GrosPay;
    
    //Exit stage right or left!
    return 0;
}