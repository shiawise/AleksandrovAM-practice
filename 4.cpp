#include <iostream>
#include <iomanip>
#include <cmath>
#include <locale>

using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");

    int K;
    double current_sales = 500000.0;
    double current_cost = 55.0;
    const double sales_growth = 0.02;
    const double cost_reduction = 0.01;

    cout << "Введите количество лет (K): ";
    cin >> K;

    cout << "Год\tОбъем продаж (тыс. руб.)\tСебестоимость (руб.)" << endl;

    for (int year = 1; year <= K; ++year) {
        current_sales *= (1.0 + sales_growth);
        current_cost *= (1.0 - cost_reduction);
        cout << year << "\t" << fixed << setprecision(2) << current_sales / 1000 << "\t\t\t" << current_cost << endl;
    }

    return 0;
}