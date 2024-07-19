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
    char              SubPack;             //subscription packages
    float             Bill;              //bills
    unsigned int      hours;      //amount of hours used
    
    //Initialize or input i.e. set variable values
    cout << "ISP Bill" << endl;
    cout << "Input Package and Hours" << endl;
    cin >> SubPack >> hours;
    
    //Map inputs -> outputs
    if (hours <= 744 )
        {
            switch (SubPack) 
            {
                case 'A' : 
                    Bill = 9.95f;
                        if (hours > 10)
                            {
                                Bill += ( (hours - 10) * 2 );
                            }
                    break;    
                
                case 'B' :
                    Bill = 14.95f;
                        if (hours > 20)
                            {
                                Bill += ( (hours - 20) * 1 );
                            }
                     break;
                
                case 'C' :
                    Bill = 19.95f;
                    break;
                
                default : cout << "You did not enter a subscription package";
            }
        }
    else 
        {
            cout << "Number of hours cannot exceed 744";
        }
    //Display the outputs
     cout << "Bill = $" << setw(6) << setprecision(2) << fixed << Bill;
    //Exit stage right or left!
    return 0;
}