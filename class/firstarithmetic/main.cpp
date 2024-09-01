/*
 * Author: Ireoluwa
 * Created on June 18, 2024, 12:19 PM
 * Purpose: first arithmetic
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - Mathematical, Scientific, Conversions

//Higher Dimensions go here. No Variables

//Function Prototypes

//Execution Begins here

int main() {
    //Setting the random number seed
    
    //Declaring Variables
    float RegularWages,     //holds regular wages
          BasePayRate,      //base pay rate
          regularHours,     //to hold regular hours
          OvertimeWages,    //overtime wages
          OvertimePayrate,  // to hold overtime pay
          OvertimeHours,    // to hold overtime hours
          totalWages;       // to hold total wages
    
    //Initialize Variables
     BasePayRate = 50;
     regularHours = 40;
     OvertimePayrate = 55;
     OvertimeHours = 12;
     
    //Processing/Mapping Inputs to Outputs
     RegularWages = BasePayRate * regularHours; //base pay for all employees
     OvertimeWages = OvertimePayrate * OvertimeHours; //maximum pay for employees who work overtime
     totalWages = RegularWages + OvertimeWages; //Minimum pay for an employee who works overtime
             
    //Displaying Input/Output Information
     cout << "the minimum pay the company is liable to pay to an employee is $" << RegularWages << " but if an employee works the maximum " << OvertimeHours << " hours of over time,";
     cout << " the company has to pay them an additional $" << OvertimeWages << ". meaning an employee can make a minimum of $" << totalWages << "." << endl;
     //Exiting stage left/right
    return 0;
}

