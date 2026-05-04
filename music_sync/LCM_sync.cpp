// My first experiment using Claude Code after setting it up

#include <iostream>
#include <string>

using namespace std;

// Function to calculate GCD using Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate LCM using GCD
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

// Helper to get note value as denominator (1 = whole, 2 = half, 4 = quarter, 8 = eighth, 16 = sixteenth)
int getNoteValue() {
    string note;
    cout << "Enter note type (quarter, eighth, sixteenth, half, whole): ";
    cin >> note;

    if (note == "whole") return 1;
    if (note == "half") return 2;
    if (note == "quarter") return 4;
    if (note == "eighth") return 8;
    if (note == "sixteenth") return 16;

    // Default to quarter if invalid
    return 4;
}

int main() {
    // First time signature
    int num1, num2;
    int noteValue1 = getNoteValue();
    cout << "How many of those notes per bar? ";
    cin >> num1;

    // Second time signature
    int noteValue2 = getNoteValue();
    cout << "How many of those notes per bar? ";
    cin >> num2;

    // Calculate bar lengths in terms of smallest note unit (1/x)
    // A bar's duration = numerator * (1/denominator) in whole note units
    // To compare, we need common denominator
    int lcmDenom = lcm(noteValue1, noteValue2);

    // Convert bar lengths to common unit
    int barLength1 = num1 * (lcmDenom / noteValue1);
    int barLength2 = num2 * (lcmDenom / noteValue2);

    // Find when they sync (LCM of bar lengths in the common unit)
    int syncUnit = lcm(barLength1, barLength2);

    // Calculate how many bars of each time signature
    int bars1 = syncUnit / barLength1;
    int bars2 = syncUnit / barLength2;

    cout << "\n--- Sync Point ---" << endl;
    cout << "Musicians will sync after " << bars1 << " bars of the first time signature" << endl;
    cout << "and " << bars2 << " bars of the second time signature." << endl;
    cout << "\nTotal duration in " << lcmDenom << "th notes: " << syncUnit << endl;

    return 0;
}
