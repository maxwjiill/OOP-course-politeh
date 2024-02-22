#include "InputUtils.h"
#include <iostream>

bool InputUtils::getCaseFlagFromUser() {
    bool caseFlag;
    std::cout << "Do you want to take the case of the text into account when analyzing? (1 - yes, 0 - no): ";
    std::cin >> caseFlag;
    return caseFlag;
}

char InputUtils::getIgnoreChar(bool value) {
    bool caseIgnoreChar;
    std::cout << "Do you want to exclude words with a certain character from processing? (1 - yes, 0 - no): ";
    std::cin >> caseIgnoreChar;

    if (caseIgnoreChar) {
        char ignoreChar;
        std::cout << "Type any specific character: ";
        std::cin >> ignoreChar;
        if (value) {
            return ignoreChar;
        }
        else {
            return tolower(ignoreChar);
        }
    }
    return '\n';
}

bool InputUtils::getSaveOption() {
    bool saveOption;
    std::cout << "\nDo you want to save the word frequency list? (1 - Yes, 0 - No): ";
    std::cin >> saveOption;
    return saveOption;
}
