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
    unsigned int    num,
                    sum,
                    numw;
    
    //Initialize or input i.e. set variable values
    num = 1;        //set the initial value to 1
    sum = 0;        //set the initial sum to 0
    cin >> numw;    //prompt user to input value
    
    //Map inputs -> outputs
    while ( num <= numw)        // Loop through numbers from 1 to 'numw', adding each to 'sum'
        {   
            sum += num;         
            num++;              // increment num by 1 
        }
    
    //Display the outputs
    cout << "Sum = " << sum; 
    //Exit stage right or left!
    return 0;
}