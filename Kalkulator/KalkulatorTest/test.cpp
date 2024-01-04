#include "pch.h"
#include <gtest/gtest.h>
#include "/Users/milos/source/repos/Kalkulator/Kalkulator/funkcje.cpp"

// Test dla funkcji logarytmNaturalny
TEST(LogarytmNaturalnyTest, PozytywnyArgument) {
    EXPECT_DOUBLE_EQ(Funkcje::logarytmNaturalny(2.0), 0.693147180559945);
}

TEST(LogarytmNaturalnyTest, ZeroLubUjemnyArgument) {
    EXPECT_TRUE(std::isnan(Funkcje::logarytmNaturalny(0.0)));
    EXPECT_TRUE(std::isnan(Funkcje::logarytmNaturalny(-1.0)));
}

// Test dla funkcji odchylenieStandardowe
TEST(OdchylenieStandardoweTest, PoprawneDane) {
    double data[] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
    EXPECT_DOUBLE_EQ(Funkcje::odchylenieStandardowe(data, 5), 1.4142135623730951);
}

TEST(OdchylenieStandardoweTest, ZaMaloDanych) {
    double data[] = { 1.0 };
    EXPECT_TRUE(std::isnan(Funkcje::odchylenieStandardowe(data, 1)));
}

// Test dla funkcji exponent
TEST(ExponentTest, PozytywnyArgument) {
    EXPECT_DOUBLE_EQ(Funkcje::exponent(1.0), 2.7182818284590451);
}

TEST(ExponentTest, ZeroArgument) {
    EXPECT_DOUBLE_EQ(Funkcje::exponent(0.0), 1.0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
