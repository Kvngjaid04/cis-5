/*
 * Author: Ireoluwa
 * Created on June 22, 2024, 1:20 PM
 * Purpose: sales Tax
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - Mathematical, Scientific, Conversions

//Higher Dimensions go here. No Variables
const unsigned char PERCENT = 100; //Percent Conversion

//Function Prototypes

//Execution Begins here

int main(int argc, char** argv) {
    //Setting the random number seed
    
    //Declaring Variables
    float Purchse,       //Input -> Purchase price in dollars
          SSTax,          //Input -> Percentage of State sales tax 
          CSTax,          //Input -> Percentage of County sales tax
          StteTax,       //Output -> State sales tax 
          CntyTax,      //Output -> County sales tax
          TSTax;          //Output -> Total sales tax
    
    //Initialize Variables
    Purchse = 95;
    SSTax = 4.0f / PERCENT;   //4% state sales tax
    CSTax = 2.0f / PERCENT;   //2% County sales tax
    
    //Processing/Mapping Inputs to Outputs
    StteTax = SSTax * Purchse;
    CntyTax = CSTax * Purchse;
    TSTax = StteTax + CntyTax;
            
    //Displaying Input/Output Information
    cout << "Purchase amount: $" << Purchse << endl;
    cout << "State sales tax: $" << StteTax << endl;
    cout << "County sales tax: $" << CntyTax << endl;
    cout << "Total sales tax: $" << TSTax << endl;
    //Exiting stage left/right
    return 0;
}

