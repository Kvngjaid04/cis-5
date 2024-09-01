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

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...


//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float   crntPrc, 
            inonRte,
            prvPrc;
    char    again;
    
    //Initialize or input i.e. set variable values
    
    //Map inputs -> outputs
    do 
    {
        cout << "Enter current price:" << endl;
        cin >> crntPrc;
        
        cout << "Enter year-ago price:" << endl;
        cin >> prvPrc;
        
        inonRte = ((crntPrc - prvPrc) / prvPrc) * 100;
        cout << "Inflation rate: " << fixed << setprecision(2) << inonRte << "%" << endl << endl;
        
        cout << "Again:" << endl;
        cin >> again;
                if ( again == 'Y' || again == 'y' )
                    {
                        cout << endl;
                    }
    }
    while (again == 'Y' || again == 'y');

    //Exit stage right or left!
    return 0;
}
