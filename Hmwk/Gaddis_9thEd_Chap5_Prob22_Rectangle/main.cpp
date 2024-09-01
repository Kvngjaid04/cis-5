/*
 * Author: Ireoluwa
 * Created on June 18, 2024, 12:19 PM
 * Purpose: Template to be utilized for all future problems
 */

// System Libraries
#include <iostream>   // I/O library for input and output operations
#include <ctime>      // Library to work with time functions
#include <cstdlib>    // random number generation
#include <iomanip>    // I/O manipulator
#include <string>     // For using std::string
#include <fstream>    // For file input and output
#include <vector>     // For STL vectors

using namespace std;

// User Libraries

// Global Constants - Mathematical, Scientific, Conversions

// Higher Dimensions go here. No Variables

// Function Prototypes
void rollmch(int&, int&, int&, int&, int&, bool, bool, bool, bool, bool, int, int, int&);
void holdmch(bool&, bool&, bool&, bool&, bool&, char, int, int, int, int, int);
void intro(string&);
void sortScores(vector<int>&, bool);  // Bubble Sort
void selectionSort(vector<int>&);
bool isValidDiceValue(int);  // Check if dice value is valid
void printArray(const vector<int>&); // Print vector contents

// Static Variable Example
static int gameCount = 0;

// Execution Begins Here
int main(int argc, char** argv) {
    // Setting the random number seed
    srand(static_cast<unsigned int>(time(0)));

    // Declaring Variables
    const int maxdice = 6, mindice = 1; // Max and min value for a six-sided dice
    char Gchoice, choice;  // Variable to store the user's game choice
    int dice1, dice2, dice3, dice4, dice5, rllsLft, roundScore, totalScore;
    bool hold1, hold2, hold3, hold4, hold5; // Booleans to track dice status
    vector<int> scores; // Vector to store scores
    string Yname, filename;

    // Initialize Variables
    intro(Yname);
    totalScore = 0;
    gameCount++;

    // Game loop to manage multiple rounds
    for (int round = 1; round <= 13; round++) {
        rllsLft = 3; // Number of rolls in the current round
        roundScore = 0; // Reset round score
        hold1 = hold2 = hold3 = hold4 = hold5 = false; // Reset dice hold status 
        cout << "Round " << round << endl;

        // Loop to handle rolling the dice
        do {
            cout << "Do you want to (R)oll, (H)old, or (Q)uit?" << endl;
            cin >> Gchoice; // Get the user's choice for the next action

            // Processing/Mapping Inputs to Outputs
            switch (Gchoice) { // Switch statement to handle the user's choice
                case 'R': // If the user chooses to roll the dice
                case 'r':
                    rollmch(dice1, dice2, dice3, dice4, dice5, hold1, 
                            hold2, hold3, hold4, hold5, maxdice, mindice, roundScore);
                    --rllsLft;           // Decrement the number of rolls left
                    break;
                case 'H': // If the user chooses to hold certain dice
                case 'h':
                    holdmch(hold1, hold2, hold3, hold4, hold5, choice,
                            dice1, dice2, dice3, dice4, dice5);   
                    break;
                case 'Q': // If the user chooses to quit the game
                case 'q':
                    cout << "You Quit!" << endl;
                    cout << "You finished with a score of " << totalScore << endl;
                    exit(0); // Exit the program
                default: // If the user enters an invalid choice
                    cout << "Invalid choice!" << endl;
            }

            // Notify the user of remaining rolls
            if (rllsLft > 0 && Gchoice != 'Q' && Gchoice != 'q') {
                cout << "You have " << rllsLft << " rolls left." << endl << endl;
            }
            // Continue while rolls are left and user hasn't quit
        } while (rllsLft > 0 && Gchoice != 'Q' && Gchoice != 'q'); 
        
        // Add round score to total score
        totalScore += roundScore;
        scores.push_back(roundScore); // Store round score
        cout << "End of round " << round << endl;
        cout << "Round Score: " << roundScore << endl;
        cout << "Total Score: " << totalScore << endl << endl; 
    }

    // Sort and display scores
    cout << "Sorting scores using Bubble Sort:" << endl;
    sortScores(scores, true); // true for Bubble Sort
    printArray(scores);

    cout << "Sorting scores using Selection Sort:" << endl;
    selectionSort(scores);
    printArray(scores);

    // Exit
    cout << "Game Over!" << endl;
    cout << "Final Score: " << totalScore << endl;
    cout << "Total Games Played: " << gameCount << endl;
    return 0; 
}

// Introduction
void intro(string& Yname)  // game intro
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

void rollmch(int& dice1, int& dice2, int& dice3, int& dice4, int& dice5, 
             bool hold1, bool hold2, bool hold3, bool hold4, bool hold5,
             int maxdice, int mindice, int& roundScore) {
    // Generate a random number between mindice and maxdice for the dice
    if (!hold1) dice1 = rand() % maxdice + mindice; 
    if (!hold2) dice2 = rand() % maxdice + mindice;
    if (!hold3) dice3 = rand() % maxdice + mindice;
    if (!hold4) dice4 = rand() % maxdice + mindice;
    if (!hold5) dice5 = rand() % maxdice + mindice;

    cout << "You rolled: " << dice1 << " " << dice2 << " "; 
    cout << dice3 << " " << dice4 << " " << dice5 << endl;

    // Calculate score for this roll (example: sum of all dice)
    roundScore = dice1 + dice2 + dice3 + dice4 + dice5;
}

void holdmch(bool& hold1, bool& hold2, bool& hold3, bool& hold4, bool& hold5,
          char choice, int dice1, int dice2, int dice3, int dice4,
          int dice5){
    cout << "Hold dice 1 (" << dice1 << ")? (Y/N): ";
    cin >> choice; // Get the user's choice for dice 1
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

bool isValidDiceValue(int value) {
    return value >= 1 && value <= 6;
}

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

void sortScores(vector<int>& scores, bool bubbleSort) {
    if (bubbleSort) {
        cout << "Using Bubble Sort" << endl;
        int n = scores.size();
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < n-i-1; j++) {
                if (scores[j] > scores[j+1]) {
                    swap(scores[j], scores[j+1]);
                }
            }
        }
    } else {
        selectionSort(scores);
    }
}

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}
