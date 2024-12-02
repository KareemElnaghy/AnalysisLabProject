//
// Created by Kareem Elnaghy on 12/2/24.
//

#include <iostream>
#include <fstream>
#include <chrono>
#include "bruteForce.h"
#include "dpAlgorithm.h"
#include "transformAndConquer.h"
using namespace std;

bool readFile(string path1, string path2, string &doc1, string &doc2)   // function to read the files
{
    ifstream file1(path1);
    ifstream file2(path2);
    if(file1.is_open() && file2.is_open())
    {
        string line;
        while(getline(file1,line))
        {
            doc1 += line + "\n";
        }
        file1.close();

        line = "";
        while(getline(file2,line))
        {
            doc2 += line + "\n";
        }
        file2.close();
    }
    else
    {
        return false;
    }


    return true;
}

string cleanDocument(const string& text) { // function to clean the text from any special characters
    string cleanedText;
    for (char ch : text) {
        if (isalpha(ch)) {
            cleanedText += ch;
        }
    }
    return cleanedText;
}

int main()
{
    string doc1, doc2;
    string path1 = "/Users/mac/Desktop/AnalysisLabProject/doc1.txt";
    string path2 = "/Users/mac/Desktop/AnalysisLabProject/doc2.txt";

    if(readFile(path1, path2, doc1, doc2))
    {
        cleanDocument(doc1);
        cleanDocument(doc2);

        auto start = std::chrono::high_resolution_clock::now();
        cout<<"% using BF: "<<calculatePlagiarismPercentageBF(doc1, doc2)<<endl;
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = duration_cast<std::chrono::microseconds>(end - start);
        cout<<duration.count()<<endl;

        cout<<"% using DP: "<<calculatePlagiarismPercentageDP(doc1, doc2)<<endl;
        cout<<"% using TC: "<<calculatePlagiarismPercentageTC(doc1, doc2)<<endl;
    }
    else
    {
        cout << "Unable to open file";
        return 0;
    }
}