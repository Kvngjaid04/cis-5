/*
 * Author: Ireoluwa (updated by Claude)
 * Created on June 18, 2024, 12:19 PM
 * Purpose: a game of Yahtzee
 */

#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Function Prototypes
void rollDice(vector<int>& dice, const vector<bool>& hold, int sides = 6);
int calculateScore(const vector<int>& dice);
void calculateScore(const vector<int>& dice, int& score);
bool isYahtzee(const vector<int>& dice);
bool isLargeStraight(vector<int> dice);
void displayRules();
void quitGame(int ttlScre);
void printDiceValues(const vector<int>& dice);
void updateScoreboard(vector<vector<int>>& scoreboard, int round, int score);
void intro(string& Yname);
void holdDice(vector<bool>& hold, const vector<int>& dice);
void playRound(vector<int>& dice, vector<bool>& hold, int& ttlScre, int round, vector<vector<int>>& scoreboard);

int main() {
    srand(static_cast<unsigned int>(time(0)));

    vector<int> dice(5);
    vector<bool> hold(5, false);
    vector<vector<int>> scoreboard(13, vector<int>(2));
    int ttlScre = 0;
    string Yname;

    intro(Yname);
    
    for (int round = 1; round <= 13; round++) {
        playRound(dice, hold, ttlScre, round, scoreboard);
    }

    float ascore = static_cast<float>(ttlScre) / 13.0f;
    int avgScore = round(ascore);
    cout << "You finished with a score of " << setw(3) << setfill('0') 
         << ttlScre << " points with an average of " << avgScore << " point(s) per round" << endl;

    return 0;
}

void intro(string& Yname) {
    cout << "Welcome to Yahtzee!" << endl;
    cout << "Rules: Roll 5 dice and try to get the best combinations for points." << endl;
    cout << "You can (R)oll to roll the dice or (H)old to hold specific dice and roll the others." << endl;
    cout << "You have 3 rolls per turn and can play up to 13 rounds. Good luck!" << endl;
    cout << "Enter your name: ";
    cin >> Yname;
    cout << endl << "Welcome " << Yname <<"!" << endl;
}

void rollDice(vector<int>& dice, const vector<bool>& hold, int sides) {
    static int rollCount = 0;
    rollCount++;
    cout << "Roll number: " << rollCount << endl;
    
    for (int i = 0; i < 5; i++) {
        if (!hold[i]) {
            dice[i] = rand() % sides + 1;
        }
    }
}

void holdDice(vector<bool>& hold, const vector<int>& dice) {
    for (int i = 0; i < 5; i++) {
        char choice;
        cout << "Hold dice " << i+1 << " (" << dice[i] << ")? (Y/N): ";
        cin >> choice;
        hold[i] = (choice == 'Y' || choice == 'y');
    }
}

void playRound(vector<int>& dice, vector<bool>& hold, int& ttlScre, int round, vector<vector<int>>& scoreboard) {
    int rllsLft = 3;
    fill(hold.begin(), hold.end(), false);
    cout << "Round " << round << endl;

    while (rllsLft > 0) {
        char Gchoice;
        cout << "Do you want to (R)oll, (H)old, (S)how rules, or (Q)uit?" << endl;
        cin >> Gchoice;

        switch (Gchoice) {
            case 'R':
            case 'r':
                rollDice(dice, hold);
                printDiceValues(dice);
                if (isYahtzee(dice)) cout << "Yahtzee!" << endl;
                else if (isLargeStraight(dice)) cout << "Large Straight!" << endl;
                --rllsLft;
                break;
            case 'H':
            case 'h':
                holdDice(hold, dice);
                break;
            case 'S':
            case 's':
                displayRules();
                break;
            case 'Q':
            case 'q':
                quitGame(ttlScre);
            default:
                cout << "Invalid choice!" << endl;
        }

        if (rllsLft > 0) {
            cout << "You have " << rllsLft << " rolls left." << endl << endl;
        }
    }

    int rndScre = calculateScore(dice);
    ttlScre += rndScre;
    cout << "End of round " << round << endl;
    cout << "Score for this round: " << rndScre << " points" << endl;
    cout << "Total score: " << ttlScre << endl << endl;

    updateScoreboard(scoreboard, round, rndScre);
}

int calculateScore(const vector<int>& dice) {
    return accumulate(dice.begin(), dice.end(), 0);
}

void calculateScore(const vector<int>& dice, int& score) {
    score = accumulate(dice.begin(), dice.end(), 0);
}

bool isYahtzee(const vector<int>& dice) {
    return all_of(dice.begin() + 1, dice.end(), [&dice](int d) { return d == dice[0]; });
}

bool isLargeStraight(vector<int> dice) {
    sort(dice.begin(), dice.end());
    return (dice == vector<int>{1,2,3,4,5} || dice == vector<int>{2,3,4,5,6});
}

void displayRules() {
    cout << "Yahtzee Rules:" << endl;
    // Add detailed rules here
}

void quitGame(int ttlScre) {
    cout << "You Quit!" << endl;
    cout << "You finished with a score of " << ttlScre << endl;
    exit(0);
}

void printDiceValues(const vector<int>& dice) {
    cout << "You rolled: ";
    for (int value : dice) {
        cout << value << " ";
    }
    cout << endl;
}

void updateScoreboard(vector<vector<int>>& scoreboard, int round, int score) {
    scoreboard[round-1][0] = round;
    scoreboard[round-1][1] = score;
}