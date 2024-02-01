#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;


class TextFileHandler {
private:
    string path;
    string fileContent;

public:
    TextFileHandler(const string& path) : path(path) {}

    bool openFile() {
        ifstream file(path);
        if (file.is_open()) {
            cout << "File opened successfully.\n";

            string line;
            while (getline(file, line)) {
                fileContent += line + "\n";
            }

            file.close();
            return true;
        }
        else {
            cerr << "Unable to open file: " << path << endl;
            return false;
        }
    }

    const string& getFileContent() const {
        return fileContent;
    }

    int countUniqueWords() const {
        istringstream iss(fileContent);
        unordered_set<string> uniqueWords;
        string word;

        while (iss >> word) {
            uniqueWords.insert(word);
        }

        return static_cast<int>(uniqueWords.size());
    }

    int countSentences() const {
        istringstream iss(fileContent);
        int sentenceCount = 0;
        string line;

        while (getline(iss, line)) {
            istringstream lineStream(line);
            string word;

            while (lineStream >> word) {
                if (word.find('.') != string::npos ||
                    word.find('!') != string::npos ||
                    word.find('?') != string::npos) {
                    sentenceCount++;
                }
            }
        }

        return sentenceCount;
    }

    vector<pair<string, int>> getWordFrequency() const {
        istringstream iss(fileContent);
        unordered_map<string, int> wordFrequency;
        string word;

        while (iss >> word) {
            word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            wordFrequency[word]++;
        }

        vector<pair<string, int>> sortedFrequency(
            wordFrequency.begin(), wordFrequency.end());

        sort(sortedFrequency.begin(), sortedFrequency.end(),
            [](const auto& a, const auto& b) {
                return a.second > b.second;
            });

        return sortedFrequency;
    }

    vector<pair<string, int>> getWordLengthRanking() const {
        istringstream iss(fileContent);
        unordered_map<string, int> wordLength;
        string word;

        while (iss >> word) {
            word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            wordLength[word] = word.length();
        }

        vector<pair<string, int>> sortedLength(
            wordLength.begin(), wordLength.end());

        sort(sortedLength.begin(), sortedLength.end(),
            [](const auto& a, const auto& b) {
                return a.second > b.second;
            });

        return sortedLength;
    }
};;

int main() {
    string filePath;
    TextFileHandler fileHandler("");
    int count = 0;

    while (true) {
        cout << "\n\nMenu:\n";
        cout << "1. Get new file\n";
        cout << "2. Open file\n";
        cout << "3. Count unique words\n";
        cout << "4. Count Sentences\n";
        cout << "5. Word Frequency. Top 10\n";
        cout << "6. Word Length Ranking. Top 10\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

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
            int uniqueWordsCount = fileHandler.countUniqueWords();
            cout << "\nNumber of unique words in the file: " << uniqueWordsCount << endl;
            break;
        }
        case 4: {
            int sentenceCount = fileHandler.countSentences();
            cout << "\nNumber of Sentences: " << sentenceCount << endl;
            break;
        }
        case 5: {
            count = 0;
            auto wordFrequency = fileHandler.getWordFrequency();
            cout << "\nWord Frequency. Top 10:\n";
            for (const auto& pair : wordFrequency) {
                if (count <= 10) {
                    cout << "\t" + pair.first << ": " << pair.second << endl;
                    count++;
                }
                else {
                    break;
                }
            }
            break;
        }
        case 6: {
            count = 0;
            auto wordLengthRanking = fileHandler.getWordLengthRanking();
            cout << "\nWord Length Ranking. Top 10:\n";
            for (const auto& pair : wordLengthRanking) {
                if (count <= 10) {
                    cout << "\t" + pair.first << ": " << pair.second << endl;
                    count++;
                }
                else {
                    break;
                }
            }
            break;
        }
        case 7: {
            cout << "\nExiting the program.\n";
            return 0;
        }
        default:
            cout << "\nInvalid character: " << choice << endl;
        }
    }

    return 0;
}
