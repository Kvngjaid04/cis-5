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

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    unsigned int NumBook,   //number of books purchased each month
                 Totpnts;    //total points awarded
                 
    //Initialize or input i.e. set variable values
    Totpnts = 0;
    cout << "Book Worm Points" << endl;
    cout << "Input the number of books purchased this month." << endl;
    cin >> NumBook;
    cout << "Books purchased =" << setw(3) << NumBook << endl;
    
    //Map inputs -> outputs
    if ( NumBook == 0 )
        {
        Totpnts = 0;
        }
    else if ( NumBook == 1 ) 
        {
        Totpnts = 5;
        }
    else if ( NumBook == 2 ) 
        {
        Totpnts = 15;
        }
    else if ( NumBook == 3 )
        {
        Totpnts = 30;
        }
    else if ( NumBook >= 4 )
        {
        Totpnts = 60;
        }
    //Display the outputs
    cout << "Points earned   =" << setw(3) << Totpnts;
     
    //Exit stage right or left!
    return 0;
}