/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 2, 2019, 12:36 PM
 * Purpose:  Creation of Template to be used for all
 *           future projects
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    unsigned short arabic, n1000s, n100s, n10s, n1s;
    string romnNm;
    
    //Initialize or input i.e. set variable values
    cout << "Arabic to Roman numeral conversion." << endl;
    cout << "Input the integer to convert." << endl;
    cin >> arabic;
    romnNm = " ";
    
    
    
    //Map inputs -> outputs
     if ( arabic < 1000 || arabic > 3000)
            {
                cout << arabic << " is Out of Range!";
            }
            
     else   {
                n1000s=arabic/1000;  //Determine # 1000'S
                arabic-=n1000s*1000; //Subtract from the Original Arabic
                n100s=arabic/100;    //Repeat process for all digits
                arabic-=n100s*100;
                n10s=arabic/10;    //Repeat process for all digits
                arabic-=n10s*10;
                n1s=arabic;
                
                switch(n1000s){
                    case 3:romnNm+="M";
                    case 2:romnNm+="M";
                    case 1:romnNm+="M";
                }
                //Output the #100's in Roman Numerals
                switch(n100s){
                    case 9:romnNm+="CM";break;
                    case 8:romnNm+="DCCC";break;
                    case 7:romnNm+="DCC";break;
                    case 6:romnNm+="DC";break;
                    case 5:romnNm+="D";break;
                    case 4:romnNm+="CD";break;
                    case 3:romnNm+="C";
                    case 2:romnNm+="C";
                    case 1:romnNm+="C";
                }
                //Output the #10's in Roman Numerals
                switch(n10s){
                    case 9:romnNm+="XC";break;
                    case 8:romnNm+="LXXX";break;
                    case 7:romnNm+="LXX";break;
                    case 6:romnNm+="LX";break;
                    case 5:romnNm+="L";break;
                    case 4:romnNm+="XL";break;
                    case 3:romnNm+="X";
                    case 2:romnNm+="X";
                    case 1:romnNm+="X";
                }
                    //Output the #10's in Roman Numerals
                switch(n1s){
                    case 9:romnNm+="IX";break;
                    case 8:romnNm+="VIII";break;
                    case 7:romnNm+="VII";break;
                    case 6:romnNm+="VI";break;
                    case 5:romnNm+="V";break;
                    case 4:romnNm+="IV";break;
                    case 3:romnNm+="I";
                    case 2:romnNm+="I";
                    case 1:romnNm+="I";
                }
            
            
                //Display the outputs
                cout<<n1000s<<n100s<<n10s<<n1s<< " is equal to" <<romnNm;
            }
    //Exit stage right or left!
    return 0;
}