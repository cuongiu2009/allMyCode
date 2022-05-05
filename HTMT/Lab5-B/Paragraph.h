#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
using namespace std;
class StatisticParagraph
{
private:
    string LinkFile;
    vector<string> Paragraph;
    int NumberOfLine;
public:
    StatisticParagraph(string File);
    StatisticParagraph();
    ~StatisticParagraph();
    void ReadFile();
    int CountWordInParagraph(string word);
};