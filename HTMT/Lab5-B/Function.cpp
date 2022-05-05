#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include"Paragraph.h"
StatisticParagraph::StatisticParagraph() {
    this->LinkFile = "";
    this->NumberOfLine = 0;
}
StatisticParagraph::~StatisticParagraph() {
}
StatisticParagraph::StatisticParagraph(string File) {
    this->NumberOfLine = 0;
    this->LinkFile = File;
    ifstream File_read(File);
    if (File_read.is_open()) {
        string line;
        while (getline(File_read, line)) {
            this->Paragraph.resize(NumberOfLine + 1);
            this->Paragraph[this->NumberOfLine] = line;
            this->NumberOfLine++;
        }
    }
    File_read.close();
}
void StatisticParagraph::ReadFile() {
    for (int i = 0; i < this->NumberOfLine; i++) {
        cout << this->Paragraph[i] << endl;
    }
}
int StatisticParagraph::CountWordInParagraph(string word) {
    int count = 0;
    for (int i = 0; i < this->NumberOfLine; i++) {
        string TempStr = this->Paragraph[i];
        while (TempStr.find(word) != string::npos) {
            if (TempStr[TempStr.find(word) + word.length()] == ' ' || TempStr[TempStr.find(word) + word.length()] == '.' || TempStr[TempStr.find(word) + word.length()] == '?' || TempStr[TempStr.find(word) + word.length()] == '!' || TempStr[TempStr.find(word) + word.length()] == ',') {
                count++;
                if (TempStr.find(word) != 0 && TempStr[TempStr.find(word) - 1] != ' ') {
                    count--;
                }
            }
            TempStr.replace(TempStr.find(word), word.length(), "");
        }
    }
    return count;
}