/*
 * Author: Ireoluwa
 * Created on June 18, 2024, 12:19 PM
 * Purpose:  compound interest.
 */

// System Libraries
#include <iostream>
#include <iomanip> // For output formatting
#include <cmath>   // For power function
using namespace std;

// Function Prototypes
float psntVal(float F, float r, int n);

// Execution Begins Here
int main(int argc, char** argv) {
    // Declaring Variables
    float FValue, ARate;    
    int years;           
    
    // Initialize Variables
    cout << "This is a Present Value Computation" << endl;
    
    cout << "Input the Future Value in Dollars" << endl;
    cin >> FValue;
    
    cout << "Input the Number of Years" << endl;
    cin >> years;
    
    cout << "Input the Interest Rate %/yr" << endl;
    cin >> ARate;
    
    // Convert annualRate from percentage to decimal
    ARate /= 100;
    
    // Processing/Mapping Inputs to Outputs
    float PValue = psntVal(FValue, ARate, years);
    
    // Displaying Input/Output Information
     
    cout << "The Present Value = $" << setprecision(2) << fixed << PValue;
    
    // Exiting stage left/right
    return 0;
}

// Function to calculate present value
float psntVal(float F, float r, int n) {
    return F / pow((1 + r), n); // Using pow function to calculate (1 + r)^n
}
