#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double F(double x) {
    x = fmod(x, 2.0);
    if (x < -1.0) x += 2.0;
    else if (x >= 1.0) x -= 2.0;

    if (x >= -1.0 && x <= 0.0) return x + 1.0;
    else return -x + 1.0;
}

int main() {

    double start = -2.0;
    double end = 4.0;
    int points = 10;
    double step = (end - start) / (points - 1);

    cout << "x\t\tF(x)" << endl;
    for (int i = 0; i < points; ++i) {
        double x = start + i * step;
        cout << fixed << setprecision(2) << x << "\t\t" << F(x) << endl;
    }

    return 0;
}