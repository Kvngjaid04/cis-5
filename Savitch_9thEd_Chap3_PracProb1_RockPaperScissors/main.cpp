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
    char p1, p2;
    
    //Initialize or input i.e. set variable values
    cout << "Rock Paper Scissors Game" << endl;
    cout << "Input Player 1 and Player 2 Choices" << endl;
    cin >> p1 >> p2;
    
    //Map inputs -> outputs
    if (p1 == p2)
        {
            cout << "Nobody wins.";
        }
    else if ((p1 == 'r' || p1 == 'R') && (p2 == 's' || p2 == 'S'))
        {
            cout << "Rock breaks scissors.";
        }
    else if ((p1 == 's' || p1 == 'S') && (p2 == 'r' || p2 == 'R'))
        {
            cout << "Rock breaks scissors.";
        }
    else if ((p1 == 's' || p1 == 'S') && (p2 == 'p' || p2 == 'P')) 
        {
            cout << "Scissors cuts paper.";
        }
    else if ((p1 == 'p' || p1 == 'P') && (p2 == 's' || p2 == 'S')) 
        {
            cout << "Scissors cuts paper.";
        }
    else if ((p1 == 'p' || p1 == 'P') && (p2 == 'r' || p2 == 'R')) 
        {
            cout << "Paper covers rock.";
        }
    else if ((p1 == 'r' || p1 == 'R') && (p2 == 'p' || p2 == 'P' ))
        {
            cout << "Paper covers rock.";
        }
    else
        {
            cout << "Invalid Input";
        }
        
    //Display the outputs

    //Exit stage right or left!
    return 0;
}