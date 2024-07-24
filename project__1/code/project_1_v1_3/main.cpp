/*
 * Author: Ireoluwa
 * Created on June 18, 2024, 12:19 PM
 * Purpose: a game of yahtzee
 */

// System Libraries
#include <iostream>   // I/O library for input and outputuy operations
#include <ctime>      // Library to work with time functions
#include <cstdlib>    // Random number generation
#include <fstream>    // File input and output
#include <iomanip>    // I/O manipulator
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
    const int maxdice = 6, mindice = 1;         // Max and min value for a  dice
    char Gchoice, choice, sChoice, plymode, shwRuls, ldgFile;    // game choices
    int dice1, dice2, dice3, dice4, dice5, rllsLft, ttlScre, y;
    bool hold1, hold2, hold3, hold4, hold5;      // Boolean to track dice status
    float ascore;
    string Yname, fname;

    // Initialize Variables
    ttlScre = 0;
        
    // Welcome message and prompt for username
    cout << "Welcome to Yahtzee!" << endl;
    cout << "Enter Username: ";
    getline (cin, Yname);
    cout << endl << "Welcome " << Yname <<"!" << endl;
    
    // Ask if the player wants to load a previous game file
    cout << "Do you want to load a previous game file? (Y/N): ";
    cin >> ldgFile;
    cin.ignore();
    while (ldgFile != 'Y' && ldgFile != 'y' && ldgFile != 'N' && ldgFile != 'n') {
        cout << "Invalid Input. Input 'Y' or 'N': ";
        cin >> ldgFile;
        cin.ignore();
    }

    // Load game file if the user chooses to
    if (ldgFile == 'Y' || ldgFile == 'y') {
        cout << "Enter the filename to load the game results: ";
        getline(cin, fname);
        ifstream inFile(fname);
        if (inFile) {
            string line;
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
    cin.ignore();
    while ( sChoice != 'Y' && sChoice != 'y' && sChoice != 'n' &&
                            sChoice != 'N'){
                        cout << "Invalid Input. Input 'Y' or 'N': ";
                         cin >> sChoice;
                            cin.ignore();
                    }

    // Determine the filename based on user input
    if (sChoice == 'Y' || sChoice == 'y') {
        fname = Yname + " game results.txt";
    } 
    else {
        cout << "Enter the filename to save the game results:";
        getline (cin, fname);  
    }
    // save file - Open file for writing game results
    ofstream outFile(fname);
    outFile << "Welcome to Yahtzee!" << endl << endl;
    
    // Ask if the player wants to see the rules
    cout << "Do you want to see the game rules? (Y/N): ";
    cin >> shwRuls;
    cin.ignore();
    while ( shwRuls != 'Y' && shwRuls != 'y' && shwRuls != 'n' &&
                            shwRuls != 'N'){
                        cout << "Invalid Input. Input 'Y' or 'N': ";
                         cin >> shwRuls;
                            cin.ignore();}
   
    // Processing/Mapping Inputs to Outputs
    // Display the game rules based on users input
if (shwRuls == 'Y' || shwRuls == 'y') {
    cout << "Game Rules:" << endl;
    cout << "1. Roll 5 dice and try to get the best";
    cout << " combinations for points." << endl;
    cout << "2. You can (R)oll to roll the dice or (H)old to hold specific";
    cout << "dice and roll the others." << endl;
    cout << "3. You have 3 rolls per turn and can play up to 13 rounds." <<endl;
    cout << "4. Scoring combinations include Yahtzee, Four of a Kind, Full";
    cout << "House, Three of a Kind," << endl;
    cout << "   Large Straight, and Small Straight." << endl;
    cout << "5. A Yahtzee is when all 5 dice show the same number." << endl;
    cout << "6. A Four of a Kind is when 4 dice show the same number." << endl;
    cout << "7. A Full House is 3 of one number and 2 of another." << endl;
    cout << "8. A Large Straight is 5 consecutive numbers. Small Straight is";
    cout << "4 consecutive numbers." << endl;
   cout << "9. Points are awarded based on the combination rolled."<<endl<<endl;
}

    // Game loop to manage multiple rounds
    for (int rnd = 1; rnd <= 13; rnd++) {
        rllsLft = 3;                     // Number of rolls in the current round
        hold1 = hold2 = hold3 = hold4 = hold5 = false; // Reset dice hold status 
        
        // Output round information
        cout << endl << "Round " << rnd << endl;
        outFile << endl << "Round " << rnd << endl;              // Write round  to file

        // Get the user's choice for the next action
        do {                                
            cout << "Do you want to (R)oll, (H)old, or (Q)uit?" << endl;
            cin >> Gchoice;   
            cin.ignore();

            switch (Gchoice) {   // Switch statement to handle the user's choice
                case 'R':                // If the user chooses to roll the dice
                case 'r':
                    if (!hold1) dice1 = rand() % maxdice + mindice; 
                    if (!hold2) dice2 = rand() % maxdice + mindice;
                    if (!hold3) dice3 = rand() % maxdice + mindice;
                    if (!hold4) dice4 = rand() % maxdice + mindice;
                    if (!hold5) dice5 = rand() % maxdice + mindice;
                    
                    // Display rolled dice values
                    cout << "You rolled: " << dice1 << " " << dice2 << " "; 
                    cout << dice3 << " " << dice4 << " " << dice5 << endl;
                    
                    // Write rolled dice values to file
                    outFile << "Rolled: " << dice1 << " " << dice2 << " ";
                    outFile << dice3 << " " << dice4 << " " << dice5 << endl;
                    
                    // Check for Yahtzee
                    if (dice1 == dice2 && dice2 == dice3 &&
                        dice3 == dice4 && dice4 == dice5) {
                        cout << "Yahtzee!" << endl;
                        outFile << "Yahtzee!" << endl;
                    }
                    
                    // Check for Four-of-a-kind
                    else if ((dice1==dice2 && dice2==dice3 && dice3 == dice4) || 
                        (dice1 == dice2 && dice2 == dice3 && dice3 == dice5) || 
                        (dice1 == dice2 && dice2 == dice4 && dice4 == dice5) || 
                        (dice1 == dice3 && dice3 == dice4 && dice4 == dice5) || 
                        (dice2 == dice3 && dice3 == dice4 && dice4 == dice5)) {
                        cout << "Four of a kind!" << endl;
                        outFile << "Four of a kind!" << endl;
                    }
                    
                    // Check for Full House
                    else if ((dice1==dice2 && dice2==dice3 && dice4 == dice5) || 
                        (dice1 == dice2 && dice3 == dice4 && dice4 == dice5) || 
                        (dice1 == dice3 && dice3 == dice4 && dice2 == dice5) || 
                        (dice1 == dice4 && dice4 == dice5 && dice2 == dice3) || 
                        (dice1 == dice5 && dice2 == dice3 && dice3 == dice4)) {
                        cout << "Full House!" << endl;
                        outFile << "Full House!" << endl;
                    }
                    
                    // Check for Three-of-a-kind
                    else if ((dice1 == dice2 && dice2 == dice3) || 
                        (dice1 == dice2 && dice2 == dice4) || 
                        (dice1 == dice2 && dice2 == dice5) || 
                        (dice1 == dice3 && dice3 == dice4) || 
                        (dice1 == dice3 && dice3 == dice5) || 
                        (dice1 == dice4 && dice4 == dice5) || 
                        (dice2 == dice3 && dice3 == dice4) || 
                        (dice2 == dice3 && dice3 == dice5) || 
                        (dice2 == dice4 && dice4 == dice5) || 
                        (dice3 == dice4 && dice4 == dice5)) {
                        cout << "Three of a kind!" << endl;
                        outFile << "Three of a kind!" << endl;
                    }

                    // Check for Large Straight
                    else if ((dice1==1 && dice2==2 && dice3==3 && dice4 == 4 &&
                        dice5 == 5) ||(dice1 == 2 && dice2 == 3 && dice3 == 4 &&
                        dice4 == 5 && dice5 == 6)) {
                        cout << "Large Straight!" << endl;
                        outFile << "Large Straight!" << endl;
                    }
                    
                    // Check for Small Straight
                    else if ((dice1==1 && dice2==2 && dice3==3 && dice4 == 4)|| 
                        (dice1 == 2 && dice2 == 3 && dice3 == 4 && dice4 == 5)|| 
                        (dice1 == 3 && dice2 == 4 && dice3 == 5 && dice4 == 6)|| 
                        (dice2 == 1 && dice3 == 2 && dice4 == 3 && dice5 == 4)|| 
                        (dice3 == 2 && dice4 == 3 && dice5 == 4 && dice1 == 1)){
                        cout << "Small Straight!" << endl;
                        outFile << "Small Straight!" << endl;
                    }

                    --rllsLft;             // Decrement the number of rolls left
                    break;

                case 'H':            // If the user chooses to hold certain dice
                case 'h':
                    
                    // Ask the user if they want to hold a certain dice
                    cout << "Hold dice 1 (" << dice1 << ")? (Y/N): ";
                    cin >> choice; 
                    cin.ignore();
                    if (choice == 'Y' || choice == 'y') {hold1 = true;}
                    else if (choice == 'N' || choice == 'n') {hold1 = false;}
                    else {cout << "Invalid choice dice will reroll!" << endl;}
                           
                    cout << "Hold dice 2 (" << dice2 << ")? (Y/N): ";
                    cin >> choice; 
                    cin.ignore();
                    if (choice == 'Y' || choice == 'y') {hold2 = true;}
                    else if (choice == 'N' || choice == 'n') {hold2 = false;}
                    else {cout << "Invalid choice dice will reroll!" << endl;}
                         
                    cout << "Hold dice 3 (" << dice3 << ")? (Y/N): ";
                    cin >> choice; 
                    cin.ignore();
                    if (choice == 'Y' || choice == 'y') {hold3 = true;}
                    else if (choice == 'N' || choice == 'n') {hold3 = false;}
                    else {cout << "Invalid choice dice will reroll!" << endl;}
                          
                    cout << "Hold dice 4 (" << dice4 << ")? (Y/N): ";
                    cin >> choice; 
                    cin.ignore();
                    if (choice == 'Y' || choice == 'y') {hold4 = true;}
                    else if (choice == 'N' || choice == 'n') {hold4 = false;}
                    else {cout << "Invalid choice dice will reroll!" << endl;}
                            
                    cout << "Hold dice 5 (" << dice5 << ")? (Y/N): ";
                    cin >> choice;
                    cin.ignore();
                    while ( choice != 'Y' && choice != 'y' && choice != 'n' &&
                            choice != 'N'){
                        cout << "Invalid Input. Input 'Y' or 'N': ";
                         cin >> choice; cin.ignore();
                    }
                    hold5 = (choice == 'Y' || choice == 'y') ? true : false;
                    break;

                case 'Q':                // If the user chooses to quit the game
                case 'q':
                    cout << "You Quit!" << endl;
                    rnd = 13;
                    break;
                default:                 // If the user enters an invalid choice
                    cout << "Invalid choice!" << endl;
            }

            // Notify the user of remaining rolls
            if (rllsLft > 0 && Gchoice != 'Q' && Gchoice != 'q') {
                cout << "You have " << rllsLft << " rolls left." << endl<<endl;
            }

        } while (rllsLft > 0 && Gchoice != 'Q' && Gchoice != 'q'); 

        cout << endl;
        
    //Displaying Input/Output Information
        int rndScre = dice1 + dice2 + dice3 + dice4 + dice5;
        ttlScre += rndScre;
        cout << "End of round " << rnd << endl;
        cout << "Score for this round: " << rndScre << " points"<<endl << endl;
        
        // Write round results to file
        outFile << "End of round " << rnd << endl;
        outFile <<"Score for this round: "<< rndScre << " points"<<endl << endl;
        
        if (rnd == 13){              // Display final score after the last round
            ascore = (ttlScre / 13.0f);
            y = round(ascore);
            cout << "You finished with a score of " << setw(3) << setfill('0');
            cout << ttlScre<<" points and had an average of ";
            cout << y << " points per round" << endl;
        
        // Write final results to file
        outFile << "You finished with a score of " << setw(3) << setfill('0');
        outFile << ttlScre<<" points and had an average of ";
        outFile << y << " points per round" << endl;
        }
    }
    // Close the file
    outFile.close();
    
    //Exiting stage left/right
    return 0; 
}
