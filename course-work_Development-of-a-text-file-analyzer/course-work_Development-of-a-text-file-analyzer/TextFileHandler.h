#ifndef TEXTFILEHANDLER_H
#define TEXTFILEHANDLER_H

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class TextFileHandler {
private:
    std::string path;
    std::string fileContent;
    bool fileOpenedSuccessfully;
    bool caseFlag;
    char ignoreChar;

public:
    TextFileHandler(const std::string& path, bool caseFlag = true, char ignoreChar = '\0');

    bool openFile();
    void printErrorMessage() const;
    void setCaseSensitive(bool value);
    bool getCaseSensitive();
    void setIgnoreChar(char value);
    const std::string& getFileContent() const;
    int countUniqueWords() const;
    int countSentences() const;
    std::vector<std::pair<std::string, int>> getWordFrequency() const;
    std::vector<std::pair<std::string, int>> getWordLengthRanking() const;
};

#endif
