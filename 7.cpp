#include <iostream>
#include <locale>
using namespace std;

void analyzeResults(int* scores, int size, int& excellent, int& good, int& satisfactory) {
    excellent = 0;
    good = 0;
    satisfactory = 0;
    for (int i = 0; i < size; ++i) {
        if (scores[i] >= 90) excellent++;
        else if (scores[i] >= 75) good++;
        else satisfactory++;
    }
}

int main() {
    setlocale(LC_CTYPE, "Russian");
    const int size = 40;
    int scores[size] = { 85, 92, 78, 65, 95, 88, 72, 60, 98, 82,
                       77, 68, 93, 84, 70, 97, 89, 73, 62, 96,
                       83, 76, 67, 94, 81, 74, 64, 91, 86, 79,
                       71, 63, 90, 87, 80, 75, 69, 61, 99, 66 };

    int excellent, good, satisfactory;
    analyzeResults(scores, size, excellent, good, satisfactory);

    cout << "Отлично: " << excellent << " разбойников" << endl;
    cout << "Хорошо: " << good << " разбойников" << endl;
    cout << "Посредственно: " << satisfactory << " разбойников" << endl;

    return 0;
}