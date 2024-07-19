/*
 * Author: Ireoluwa
 * Created on June 20, 2024, 4:00 PM
 * Purpose:  Paint Coverage Problem
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
    unsigned char   fncLen,                //Input -> length of fence in feet
                    fncHgt,                //Input -> height of fence in feet
                    nmPtCns;               //Output -> Number of cans of paint required
    unsigned short  ptCanCv;               //Input -> Gallon of Paint to Cover ft^2
    
    //Initial Variables
    fncLen = 100;              //100 feet
    fncHgt = 6;                //6 feet
    ptCanCv = 340;             //340 ft^2
    
    //Map the Inputs to the Outputs
    nmPtCns= 4 * fncLen * fncHgt / ptCanCv + 1;
    
    //Display the Inputs and Outputs
    cout << "Number of Cans of Paint required = " << static_cast<int>(nmPtCns) << endl;

    //Exit the code
    return 0;
}