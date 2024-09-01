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
const float Payinc = 0.076f;    //% pay increase retroactive for 6 months. 

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float PrvAsal,      // previous annual salary 
          RtroPay,      //Retroactive pay for 6 months
          NewASal,      // New annual salary
          NewMSal,      // New monthly salary
          OldMSal;      //Old monthly salary
         
    
    //Initialize or input i.e. set variable values
    cout << "Input previous annual salary." << endl;
    cin >> PrvAsal;
    
    //Map inputs -> outputs
    OldMSal =  PrvAsal / 12;
    RtroPay = (OldMSal * Payinc) * 6;
    NewMSal = (OldMSal * Payinc) + OldMSal;
    NewASal = NewMSal * 12;
    
    //Display the outputs
    cout << "Retroactive pay    = $" << setw(7) << setprecision(2) << fixed << RtroPay << endl;
    cout << "New annual salary  = $" << setw(7) << setprecision(2) << fixed << NewASal << endl;
    cout << "New monthly salary = $" << setw(7) << setprecision(2) << fixed << NewMSal;
    
    //Exit stage right or left!
    return 0;
}