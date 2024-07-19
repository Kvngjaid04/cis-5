#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <algorithm>  // Include algorithm for std::sort
using namespace std;

// Global Variables
int dice[5];
bool hold[5];
int playerScore = 0;
bool gameOver = false;
int rollsLeft = 3;  // Variable to track remaining rolls
int roundNumber = 0;  // Track the number of rounds played

// Function Prototypes
void initializeGame();
void playerTurn();
void rollDice();
void holdDice();
void calculateScore();
void saveGame();
void loadGame();
void displayRules();
void sortDice();  // Prototype for sorting function

// Execution Begins Here
int main(int argc, char** argv) {
    // Setting the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    // Initialize Variables and automatically roll the dice
    initializeGame();
    displayRules();
    
    // Load game state if desired
    char loadChoice;
    cout << "Do you want to load a saved game? (Y/N): ";
    cin >> loadChoice;
    if (loadChoice == 'Y' || loadChoice == 'y') {
        loadGame();
    }

    // Game Loop
    while (!gameOver) {
        playerTurn();
        roundNumber++;
        // End game after 13 rounds
        if (roundNumber >= 13) {
            gameOver = true;
            cout << "Game over! Your final score is " << playerScore << "." << endl;
        }
    }
    
    // Save game state
    saveGame();
    
    // Exiting stage left/right
    return 0;
}

// Function Implementations

void initializeGame() {
    for (int i = 0; i < 5; ++i) {
        dice[i] = rand() % 6 + 1;  // Initial roll of the dice
        hold[i] = false;  // Initially, no dice are held
    }
    playerScore = 0;
    gameOver = false;
    rollsLeft = 3;  // Reset rolls left
    roundNumber = 0;  // Reset round number
}

void playerTurn() {
    char choice;
    rollsLeft = 3;  // Reset rolls left for the new round
    while (rollsLeft > 0 && !gameOver) {
        cout << "You have " << rollsLeft << " rolls left." << endl;
        cout << "Do you want to (R)oll, (H)old, or (Q)uit? ";
        cin >> choice;
        
        switch (choice) {
            case 'R':
            case 'r':
                rollDice();
                rollsLeft--;
                break;
            case 'H':
            case 'h':
                holdDice();
                break;
            case 'Q':
            case 'q':
                gameOver = true;
                break;
            default:
                cout << "Invalid choice. Please choose R, H, or Q." << endl;
        }
    }
    calculateScore();
}

void rollDice() {
    for (int i = 0; i < 5; ++i) {
        if (!hold[i]) {
            dice[i] = rand() % 6 + 1;  // Roll dice that are not held
        }
    }
    cout << "You rolled: ";
    for (int i = 0; i < 5; ++i) {
        cout << dice[i] << " ";
    }
    cout << endl;
}

void holdDice() {
    char choice;
    for (int i = 0; i < 5; ++i) {
        cout << "Hold dice " << i+1 << " (" << dice[i] << ")? (Y/N): ";
        cin >> choice;
        hold[i] = (choice == 'Y' || choice == 'y');
    }
}

void calculateScore() {
    // Sort the dice before calculating the score
    sortDice();
    
    // Simple scoring: Sum of all dice values
    int roundScore = 0;
    for (int i = 0; i < 5; ++i) {
        roundScore += dice[i];
    }
    playerScore += roundScore;
    cout << "Your score for this round is " << roundScore << ". Total score: " << playerScore << endl;
    
    // Reset hold for next round
    for (int i = 0; i < 5; ++i) {
        hold[i] = false;
    }
}

void sortDice() {
    std::sort(dice, dice + 5);
    cout << "Sorted dice: ";
    for (int i = 0; i < 5; ++i) {
        cout << dice[i] << " ";
    }
    cout << endl;
}

void saveGame() {
    ofstream outFile("yahtzee_save.txt");
    outFile << playerScore << endl;
    for (int i = 0; i < 5; ++i) {
        outFile << dice[i] << " ";
    }
    outFile.close();
    cout << "Game saved!" << endl;
}

void loadGame() {
    ifstream inFile("yahtzee_save.txt");
    if (inFile.is_open()) {
        inFile >> playerScore;
        for (int i = 0; i < 5; ++i) {
            inFile >> dice[i];
        }
        inFile.close();
        cout << "Game loaded! Your score: " << playerScore << endl;
        cout << "Current dice: ";
        for (int i = 0; i < 5; ++i) {
            cout << dice[i] << " ";
        }
        cout << endl;
    } else {
        cout << "No saved game found." << endl;
    }
}

void displayRules() {
    cout << "Welcome to Yahtzee!" << endl;
    cout << "Rules: Roll 5 dice and try to get the best combinations for points." << endl;
    cout << "You can (R)oll to roll the dice or (H)old to hold specific dice and roll the others." << endl;
    cout << "You have 3 rolls per turn and can play up to 13 rounds. Good luck!" << endl;
}
