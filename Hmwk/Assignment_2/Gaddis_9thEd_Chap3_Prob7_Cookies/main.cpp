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
    unsigned short  NCookie,   // Number of cookies per serving in the bag
                    Calcook,    // Number of calories per serving in the bag
                    NEatC;     // Number of cookies eaten
    float           NumCal;    // Number of calories consumed
    //Initialize or input i.e. set variable values
    NCookie = 4;
    Calcook = 300;
    cout << "Calorie Counter" << endl;
    cout << "How many cookies did you eat?" << endl;
    cin >> NEatC ;
    //Map inputs -> outputs
     NumCal = (Calcook / NCookie) * NEatC;
    //Display the outputs
    cout << "You consumed " << NumCal<< " calories.";

    //Exit stage right or left!
    return 0;
}