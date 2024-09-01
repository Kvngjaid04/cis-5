/*
 * Author: Ireoluwa
 * Created on June 18, 2024, 12:19 PM
 * Purpose: a game of yahtzee version 1
 */

// System Libraries
#include <iostream>   // I/O library for input and output operations
#include <ctime>      // Library to work with time functions
#include <cstdlib>    // Random number generation
#include <fstream>    // File input and output
#include <string>     // string library
#include <cmath>      // Math library
using namespace std;
//User Libraries

//Global Constants - Mathematical, Scientific, Conversions

//Higher Dimensions go here. No Variables

//Function Prototypes

//Execution Begins here
int main(int argc, char** argv) {
    // Setting the random number seed
    srand(static_cast<unsigned int>(time(0)));

    // Declaring Variables
    const int maxdice = 6, mindice = 1;         // Max and min value for a dice
    char Gchoice, choice, sChoice, plymode, shwRuls, ldgFile;    // game choices
    int dice1, dice2, dice3, dice4, dice5, rllsLft, ttlScre, y;
    bool hold1, hold2, hold3, hold4, hold5;      // Boolean to track dice status
    float ascore;
    string Yname, fname, line;

    // Initialize Variables
    ttlScre = 0;

    // Welcome message and prompt for username
    cout << "Welcome to Yahtzee!" << endl;
    cout << "Enter Username: ";
    cin >> Yname;
    cout << endl << "Welcome " << Yname <<"!" << endl;

    // Ask if the player wants to load a previous game file
    cout << "Do you want to load a previous game file? (Y/N): ";
    cin >> ldgFile;
    while(ldgFile != 'Y' && ldgFile != 'y' && ldgFile != 'N' && ldgFile != 'n'){
        cout << "Invalid Input. Input 'Y' or 'N': ";
        cin >> ldgFile;
    }

    // Load game file if the user chooses to
    if (ldgFile == 'Y' || ldgFile == 'y') {
        cout << "Enter the filename to load the game results: ";
        cin >> fname;
        ifstream inFile(fname);
        if (inFile) {
            while (getline(inFile, line)) {
                cout << line << endl << endl;
            }
            cout << "Try to beat your previous score" << endl;
            cout << "Starting New Game!" << endl << endl;

            inFile.close();
        } else {
            cout << "File not found. Starting a new game." << endl << endl;
        }
    }

    // Ask if the player wants to use their username as part of the filename
    cout << "Do you want to use your username as part of the filename? (Y/N): ";
    cin >> sChoice;
    while ( sChoice != 'Y' && sChoice != 'y' && sChoice != 'n' &&
            sChoice != 'N'){
        cout << "Invalid Input. Input 'Y' or 'N': ";
        cin >> sChoice;
    }

    // Determine the filename based on user input
    if (sChoice == 'Y' || sChoice == 'y') {
        fname = Yname + " game results.txt";
    } 
    else {
        cout << "Enter the filename to save the game results:";
        cin >> fname;  
    }
    // save file - Open file for writing game results
    ofstream outFile(fname);
    outFile << "Welcome to Yahtzee!" << endl << endl;

        // Game loop to manage multiple rounds
    for (int rnd = 1; rnd <= 13; rnd++) {
        rllsLft = 3;                     // Number of rolls in the current round
        hold1 = hold2 = hold3 = hold4 = hold5 = false; // Reset dice hold status 

        // Output round information
        cout << endl << "Round " << rnd << endl;
        outFile << endl << "Round " << rnd << endl;              // Write round to file

        // Get the user's choice for the next action
        do {                                
            cout << "Do you want to (R)oll, (H)old, or (Q)uit?" << endl;
            cin >> Gchoice;   

            if (Gchoice == 'R' || Gchoice == 'r') {                // If the user chooses to roll the dice
                if (!hold1) dice1 = rand() % maxdice + mindice; 
                if (!hold2) dice2 = rand() % maxdice + mindice;
                if (!hold3) dice3 = rand() % maxdice + mindice;
                if (!hold4) dice4 = rand() % maxdice + mindice;
                if (!hold5) dice5 = rand() % maxdice + mindice;

                // Display rolled dice values
                cout << "You rolled: " << dice1 << " " << dice2 << " " << dice3 
                        << " " << dice4 << " " << dice5 << endl;
                    
                // Write rolled dice values to file
                outFile << "Rolled: " << dice1 << " " << dice2 << " " << dice3 
                        << " " << dice4 << " " << dice5 << endl;

                // Check for Yahtzee
                if (dice1 == dice2 && dice2 == dice3 && dice3 == dice4 && dice4 == dice5) {
                    cout << "Yahtzee!" << endl;
                    outFile << "Yahtzee!" << endl;
                }

                // Check for Large Straight
                else if ((dice1 == 1 && dice2 == 2 && dice3 == 3 && dice4 == 4 && dice5 == 5) ||
                         (dice1 == 2 && dice2 == 3 && dice3 == 4 && dice4 == 5 && dice5 == 6)) {
                    cout << "Large Straight!" << endl;
                    outFile << "Large Straight!" << endl;
                }

                --rllsLft;             // Decrement the number of rolls left
            } 
            else if (Gchoice == 'H' || Gchoice == 'h') {            // If the user chooses to hold certain dice
                // Ask the user if they want to hold a certain dice
                cout << "Hold dice 1 (" << dice1 << ")? (Y/N): ";
                cin >> choice; 
                hold1 = (choice == 'Y' || choice == 'y') ? true : false;
                
                cout << "Hold dice 2 (" << dice2 << ")? (Y/N): ";
                cin >> choice; 
                hold2 = (choice == 'Y' || choice == 'y') ? true : false;
                
                cout << "Hold dice 3 (" << dice3 << ")? (Y/N): ";
                cin >> choice; 
                hold3 = (choice == 'Y' || choice == 'y') ? true : false;
                
                cout << "Hold dice 4 (" << dice4 << ")? (Y/N): ";
                cin >> choice; 
                hold4 = (choice == 'Y' || choice == 'y') ? true : false;
                
                cout << "Hold dice 5 (" << dice5 << ")? (Y/N): ";
                cin >> choice; 
                hold5 = (choice == 'Y' || choice == 'y') ? true : false;
            } 
            else if (Gchoice == 'Q' || Gchoice == 'q') {            // If the user chooses to quit
                cout << "You have chosen to quit the game." << endl;
                outFile << "Game quit by user." << endl;
                round = 13;
                outFile.close();
               } 
            else {           // Handle invalid input
                cout << "Invalid choice! Please enter R, H, or Q." << endl;
            }
        } while (rllsLft > 0);

        // Calculate and display the score for the round
        ttlScre += dice1 + dice2 + dice3 + dice4 + dice5;
        cout << "Total Score: " << ttlScre << endl;
        outFile << "Total Score: " << ttlScre << endl;
    }

    // Close the output file
    outFile.close();

    return 0;
}
