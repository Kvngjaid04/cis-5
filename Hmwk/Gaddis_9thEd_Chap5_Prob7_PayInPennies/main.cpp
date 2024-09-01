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
    //Declare Variables
    unsigned int    day,
                    ndays,
                    pay = 1, // Initialize pay to one penny as unsigned int
                    gpay = 0;
         
    //Initialize or input i.e. set variable values           
    cin >> ndays;
    if (ndays < 1) 
    {
        cout << "Number of days cannot be less than 1.";
    }
    else 
    {
        for (day = 1; day <= ndays; day++) 
        {
            gpay += pay; // Add the current day's pay to the total
            pay *= 2; // Double the pay for the next day
        }

        // Calculate the results in pennies
        // Convert total earnings from pennies to dollars
        int dollars = gpay / 100;
        int pennies = gpay % 100;

        // Display the outputs
        cout << "Pay = $" << dollars << ".";

        // If pennies are less than 10, output a zero before the number
        if (pennies < 10) 
        {
            cout << "0";
        }
        cout << pennies;
    }
   
    return 0;
}
