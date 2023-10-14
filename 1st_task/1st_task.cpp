//g++ 1st_task.cpp -o 1st_task.exe

#include <iostream>
#include <string>
#include <limits>
using namespace std;

bool belongsToInterval(int x, int top, int bottom) {
    return (x >= bottom && x <= top);
}

int minValueInt(int intValue1, int intValue2) {
    return (intValue1 < intValue2) ? intValue1 : intValue2;
}

float minValueFloat(float floatValue1, float floatValue2) {
    return (floatValue1 < floatValue2) ? floatValue1 : floatValue2;
}

int getLetterCode(char anySymbol) {
    return static_cast<int>(anySymbol);
}

int countIntPlaces(int randomNumber) {
    string numString = to_string(randomNumber);
    return numString.length();
}

void showTypeInfo() {
    cout << "Размер типа char: " << sizeof(char) << " байт" << endl;
    cout << "Максимальное значение для char: " << CHAR_MAX << endl;
    cout << "Минимальное значение для char: " << CHAR_MIN << endl << endl;

    cout << "Размер типа int: " << sizeof(int) << " байт" << endl;
    cout << "Максимальное значение для int: " << INT_MAX << endl;
    cout << "Минимальное значение для int: " << INT_MIN << endl << endl;

    cout << "Размер типа short: " << sizeof(short) << " байт" << endl;
    cout << "Максимальное значение для short: " << SHRT_MAX << endl;
    cout << "Минимальное значение для short: " << SHRT_MIN << endl << endl;

    cout << "Размер типа long: " << sizeof(long) << " байт" << endl;
    cout << "Максимальное значение для long: " << LONG_MAX << endl;
    cout << "Минимальное значение для long: " << LONG_MIN << endl << endl;

    cout << "Размер типа long long: " << sizeof(long long) << " байт" << endl;
    cout << "Максимальное значение для long long: " << LLONG_MAX << endl;
    cout << "Минимальное значение для long long: " << LLONG_MIN << endl << endl;
}

int main()
{

    char function_choice = '\0';

    while (function_choice != 't' && function_choice != 'b' && function_choice != 'c' && function_choice != 'o' && function_choice != 'i' && function_choice != 'f' && function_choice != 'e')
    {
        cout << "\n\nMENU\n\nSelect function:\n"
            "\t\'b\' - belongsToInterval\n"
            "\t\'t\' - showTypeInfo\n"
            "\t\'c\' - getLetterCode\n"
            "\t\'o\' - order\n"
            "\t\'i\' - minValueInt\n"
            "\t\'f\' - minValueFloat\n"
            "\t\'e\' - exit from menu\n"
            "Your choice: ";
        cin >> function_choice;

        switch (function_choice)
        {
        case 'b':
            int x, top, bottom;
            cout << "x number: "; cin >> x;
            cout << "top number: "; cin >> top;
            cout << "bottom number: "; cin >> bottom;

            if (belongsToInterval(5,10,1)) {
                cout << x << " in the interval between " << bottom << " and " << top << endl;
            }

            break;
        case 'i':
            int intValue1, intValue2;
            cout << "intValue1: "; cin >> intValue1;
            cout << "intValue2: "; cin >> intValue2;

            cout << "Minimal value: " << minValueInt(intValue1, intValue2) << endl;
            break;
        case 'c':
            char anySymbol;
            cout << "Enter any character: "; cin >> anySymbol;

            cout << "Numeric value of the symbol: " << getLetterCode(anySymbol) << endl;
            break;
        case 'o':
            float randomNumber;
            cout << "Enter any int value: "; cin >> randomNumber;

            cout << "Number order " << countIntPlaces(randomNumber) << endl;
            break;
        case 'f':
            float floatValue1, floatValue2;
            cout << "floatValue1: "; cin >> floatValue1;
            cout << "floatValue2: "; cin >> floatValue2;

            cout << "Minimal value: " << minValueFloat(floatValue1, floatValue2) << endl;
            break;
        case 't':
            showTypeInfo();
            break;
        case 'e':
            cout << "Exiting the program" << endl;
            break;
        default:
            cout << "\nInvalid character: " << function_choice << endl;
            break;
        }
    }
    return 0;
}