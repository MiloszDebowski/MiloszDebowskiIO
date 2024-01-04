
#include <cmath>
#include "funkcje.h"

double Funkcje::logarytmNaturalny(double x) {
    if (x <= 0) {
        
        return NAN;
    }
    return log(x);
}

double Funkcje::odchylenieStandardowe(double data[], int n) {
    if (n <= 1) {
        return NAN;
    }

    double suma = 0.0;
    double srednia;

    for (int i = 0; i < n; ++i) {
        suma += data[i];
    }

    srednia = suma / n;

    double sumaKwadratowRoznic = 0.0;

    for (int i = 0; i < n; ++i) {
        sumaKwadratowRoznic += pow(data[i] - srednia, 2);
    }

    return sqrt(sumaKwadratowRoznic / n);
}

double Funkcje::exponent(double x) {
    return exp(x);
}
