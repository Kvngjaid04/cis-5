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
const float CMass = 350,               //mass of a single can of soda
            ASTKM = 5,                 //amount of artificial sweetener needed to kill a mouse
            MasMous = 35,              // mass of the mouse
           Fraswet = 0.001f,           //Fraction of sweetener in soda
            GramPpo = 453.592f;         //grams per pound
//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float           EndWei,               // weight at which the dieter will stop dieting
                    LeSwt,                //Letahl dose of sweetner for a person   
                    WDinGPp;              //Weight of dieter in grams (per pound)
    unsigned int    Numcans;              //number of cans that can be consumed
          
    //Initialize or input i.e. set variable values
    cout << "Program to calculate the limit of Soda Pop Consumption." << endl;
    cout << "Input the desired dieters weight in lbs." << endl;
    cin >> EndWei;
    
    //Map inputs -> outputs
    WDinGPp = EndWei * GramPpo;
    LeSwt = ( ASTKM / MasMous ) * WDinGPp;
    Numcans = LeSwt / ( Fraswet * CMass);
    
    //Display the outputs
    cout << "The maximum number of soda pop cans" << endl;
    cout << "which can be consumed is " << Numcans << " cans";
    
    //Exit stage right or left!
    return 0;
}