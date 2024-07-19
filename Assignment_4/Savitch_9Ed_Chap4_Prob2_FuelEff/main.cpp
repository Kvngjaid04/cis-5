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
    float   miles,
            gas,
            MiPerG,
            LinG = 0.264179,            // liter in gallons
            MiPerg;
    char    again;
    
    //Initialize or input i.e. set variable values
    
    //Map inputs -> outputs
    do 
        {
            cout << "Car 1" << endl;
                cout << "Enter number of liters of gasoline:" << endl;
                cin >> gas;
                cout << "Enter number of miles traveled:" << endl;
                cin >> miles;
                
                    MiPerg = miles / ( LinG * gas);
                cout << "miles per gallon:";
                cout << setprecision(2) << setw(6) << fixed << MiPerg << endl << endl;
            
            cout << "Car 2" << endl;
                cout << "Enter number of liters of gasoline:" << endl;
                cin >> gas;
                cout << "Enter number of miles traveled:" << endl;
                cin >> miles;
                
                    MiPerG = miles / ( LinG * gas);
                cout << "miles per gallon:";
                cout << setprecision(2) << setw(6) << fixed << MiPerG << endl << endl;
                
                if ( MiPerG < MiPerg )
                    {
                        cout << "Car 1 is more fuel efficient" << endl << endl;
                    }
                else 
                    {
                        cout << "Car 2 is more fuel efficient" << endl << endl;
                    }
                    
            cout << "Again:" << endl;
            cin >> again;
            
                if ( again == 'Y' || again == 'y' )
                    {
                        cout << endl;
                    }
        }
    while ( again == 'Y' || again == 'y');
    //Display the outputs

    //Exit stage right or left!
    return 0;
}