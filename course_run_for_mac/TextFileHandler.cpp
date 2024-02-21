#include "TextFileHandler.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <functional>

TextFileHandler::TextFileHandler(const std::string& path, bool caseFlag, char ignoreChar)
    : path(path), fileOpenedSuccessfully(false), caseFlag(caseFlag), ignoreChar(ignoreChar) {}

bool TextFileHandler::openFile() {
    std::ifstream file(path);
    if (file.is_open()) {
        std::cout << "File opened successfully.\n";

        std::string line;
        while (getline(file, line)) {
            fileContent += line + "\n";
        }

        file.close();
        fileOpenedSuccessfully = true;
        return true;
    }
    else {
        std::cerr << "\n\tUnable to open file: " << path << std::endl;
        fileOpenedSuccessfully = false;
        return false;
    }
}

void TextFileHandler::printErrorMessage() const {
    std::cerr << "\n\tCannot get file content. Try to reload the file\n";
}

void TextFileHandler::setCaseSensitive(bool value) {
    caseFlag = value;
}

bool TextFileHandler::getCaseSensitive() {
    return caseFlag;
}

void TextFileHandler::setIgnoreChar(char value) {
    ignoreChar = value;
}

const std::string& TextFileHandler::getFileContent() const {
    if (!fileOpenedSuccessfully) {
        printErrorMessage();
        return "";
    }

    return fileContent;
}

int TextFileHandler::countUniqueWords() const {
    if (!fileOpenedSuccessfully) {
        printErrorMessage();
        return 0;
    }

    std::istringstream iss(fileContent);
    std::unordered_set<std::string> uniqueWords;
    std::string word;

    while (iss >> word) {
        if (!caseFlag) {
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        }

        if (ignoreChar != '\0' && word.find(ignoreChar) != std::string::npos) {
            continue;
        }

        uniqueWords.insert(word);
    }

    return static_cast<int>(uniqueWords.size());
}

int TextFileHandler::countSentences() const {
    if (!fileOpenedSuccessfully) {
        printErrorMessage();
        return 0;
    }

    std::istringstream iss(fileContent);
    int sentenceCount = 0;
    std::string line;

    while (getline(iss, line)) {
        std::istringstream lineStream(line);
        std::string word;

        while (lineStream >> word) {
            if (word.find('.') != std::string::npos ||
                word.find('!') != std::string::npos ||
                word.find('?') != std::string::npos) {
                sentenceCount++;
            }
        }
    }

    return sentenceCount;
}

std::vector<std::pair<std::string, int> > TextFileHandler::getWordFrequency() const {
    if (!fileOpenedSuccessfully) {
        printErrorMessage();
        return {};
    }

    std::istringstream iss(fileContent);
    std::unordered_map<std::string, int> wordFrequency;
    std::string word;

    while (iss >> word) {
        if (!caseFlag) {
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        }

        if (ignoreChar != '\0' && word.find(ignoreChar) != std::string::npos) {
            continue;
        }

        word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
        wordFrequency[word]++;
    }

    std::vector<std::pair<std::string, int> > sortedFrequency(
        wordFrequency.begin(), wordFrequency.end());

    std::sort(sortedFrequency.begin(), sortedFrequency.end(),
        [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

    return sortedFrequency;
}

std::vector<std::pair<std::string, int> > TextFileHandler::getWordLengthRanking() const {
    if (!fileOpenedSuccessfully) {
        printErrorMessage();
        return {};
    }

    std::istringstream iss(fileContent);
    std::unordered_map<std::string, int> wordLength;
    std::string word;

    while (iss >> word) {
        if (!caseFlag) {
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        }

        if (ignoreChar != '\0' && word.find(ignoreChar) != std::string::npos) {
            continue;
        }

        word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
        wordLength[word] = word.length();
    }

    std::vector<std::pair<std::string, int> > sortedLength(
        wordLength.begin(), wordLength.end());

    std::sort(sortedLength.begin(), sortedLength.end(),
        [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

    return sortedLength;
}
