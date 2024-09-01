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
    string Nam1,
           Nam2,
           Nam3;
    
    //Initialize or input i.e. set variable values
    cout << "Sorting Names" << endl;
    cout << "Input 3 names" << endl;
    cin >> Nam1 >> Nam2 >> Nam3;
    
    //Map inputs -> outputs
    if ( Nam1 < Nam2 && Nam2 < Nam3 )
        {
            cout << Nam1 << endl;
            cout << Nam2 << endl;
            cout << Nam3;
        }
    else if ( Nam1 < Nam3 && Nam3 < Nam2 )
        {
            cout << Nam1 << endl;
            cout << Nam3 << endl;
            cout << Nam2;
        }
    else if ( Nam2 < Nam1 && Nam1 < Nam3 )
        {
            cout << Nam2 << endl;
            cout << Nam1 << endl;
            cout << Nam3;
        }
    else if ( Nam2 < Nam3 && Nam3 < Nam1 )
        {
            cout << Nam2 << endl;
            cout << Nam3 << endl;
            cout << Nam1;
        }
    else if ( Nam3 < Nam2  && Nam2 < Nam1 )
        {
            cout << Nam3 << endl;
            cout << Nam2 << endl;
            cout << Nam1;
        }
    else
        {
            cout << Nam3 << endl;
            cout << Nam1 << endl;
            cout << Nam2;
        }
    //Display the outputs

    //Exit stage right or left!
    return 0;
}