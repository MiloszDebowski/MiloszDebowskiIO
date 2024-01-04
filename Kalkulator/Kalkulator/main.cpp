
#include <iostream>
#include "funkcje.h"

int main() {
    double liczba, data[5] = { 1.0, 2.0, 3.0, 4.0, 5.0 };

    std::cout << "Podaj liczbe dla logarytmu naturalnego: ";
    std::cin >> liczba;

    double wynikLogarytmu = Funkcje::logarytmNaturalny(liczba);
    std::cout << "Logarytm naturalny: " << wynikLogarytmu << std::endl;

    double wynikOdchylenia = Funkcje::odchylenieStandardowe(data, 5);
    std::cout << "Odchylenie standardowe: " << wynikOdchylenia << std::endl;

    double wynikExponentu = Funkcje::exponent(liczba);
    std::cout << "Exponent: " << wynikExponentu << std::endl;

    return 0;
}
