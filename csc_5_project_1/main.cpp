/*
 * Author: Ireoluwa
 * Created on June 18, 2024, 12:19 PM
 * Purpose: a game of yatzhee
 */

// System Libraries
#include <iostream>   // I/O library for input and output operations
#include <ctime>      // Library to work with time functions
#include <cstdlib>    // random number generation
#include <iomanip>    // I/O manipulator
#include <string>     // For using std::string
#include <fstream>    // For file input and output

using namespace std;

// User Libraries

// Global Constants - Mathematical, Scientific, Conversions

// Higher Dimensions go here. No Variables

// Function Prototypes
void rollmch(int&,int&,int&, int&, int&,bool, bool, bool, bool, bool, int, int);
void holdmch(bool&,bool&,bool&,bool&,bool&,char&, int&, int&, int&, int&, int&);
void dceloop (int&, int&, int&, int&, int&, bool&, bool&, bool&, bool&, bool&,
              int&, char&, char&, const int, const int, int&);
void scecalc(int, int, int, int, int, int&, int&);
void savemch();
void intro(string &);

// Execution Begins Here
int main(int argc, char** argv) {
    // Setting the random number seed
    srand(static_cast<unsigned int>(time(0)));

    // Declaring Variables
    const int maxdice = 6, mindice = 1; //Max and min value for a six-sided dice
    char Gchoice, choice;  // Variable to store the user's game choice
    int dice1, dice2, dice3, dice4, dice5,rllsLft, ttlScre;
    bool hold1, hold2, hold3, hold4, hold5; // Boolean to track dice status
    float ascore;
    string Yname, filename;

    // Initialize Variables
    ttlScre = 0;
    intro(Yname);
    
    // Game loop to manage multiple rounds
    for (int round = 1; round <= 13; round++) {
        rllsLft = 3; // Number of rolls in the current round
        hold1 = hold2 = hold3 = hold4 = hold5 = false; // Reset dice hold status 
        cout << "Round " << round << endl;

        // Loop to handle rolling the dice
        dceloop (dice1, dice2, dice3, dice4, dice5, hold1, hold2, hold3, hold4,
                 hold5, rllsLft, Gchoice, choice, maxdice, mindice, ttlScre);
        
         // Calculate score for the current round
        scecalc(dice1, dice2, dice3, dice4, dice5, round, ttlScre);  
        
    }
    // Exit
    return 0; 
}

// Introduction
void intro(string &Yname)  // game intro
    {
    cout << "Welcome to Yahtzee!" << endl;
    cout << "Rules: Roll 5 dice and try to get the best";
    cout << " combinations for points." << endl;
    cout << "You can (R)oll to roll the dice or (H)old";
    cout << " to hold specific dice and roll the others." << endl;
    cout << "You have 3 rolls per turn and can play up";
    cout << " to 13 rounds. Good luck!" << endl;
    cout << "Enter your name: ";
    cin >> Yname;
    cout << endl << "Welcome " << Yname <<"!" << endl;
}

//roll mechanism
void rollmch (int &dice1, int &dice2, int &dice3, int &dice4, int &dice5, 
              bool hold1, bool hold2, bool hold3, bool hold4, bool hold5,
              int maxdice, int mindice) {
    // Generate a random number between mindice and maxdice for the dice
    if (!hold1) dice1 = rand() % maxdice + mindice; 
    if (!hold2) dice2 = rand() % maxdice + mindice;
    if (!hold3) dice3 = rand() % maxdice + mindice;
    if (!hold4) dice4 = rand() % maxdice + mindice;
    if (!hold5) dice5 = rand() % maxdice + mindice;

        cout << "You rolled: " << dice1 << " " << dice2 << " "; 
        cout << dice3 << " " << dice4 << " " << dice5 <<endl;
}

//hold mechanism
void holdmch (bool &hold1, bool &hold2, bool &hold3, bool &hold4, bool &hold5,
              char &choice, int &dice1, int &dice2, int &dice3, int &dice4,
              int &dice5){
        cout << "Hold dice 1 (" << dice1 << ")? (Y/N): ";
        // Get the user's choice for dice 1
        cin >> choice; 
        hold1 = (choice == 'Y' || choice == 'y');

        // Repeat procedure for the rest of the dice
        cout << "Hold dice 2 (" << dice2 << ")? (Y/N): ";
        cin >> choice; 
        hold2 = (choice == 'Y' || choice == 'y');

        cout << "Hold dice 3 (" << dice3 << ")? (Y/N): ";
        cin >> choice; 
        hold3 = (choice == 'Y' || choice == 'y');

        cout << "Hold dice 4 (" << dice4 << ")? (Y/N): ";
        cin >> choice; 
        hold4 = (choice == 'Y' || choice == 'y'); 

        cout << "Hold dice 5 (" << dice5 << ")? (Y/N): ";
        cin >> choice; 
        hold5 = (choice == 'Y' || choice == 'y'); 
}

 // Calculate score for the current round
void scecalc(int dice1, int dice2, int dice3, int dice4, int dice5, int &round,
                int &ttlScre) {
    int rndScre = dice1 + dice2 + dice3 + dice4 + dice5;
        ttlScre += rndScre;

        cout << "End of round " << round << endl;
        cout << "Score for this round: " << rndScre << endl;
        cout << "Total score: " << ttlScre << endl << endl;
}

 // Loop to handle rolling the dice
void dceloop(int &dice1, int &dice2, int &dice3, int &dice4, int &dice5,
             bool &hold1, bool &hold2, bool &hold3, bool &hold4, bool &hold5,
             int &rllsLft, char &Gchoice, char &choice, const int maxdice, 
             const int mindice, int& ttlScre) {
    
    do{
        cout << "Do you want to (R)oll, (H)old, or (Q)uit?" << endl;
        cin >> Gchoice; // Get the user's choice for the next action

        // Processing/Mapping Inputs to Outputs
        switch (Gchoice) { // Switch statement to handle the user's choice
            case 'R': // If the user chooses to roll the dice
            case 'r':
                rollmch(dice1, dice2, dice3, dice4, dice5, hold1, 
                        hold2, hold3, hold4, hold5, maxdice, mindice);
                --rllsLft;           // Decrement the number of rolls left
                break;
            case 'H': // If the user chooses to hold certain dice
            case 'h':
                holdmch(hold1, hold2, hold3, hold4, hold5, choice,
                        dice1, dice2, dice3, dice4, dice5);   break;

            case 'Q': // If the user chooses to quit the game
            case 'q':
                cout << "You Quit!" << endl;
                cout << "You finished with a score of " << ttlScre ;
                exit(0);
            default: // If the user enters an invalid choice
                cout << "Invalid choice!" << endl;
        }

        // Notify the user of remaining rolls
        if (rllsLft > 0 && Gchoice != 'Q' && Gchoice != 'q') {
            cout << "You have " << rllsLft << " rolls left." <<endl<<endl;
        }

        // Continue while rolls are left and user hasn't quit
    } while (rllsLft > 0 && Gchoice != 'Q' && Gchoice != 'q'); 
    cout << endl; 

}
