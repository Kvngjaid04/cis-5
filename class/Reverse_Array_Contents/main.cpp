/* 
 * File:   main.cpp
 * Author:
 * Created:
 * Purpose:  Reverse the Array
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

//Function Prototypes
void  init(int [],int);//Initialize the array
void  print(int [],int,int);//Print the array
void  revrse(int [],int);;//Reverse the array


//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned>(time(0)));
    
    //Declare Variables
    const int SIZE=50;
    int test[SIZE]={};
     int perline;
    
    //Initialize or input i.e. set variable values
    perline=10;
    init(test,SIZE);
    
    //Display the outputs
   // print(test,SIZE,10);
    
    //Reverse the Values
    revrse(test,SIZE);
    
    //Display the outputs
   // print(test,SIZE,10);

    //Exit stage right or left!
    return 0;
}
void  init(int a[],int n){
    for (int i =0; i < n; i++ ){
        cin>> a[i];
    };//Initialize the array
}

void  print(int a[],int n ,int perline){
    for (int i =0; i < n; i++ ){
        cout << a[i] <<" ";  
        if (i % perline == (perline-1)) cout << endl;
    }
    };//Print the array
    
void  revrse(int a[],int n){
    int perline=10;
    for (int i =0; i < n; i++ ){
        cout << a[n - 1 - i] << " ";
        if (i % perline == (perline-1)) cout << endl;}
        
};//Reverse the array
