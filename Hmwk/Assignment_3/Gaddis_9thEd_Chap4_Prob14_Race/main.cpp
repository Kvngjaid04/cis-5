/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 2, 2019, 12:36 PM
 * Purpose:  Creation of Template to be used for all
 *           future projects
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <string>
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
    string  nam1, nam2, nam3;       //name of runners
    float   tme1, tme2, tme3;       //time it took to finish the race
           
            
    //Initialize or itnput i.e. set variable values
    cout << "Race Ranking Program" << endl;
    cout << "Input 3 Runners" << endl;
    cout << "Their names, then their times" << endl;
    cin >> nam1 >> tme1 >> nam2;
    cin >> tme2 >> nam3 >> tme3;
    
    //Map inputs -> outputs
    if ( tme1 < tme2 && tme2 < tme3)
        {
            cout << nam1 << "\t" << setw(3) << tme1 << endl;
            cout << nam2 << "\t" << setw(3) << tme2 << endl;
            cout << nam3 << "\t" << setw(3) << tme3;
        }
    else if ( tme1 < tme3 && tme3 < tme2)
        {
            cout << nam1 << "\t" << setw(3) << tme1 << endl;
            cout << nam3 << "\t" << setw(3) << tme3 << endl;
            cout << nam2 << "\t" << setw(3) << tme2;
        }
    else if ( tme2 < tme1 && tme1 < tme3)
        {
            cout << nam2 << "\t" << setw(3) << tme2 << endl;
            cout << nam1 << "\t" << setw(3) << tme1 << endl;
            cout << nam3 << "\t" << setw(3) << tme3;
        }
    else if ( tme2 < tme3 && tme3 < tme1)
        {
            cout << nam2 << "\t" << setw(3) << tme2 << endl;
            cout << nam3 << "\t" << setw(3) << tme3 << endl;
            cout << nam1 << "\t" << setw(3) << tme1;
        }
    else if ( tme3 < tme1 && tme1 < tme2)
        {
            cout << nam3 << "\t" << setw(3) << tme3 << endl;
            cout << nam1 << "\t" << setw(3) << tme1 << endl;
            cout << nam2 << "\t" << setw(3) << tme2;
        }
    else 
        {
            cout << nam3 << "\t" << setw(3) << tme3 << endl;
            cout << nam2 << "\t" << setw(3) << tme2 << endl;
            cout << nam1 << "\t" << setw(3) << tme1;
            
        }
    //Display the outputs

    //Exit stage right or left!
    return 0;
}