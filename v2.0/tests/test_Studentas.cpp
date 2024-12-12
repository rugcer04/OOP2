#include <gtest/gtest.h>
#include "../include/Studentas.h"

// Testas galutinio įvertinimo apskaičiavimui pagal vidurkį
TEST(StudentasTest, IvertinimasVidurkis) {
    std::vector<int> nd = {8, 6, 7, 10, 9};
    Studentas s("Jonas", "Jonaitis", nd, 8);
    
    s.skaiciuotiGalutiniVidurkiu();

    double expectedGalutinis = 0.4 * 8 + 0.6 * 8;
    EXPECT_EQ(s.getGalutinis(), expectedGalutinis);
}

// Testas kopijavimo konstruktoriui
TEST(StudentasTest, KopijavimoKonstruktorius) {
    std::vector<int> nd = {6, 7, 10, 6, 9};
    Studentas originalas("Jonas", "Jonaitis", nd, 9);
    originalas.skaiciuotiGalutiniVidurkiu();
    
    Studentas kopija(originalas);

    EXPECT_EQ(originalas.getVardas(), kopija.getVardas());
    EXPECT_EQ(originalas.getPavarde(), kopija.getPavarde());
    EXPECT_EQ(originalas.getNamudarbai(), kopija.getNamudarbai());
    EXPECT_EQ(originalas.getEgzaminas(), kopija.getEgzaminas());
    EXPECT_EQ(originalas.getGalutinis(), kopija.getGalutinis());
}
