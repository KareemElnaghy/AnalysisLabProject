//
// Created by Kareem ELnaghy on 12/2/2024.
//
// Plagiarism Detection

#include <iostream>
#include <vector>
using namespace std;

// function that implements the brute force algorithm to find the longest common substring
int longestCommonSubstringBruteForce(const string& source, const string& target) {
    int maxLength = 0;
    int sourceLen = source.size();
    int targetLen = target.size();

    for (int i = 0; i < sourceLen; i++) {   // loop through the source string
        for (int j = 0; j < targetLen; j++) {   // loop through the target string
            int length = 0;
            while (i + length < sourceLen && j + length < targetLen && source[i + length] == target[j + length]) {
                length++;   // increment the length of the common substring
            }
            maxLength = max(maxLength, length); // update the maximum length
        }
    }

    return maxLength;
}

// function that calculates the plagiarism percentage
double calcPercentageBF(const string& source, const string& target) {
    int matchLength = longestCommonSubstringBruteForce(source, target);
    if (matchLength == 0)
        return 0;
    return (static_cast<double>(matchLength) / source.size()) * 100.0;
}


