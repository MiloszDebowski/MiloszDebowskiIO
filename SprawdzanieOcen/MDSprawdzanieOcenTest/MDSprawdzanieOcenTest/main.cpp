#include<iostream>
#include "funkcje.h"
using namespace std;

int main(void)
{
    Autoryzacja authorization;
    Przedmiot przedmioty[5];
    int x;

wybor:
    wyswietlPrzedmioty(przedmioty);
    cin >> x;
    system("cls");

    if (x < 1 || x > 5)
    {
        bladWyboruPrzedmiotu();
        goto wybor;
    }

    int y;

wybor2:
    wyswietlTesty(przedmioty[x - 1]);
    cin >> y;
    system("cls");

    if (y < 1 || y > 5)
    {
        bladWyboruTestu();
        goto wybor2;
    }

    if (!authorization.pozwolenie) {
        cout << "Brak uprawnien do przegladania ocen." << endl;
        return 0;
    }

    wypisz(przedmioty[x - 1], y);

    return 0;
}
