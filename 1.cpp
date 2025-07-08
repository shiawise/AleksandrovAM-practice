#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <math.h>
#define PI 3.14159265358979323846

int main(void) {
    setlocale(LC_CTYPE, "Russian");
    int k1, k2;
    double x, rada;
    double anhora, anhorb;
    int degrees, minutes;
    double remaining_minutes;

    printf("Введите катеты:\n");
    scanf_s("%d%d", &k1, &k2);

    if (k1 <= 0 || k2 <= 0) {
        printf("Катеты должны быть положительными числами.\n");
        system("pause");
        return 1;
    }

    x = (double)k1 / k2;
    rada = atan(x);
    anhora = (rada * 180) / PI;
    anhorb = 90 - anhora;

    degrees = (int)anhora;
    remaining_minutes = (anhora - degrees) * 60;
    minutes = (int)round(remaining_minutes);
    printf("Угол a = %d градусов %d минут\n", degrees, minutes);

    degrees = (int)anhorb;
    remaining_minutes = (anhorb - degrees) * 60;
    minutes = (int)round(remaining_minutes);
    printf("Угол b = %d градусов %d минут\n", degrees, minutes);

    system("pause");
    return 0;
}