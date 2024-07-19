/*
 * Author: Ireoluwa
 * Created on June 22, 2024, 12:19 PM
 * Purpose: Restaurant Bill
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - Mathematical, Scientific, Conversions

//Higher Dimensions go here. No Variables
const unsigned char PERCENT = 100;//Percent Conversion

//Function Prototypes

//Execution Begins here

int main(int argc, char** argv) {
    //Setting the random number seed
    
    //Declaring Variables
    float Charge,       //Meal Charge in dollars
          TaxPer,       //Tax percentage
          TaxAmnt,    //Tax amount in dollars
          TipPer,       //Tip percentage
          TipAmnt,    //Tip amount in dollars
          TotBill;    //Total bill in dollars
    
    //Initialize Variables
    Charge = 88.67;
    TaxPer = 6.75f / PERCENT;    //6.75% tax rate
    TipPer = 20.0f / PERCENT;       //20% Tip rate
            
    //Processing/Mapping Inputs to Outputs
    TaxAmnt = TaxPer * Charge;
    TipAmnt = (TaxAmnt + Charge)* TipPer;
    TotBill = TaxAmnt + TipAmnt + Charge;
    
    //Displaying Input/Output Information
    cout << "Meal cost: $" << Charge << endl;
    cout << "Tax amount: $" << TaxAmnt << endl;
    cout << "Tip amount: $" << TipAmnt << endl;
    cout << "Total bill: $" << TotBill << endl;    
    //Exiting stage left/right
    return 0;
}

