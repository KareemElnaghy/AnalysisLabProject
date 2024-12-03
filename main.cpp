//
// Created by Kareem Elnaghy on 12/2/24.
//

#include <iostream>
#include <fstream>
#include "bruteForce.h"
#include "dpAlgorithm.h"
#include "transformAndConquer.h"
using namespace std;

string cleanDocument(const string& text) { // function to clean the text from any special characters
    string cleanedText;
    for (char ch : text) {
        if (isalpha(ch)) {
            cleanedText += ch;
        }
    }
    return cleanedText;
}

bool readFile(const string& path1, const string& path2, string& doc1, string& doc2) { // function that reads the files and stores in strings
    ifstream file1(path1);
    ifstream file2(path2);
    if (file1.is_open() && file2.is_open()) {
        string line;
        while (getline(file1, line)) {
            doc1 += line + "\n";
        }
        file1.close();

        while (getline(file2, line)) {
            doc2 += line + "\n";
        }
        file2.close();

        doc1 = cleanDocument(doc1);
        doc2 = cleanDocument(doc2);

        return true;
    } else {
        return false;
    }
}



int main()
{
    string doc1, doc2;
    string path1 = "/Users/mac/Desktop/AnalysisLabProject/doc1.txt";
    string path2 = "/Users/mac/Desktop/AnalysisLabProject/doc2.txt";
    string path3 = "/Users/mac/Desktop/AnalysisLabProject/doc3.txt";
    string path4 = "/Users/mac/Desktop/AnalysisLabProject/doc4.txt";

    if(readFile(path1, path2, doc1, doc2))
    {

        cout<<"% using BF: "<<calcPercentageBF(doc1, doc2)<<endl;
        cout<<"% using DP: "<<calcPercentageDP(doc1, doc2)<<endl;
        cout<<"% using TC: "<<calcPercentageTC(doc1, doc2)<<endl;
    }
    else
    {
        cout << "Unable to open file";
        return 0;
    }
}