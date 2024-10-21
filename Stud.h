
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
};

//funkcija galutiniam balui apskaiciuoti naudojant vidurki
double skaiciuotiGalutiniVidurkiu(const vector<int>& namuDarbai, int egzaminas);

//funkcija galutiniam balui apskaiciuoti naudojant mediana
double skaiciuotiGalutiniMediana(vector<int>& namuDarbai, int egzaminas);

//funkcija generuoti atsitiktinius skaicius
//int generuotiSkaiciu();

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
template <typename Container>
void nuskaitytiIsFailo(Container& studentai, const string& failoPavadinimas);

//funckija irasyti rezultatus i faila
template <typename Container>
void isvedimasIFaila(const Container& studentai, char pasirinkimas, const string& failoPavadinimas);

//Funckija generuoti failus
void generuotiFaila(int studentuSkaicius, const string& failoPavadinimas);

//funkcija suskirstyti studentus i dvi grupes
void skirstytiStudentus(const vector<Studentas>& studentai, vector<Studentas>& vargsiukai, vector<Studentas>& kietiakai);

//funkcija rusiuoti studentus
template <typename Container>
void rusiuotiStudentus(Container& studentai, char parametras);

//funckija vartotojui pasirinkti galutinio balo matavimo buda
char pasirinktiGalutinioskaiciavimoMetoda();

//funkcija pasirinkti rusiavimo parametra
void pasirinktiRusiavimoParametra(vector<Studentas>& studentai);

//funckija pasirinkti rezultato isvedimo buda
void pasirinktiRezultatuIsvedimoBuda(const vector<Studentas>& studentai, char pasirinkimas);

char pasirinktiDuomenuIvedima();

template <typename Container>
void ivedimasRanka(Container& studentas);

#endif