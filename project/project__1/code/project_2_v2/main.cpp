/*
 * Author: Ireoluwa
 * Created on July 21, 4:18 pm
 * Purpose: a game of Yahtzee
 */

// System Libraries
#include <iostream>   // I/O library for input and output operations
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
void wlcmMsg (string uname = "Player");                 // welcome Message
void srtAray (int[], int);                               // sort Array
void dFilnme (string&, string&);                         // determine Filename
void savGame (fstream&, const string&, const string&);   // Saved Game
void rllDice (int[], bool[]);                            // roll Dice
void dspRoll (const int[], fstream&);                    // display Roll
void Spclcmb (const int[], fstream&);                    // Special Combinations
void hldDice (int[], bool[]);                            // hold Dice
void dspscre (int, int, fstream&);                       // display Round Result
void dspscre (const int[], fstream&);                    // display Final Result
void exitGme (int);                                      // exit Game
void Gmeloop (int[], fstream& out);                      // Game loop
void bblSort (int [], int);                              // bubble sort
void selSort (int[], int);                               // selection sort
bool Yahtzee (const int[]);                              // Yahtzee combination
bool FrOAKnd (const int[]);                              // Four Of A Kind
bool FullHse (const int[]);                              // Full House 
bool LrgStht (const int[]);                              // Large Straight 
bool SmlStht (const int[]);                              // Small Straight 
bool ThOAKnd (const int[]);                              // Three Of A Kind 
bool ldPvGme (const string&);                            // load Previous Game
int  smArray (const int[], int);                         // sum Array
int  linSrch (const int[], int, int);                    // linear search

//Execution Begins here
int main() {
    // Setting the random number seed
    srand(static_cast<unsigned int>(time(0)));

    // Declaring Variables
    string uname, fname;
    fstream out;
    
    // Initialize Variables
    int scores[13] = {0};
    
    // Welcome message and prompt for username
    wlcmMsg();
    
    //Gamefile choice
    if (!ldPvGme(fname)) {dFilnme(uname, fname);}
    savGame(out, uname, fname);
    
    // Game loop to manage multiple rounds
    Gmeloop(scores, out);
    dspscre(scores, out);
    out.close();
    return 0;}

// Function Definitions
void Gmeloop(int scores[], fstream& out) {
    for (int round = 0; round < 13; round++) {
        int dice[5] = {0};
        bool hold[5] = {false};
        static int rllsLft = 3;
        cout << "Round " << round + 1 << endl;
        out << "Round " << round + 1 << endl;
            
        char Gchce;
        do {
            cout << "Do you want to (R)oll, (H)old, or (Q)uit? ";
            cin >> Gchce;
            cin.ignore();

            switch (Gchce) {
                case 'R':
                case 'r':
                    rllDice(dice, hold);
                    dspRoll(dice, out);
                    Spclcmb(dice, out);
                    rllsLft--;          // Decrement rolls left
                    break;
                    
                case 'H':
                case 'h':
                    hldDice(dice, hold);
                    break;

                case 'Q':
                case 'q':
                    exitGme(smArray(scores, round));
                    exit(0);
                    
                default:                 // If the user enters an invalid choice
                    cout << "Invalid choice!" << endl;
            }
            // Notify the user of remaining rolls
            if (rllsLft < 3){cout << rllsLft << " rolls left." << endl<<endl;}
        } while (rllsLft > 0 && Gchce != 'Q' && Gchce != 'q');
            rllsLft = 3;         // Reset rolls left for next round

        scores[round] = smArray(dice, 5);
        dspscre(round + 1, scores[round], out);
       
    }
}

void wlcmMsg(string uname) {
    string input;
    cout << "Welcome to Yahtzee!" << endl;
    cout << "Enter Username: ";
    getline(cin, input);
    if (!input.empty()) { uname = input;}
    cout << endl << "Welcome " << uname << "!" << endl;}

bool ldPvGme(const string& fname) {
    char lodChce;
    cout << "Do you want to load a previous game file? (Y/N): ";
    cin >> lodChce;
    cin.ignore();
    while (lodChce != 'Y' && lodChce != 'y' && lodChce != 'N' && lodChce != 'n')
    {cout << "Invalid Input. Input 'Y' or 'N': ";           //input validation
    cin >> lodChce;
    cin.ignore();}

    if (lodChce == 'Y' || lodChce == 'y') {
        string fname;
        cout << "Enter the filename to load the game results: ";
        getline(cin, fname);
        
        ifstream in(fname);
        if (in.is_open()) {
            string line;
            while (getline(in, line)) {
                cout << line << endl;
            }
            cout << "Try to beat your previous score" << endl;
            cout << "Starting New Game!" << endl << endl;
            in.close();
            return true;
        } else {
            cout << "File not found. Starting a new game." << endl << endl;
        }
    }
    return false;
}

void dFilnme(string& uname, string& fname) {
    char svChce;
    cout << "Do you want to use your username as part of the filename? (Y/N): ";
    cin >> svChce;
    cin.ignore();
    while (svChce != 'Y' && svChce != 'y' && svChce != 'N' && svChce != 'n') {
    cout << "Invalid Input. Input 'Y' or 'N': ";
    cin >> svChce;
    cin.ignore();}

    if (svChce == 'Y' || svChce == 'y') {
        fname = uname + " game results.txt";
    } else {
        cout << "Enter the filename to save the game results: ";
        getline(cin, fname);
        while (fname.empty()) {             //input validation
        cout << "Filename cannot be empty. Please enter a filename: ";
        getline(cin, fname);}
    }cout << endl;
    return;
}

void savGame(fstream& out, const string& uname, const string& fname) {
    out.open(fname, ios::out);
    if (out.is_open()) {
        out << "Welcome to Yahtzee!" << endl;
        out << "Player: " << uname << endl << endl;
    }
}

void rllDice(int dice[], bool hold[]) {
    for (int i = 0; i < 5; i++) {
        if (!hold[i]) {
            dice[i] = rand() % 6 + 1;
        }
    }
}

void dspRoll(const int dice[], fstream& out) {
    cout << "You rolled: ";
    out << "Rolled: ";
    for (int i = 0; i < 5; i++) {
        cout << dice[i] << " ";
        out << dice[i] << " ";
    }
    cout << endl;
    out << endl;
}

void Spclcmb(const int dice[], fstream& out) {
    int sortedDice[5];
    for (int i = 0; i < 5; i++) {
        sortedDice[i] = dice[i];
    }
    srtAray(sortedDice, 5);

    if (Yahtzee(sortedDice)) {
        cout << "Yahtzee!" << endl;
        out << "Yahtzee!" << endl;
    }
    else if (FrOAKnd(sortedDice)) {
        cout << "Four of a kind!" << endl;
        out << "Four of a kind!" << endl;
    }
    else if (FullHse(sortedDice)) {
        cout << "Full House!" << endl;
        out << "Full House!" << endl;
    }
    else if (LrgStht(sortedDice)) {
        cout << "Large Straight!" << endl;
        out << "Large Straight!" << endl;
    }
    else if (SmlStht(sortedDice)) {
        cout << "Small Straight!" << endl;
        out << "Small Straight!" << endl;
    }
    else if (ThOAKnd(sortedDice)) {
        cout << "Three of a kind!" << endl;
        out << "Three of a kind!" << endl;
    }
}

void hldDice(int dice[], bool hold[]) {
    for (int i = 0; i < 5; i++) {
        char choice;
        cout << "Hold dice " << i + 1 << " (" << dice[i] << ")? (Y/N): ";
        cin >> choice;
        hold[i] = (choice == 'Y' || choice == 'y');
        while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n') 
        {cout << "Invalid Input. Input 'Y' or 'N': ";
        cin >> choice;
        cin.ignore();}
    }
}

void dspscre(int round, int rndScre, fstream& out) {
    cout << "End of round " << round << endl;
    cout << "Score for this round: " << rndScre << " points" << endl << endl;
    out << "Score for this round: " << rndScre << " points" << endl << endl;
}

void dspscre(const int scores[], fstream& out) {
    int ttlScre = smArray(scores, 13);
    float aScore = ttlScre / 13.0f;
    int rndAvrg = round(aScore);
    
    // Create a copy of scores for sorting
    int srtScrs[13];
    for (int i = 0; i < 13; i++) {
        srtScrs[i] = scores[i];
    }
    // Sort the copy using bubble sort
    bblSort(srtScrs, 13);

    cout << "Final score: " << setw(3) << setfill('0') << ttlScre << endl
         << "Average points: " << rndAvrg << " point(s) per round" << endl
         << "Scores by round: ";
        for (int i = 0; i < 13; i++) {
            cout << scores[i] << " ";} 
    cout << endl;

    cout << "Sorted points: ";
        for (int i = 0; i < 13; i++) {
            cout << srtScrs[i] << " ";} 
    cout << endl;

    int hScore = srtScrs[12];                             // highest score 
    int lScore = srtScrs[0];                             // lowest score
    int hscrer = linSrch(srtScrs, 13, hScore);   // highest score's round
    int lscrer = linSrch(srtScrs, 13, lScore);    // lowest score's round
    
    cout << "Highest score: " << hScore << " points in round " << hscrer<< endl;
    cout << "Lowest score: " << lScore << " points in round " << lscrer << endl;

    out << "Final score: " << setw(3) << setfill('0') << ttlScre << endl
        << "Average points: " << rndAvrg << " point(s) per round" << endl
        << "Scores by round: ";
        for (int i = 0; i < 13; i++) {
                out << scores[i] << " ";} 
    out << endl;
    out << "Sorted points: ";
        for (int i = 0; i < 13; i++) {
                out << srtScrs[i] << " ";} 
    cout << endl;
}

void exitGme(int ttlScre) {
    cout << "You Quit!" << endl;
    cout << "Final Score: " << ttlScre << " points" << endl;
    exit(0);
}

int smArray(const int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

bool Yahtzee(const int dice[]) {
    bool form = false;
    // Check if dice form a Yahtzee
    for (int i = 1; i < 5; i++) {
        if (dice[i] == dice[0]) {
            form = true;
        } else {
            form = false;
            break;
        }
    }
    return form;
}

bool FrOAKnd(const int dice[]) {
    if ((dice[0] == dice[1] && dice[1] == dice[2] && dice[2] == dice[3]) || 
        (dice[1] == dice[2] && dice[2] == dice[3] && dice[3] == dice[4])) {
        return true;
    }
    return false;
}

bool FullHse(const int dice[]) {
    if ((dice[0] == dice[1] && dice[1] == dice[2] && dice[3] == dice[4]) ||
        (dice[0] == dice[1] && dice[2] == dice[3] && dice[3] == dice[4])) {
        return true;
    }
    return false;
}

bool LrgStht(const int dice[]) {
    if ((dice[0] == 1 && dice[1] == 2 && dice[2] == 3 && dice[3] == 4 && dice[4] == 5) ||
        (dice[0] == 2 && dice[1] == 3 && dice[2] == 4 && dice[3] == 5 && dice[4] == 6)) {
        return true;
    }
    return false;
}

bool SmlStht(const int dice[]) {
    int counts[6] = {0};
    for (int i = 0; i < 5; i++) {
        counts[dice[i] - 1]++;
    }
    for (int i = 0; i < 3; i++) {
        if (counts[i] > 0 && counts[i+1] > 0 && counts[i+2] > 0 && counts[i+3] > 0) {
            return true;
        }
    }
    return false;
}

bool ThOAKnd(const int dice[]) {
    for (int i = 0; i < 3; i++) {
        if (dice[i] == dice[i+1] && dice[i] == dice[i+2]) {
            return true;
        }
    }
    return false;
}

void srtAray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void bblSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) { 
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }}}}

void selSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndx]) {
                minIndx = j;
            }}
        if (minIndx != i) {
            int temp = arr[i];
            arr[i] = arr[minIndx];
            arr[minIndx] = temp;
        }}
}

int linSrch(const int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i + 1; // Return the round number (i + 1)
        }
    }
}