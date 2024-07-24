/* 
 * File:   main.cpp
 * Author:
 * Created on:
 * Purpose:
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstdlib>   //Srand
#include <ctime>     //Time to set random number seed
#include <cmath>     //Math Library
#include <iomanip>   //Format Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const float MAXRAND=pow(2,31)-1;

//Function Prototypes
void  init(float [],int);//Initialize the array
void  print(float [],int,int);//Print the array
float avgX(float [],int);//Calculate the Average
float stdX(float [],int);//Calculate the standard deviation

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned>(time(0)));
    
    //Declare Variables
    const int SIZE=20;
    float test[SIZE];
    
    //Initialize or input i.e. set variable values
    init(test,SIZE);
    
    //Display the outputs
    //print(test,SIZE,5);
    cout<<"The average            = "<<avgX(test,SIZE)<<endl;
    cout<<"The standard deviation = "<<stdX(test,SIZE)<<endl;

    //Exit stage right or left!
    return 0;
}

void  init(float a[],int n){
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
};//Initialize the array

void  print(float a[],int n,int pntLine){
    for (int i =0; i < n; i++ ){
        cout << setw(12)<< setprecision(7) << showpoint << fixed;
        cout << a[i];  
        if ( i % pntLine == (pntLine-1)) {cout <<endl;}
    }    
        
};//Print the array

float avgX(float a[],int s){
        float sum = 0; 
    for (int i = 0; i < s; i++){
        sum+=a[i];
    }
    cout << setw(6)<< setprecision(7) << showpoint << fixed;
    return sum/s;
};//Calculate the Average

float stdX(float a[], int s) {
    float mean = avgX(a, s);  // Calculate the mean
    float sum = 0.0;

    for (int i = 0; i < s; i++) {
        float diff = a[i] - mean;
        sum += diff * diff;
    }

    return sqrt(sum / (s - 1));
}//Calculate the standard deviation