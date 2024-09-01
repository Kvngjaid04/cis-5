/* 
 * File:   main.cpp
 * Author: 
 * Created:
 * Purpose:  
 * 
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>   //Format Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const int COLS=6;

//Function Prototypes
void fillTbl(int [][COLS],int);
void prntTbl(const int [][COLS],int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    const int ROWS=6;
    int tablSum[ROWS][COLS];
    
    //Initialize or input i.e. set variable values
    fillTbl(tablSum,ROWS);
    
    //Display the outputs
    cout << "Think of this as a Product/Muliplication Table" << endl;
    cout << "           C o l u m n s" <<endl;
    cout << "     |   1   2   3   4   5   6" << endl;
    cout << "----------------------------------" << endl;
    prntTbl(tablSum,ROWS);

    //Exit stage right or left!
    return 0;
}

void fillTbl(int table[][COLS],int rows){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            table[i][j] = (i + 1) * (j + 1);
        }
    }    
}

void prntTbl(const int table[][COLS],int rows){
      for (int i = 0; i < rows; i++) {
          if (i==0) {cout << " " ;}
          else if (i==1) {cout << "R" ;}
          else if (i==2) {cout << "O" ;}
          else if (i==3) {cout << "W" ;}
          else if (i==4) {cout << "S" ;}
          else {cout << " ";}
        cout << setw(3) << i + 1 << " |";
        for (int j = 0; j < COLS; j++) {
            cout << setw(4) << table[i][j];
        }
        cout << endl;
    }
}