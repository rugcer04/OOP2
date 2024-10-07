
#ifndef  STUD_H_INCLUDED
#define STUD_H_INCLUDED

#include "Lib.h"

//struktura studento duomenims saugoti
struct Studentas {
   string vardas;
   string pavarde;
   vector<int> namuDarbai;
   int egzaminas;
   double galutinis;
   enum class Kategorija {Vargsiukai, Kietiakai};
   Kategorija kategorija;
};

//funkcija galutiniam balui apskaiciuoti naudojant vidurki
double skaiciuotiGalutiniVidurkiu(const vector<int> namuDarbai, int egzaminas);

//funkcija galutiniam balui apskaiciuoti naudojant mediana
double skaiciuotiGalutiniMediana(vector<int> namuDarbai, int egzaminas);

//funkcija generuoti atsitiktinius skaicius
int generuotiSkaiciu();

//funckija sugeneruoti atsitiktinius namu darbu ir egzamino pazymius
void generuotiDuomenis(Studentas& Lok, int ndSkaicius);

//funkcija ivesti studento varda ir pavarde
void ivestiVardaPavarde(Studentas& Lok);

//funkcija ivesti pazymius ranka
void ivedimas(Studentas &Lok);

//funkcija pasirinkti duomenu ivedimo buda
void pasirinktiDuomenuIvedimoBuda(Studentas& Lok);
 
//funkcija apskaiciuoti galutini bala
void skaiciuotiGalutini(Studentas& Lok, char pasirinkimas);

//funkcija isvesti duomenis
void isvedimas(const vector<Studentas>& studentai, char pasirinkimas);

//funkcija skaityti duomenis is failo
void nuskaitytiIsFailo(vector<Studentas>& studentai, const string& failoPavadinimas);

//funckija irasyti rezultatus i faila
void isvedimasIFaila(const vector<Studentas>& studentai, char pasirinkimas, const string& failoPavadinimas);

#endif