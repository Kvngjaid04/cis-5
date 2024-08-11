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
void wlcmMsg (string uname = "Player");                  // welcome Message
void bblsort (int[], int);                               // bubble sort Array
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
void linsrch (const int[], int&, int&, int&, int&);      // linear search
void selsort (int[], int);                               // selection sort
bool Yahtzee (const int[]);                              // Yahtzee combination
bool FrOAKnd (const int[]);                              // Four Of A Kind
bool FullHse (const int[]);                              // Full House 
bool LrgStht (const int[]);                              // Large Straight 
bool SmlStht (const int[]);                              // Small Straight 
bool ThOAKnd (const int[]);                              // Three Of A Kind 
bool ldPvGme (const string&);                            // load Previous Game
int  smArray (const int[], int);                         // sum Array

//Execution Begins here
int main(int argc, char *argv[]) {
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
void Gmeloop(int scores[], fstream& out) {          // loop to manage all rounds
    for (int round = 0; round < 13; round++) {      //13 rounds
        int dice[5];                          // Initialize dice and hold arrays
        bool hold[5];
        
        // Reset the hold array for each round
        for (int i = 0; i < 5; i++) {
            hold[i] = false;
        }
        static int rllsLft = 3;                     // Initialize rolls left
        cout << "Round " << round + 1 << endl;      // Display round number
        out << "Round " << round + 1 << endl;
            
        char Gchce;                             // Get user input for each round
        do {
            cout << "Do you want to (R)oll, (H)old, or (Q)uit? ";
            cin >> Gchce;                              // Prompt user for action
            cin.ignore();               

            switch (Gchce) {                            // Handle user input
                case 'R':                                   // Roll dice
                case 'r':
                    rllDice(dice, hold);
                    dspRoll(dice, out);
                    Spclcmb(dice, out);
                    rllsLft--;          // Decrement rolls left
                    break;
                    
                case 'H':                                        // hold dice
                case 'h':
                    hldDice(dice, hold);
                    break;

                case 'Q':                                       //quit
                case 'q':
                    exitGme(smArray(scores, round));
                    exit(0);
                    
                default:                 // If the user enters an invalid choice
                    cout << "Invalid choice!" << endl;
            }
            // Display remaining rolls
            if (rllsLft < 3){cout << rllsLft << " rolls left." << endl<<endl;}
        } while (rllsLft > 0 && Gchce != 'Q' && Gchce != 'q');
            rllsLft = 3;         // Reset rolls left for next round

        scores[round] = smArray(dice, 5);      // Calculate score each round
        dspscre(round + 1, scores[round], out);     // Display round result
    }
}

void wlcmMsg(string uname) {            //welcome messasge
    string input;
    cout << "Welcome to Yahtzee!" << endl;
    cout << "Enter Username: ";         //prompt user for username
    getline(cin, input);
    if (!input.empty()) { uname = input;}
    cout << endl << "Welcome " << uname << "!" << endl;}

bool ldPvGme(const string& fname) {         //gamefile choice
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
        getline(cin, fname);                //prompt user for game file name
        
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
        } else {                //error message
            cout << "File not found. Starting a new game." << endl << endl;
        }
    }
    return false;
}

void dFilnme(string& uname, string& fname) {            //determine file name
    char svChce;
    cout << "Do you want to use your username as part of the filename? (Y/N): ";
    cin >> svChce;
    cin.ignore();
    while (svChce != 'Y' && svChce != 'y' && svChce != 'N' && svChce != 'n') {
    cout << "Invalid Input. Input 'Y' or 'N': ";        //input validation
    cin >> svChce;
    cin.ignore();}

    if (svChce == 'Y' || svChce == 'y') {
        fname = uname + " game_results.txt";
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
        out << "Welcome to Yahtzee!" << endl;       //begin game
        out << "Player: " << uname << endl << endl;
    }
}

void rllDice(int dice[], bool hold[]) {         //roll dice function
    for (int i = 0; i < 5; i++) {
        if (!hold[i]) {
            dice[i] = rand() % 6 + 1;
        }
    }
}

void dspRoll(const int dice[], fstream& out) {      //display rolled dice 
    cout << "You rolled: ";
    out << "Rolled: ";
    for (int i = 0; i < 5; i++) {
        cout << dice[i] << " ";
        out << dice[i] << " ";
    }
    cout << endl;
    out << endl;
}

void Spclcmb(const int dice[], fstream& out) {      //determine combinations
    int srtdDce[5];
    for (int i = 0; i < 5; i++) {
        srtdDce[i] = dice[i];
    }
    bblsort(srtdDce, 5);

    if (Yahtzee(srtdDce)) {             //yahtzee combination
        cout << "Yahtzee!" << endl;
        out << "Yahtzee!" << endl;
    }
    else if (FrOAKnd(srtdDce)) {        //four of a kind
        cout << "Four of a kind!" << endl;
        out << "Four of a kind!" << endl;
    }
    else if (FullHse(srtdDce)) {        //full house
        cout << "Full House!" << endl;
        out << "Full House!" << endl;
    }
    else if (LrgStht(srtdDce)) {        //large straight
        cout << "Large Straight!" << endl;
        out << "Large Straight!" << endl;
    }
    else if (SmlStht(srtdDce)) {        //small straight
        cout << "Small Straight!" << endl;
        out << "Small Straight!" << endl;
    }
    else if (ThOAKnd(srtdDce)) {            //three of a kind
        cout << "Three of a kind!" << endl;
        out << "Three of a kind!" << endl;
    }
}

void hldDice(int dice[], bool hold[]) {             //hold dice
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

void dspscre(int round, int rndScre, fstream& out) {      // display round score
    cout << "End of round " << round << endl;
    cout << "Score for this round: " << rndScre << " points" << endl << endl;
    out << "Score for this round: " << rndScre << " points" << endl << endl;
}

void dspscre(const int scores[], fstream& out) {          // display final score
    int ttlScre = smArray(scores, 13);
    float aScore = ttlScre / 13.0f;
    int rndAvrg = round(aScore);
    
    int hghst, lwst, hRnd, lRnd;
    linsrch(scores, hghst, lwst, hRnd, lRnd);

    cout << "Final score: " << setw(3) << setfill('0') << ttlScre << endl
         << "Average points: " << rndAvrg << " point(s) per round" << endl
         << "Highest score: " << hghst << " points in round " << hRnd << endl
         << "Lowest score: " << lwst << " points in round " << lRnd << endl;

    out  << "Final score: " << setw(3) << setfill('0') << ttlScre << endl
         << "Average points: " << rndAvrg << " point(s) per round" << endl
         << "Highest score: " << hghst << " points in round " << hRnd << endl
         << "Lowest score: " << lwst << " points in round " << lRnd << endl;
    
    // Sort and display scores in descending order
    int stdScrs[13];
    for (int i = 0; i < 13; i++) {
        stdScrs[i] = scores[i];
    }
    selsort(stdScrs, 13);

    cout << "Scores in descending order: "; 
    out << "Scores in descending order: ";
    for (int i = 0; i < 13; i++) {
        cout << stdScrs[i] << " ";
        out << stdScrs[i] << " ";
    }
    cout << endl;
    out << endl;
}

void exitGme(int ttlScre) {                 //exit game
    cout << "You Quit!" << endl;
    cout << "Final Score: " << ttlScre << " points" << endl;
}

int smArray(const int arr[], int size) {        //sum scores
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

bool FrOAKnd(const int dice[]) {        //check for four of a kind
    if ((dice[0] == dice[1] && dice[1] == dice[2] && dice[2] == dice[3]) || 
        (dice[1] == dice[2] && dice[2] == dice[3] && dice[3] == dice[4])) {
        return true;
    }
    return false;
}

bool FullHse(const int dice[]) {                     //check for full house
    if ((dice[0] == dice[1] && dice[1] == dice[2] && dice[3] == dice[4]) ||
        (dice[0] == dice[1] && dice[2] == dice[3] && dice[3] == dice[4])) {
        return true;
    }
    return false;
}

bool LrgStht(const int dice[]) {            //check for large straight
    if ((dice[0] == 1 && dice[1] == 2 && dice[2] == 3 && dice[3] == 4 && dice[4]
         == 5) || (dice[0] == 2 && dice[1] == 3 && dice[2] == 4 && dice[3] == 5 
         && dice[4] == 6)) {
        return true;
    }
    return false;
}

bool SmlStht(const int dice[]) {        //check for small straight
    int counts[6] = {0};
    for (int i = 0; i < 5; i++) {
        counts[dice[i] - 1]++;
    }
    for (int i = 0; i < 3; i++) {
        if (counts[i] > 0 && counts[i+1] > 0 && counts[i+2] > 0 &&
                counts[i+3] > 0) {
            return true;
        }
    }
    return false;
}

bool ThOAKnd(const int dice[]) {        //check for three of a kind
    for (int i = 0; i < 3; i++) {
        if (dice[i] == dice[i+1] && dice[i] == dice[i+2]) {
            return true;
        }
    }
    return false;
}

void bblsort(int arr[], int size) {             //bubble sort
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

void linsrch(const int scrs[], int& hghst, int& lwst, int& hRnd, int& lRnd) {
    hghst = scrs[0];                        //linear search
    lwst = scrs[0];
    hRnd = 1;
    lRnd = 1;

    for (int i = 1; i < 13; i++) {
        if (scrs[i] > hghst) {
            hghst = scrs[i];
            hRnd = i + 1;
        }
        if (scrs[i] < lwst) {
            lwst = scrs[i];
            lRnd = i + 1;
        }
    }
}

void selsort(int arr[], int size) {                 //selection sort
    for (int i = 0; i < size - 1; i++) {
        int maxIndx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] > arr[maxIndx]) {
                maxIndx = j;
            }
        }
        if (maxIndx != i) {
            int temp = arr[i];
            arr[i] = arr[maxIndx];
            arr[maxIndx] = temp;
        }
    }
}