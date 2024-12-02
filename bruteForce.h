//
// Created by Kareem ELnaghy on 12/2/2024.
//
// Plagiarism Detection

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


// Function to find and calculate the total match length without overlaps
int calculateNonOverlappingMatchLength(const string& source, const string& target) {
    int sourceLen = source.size();
    int targetLen = target.size();

    if(source.size()==0 || target.size()==0)
        return 0;

    vector<bool> usedInTarget(targetLen, false); // Track matched characters in the target
    int matchLength = 0;

    for (int i = 0; i < sourceLen; ++i) {
        for (int j = 0; j < targetLen; ++j) {
            if (!usedInTarget[j] && source[i] == target[j]) {
                matchLength++;
                usedInTarget[j] = true; // Mark this character as used
                break; // Move to the next character in the source
            }
        }
    }

    return matchLength;
}

// Function to calculate the plagiarism percentage
double calculatePlagiarismPercentageBF(const string& source, const string& target) {
    int matchLength = calculateNonOverlappingMatchLength(source, target);
    if(matchLength == 0)
        return 0;
    return (static_cast<double>(matchLength) / source.size()) * 100.0;
}


