#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <cctype>

using namespace std;

string transformString(const string& input) {
    string result;
    for (char c : input) {
        if (isalpha(c)) {
            result += c;
            result += c;
        }
        else {
            result += c;
        }
    }
    return result;
}

int main() {
    setlocale(LC_CTYPE, "Russian");

    ifstream inFile("F1.txt");
    if (!inFile.is_open()) {
        cerr << "Ошибка: файл F1.txt не найден или не открыт." << endl;
        return 1; 
    }

    ofstream outFile("F2.txt");
    if (!outFile.is_open()) {
        cerr << "Ошибка: не удалось создать F2.txt." << endl;
        return 1;
    }

    string line;
    while (getline(inFile, line)) {
        string transformed = transformString(line);
        outFile << transformed << endl;
    }

    inFile.close();
    outFile.close();

    cout << "Готово! Результат записан в F2.txt." << endl;
    return 0;
}