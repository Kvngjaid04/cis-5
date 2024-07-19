/*
 * Author: Ireoluwa
 * Created on June 18, 2024, 12:19 PM
 * Purpose: Template to be utilized for all future problems
 */

//System Libraries
#include <iostream>               // I/O library for input and output operations
#include <ctime>                          // Library to work with time functions
#include <cstdlib>                                  // random number generation
using namespace std;

//User Libraries

//Global Constants - Mathematical, Scientific, Conversions


//Higher Dimensions go here. No Variables

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Setting the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declaring Variables
    const unsigned int maxdice = 6;          // Max value for a six-sided dice
    const unsigned int mindice = 1;          // Min value for a  six-sided dice
    char Gchoice;                    // Variable to store the user's game choice
    int dceroll[5];               // Array to hold the values of five dice rolls
    bool hold[5] = {false};               // Array to track which dice are held
    int rollsLeft;
    
    //Initialize Variables
    cout << "Welcome to Yahtzee!" << endl;
    cout << "Rules: Roll 5 dice and try to get the best";
    cout << " combinations for points." << endl;
    cout << "You can (R)oll to roll the dice or (H)old";
    cout << " to hold specific dice and roll the others." << endl;
    cout << "You have 3 rolls per turn and can play up";
    cout << " to 13 rounds. Good luck!" << endl;
    
    // Game loop to manage multiple turns
    for (int round = 1; round <= 13; round++) {
        rollsLeft = 3; // Number of rolls left in the current turn
        cout << "Round " << round << endl;
        
    // Turn loop to handle rolling the dice up to 3 times
    do {
            cout << "Do you want to (R)oll, (H)old, or (Q)uit?" << endl;
            cin >> Gchoice; // Get the user's choice for the next action
            
            //Processing/Mapping Inputs to Outputs
            switch (Gchoice) { // Switch statement to handle the user's choice
                case 'R': // If the user chooses to roll the dice
                case 'r':
                    for (int i = 0; i < 5; ++i) { // Loop through each of the five dice
                        if (!hold[i]) { // If the dice is not held
                            dceroll[i] = rand() % 6 + 1; // Generate a random number between 1 and 6 for the dice
                        }
                    }
                    cout << "You rolled: ";
                    for (int i = 0; i < 5; ++i) { // Loop through the dice to display their values
                        cout << dceroll[i] << " ";
                    }
                    cout << endl;
                    --rollsLeft; // Decrement the number of rolls left
                    break;
                case 'H': // If the user chooses to hold certain dice
                    char choice; // Variable to store the user's decision to hold a specific dice
                    for (int i = 0; i < 5; ++i) { // Loop through each of the five dice
                        cout << "Hold dice " << i + 1 << " (" << dceroll[i] << ")? (Y/N): ";
                        cin >> choice; // Get the user's choice for each dice
                        hold[i] = (choice == 'Y' || choice == 'y'); // Set the hold status based on user's input
                    }
                    break;
                case 'Q': // If the user chooses to quit the game
                case 'q':
                    cout << "You forfeit!" << endl;
                    return 0; // Exit the program
                default: // If the user enters an invalid choice
                    cout << "Invalid choice!" << endl;
            }

            // Notify the user of remaining rolls
            if (rollsLeft > 0 && Gchoice != 'Q' && Gchoice != 'q') {
                cout << "You have " << rollsLeft << " rolls left." << endl<< endl;
            }

        } while (rollsLeft > 0 && Gchoice != 'Q' && Gchoice != 'q'); // Continue while rolls are left and user hasn't quit
        cout << "End of round " << round<< endl<< endl; 
    }
    
    //Exiting stage left/right
    return 0; // Return statement to indicate the program has ended successfully
}
