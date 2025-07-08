#include <iostream>
#include <ctime>
#include <cstdlib>
#include <locale>
using namespace std;

void generateRandomArray(int* arr, int size, int min, int max) {
    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 0; i < size; ++i)
        arr[i] = rand() % (max - min + 1) + min;
}

double calculateAverage(int* arr, int size) {
    double sum = 0;
    for (int i = 0; i < size; ++i)
        sum += arr[i];
    return sum / size;
}

void findLessThanNeighborsAverage(int* src, int srcSize, int* dest, int& destSize) {
    destSize = 0;
    for (int i = 1; i < srcSize - 1; ++i) {
        double avg = (src[i - 1] + src[i + 1]) / 2.0;
        if (src[i] < avg)
            dest[destSize++] = src[i];
    }
}

int main() {
    setlocale(LC_CTYPE, "Russian");
    const int size = 10;
    int arr[size];

    generateRandomArray(arr, size, -10, 10);
    cout << "Сгенерированный массив: ";
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;

    cout << "Среднее арифметическое: " << calculateAverage(arr, size) << endl;

    int result[size];
    int resultSize;
    findLessThanNeighborsAverage(arr, size, result, resultSize);

    cout << "Элементы меньшие среднего соседей: ";
    for (int i = 0; i < resultSize; ++i)
        cout << result[i] << " ";
    return 0;
}