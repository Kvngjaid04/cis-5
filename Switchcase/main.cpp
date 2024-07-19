/*
 * Author: Ireoluwa
 * Created on June 18, 2024, 12:19 PM
 * Purpose: Template to be utilized for all future problems
 */

//System Libraries
#include <iostream> //I/0 library
#include <cstdlib> //library for random function
#include <ctime> // library for time
using namespace std;

//User Libraries

//Global Constants - Mathematical, Scientific, Conversions

//Higher Dimensions go here. No Variables

//Function Prototypes

//Execution Begins here

int main(int argc, char** argv) {
    //Setting the random number seed
    srand(  static_cast <unsigned int>(time(0))); 
    
    //Declaring Variables
    char grade; //grade associated with the score
    unsigned char score; //1 Byte integer
    
    //Initialize Variables
    score = rand()%51+50;   //[50,100]  %51 -> 0, 50    +50 ->  50,100
    switch (score/10){       
        case 10:
        case  9: grade = 'A'; break;
        case  8: grade = 'B'; break;
        case  7: grade = 'C'; break;
        case  6: grade = 'D'; break;
        default: grade = 'F';
    }
    
    //Processing/Mapping Inputs to Outputs
    cout << "With a score of " << static_cast <int> (score) << " the grade = " << grade << endl;
    //Displaying Input/Output Information
    
    //Exiting stage left/right
    return 0;
}

