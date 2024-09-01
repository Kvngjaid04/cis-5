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
const unsigned char PERCENT = 100; //Percent Conversion 
//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    unsigned int   Percent;     //  percentage of the amount it would cost to replace the structure.
    float           RepCost,     // the replacement cost of a building
                    Insure;      // minimum amount of insurance required to buy property
                   
    //Initialize or input i.e. set variable values
    Percent  = 80;
    cout << "Insurance Calculator" << endl;
    cout << "How much is your house worth?" << endl;
    cin >> RepCost;
   
    //Map inputs -> outputs
   Insure = (RepCost) * (static_cast<float>(Percent) / PERCENT);
    //Display the outputs
    cout << "You need $" << Insure<< " of insurance.";
    //Exit stage right or left!
    return 0;
}