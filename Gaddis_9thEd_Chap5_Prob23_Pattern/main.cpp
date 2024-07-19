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
    unsigned int        num;
    
    //Initialize or input i.e. set variable values
    cin >> num;
    
    //Map inputs -> outputs
    
    for (unsigned int row = 1; row <= num; row++) 
        {
            for (unsigned int col = 1; col <= row; col++)  // Print '+' signs incrementing with row number
                {     
                    cout << "+";
                }
                cout << endl << endl;
        }        
    for (unsigned int row = num; row >= 2 ; row--) 
        {
            for (unsigned int col = 1; col <= row; col++)  // Print '+' signs decrementing with row number
                {     
                    cout << "+";
                }
                cout << endl << endl;
        }      
                cout << "+";
    //Display the outputs

    //Exit stage right or left!
    return 0;
}