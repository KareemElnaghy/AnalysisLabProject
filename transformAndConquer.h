//
// Created by Kareem Elnaghy on 12/2/24.
//

#ifndef ANALYSISLABPROJECT_TRANSFORMANDCONQUER_H
#define ANALYSISLABPROJECT_TRANSFORMANDCONQUER_H
int substringLength = 3;

#include <iostream>
#include <cmath>
#include <unordered_set>
using namespace std;

// Function to compute the hash of a substring using rolling hash
unsigned long long computeHash(const string& s, int start, int length, int base, int mod) {
    unsigned long long hash = 0;
    for (int i = start; i < start + length; i++) {
        hash = (hash * base + s[i]) % mod;
    }
    return hash;
}

// Function to calculate the length of the longest common substring
int calculateCommonSubstringLength(const string& s1, const string& s2, int length, int base, int mod) {
    unordered_set<unsigned long long> matchedHashes;
    int matchLength = 0;

    // Iterate over all substrings of the given length in s1
    for (int i = 0; i <= s1.size() - length; i++) {
        unsigned long long hashS1 = computeHash(s1, i, length, base, mod);

        // Check for matching substrings in s2
        for (int j = 0; j <= s2.size() - length; j++) {
            unsigned long long hashS2 = computeHash(s2, j, length, base, mod);

            // If a match is found and it hasn't been counted yet, mark it
            if (hashS1 == hashS2 && matchedHashes.find(hashS1) == matchedHashes.end()) {
                matchedHashes.insert(hashS1);
                matchLength += length;
            }
        }
    }

    return matchLength;
}

// Function to calculate plagiarism percentage (with adjusted matching logic)
double calculatePlagiarismPercentageTC(const string& source, const string& target) {
    // Calculate total match length while avoiding double counting
    int matchLength = calculateCommonSubstringLength(source, target, substringLength, 257, 1e9 + 7);

    // Prevent percentages over 100%
    double percentage = (static_cast<double>(matchLength) / source.size()) * 100.0;
    return min(percentage, 100.0); // Ensure it doesn't exceed 100%
}


#endif //ANALYSISLABPROJECT_TRANSFORMANDCONQUER_H
