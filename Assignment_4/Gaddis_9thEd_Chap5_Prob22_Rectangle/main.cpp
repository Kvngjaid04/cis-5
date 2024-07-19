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
    unsigned short  num,
                    length,
                    height;
    char            cter;
    
    //Initialize or input i.e. set variable values
    cin >> num;
    cin >> cter;
    
    
    //Map inputs -> outputs
        if (num > 15)
            {
                cout << "Input a positive integer less than 15";
            }
        else 
            {
                for ( height =  2; height <= num; height++)                 //print from rows 1 to a row before num
            {
                for ( length = 1; length <= num; length++) 
                {
                    cout << cter;
                }
                cout << endl;
            }
            
        for ( length = 1; length <= num; length++)                  // Print the last row separately
            {
                cout << cter;
            }
            }
    //Display the outputs

    //Exit stage right or left!
    return 0;
}