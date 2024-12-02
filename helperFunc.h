////
//// Created by Kareem Elnaghy on 12/2/24.
////
//
//#ifndef ANALYSISLABPROJECT_HELPERFUNC_H
//#define ANALYSISLABPROJECT_HELPERFUNC_H
//
//#include <iostream>
//#include <fstream>
//using namespace std;
//
//bool readFile(string path1, string path2, string &doc1, string &doc2)   // function to read the files
//{
//    ifstream file1(path1);
//    ifstream file2(path2);
//    if(file1.is_open() && file2.is_open())
//    {
//        string line;
//        while(getline(file1,line))
//        {
//            doc1 += line + "\n";
//        }
//        file1.close();
//
//        line = "";
//        while(getline(file2,line))
//        {
//            doc2 += line + "\n";
//        }
//        file2.close();
//    }
//    else
//    {
//        cout << "Unable to open file";
//        return false;
//    }
//
//
//    return true;
//}
//
//string cleanDocument(const string& text) { // function to clean the text from any special characters
//    string cleanedText;
//    for (char ch : text) {
//        if (isalpha(ch)) {
//            cleanedText += ch;
//        }
//    }
//    return cleanedText;
//}
//
//
//#endif //ANALYSISLABPROJECT_HELPERFUNC_H
