/*
 * Author: Ireoluwa
 * Created on June 24, 2024, 3:30 PM
 * Purpose: Distance per tank of gas
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - Mathematical, Scientific, Conversions

//Higher Dimensions go here. No Variables

//Function Prototypes

//Execution Begins here

int main(int argc, char** argv) {
    //Setting the random number seed
    
    //Declaring Variables
    unsigned short CarTank;    //amount of gallons a car can hold
    float          DisTMil,    //Distance per gallon in miles (town)
                   DisHMil,     //Distance per gallon in miles (highway)
                   DistncT,    //Total distance travelled in town on one tank
                   DistncH;     //Total distance travelled on the highway on one tank
    //Initialize Variables
    CarTank = 20;
    DisTMil = 23.5;
    DisHMil = 28.9;
    
    //Processing/Mapping Inputs to Outputs
    DistncT = CarTank * DisTMil;
    DistncH = CarTank * DisHMil;
    
    //Displaying Input/Output Information
    cout << "The average distance the car can travel on one Tank of gas when driven in town is " << DistncT << " miles" << endl;
    cout << "The average distance the car can travel on one Tank of gas when driven on the Highway is " << DistncH << " miles" << endl;
    //Exiting stage left/right
    return 0;
}

