#include <iostream>
#include <locale>
using namespace std;

int sumArray(int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i)
        sum += arr[i];
    return sum;
}

void processMatrix(int** matrix, int n, int m) {
    for (int i = 0; i < n; ++i) {
        int sum = sumArray(matrix[i], m);
        matrix[i][m] = sum;
    }
}

int main() {
    setlocale(LC_CTYPE, "Russian");

    int n, m;
    cout << "Введите количество строк (n): ";
    cin >> n;
    cout << "Введите количество столбцов (m): ";
    cin >> m;

    int** matrix = new int* [n];
    for (int i = 0; i < n; ++i)
        matrix[i] = new int[m + 1];

    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> matrix[i][j];

    processMatrix(matrix, n, m);

    cout << "Результат:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= m; ++j)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }

    for (int i = 0; i < n; ++i)
        delete[] matrix[i];
    delete[] matrix;

    return 0;
}