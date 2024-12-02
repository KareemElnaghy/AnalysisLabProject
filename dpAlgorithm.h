//
// Created by Kareem Elnaghy on 12/2/24.
//
#ifndef ANALYSISLABPROJECT_DPALGORITHM_H
#define ANALYSISLABPROJECT_DPALGORITHM_H

#include <iostream>
#include <vector>
using namespace std;

// Dynamic Programming approach to calculate the longest common substring
int longestCommonSubstring(const string& source, const string& target) {
    int n = source.size();
    int m = target.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // DP table

    int maxLength = 0; // To track the longest common substring length

    // Fill the DP table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (source[i - 1] == target[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                maxLength = max(maxLength, dp[i][j]);
            }
        }
    }

    return maxLength;
}

// Function to calculate the plagiarism percentage
double calculatePlagiarismPercentageDP(const string& source, const string& target) {
    int matchLength = longestCommonSubstring(source, target);
    if(matchLength == 0)
        return 0;
    return (static_cast<double>(matchLength) / source.size()) * 100.0;
}
#endif //ANALYSISLABPROJECT_DPALGORITHM_H
