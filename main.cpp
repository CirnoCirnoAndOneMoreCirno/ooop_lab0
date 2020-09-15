#include "Parser.h"


int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        Parser newParser(argv[1], argv[2]);
        newParser.openFileStreams();
        newParser.readStringsAndFillMap();
        newParser.makeCsvTable();
        newParser.closeFileStreams();
    }
    else
        cout
        << "Wrong arguments! Use: \n"
        <<">word_count.exe input.txt output.csv"
        <<endl;


}