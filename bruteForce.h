//
// Created by Kareem ELnaghy on 12/2/2024.
//
// Plagiarism Detection

#include <iostream>
#include <vector>
using namespace std;

// Function to find the longest common substring using brute force
int longestCommonSubstringBruteForce(const string& source, const string& target) {
    int maxLength = 0;
    int sourceLen = source.size();
    int targetLen = target.size();

    for (int i = 0; i < sourceLen; ++i) {
        for (int j = 0; j < targetLen; ++j) {
            int length = 0;
            while (i + length < sourceLen && j + length < targetLen && source[i + length] == target[j + length]) {
                length++;
            }
            maxLength = max(maxLength, length);
        }
    }

    return maxLength;
}

// Function to calculate the plagiarism percentage using brute force
double calculatePlagiarismPercentageBF(const string& source, const string& target) {
    int matchLength = longestCommonSubstringBruteForce(source, target);
    if (matchLength == 0)
        return 0;
    return (static_cast<double>(matchLength) / source.size()) * 100.0;
}


