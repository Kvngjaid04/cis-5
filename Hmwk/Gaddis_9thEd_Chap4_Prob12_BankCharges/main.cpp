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
    unsigned int    NumChks;        //number of Checks
    float           CrBkBal,        //Current bank balance
                    ChkFees,        //check fees
                    TotChar,        //Total Service Fees
                    NewBal,         //new balance
                    Totcha,          //Charges + extra charges
                    Charges = 10,    // bank charges per month for a commercial checking account
                    XCharge;         //low balance charge
    
    //Initialize or input i.e. set variable values
    cout << "Monthly Bank Fees" << endl;
    cout << "Input Current Bank Balance and Number of Checks" << endl;
    cin >> CrBkBal >> NumChks;
    
    //Map inputs -> outputs
    if ( CrBkBal >= 0 ){
        if ( NumChks > 0 ){
            if (CrBkBal < 400){   
                        XCharge = 15;
                        Totcha = Charges + XCharge;

                            if ( NumChks < 20 )
                                {
                                    ChkFees = NumChks * .10;
                                }
                            else if ( NumChks >= 20 && NumChks <=39 )
                                {
                                    ChkFees = NumChks * .08;
                                }
                            else if ( NumChks >=40 && NumChks <= 59 )
                                {
                                     ChkFees = NumChks * .06;
                                }
                            else 
                                {
                                     ChkFees = NumChks * .04;
                                }
                        TotChar = ChkFees + Totcha;
                    }

            else{       
                            XCharge = 0;

                            if ( NumChks < 20 )
                                {
                                    ChkFees = NumChks * .10;
                                }
                            else if ( NumChks >= 20 && NumChks <=39 )
                                {
                                    ChkFees = NumChks * .08;
                                }
                            else if ( NumChks >= 40 && NumChks <= 59 )
                                {
                                    ChkFees = NumChks * .06;
                                }
                            else 
                                {
                                ChkFees = NumChks * .04;
                                }
                        TotChar = ChkFees + Charges;  
                }
                                
            NewBal = CrBkBal - TotChar;    

            cout << "Balance     $" << setw(9) << setprecision(2) << fixed << CrBkBal << endl;
            cout << "Check Fee   $" << setw(9) << setprecision(2) << fixed << ChkFees << endl;
            cout << "Monthly Fee $" << setw(9) << setprecision(2) << fixed << Charges << endl;
            cout << "Low Balance $" << setw(9) << setprecision(2) << fixed << XCharge << endl;
            cout << "New Balance $" << setw(9) << setprecision(2) << fixed << NewBal;  
                }
                
        else 
            {
               cout << "cannot accept a negative value for the number of checks written"; 
            }
        }
    else 
        {
            cout << "The Account is Overdrawn";
        }
    
    //Display the outputs
    
    //Exit stage right or left!
    return 0;
}