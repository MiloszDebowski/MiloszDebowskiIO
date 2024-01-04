#include "pch.h"
#include "gtest/gtest.h"
#include "/Users/milos/Desktop/LabIO/SprawdzanieOcen/MDSprawdzanieOcenTest/MDSprawdzanieOcenTest/funkcje.h"

// Testuje funkcj� bladWyboruTestu()
TEST(BledyTest, BladWyboruTestu) {
    testing::internal::CaptureStdout();  // Przechwy� wyj�cie standardowe
    bladWyboruTestu();
    std::string output = testing::internal::GetCapturedStdout();  // Pobierz przechwycone wyj�cie
    EXPECT_EQ(output, "\n\nNIE MA TAKIEGO TESTU - WYBIERZ JESZCZE RAZ\n\n");
}

// Testuje funkcj� bladWyboruPrzedmiotu()
TEST(BledyTest, BladWyboruPrzedmiotu) {
    testing::internal::CaptureStdout();
    bladWyboruPrzedmiotu();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "\n\nNIE MA TAKIEGO PRZEDMIOTU - WYBIERZ JESZCZE RAZ\n\n");
}

// Testuje funkcj� wypisz()
TEST(WypiszTest, Wypisz) {
    testing::internal::CaptureStdout();
    Przedmiot testPrzedmiot;
    wypisz(testPrzedmiot, 1);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Przedmiot: przedmiot x\nTest 1: test x - Ocena: 5\n");
}

// Testuje funkcj� wyswietlPrzedmioty()
TEST(WyswietlPrzedmiotyTest, WyswietlPrzedmioty) {
    testing::internal::CaptureStdout();
    Przedmiot przedmioty[5];
    wyswietlPrzedmioty(przedmioty);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Wybierz przedmiot: \n1. przedmiot x\n2. przedmiot x\n3. przedmiot x\n4. przedmiot x\n5. przedmiot x\n");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
