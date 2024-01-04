#include <iostream>
#include <string>

using namespace std;

struct Ocena {
    string przedmiot;
    int punkty;
};

class RejestrOcen {
public:
    string imie;
    Ocena oceny[10];
    int iloscOcen;

    RejestrOcen() : iloscOcen(0) {}

    void przegladOcen() const {
        cout << "Przeglad ocen..." << endl;
        cout << "Oceny ucznia " << imie << ":" << endl;
        for (int i = 0; i < iloscOcen; ++i) {
            cout << "Przedmiot: " << oceny[i].przedmiot << ", Punkty: " << oceny[i].punkty << endl;
        }
    }


};

class BudowniczyRejestruOcen {
protected:
    RejestrOcen rejestr;

public:
    virtual void budujImie() = 0;
    virtual void budujOceny() = 0;
    virtual void reset() {
        rejestr = RejestrOcen();
    }
    virtual ~BudowniczyRejestruOcen() {}
};

class DomyślnyBudowniczyRejestruOcen : public BudowniczyRejestruOcen {
public:
    void budujImie() override {
        cout << "Podaj imie ucznia: ";
        getline(cin, rejestr.imie);

        cout << "Utworzono rejestr ocen dla ucznia o imieniu " << rejestr.imie << endl;
    }

    void budujOceny() override {
        char dodajWiecej;
        do {
            cout << "Podaj przedmiot: ";
            getline(cin, rejestr.oceny[rejestr.iloscOcen].przedmiot);

            cout << "Podaj ilosc punktow: ";
            cin >> rejestr.oceny[rejestr.iloscOcen].punkty;
            cin.ignore();

            rejestr.iloscOcen++;

            cout << "Czy chcesz dodac kolejna ocene? (T/N): ";
            cin >> dodajWiecej;
            cin.ignore();
        } while (dodajWiecej == 'T' || dodajWiecej == 't');
    }

    void reset() override {
        BudowniczyRejestruOcen::reset();
        rejestr.iloscOcen = 0;
    }

    RejestrOcen getResult() {
        return rejestr;
    }
};

class DyrektorRejestruOcen {
public:
    void stworzRejestrOcen(BudowniczyRejestruOcen& budowniczy) {
        budowniczy.budujImie();
        budowniczy.budujOceny();
    }
};

int main() {
    DomyślnyBudowniczyRejestruOcen domyslnyBudowniczy;
    DyrektorRejestruOcen dyrektor;

    dyrektor.stworzRejestrOcen(domyslnyBudowniczy);

    RejestrOcen rejestrOcen = domyslnyBudowniczy.getResult();


    rejestrOcen.przegladOcen();




    return 0;
}
