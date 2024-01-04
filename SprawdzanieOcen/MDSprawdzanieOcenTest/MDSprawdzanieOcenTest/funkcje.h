#pragma once
#ifndef FUNKCJE_H
#define FUNKCJE_H

#include<iostream>
using namespace std;

class Autoryzacja {
public:
    bool pozwolenie;

    Autoryzacja();
};

struct Test
{
    string nazwa;
    int ocena;
};

struct Przedmiot : public Test
{
    string nazwa;
    Test testy[5];

    Przedmiot();
};

void bladWyboruPrzedmiotu();
void bladWyboruTestu();
void wypisz(Przedmiot przedmiot, int i);
void wyswietlPrzedmioty(Przedmiot przedmioty[]);
void wyswietlTesty(Przedmiot przedmiot);

#endif // FUNKCJE_H
