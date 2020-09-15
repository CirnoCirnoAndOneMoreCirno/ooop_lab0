#include "Parser.h"


bool pairsCmp(pair <string, int>& p1,  pair <string, int>& p2)
{
    return p1.second > p2.second;
}

bool isAllowedSymbol(char sym)
{
    return isdigit(sym) || isalpha(sym);
}

void Parser::openFileStreams()
{
    inputFile.open(inputFileName);
    outputFile.open(outputFileName);
    if (!inputFile.is_open())
    {
        cout<<"Some problems with input file" << endl;
        exit(1);
    }
    if (!outputFile.is_open())
    {
        cout<<"Some problems with output file" << endl;
        exit(1);
    }
}

void Parser::closeFileStreams()
{
    inputFile.close();
    outputFile.close();
}


void Parser::readStringsAndFillMap()
{
    string currString, currWord;
    int currStringLen = 0;
    bool isWordStringEmpty = true;

    while(getline(inputFile, currString, '\n'))
    {
        currStringLen = currString.length();
        for (int i = 0; i < currStringLen; ++i)
        {
            if (isAllowedSymbol(currString[i]))
            {
                isWordStringEmpty = false;
                currWord += currString[i];
            }
            else if (!isWordStringEmpty)
            {
                wordCounter[currWord]++;
                totalWordsCount++;
                currWord.clear();
                isWordStringEmpty = true;
            }
        }
        if (!isWordStringEmpty)
        {
            wordCounter[currWord]++;
            totalWordsCount++;
            currWord.clear();
            isWordStringEmpty = true;
        }
        }
    }




void Parser::makeCsvTable()
{
    vector < pair<string, int> > sortedMap;
    map <string, int> :: iterator it;
    for (it = wordCounter.begin(); it != wordCounter.end(); it++)
    {
        sortedMap.push_back(make_pair(it->first, it->second));
    }

    sort(sortedMap.begin(), sortedMap.end(), pairsCmp);

    double percentage;
    for(int i = 0; i < sortedMap.size(); i++)
    {
        percentage = (100.0*sortedMap[i].second/totalWordsCount);
        outputFile<< sortedMap[i].first <<DIVEDER<< sortedMap[i].second << DIVEDER << percentage << DIVEDER <<endl;
    }

}