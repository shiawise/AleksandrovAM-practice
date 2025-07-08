#include <iostream>
#include <locale>
#include <string>
using namespace std;

int countCharInString(const string& str, char target) {
    int count = 0;
    for (char c : str) {
        if (c == target) {
            count++;
        }
    }
    return count;
}

int main() {
    setlocale(LC_CTYPE, "Russian");

    string inputString;
    char searchChar;

    cout << "Введите строку: ";
    getline(cin, inputString);

    cout << "Введите символ для поиска: ";
    cin >> searchChar;

    int occurrences = countCharInString(inputString, searchChar);
    cout << "Символ '" << searchChar << "' встречается " << occurrences << " раз(а)" << endl;

    return 0;
}