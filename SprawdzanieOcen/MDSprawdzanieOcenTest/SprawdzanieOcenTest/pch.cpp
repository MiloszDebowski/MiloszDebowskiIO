//
// pch.cpp
//

#include "pch.h"
#include "/Users/milos/Desktop/LabIO/SprawdzanieOcen/MDSprawdzanieOcenTest/MDSprawdzanieOcenTest/funkcje.h"

Autoryzacja::Autoryzacja() {
    pozwolenie = true;
}

Przedmiot::Przedmiot()
{
    nazwa = "przedmiot x";
    for (int i = 0; i < 5; i++)
    {
        testy[i].nazwa = "test x";
        testy[i].ocena = 5;
    }
}

void bladWyboruPrzedmiotu() {
    cout << endl << endl << "NIE MA TAKIEGO PRZEDMIOTU - WYBIERZ JESZCZE RAZ" << endl << endl;
}

void bladWyboruTestu() {
    cout << endl << endl << "NIE MA TAKIEGO TESTU - WYBIERZ JESZCZE RAZ" << endl << endl;
}

void wypisz(Przedmiot przedmiot, int i) {
    cout << "Przedmiot: " << przedmiot.nazwa << endl;
    cout << "Test " << i << ": " << przedmiot.testy[i - 1].nazwa << " - Ocena: " << przedmiot.testy[i - 1].ocena << endl;
}

void wyswietlPrzedmioty(Przedmiot przedmioty[]) {
    cout << "Wybierz przedmiot: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << ". " << przedmioty[i].nazwa << endl;
    }
}

void wyswietlTesty(Przedmiot przedmiot) {
    cout << "Wybrany przedmiot: " << przedmiot.nazwa << endl;
    cout << "Wybierz test. Dostepne testy: " << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << ". " << przedmiot.testy[i].nazwa << endl;
    }
}
