/* 
 * File:   main.cpp
 * Author:
 * Created on:
 * Purpose:  Binary Search
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstdlib>   //Random Functions
#include <ctime>     //Time Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
void fillAry(int [],int);
void prntAry(int [],int,int);
void bublSrt(int [],int);
bool binSrch(int [],int,int,int&);
void swap (int&, int&);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE=100;
    int array[SIZE];
    int indx,val;
    
    //Initialize or input i.e. set variable values
    fillAry(array,SIZE);

    //Sorted List
   // prntAry(array,SIZE,10);
    swap(array[1], array[SIZE-2]);
    bublSrt(array,SIZE);

    //Display the outputs
    prntAry(array,SIZE,10);
    cout << endl;
    cout<<"Input the value to find in the array"<<endl;
    cin>>val;
    if(binSrch(array,SIZE,val,indx))
        cout<<val<<" was found at indx = "<<indx<<endl;

    //Exit stage right or left!
    return 0;
}

void  fillAry(int a[],int n){
    for (int i =0; i < n; i++ ){
        cin>> a[i];
    };//Initialize the array
    }

void  prntAry(int a[],int n ,int perline){
    for (int i =0; i < n; i++ ){
        cout << a[i] <<" ";  
        if (i % perline == (perline-1)) cout << endl;
    }
    };//Print the array
    
void swap (int &a, int &b){
    a=a^b;
    b=a^b;
    a=a^b;
    }
    
bool binSrch(int a[], int n, int val, int& indx) {
    int f = 0;
    int l = n - 1;
    
    while (f <= l) {
        int m = f + (l - f) / 2;
        if (a[m] == val) {
            indx = m;
            return true;
        }
        
        if (a[m] < val)
            f = m + 1;
        else
            l = m - 1;
    }
    
    indx = -1;
    return false;
}

void bublSrt(int arr[],int s){
    int elem;
    int index;
    
     for(elem = s-1; elem >0; elem--){
         for( index = 0; index < elem; index++){
             if (arr[index] > arr[index+1] ){
                 swap(arr[index], arr[index+1]);
             }
         }
     }
};