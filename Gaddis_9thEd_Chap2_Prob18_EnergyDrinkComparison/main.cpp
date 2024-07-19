/*
 * Author: Ireoluwa
 * Created on June 18, 2024, 12:19 PM
 * Purpose: Energy Drink Consumption
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - Mathematical, Scientific, Conversions

//Higher Dimensions go here. No Variables
const unsigned char PERCENT = 100; //Percent Conversion

//Function Prototypes

//Execution Begins here

int main(int argc, char** argv) {
    //Setting the random number seed
    
    //Declaring Variables
    unsigned short Cstmer,      //Number of surveyed customers
                   SurCst,      //Number of customers in the survey who purchase one or more energy drinks per week 
                   NscCFED;     //number of customers in the survey who prefer citrus-flavored energy drinks
    float          SurPur,      //percentage of surveyed purchase of  one or more energy drinks per week
                   PerCFED;     //percentage of surveyed purchase who prefer cirrus-flavored energy drinks
            
    //Initialize Variables
    Cstmer = 16500;
    SurPur = 15.0f / 100;
    PerCFED = 58.0f / 100;
    
    //Processing/Mapping Inputs to Outputs
    SurCst = SurPur * Cstmer;
    NscCFED = SurCst * PerCFED;
    
    //Displaying Input/Output Information
    cout << "The approximate number of customers in the survey who purchase one or more energy drinks per week is " << SurCst << endl;
    cout << "The approximate number of customers in the survey who prefer citrus-flavored energy drinks is " << NscCFED <<  endl;
    //Exiting stage left/right
    return 0;
}

