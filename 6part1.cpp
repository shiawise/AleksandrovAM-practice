#include <iostream>
#include <locale>
using namespace std;

void printArray(int* arr, int size) {
    cout << "Массив: [";
    for (int i = 0; i < size; ++i) {
        cout << arr[i];
        if (i < size - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int countNegatives(int* arr, int size) {
    int count = 0;
    for (int i = 0; i < size; ++i)
        if (arr[i] < 0) ++count;
    return count;
}

int findMaxNegative(int* arr, int size) {
    int maxNeg = 0;
    bool found = false;
    for (int i = 0; i < size; ++i)
        if (arr[i] < 0 && (!found || arr[i] > maxNeg)) {
            maxNeg = arr[i];
            found = true;
        }
    return found ? maxNeg : 0;
}

int main() {
    setlocale(LC_CTYPE, "Russian");

    int arr1[] = { 3, -5, -2, 8, -1, 4, -7 };
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    printArray(arr1, size1);
    cout << "Количество отрицательных элементов: " << countNegatives(arr1, size1) << endl;
    cout << "Наибольший отрицательный элемент: " << findMaxNegative(arr1, size1) << endl << endl;

    return 0;
}