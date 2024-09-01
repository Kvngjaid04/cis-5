/* 
 * Author: 
 * Created on 
 * Purpose:  
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
int fctrl(int, int&);//Function to write for this problem

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int n, fact;
    //Initialize Variables
    fact= 1;
     cout << "This program calculates the factorial using a function prototype found in the template for this problem." << endl;
    cout << "Input the number for the function." << endl;
    cin>> n;
    //Process/Map inputs to outputs
    fctrl (n, fact);
    //Output data
    cout << n << "! = " << fact;
    //Exit stage right!
    return 0;
}

int fctrl (int n, int &fact) {
    for (int i = 1; i <= n; i++){
        fact*=i;
    }
}