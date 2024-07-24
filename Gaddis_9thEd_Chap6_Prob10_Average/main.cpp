/*
 * Author: Ireoluwa Dairo
 * Created on July 20, 2024
 * Purpose: Calculate the average of five test scores, dropping the lowest score
 */

// System Libraries
#include <iostream>
#include <iomanip>  // For setting output precision
using namespace std;

// Function Prototypes
void getScre(int &, int &, int &, int &, int &);
float calcAvg(int, int, int, int, int);
int fndLwst(int, int, int, int, int);

// Main function
int main() {
    // Declare variables for the five scores
    int score1, score2, score3, score4, score5;

    // Print introduction message
    cout << "Find the Average of Test Scores" << endl;
    cout << "by removing the lowest value." << endl;
    cout << "Input the 5 test scores." << endl;

    // Get scores from the user
    getScre(score1, score2, score3, score4, score5);

    // Calculate and display the average of the four highest scores
    float average = calcAvg(score1, score2, score3, score4, score5);
    cout << "The average test score = " << setprecision(1) << fixed << average;

    return 0;
}

// Function to get scores from the user
void getScre(int &s1, int &s2, int &s3, int &s4, int &s5) {
    cin >> s1 >> s2 >> s3 >> s4 >> s5;

    // Check for valid input
    while (s1 < 1 || s1 > 100 || s2 < 1 || s2 > 100 || s3 < 1 || s3 > 100 || s4 
            < 1 || s4 > 100 || s5 < 1 || s5 > 100) {
        cout << "Invalid input. Please enter scores between 1 and 100:" << endl;
        cin >> s1 >> s2 >> s3 >> s4 >> s5;
    }
}

// Function to calculate the average of the four highest scores
float calcAvg(int s1, int s2, int s3, int s4, int s5) {
    // Find the lowest score
    int lowest = fndLwst(s1, s2, s3, s4, s5);

    // Sum of all scores
    int sum = s1 + s2 + s3 + s4 + s5;

    // Return the average of the four highest scores
    return (sum - lowest) / 4.0;
}

// Function to find the lowest score
int fndLwst(int s1, int s2, int s3, int s4, int s5) {
    // Initialize lowest with the first score
    int lowest = s1;

    // Compare with other scores
    if (s2 < lowest) lowest = s2;
    if (s3 < lowest) lowest = s3;
    if (s4 < lowest) lowest = s4;
    if (s5 < lowest) lowest = s5;

    return lowest;
}
