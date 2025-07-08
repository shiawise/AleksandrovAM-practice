#include <iostream>
#include <locale>
using namespace std;

void inputArray(int* arr, int size) {
    for (int i = 0; i < size; ++i)
        cin >> arr[i];
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

void deleteMaxNegative(int* arr, int& size) {
    int maxNeg = 0;
    bool found = false;
    for (int i = 0; i < size; ++i)
        if (arr[i] < 0 && (!found || arr[i] > maxNeg)) {
            maxNeg = arr[i];
            found = true;
        }

    if (!found) return;

    int newSize = 0;
    for (int i = 0; i < size; ++i)
        if (arr[i] != maxNeg)
            arr[newSize++] = arr[i];
    size = newSize;
}

int main() {
    setlocale(LC_CTYPE, "Russian");
    const int max_size = 10;
    int arr[max_size];
    int size;

    cout << "Введите размер массива: ";
    cin >> size;

    cout << "Введите элементы массива: ";
    inputArray(arr, size);

    cout << "Исходный массив: ";
    printArray(arr, size);

    deleteMaxNegative(arr, size);

    cout << "Массив после удаления наибольшего из отрицательных элементов: ";
    printArray(arr, size);
    return 0;
}