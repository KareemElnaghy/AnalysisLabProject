//
// Created by Kareem Elnaghy on 12/2/24.
//

#include <iostream>
#include <cmath>
#include <unordered_set>
using namespace std;

int substringLength = 3;

// Function to compute the initial hash of a substring
unsigned long long computeInitialHash(const string& s, int length, int base, int mod) {
    unsigned long long hash = 0;
    for (int i = 0; i < length; i++) {
        hash = (hash * base + s[i]) % mod;
    }
    return hash;
}

// Function to update the hash using rolling hash technique
unsigned long long rollHash(unsigned long long oldHash, char oldChar, char newChar, int base, int mod, unsigned long long basePower) {
    oldHash = (oldHash * base + newChar - oldChar * basePower % mod + mod) % mod;
    return oldHash;
}

// Function to calculate the length of the longest common substring
int calculateCommonSubstringLength(const string& s1, const string& s2, int length, int base, int mod) {
    unordered_set<unsigned long long> matchedHashes;
    int matchLength = 0;

    if (s1.size() < length || s2.size() < length) {
        return 0;
    }

    unsigned long long basePower = 1;
    for (int i = 1; i < length; i++) {
        basePower = (basePower * base) % mod;
    }

    // Compute initial hashes for s1
    unordered_set<unsigned long long> s1Hashes;
    unsigned long long hashS1 = computeInitialHash(s1, length, base, mod);
    s1Hashes.insert(hashS1);
    for (int i = 1; i <= s1.size() - length; i++) {
        hashS1 = rollHash(hashS1, s1[i - 1], s1[i + length - 1], base, mod, basePower);
        s1Hashes.insert(hashS1);
    }

    // Compute initial hash for s2 and check for matches
    unsigned long long hashS2 = computeInitialHash(s2, length, base, mod);
    if (s1Hashes.find(hashS2) != s1Hashes.end()) {
        matchedHashes.insert(hashS2);
        matchLength += length;
    }
    for (int j = 1; j <= s2.size() - length; j++) {
        hashS2 = rollHash(hashS2, s2[j - 1], s2[j + length - 1], base, mod, basePower);
        if (s1Hashes.find(hashS2) != s1Hashes.end() && matchedHashes.find(hashS2) == matchedHashes.end()) {
            matchedHashes.insert(hashS2);
            matchLength += length;
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