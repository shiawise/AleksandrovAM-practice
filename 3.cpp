#include <iostream>
#include <iomanip>
#include <cmath>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");

    double a_values[] = { 1.2, 1.3, 1.4, 1.5, 1.6 };
    int num_a = sizeof(a_values) / sizeof(a_values[0]);
    const double PI = 3.14159265358979323846;

    for (int i = 0; i < num_a; ++i) {
        double a = a_values[i];
        cout << "Таблица для a = " << fixed << setprecision(1) << a << endl;
        cout << setw(10) << "x" << setw(15) << "y(x)" << endl;

        for (double x = -4.0; x <= 4.0; x += 0.3) {
            double y;
            if (x < 0) {
                y = sin(x) + a;
            }
            else if (x <= 2) {
                y = cos(PI * x);
            }
            else {
                y = a * a + x * x;
            }

            cout << fixed << setprecision(1) << setw(10) << x;
            cout << fixed << setprecision(6) << setw(15) << y << endl;
        }

        cout << endl;
    }

    return 0;
}