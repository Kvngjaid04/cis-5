/*
 * Author: Ireoluwa
 * Created on June 20, 2024, 2:40 PM
* Purpose:  Diamond Pattern
 */

//System Libraries
#include <iostream>  
using namespace std;

//User Libraries

//Global Constants - Mathematical, Scientific, Conversions

//Higher Dimensions go here. No Variables
const unsigned char PERCENT = 100;        //Percent Conversion

//Function Prototypes

//Execution Begins here
int main(int argc, char** argv) {
   //Setting the random number seed
    
    //Declaring Variables
    unsigned short nShares;         //Number of Shares of Stock
    float          shrPrce,         //Share price in $'s
                   percCom,         //Percent Commission 
                   prcStk,          //Total Price of Stock $'s without Commission
                   commshn,         //Commission Price $'s
                   totPrc;          //Total price of stock purchase
    
    //Initialize Variables
    nShares = 750;
    shrPrce = 3.5e1f;//$35
    percCom = 2.0f / PERCENT;
    
    //Processing/Mapping Inputs to Outputs
    prcStk = nShares * shrPrce;
    commshn = percCom * prcStk;
    totPrc = prcStk + commshn;
    
    //Displaying Input/Output Information
    cout << "Number of Shares = " << nShares << endl;
    cout << "Share Price = $" << shrPrce << endl;
    cout << "Commission Percent = "<< percCom * PERCENT << "%" << endl;
    cout << "Price of Stock Before Commission = $" << prcStk << endl;
    cout << "Commission Charge = $" << commshn << endl;
    cout << "Total cost of Stock Purchase = $" << totPrc << endl;

    //Exit the program
    return 0;
}