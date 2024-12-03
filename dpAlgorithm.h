//
// Created by Kareem Elnaghy on 12/2/24.
//
#ifndef ANALYSISLABPROJECT_DPALGORITHM_H
#define ANALYSISLABPROJECT_DPALGORITHM_H

#include <iostream>
#include <vector>
using namespace std;

// dp approach to find the longest common substring
int longestCommonSubstring(const string& source, const string& target) {
    int n = source.size();
    int m = target.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // DP table
    //cell definition: dp[i][j] is the length of the longest common suffix of source[0..i-1] and target[0..j-1]

    int maxLength = 0; // to track the maximum length of the common substring

    // fill the DP table
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
        if (source[i - 1] == target[j - 1]) {   // if the characters match
            dp[i][j] = dp[i - 1][j - 1] + 1;    // we consider the previous characters
            maxLength = max(maxLength, dp[i][j]);
        } else {
            dp[i][j] = 0;   // if the characters don't match, we reset the length to 0
        }
    }
}
    return maxLength;
}

// Function to calculate the plagiarism percentage
double calcPercentageDP(const string& source, const string& target) {
    int matchLength = longestCommonSubstring(source, target);
    if(matchLength == 0)
        return 0;
    return (static_cast<double>(matchLength) / source.size()) * 100.0;
}
#endif //ANALYSISLABPROJECT_DPALGORITHM_H
