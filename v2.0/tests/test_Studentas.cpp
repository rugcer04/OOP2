#include <gtest/gtest.h>
#include "../include/Studentas.h"
#include <sstream>

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

// Testas patikrinina ar sugeneruotas skaičius patenka į intervalą 1-10
TEST(StudentasTest, PazymioGeneravimoKonstruktorius) {
    std::string vardas = "Jonas";
    std::string pavarde = "Jonaitis";
    int ndSkaicius = 5;

    Studentas studentas(vardas, pavarde, ndSkaicius);

    EXPECT_EQ(studentas.getVardas(), vardas);
    EXPECT_EQ(studentas.getPavarde(), pavarde);

    EXPECT_EQ(studentas.getNamudarbai().size(), ndSkaicius);

    for (int grade : studentas.getNamudarbai()) {
        EXPECT_GE(grade, 1);
        EXPECT_LE(grade, 10);
    }
    
    EXPECT_GE(studentas.getEgzaminas(), 1);
    EXPECT_LE(studentas.getEgzaminas(), 10);
}

// Testas išvesties operatoriui
TEST(StudentasTest, IsvestiesOperatorius) {
    Studentas studentas("Jonas", "Jonaitis", {8, 7, 9}, 9);
    studentas.skaiciuotiGalutiniVidurkiu();

    std::ostringstream output;
    output << studentas;

    std::string expectedOutput = "Jonaitis       Jonas          8.60                ";

    EXPECT_EQ(output.str(), expectedOutput);
}