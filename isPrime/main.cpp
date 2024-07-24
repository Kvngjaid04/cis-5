/* 
 * Author: 
 * Created on 
 * Purpose:  
 */

//System Libraries
#include <iostream>
#include <cmath>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
bool isPrime(int);//Determine if the input number is prime.

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int num;
    
    //Initialize Variables
    cout << "Input a number to test if Prime." << endl;
    cin >> num;
    
    //Process/Map inputs to outputs
    cout << num <<(isPrime (num)? " is prime.": " is not prime.");
    //Output data
    
    //Exit stage right!
    return 0;
}

bool isPrime( int number){
    int sqrn = sqrt(number);
        for (int i=2; i <= sqrn; i++){
            if (number% i == 0) return false;
        }
    return true;
}