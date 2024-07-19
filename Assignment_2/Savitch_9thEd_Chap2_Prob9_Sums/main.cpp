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
    int num1,
        num2,
        num3,
        num4,
        num5,
        num6,
        num7,
        num8,
        num9,
        num10,
        Negsum,
        PosSum,
        TotSum;
    
    //Initialize or input i.e. set variable values
    cout << "Input 10 numbers, any order, positive or negative" << endl;
    cin >> num1 >> num2 >> num3 >> num4 >> num5 >> num6 >> num7 >> num8 >> num9 >> num10;
    
    //Map inputs -> outputs
    TotSum = num1 + num2 + num3 + num4 + num5 + num6 + num7 + num8 + num9 + num10;
    PosSum = 0;
    Negsum = 0;
    
    if (num1 > 0) PosSum += num1;
        else if (num1 < 0) Negsum += num1;

    if (num2 > 0) PosSum += num2;
        else if (num2 < 0) Negsum += num2;

    if (num3 > 0) PosSum += num3;
        else if (num3 < 0) Negsum += num3;

    if (num4 > 0) PosSum += num4;
        else if (num4 < 0) Negsum += num4;

    if (num5 > 0) PosSum += num5;
        else if (num5 < 0) Negsum += num5;

    if (num6 > 0) PosSum += num6;
        else if (num6 < 0) Negsum += num6;

    if (num7 > 0) PosSum += num7;
        else if (num7 < 0) Negsum += num7;

    if (num8 > 0) PosSum += num8;
        else if (num8 < 0) Negsum += num8;

    if (num9 > 0) PosSum += num9;
        else if (num9 < 0) Negsum += num9;

    if (num10 > 0) PosSum += num10;
        else if (num10 < 0) Negsum += num10;
    
    //Display the outputs
    cout << "Negative sum =" << setw(4) << Negsum << endl;
    cout << "Positive sum =" << setw(4) << PosSum << endl;
    cout << "Total sum    =" << setw(4) << TotSum;

    //Exit stage right or left!
    return 0;
}