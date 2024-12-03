//
// Created by Kareem Elnaghy on 12/2/24.
//

#include <iostream>
#include <cmath>
#include <unordered_set>
using namespace std;

int substringLength = 3;
int base = 257;
int mod = 1e9 + 7;

// function that computes the initial hash value of string of 'length'
unsigned long long initialHash(const string& s, int length, int base, int mod) {
    unsigned long long hash = 0;
    for (int i = 0; i < length; i++) {
        hash = (hash * base + s[i]) % mod;
    }
    return hash;
}

// function that computes the hash value of the string after rolling the window by reusing the previous hash value
unsigned long long rollHash(unsigned long long oldHash, char oldChar, char newChar, int base, int mod, unsigned long long basePower) {
    oldHash = (oldHash * base + newChar - oldChar * basePower % mod + mod) % mod;
    return oldHash;
}

int calculateCommonSubstringLength(const string& s1, const string& s2, int length, int base, int mod) {
    unordered_set<unsigned long long> matchedHashes; // to store the matched hashes
    int matchLength = 0;

    if (s1.size() < length || s2.size() < length) { // if the strings are smaller than the length of the substring
        return 0;
    }

    unsigned long long basePower = 1;
    for (int i = 1; i < length; i++) {
        basePower = (basePower * base) % mod;
    }

    // compute initial hashes for s1
    unordered_set<unsigned long long> s1Hashes; // stores the hashes of s1
    unsigned long long hashS1 = initialHash(s1, length, base, mod);
    s1Hashes.insert(hashS1);
    for (int i = 1; i <= s1.size() - length; i++) { // loop that computes the hash values of s1 and stores them all
        hashS1 = rollHash(hashS1, s1[i - 1], s1[i + length - 1], base, mod, basePower);
        s1Hashes.insert(hashS1);
    }

    // compute initial hash for s2 and check for matches, repeat as hash s1
    unsigned long long hashS2 = initialHash(s2, length, base, mod);
    if (s1Hashes.find(hashS2) != s1Hashes.end()) { // check if this hash matches any of the hashes of s1
        matchedHashes.insert(hashS2);
        matchLength += length;  // add it to the length
    }

    for (int j = 1; j <= s2.size() - length; j++) { // loop that computes the hash values of s2 and checks for matches
        hashS2 = rollHash(hashS2, s2[j - 1], s2[j + length - 1], base, mod, basePower);
        if (s1Hashes.find(hashS2) != s1Hashes.end() && matchedHashes.find(hashS2) == matchedHashes.end()) {
            matchedHashes.insert(hashS2);
            matchLength += length;
        }
    }

    return matchLength;
}

double calcPercentageTC(const string& source, const string& target) {
    int matchLength = calculateCommonSubstringLength(source, target, substringLength, base, mod);

    double percentage = (static_cast<double>(matchLength) / source.size()) * 100.0;
    return min(percentage, 100.0);
}