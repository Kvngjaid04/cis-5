#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <vector>
#include <numeric>  // For std::accumulate
#include <limits>  

using namespace std;

// Constants
const int NUM_DICE = 5;
const int MAX_ROLLS = 3;
const int MAX_ROUNDS = 13;

// Global Variables
int dice[NUM_DICE];
bool hold[NUM_DICE];
int rollsLeft = MAX_ROLLS;
int roundNum = 0;
vector<int> scorecard(MAX_ROUNDS, -1);  // Scorecard for each category

// Function Prototypes
void initializeGame();
void playerTurn();
void rollDice();
void holdDice();
int calculateScore(const int dice[5], int category);
bool hasNOfAKind(const int dice[5], int n);
bool hasFullHouse(const int dice[5]);
bool hasSmallStraight(const int dice[5]);
bool hasLargeStraight(const int dice[5]);
int sumDice(const int dice[5]);
void saveGame();
void loadGame();
void displayRules();
void sortDice();
int getValidInput(int min, int max);
int selectCategory();
void bubbleSort(int arr[], int n);

// Execution Begins Here
int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    
    initializeGame();
    displayRules();
    
    char loadChoice;
    cout << "Do you want to load a saved game? (Y/N): ";
    cin >> loadChoice;
    if (loadChoice == 'Y' || loadChoice == 'y') {
        loadGame();
    }

    while (roundNum < MAX_ROUNDS) {
        playerTurn();
        roundNum++;
    }
    
    int finalScore = accumulate(scorecard.begin(), scorecard.end(), 0);
    cout << "Game over! Your final score is " << finalScore << "." << endl;
    
    saveGame();
    
    return 0;
}

// Function Implementations

void initializeGame() {
    for (int i = 0; i < NUM_DICE; ++i) {
        dice[i] = rand() % 6 + 1;
        hold[i] = false;
    }
    rollsLeft = MAX_ROLLS;
    roundNum = 0;
    fill(scorecard.begin(), scorecard.end(), -1);
}

void playerTurn() {
    char choice;
    rollsLeft = MAX_ROLLS;
    while (rollsLeft > 0) {
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
                roundNum = MAX_ROUNDS;  // End game early
                return;
            default:
                cout << "Invalid choice. Please choose R, H, or Q." << endl;
        }
    }
    int category = selectCategory();
    int roundScore = calculateScore(dice, category);
    scorecard[category - 1] = roundScore;
    cout << "Your score for this category is " << roundScore << ".\n";
}

void rollDice() {
    for (int i = 0; i < NUM_DICE; ++i) {
        if (!hold[i]) {
            dice[i] = rand() % 6 + 1;
        }
    }
    cout << "You rolled: ";
    for (int i = 0; i < NUM_DICE; ++i) {
        cout << dice[i] << " ";
    }
    cout << endl;
}

void holdDice() {
    char choice;
    for (int i = 0; i < NUM_DICE; ++i) {
        cout << "Hold dice " << i+1 << " (" << dice[i] << ")? (Y/N): ";
        cin >> choice;
        hold[i] = (choice == 'Y' || choice == 'y');
    }
}

int calculateScore(const int dice[5], int category) {
    switch (category) {
        case 1: case 2: case 3: case 4: case 5: case 6:
            return count(dice, dice + 5, category) * category;
        case 7:
            return hasNOfAKind(dice, 3) ? sumDice(dice) : 0;
        case 8:
            return hasNOfAKind(dice, 4) ? sumDice(dice) : 0;
        case 9:
            return hasFullHouse(dice) ? 25 : 0;
        case 10:
            return hasSmallStraight(dice) ? 30 : 0;
        case 11:
            return hasLargeStraight(dice) ? 40 : 0;
        case 12:
            return hasNOfAKind(dice, 5) ? 50 : 0;
        case 13:
            return sumDice(dice);
        default:
            return 0;
    }
}

bool hasNOfAKind(const int dice[5], int n) {
    int counts[6] = {0};
    for (int i = 0; i < NUM_DICE; ++i) counts[dice[i] - 1]++;
    return *max_element(counts, counts + 6) >= n;
}

bool hasFullHouse(const int dice[5]) {
    int counts[6] = {0};
    for (int i = 0; i < NUM_DICE; ++i) counts[dice[i] - 1]++;
    return (find(counts, counts + 6, 2) != counts + 6) && 
           (find(counts, counts + 6, 3) != counts + 6);
}

bool hasSmallStraight(const int dice[5]) {
    int unique[NUM_DICE] = {0};
    int uniqueCount = 0;
    for (int i = 0; i < NUM_DICE; ++i) {
        if (find(unique, unique + uniqueCount, dice[i]) == unique + uniqueCount) {
            unique[uniqueCount++] = dice[i];
        }
    }
    sort(unique, unique + uniqueCount);
    for (int i = 0; i < uniqueCount - 3; ++i) {
        if (unique[i + 3] - unique[i] == 3) return true;
    }
    return false;
}

bool hasLargeStraight(const int dice[5]) {
    int sortedDice[NUM_DICE];
    copy(dice, dice + NUM_DICE, sortedDice);
    sort(sortedDice, sortedDice + NUM_DICE);
    return (sortedDice[4] - sortedDice[0] == 4);
}

int sumDice(const int dice[5]) {
    return accumulate(dice, dice + NUM_DICE, 0);
}

void saveGame() {
    ofstream outFile("yahtzee_save.txt");
    if (outFile.is_open()) {
        outFile << roundNum << endl;
        for (int i = 0; i < MAX_ROUNDS; ++i) {
            outFile << scorecard[i] << " ";
        }
        outFile.close();
        cout << "Game saved!" << endl;
    } else {
        cout << "Error saving game." << endl;
    }
}

void loadGame() {
    ifstream inFile("yahtzee_save.txt");
    if (inFile.is_open()) {
        inFile >> roundNum;
        for (int i = 0; i < MAX_ROUNDS; ++i) {
            inFile >> scorecard[i];
        }
        inFile.close();
        cout << "Game loaded! Current round: " << roundNum << endl;
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

void sortDice() {
    bubbleSort(dice, NUM_DICE);
    cout << "Sorted dice: ";
    for (int i = 0; i < NUM_DICE; ++i) {
        cout << dice[i] << " ";
    }
    cout << endl;
}

int getValidInput(int min, int max) {
    int input;
    while (true) {
        cin >> input;
        if (cin.fail() || input < min || input > max) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between " << min << " and " << max << ": ";
        } else {
            return input;
        }
    }
}

int selectCategory() {
    cout << "Select a category (1-13): ";
    return getValidInput(1, 13);
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
