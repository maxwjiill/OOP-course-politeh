//C:\Users\Professional\Documents\git\OOP-course-politeh\course-work_Development-of-a-text-file-analyzer\upperRegister.txt
//g++ -std=c++14 course-work_Development-of-a-text-file-analyzer.cpp TextFileHandler.cpp -o course-work_Development-of-a-text-file-analyzer

#include "TextFileHandler.h"
#include "InputUtils.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    string filePath;
    TextFileHandler fileHandler("");
    int count = 0;

    while (true) {
        cout << "\n\nMenu:\n";
        cout << "1. Get new file (reload file)\n";
        cout << "2. Open file\n";
        cout << "3. Count unique words\n";
        cout << "4. Count sentences\n";
        cout << "5. Word Frequency. Top N words\n";
        cout << "6. Word Length Ranking. Top N words\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n\tIncorrect input. Please enter a number\n";
            continue;
        }

        switch (choice) {
        case 1: {
            cout << "\nEnter path to file: ";
            cin >> filePath;
            fileHandler = TextFileHandler(filePath);
            fileHandler.openFile();
            break;
        }
        case 2: {
            cout << fileHandler.getFileContent();
            break;
        }
        case 3: {
            bool caseFlag = InputUtils::getCaseFlagFromUser();
            fileHandler.setCaseSensitive(caseFlag);

            cout << caseFlag << endl;

            char ignoreChar = InputUtils::getIgnoreChar(fileHandler.getCaseSensitive());
            if (ignoreChar != '\n') { fileHandler.setIgnoreChar(ignoreChar); }

            int uniqueWordsCount = fileHandler.countUniqueWords();
            if (uniqueWordsCount != 0) {
                cout << "\nNumber of unique words in the file: " << uniqueWordsCount << endl;
            }
            else {
                cout << "\n\tEmpty\n";
            }
            break;
        }
        case 4: {
            int sentenceCount = fileHandler.countSentences();
            if (sentenceCount != 0) {
                cout << "\nNumber of Sentences: " << sentenceCount << endl;
            }
            break;
        }
        case 5: {
            count = 0;

            bool caseFlag = InputUtils::getCaseFlagFromUser();
            fileHandler.setCaseSensitive(caseFlag);

            char ignoreChar = InputUtils::getIgnoreChar(fileHandler.getCaseSensitive());
            if (ignoreChar != '\n') { fileHandler.setIgnoreChar(ignoreChar); }

            auto wordFrequency = fileHandler.getWordFrequency();

            if (!wordFrequency.empty()) {
                int countInTheTop;
                cout << "Enter the top N words: ";
                cin >> countInTheTop;

                cout << "\nWord Frequency. Top " << countInTheTop << endl;
                for (const auto& pair : wordFrequency) {
                    if (count < countInTheTop) {
                        cout << "\t" + pair.first << ": " << pair.second << endl;
                        count++;
                    }
                    else {
                        break;
                    }
                }

                bool saveOption = InputUtils::getSaveOption();
                if (saveOption) {
                    count = 0;
                    string outputPath;
                    cout << "Enter the path: ";
                    cin >> outputPath;

                    ofstream outputFile(outputPath);
                    if (outputFile.is_open()) {
                        for (const auto& pair : wordFrequency) {
                            if (count < countInTheTop) {
                                outputFile << pair.first << ": " << pair.second << endl;
                                count++;
                            }
                        }
                        outputFile.close();
                        cout << "\nWord frequency list saved to: " << outputPath << endl;
                    }
                    else {
                        cerr << "Unable to open output file for writing." << endl;
                    }
                }
            }
            else {
                cout << "\n\tEmpty\n";
            }
            break;
        }
        case 6: {
            count = 0;

            bool caseFlag = InputUtils::getCaseFlagFromUser();
            fileHandler.setCaseSensitive(caseFlag);

            char ignoreChar = InputUtils::getIgnoreChar(fileHandler.getCaseSensitive());
            if (ignoreChar != '\n') { fileHandler.setIgnoreChar(ignoreChar); }

            auto wordLengthRanking = fileHandler.getWordLengthRanking();

            if (!wordLengthRanking.empty()) {
                int countInTheTop;
                cout << "Enter the top N words: ";
                cin >> countInTheTop;

                cout << "\nWord Length Ranking. Top " << countInTheTop << endl;

                for (const auto& pair : wordLengthRanking) {
                    if (count < countInTheTop) {
                        cout << "\t" + pair.first << ": " << pair.second << endl;
                        count++;
                    }
                    else {
                        break;
                    }
                }

                bool saveOption = InputUtils::getSaveOption();
                if (saveOption) {
                    count = 0;
                    string outputPath;
                    cout << "Enter the path: ";
                    cin >> outputPath;

                    ofstream outputFile(outputPath);
                    if (outputFile.is_open()) {
                        for (const auto& pair : wordLengthRanking) {
                            if (count < countInTheTop) {
                                outputFile << pair.first << ": " << pair.second << endl;
                                count++;
                            }
                        }
                        outputFile.close();
                        cout << "\nWord frequency list saved to: " << outputPath << endl;
                    }
                    else {
                        cerr << "Unable to open output file for writing." << endl;
                    }
                }
            }
            else {
                cout << "\n\tEmpty\n";
            }
            break;
        }
        case 7: {
            cout << "\n\tExiting the program.\n";
            return 0;
        }
        default:
            cout << "\n\tPlease enter a number from the menu" << endl;
        }
    }

    return 0;
}