/* 
 * File:   
 * Author: 
 * Created on 
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
    float   num1,
            num2,
            num3,
            lnumf2,     //Largest number from two parameters
            lnumf3;     //largest number from three parameters
            
    //Initialize or input i.e. set variable values
    cout << "Enter first number:" << endl << endl;
    cin >> num1;
    cout << "Enter Second number:" << endl << endl;
    cin >> num2;
    cout << "Enter third number:" << endl << endl;
    cin >> num3;
    
    //Map inputs -> outputs
    if ( num1 < num2)
        {
            lnumf2 = num2;
        }
    else 
        {
            lnumf2 = num1;
        }
        
    if (lnumf2 > num3)              
        {
            lnumf3 = lnumf2;
        } 
    else 
        {
            lnumf3 = num3;
        }
    
    //Display the outputs
    cout << "Largest number from two parameter function:" << endl;
    cout << setprecision(1) << fixed << lnumf2 << endl << endl;
    cout << "Largest number from three parameter function:" << endl;
    cout << setprecision(1) << fixed << lnumf3 << endl; 
    
    //Exit stage right or left!
    return 0;
}