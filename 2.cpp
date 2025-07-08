#include <iostream>
#include <locale>
using namespace std;

int computePosition(double a, double b, double c, double d, double x, double y) {
    return (d - b) * (x - a) - (c - a) * (y - b);
}

int main() {
    setlocale(LC_CTYPE, "Russian");
    double a, b, c, d, x1, y1, x2, y2;
    char choice;

    cout << "Введите координаты двух точек, задающих прямую (a b c d): ";
    cin >> a >> b >> c >> d;

    do {
        cout << "Введите координаты двух точек для проверки (x1 y1 x2 y2): ";
        cin >> x1 >> y1 >> x2 >> y2;

        int pos1 = computePosition(a, b, c, d, x1, y1);
        int pos2 = computePosition(a, b, c, d, x2, y2);

        if (pos1 * pos2 < 0) {
            cout << "Точки находятся в разных полуплоскостях.\n";
        }
        else {
            cout << "Точки находятся в одной полуплоскости.\n";
        }

        cout << "Хотите проверить другие точки? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}