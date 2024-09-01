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
#include <vector>
using namespace std;

//User Libraries

//Global Constants - Mathematical, Scientific, Conversions

//Higher Dimensions go here. No Variables

//Function Prototypes
void wlcmMsg (string uname = "Player");                 // welcome Message
void srtAray (int[], int);                               // sort Array
void dFilnme (string&, string&);                         // determine Filename
void savGame (fstream&, const string&, const string&);   // Saved Game
void rllDice (int[][2]);                                  // roll Dice
void dspRoll (const int[][2], fstream&);                 // display Roll
void Spclcmb (const int[][2], fstream&);                 // Special Combinations
void hldDice (int[][2]);                                  // hold Dice
void dspscre (int, int, fstream&);                       // display Round Result
void dspscre (const int[], fstream&);                    // display Final Result
void exitGme (int);                                      // exit Game
void Gmeloop (int[], fstream&);                          // Game loop
bool Yahtzee (const int[]);                              // Yahtzee combination
bool FrOAKnd (const int[]);                              // Four Of A Kind
bool FullHse (const int[]);                              // Full House 
bool LrgStht (const int[]);                              // Large Straight 
bool SmlStht (const int[]);                              // Small Straight 
bool ThOAKnd (const int[]);                              // Three Of A Kind 
bool ldPvGme (const string&);                            // load Previous Game
int  smArray (const int[], int);                         // sum Array

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
        const int size = 5;
        int dceinfo[size][2]; // 2 columns: 0 for dice value, 1 for hold status

        // Initialize dice values
        for (int i = 0; i < size; i++) {
            dceinfo[i][0] = i + 1; // dice value
            dceinfo[i][1] = 0; // hold status
        }

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
                    rllDice(dceinfo);
                    dspRoll(dceinfo, out);
                    Spclcmb(dceinfo, out);
                    rllsLft--;          // Decrement rolls left
                    break;
                    
                case 'H':
                case 'h':
                    hldDice(dceinfo);
                    break;

                case 'Q':
                case 'q':
                    //exitGme(smArray(scores, round));
                    exit(0);
                    
                default:                 // If the user enters an invalid choice
                    cout << "Invalid choice!" << endl;
            }
            // Notify the user of remaining rolls
                        if (rllsLft < 3){cout << rllsLft << " rolls left." << endl<<endl;}
        } while (rllsLft > 0 && Gchce != 'Q' && Gchce != 'q');
            rllsLft = 3;         // Reset rolls left for next round

       // scores[round] = smArray(dceinfo, 5);
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

void rllDice(int dceinfo[][2]) {
    for (int i = 0; i < 5; i++) {
        if (dceinfo[i][1] == 0) {
            dceinfo[i][0] = rand() % 6 + 1;
        }
    }
}

void dspRoll(const int dceinfo[][2], fstream& out) {
    cout << "You rolled: ";
    out << "Rolled: ";
    for (int i = 0; i < 5; i++) {
        cout << dceinfo[i][0] << " ";
        out << dceinfo[i][0] << " ";
    }
    cout << endl;
    out << endl;
}

void Spclcmb(const int dceinfo[][2], fstream& out) {
    int stddce[5];
    for (int i = 0; i < 5; i++) {
        stddce[i] = dceinfo[i][0];
    }
    srtAray(stddce, 5);

    if (Yahtzee(stddce)) {
        cout << "Yahtzee!" << endl;
        out << "Yahtzee!" << endl;
    }
    else if (FrOAKnd(stddce)) {
        cout << "Four of a kind!" << endl;
        out << "Four of a kind!" << endl;
    }
       else if (FullHse(stddce)) {
        cout << "Full House!" << endl;
        out << "Full House!" << endl;
    }
    else if (LrgStht(stddce)) {
        cout << "Large Straight!" << endl;
        out << "Large Straight!" << endl;
    }
    else if (SmlStht(stddce)) {
        cout << "Small Straight!" << endl;
        out << "Small Straight!" << endl;
    }
    else if (ThOAKnd(stddce)) {
        cout << "Three of a kind!" << endl;
        out << "Three of a kind!" << endl;
    }
}

void hldDice(int dceinfo[][2]) {
    for (int i = 0; i < 5; i++) {
        char choice;
        cout << "Hold dice " << i + 1 << " (" << dceinfo[i][0] << ")? (Y/N): ";
        cin >> choice;
        dceinfo[i][1] = (choice == 'Y' || choice == 'y');
        while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n') 
        {cout << "Invalid Input. Input 'Y' or 'N': ";
        cin >> choice;
        cin.ignore();}
    }
}

void dspscre(int round, int score, fstream& out) {
    cout << "Round " << round << " score: " << score << endl;
    out << "Round " << round << " score: " << score << endl << endl;
}

void dspscre(const int scores[], fstream& out) {
    int ttlscre = 0;
    cout << "Final Scores:" << endl;
    out << "Final Scores:" << endl;
    for (int i = 0; i < 13; i++) {
        cout << "Round " << i + 1 << ": " << scores[i] << endl;
        out << "Round " << i + 1 << ": " << scores[i] << endl;
        ttlscre += scores[i];
    }
    cout << "Total Score: " << ttlscre << endl;
    out << "Total Score: " << ttlscre << endl;
}

void exitGme(int score) {
    cout << "Game Over! Your final score is " << score << endl;
    exit(0);
}

bool Yahtzee(const int dice[]) {
    return (dice[0] == dice[1] && dice[1] == dice[2] && dice[2] == dice[3] 
            && dice[3] == dice[4]);
}

bool FrOAKnd(const int dice[]) {
    int count[6] = {0};
    for (int i = 0; i < 5; i++) {
        count[dice[i] - 1]++;
    }
    for (int i = 0; i < 6; i++) {
        if (count[i] >= 4) {
            return true;
        }
    }
    return false;
}

bool FullHse(const int dice[]) {
    int count[6] = {0};
    for (int i = 0; i < 5; i++) {
        count[dice[i] - 1]++;
    }
    bool three = false;
    bool two = false;
    for (int i = 0; i < 6; i++) {
        if (count[i] == 3) {
            three = true;
        }
        if (count[i] == 2) {
            two = true;
        }
    }
    return three && two;
}

bool LrgStht(const int dice[]) {
    for (int i = 0; i < 2; i++) {
        if (dice[i] != dice[i + 1] - 1) {
            return false;
        }
    }
    return true;
}

bool SmlStht(const int dice[]) {
    for (int i = 0; i < 3; i++) {
        if (dice[i] != dice[i + 1] - 1) {
            return false;
        }
    }
    return true;
}

bool ThOAKnd(const int dice[]) {
    int count[6] = {0};
    for (int i = 0; i < 5; i++) {
        count[dice[i] - 1]++;
    }
    for (int i = 0; i < 6; i++) {
        if (count[i] >= 3) {
            return true;
        }
    }
    return false;
}

int smArray(const int arr[][2], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i][0];
    }
    return sum;
}

void srtAray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}