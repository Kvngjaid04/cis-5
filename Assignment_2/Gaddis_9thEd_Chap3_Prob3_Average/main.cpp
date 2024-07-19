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

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float Test1,Test2, Test3, Test4, Test5,     //Test scores
            sum;                                //sum of test scores
    
    //Initialize or input i.e. set variable values
    cout << "Input 5 numbers to average." << endl;
    cin >>Test1>>Test2>>Test3>>Test4>>Test5;
    
    //Map inputs -> outputs
    sum = Test1 + Test2 + Test3 + Test4 + Test5;
    //Correctly calculate the average by dividing by 5
    float average = sum / 5; // Use 5 for division
    
    //Display the outputs
    cout << "The average = " << setprecision(1) << fixed << average;
    
    //Exit stage right or left!
    return 0;
}
