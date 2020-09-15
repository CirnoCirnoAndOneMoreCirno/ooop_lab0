//
// Created by Andrew on 004 04.09.20.
//
#pragma once


#include <map>
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#define DIVEDER ';'

#ifndef LAB0_PARSER_H
#define LAB0_PARSER_H

using namespace std;

bool pairsCmp(pair <string, int>& p1,  pair <string, int>& p2);
bool isAllowedSymbol(char sym);

class Parser
{
private:
    ifstream inputFile;
    ofstream outputFile;
    string inputFileName;
    string outputFileName;
    unsigned long long int totalWordsCount;
    map<string, int> wordCounter;
public:

    Parser(const string &argv1, const string &argv2)
    {
        inputFileName = argv1;
        outputFileName = argv2;
        totalWordsCount = 0;
    }
    void openFileStreams();
    void closeFileStreams();
    void readStringsAndFillMap();
    void makeCsvTable();
};


#endif //LAB0_PARSER_H
