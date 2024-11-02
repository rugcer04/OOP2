
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
template <typename Container>
void isvedimas(const Container& studentai, char pasirinkimas);

//funkcija skaityti duomenis is failo
template <typename Container>
void nuskaitytiIsFailo(Container& studentai, const string& failoPavadinimas);

//funckija irasyti rezultatus i faila
template <typename Container>
void isvedimasIFaila(const Container& studentai, char pasirinkimas, const string& failoPavadinimas);

//Funckija generuoti failus
void generuotiFaila(int studentuSkaicius, const string& failoPavadinimas);

//funkcija suskirstyti studentus i dvi grupes
template <typename Container>
void skirstytiStudentusPirmaStrategija(const Container& studentai, Container& vargsiukai, Container& kietiakai);

//funkcija rusiuoti studentus
template <typename Container>
void rusiuotiStudentus(Container& studentai, char parametras);

//funckija vartotojui pasirinkti galutinio balo matavimo buda
char pasirinktiGalutinioskaiciavimoMetoda();

//funkcija pasirinkti rusiavimo parametra
template <typename Container>
void pasirinktiRusiavimoParametra(Container& studentai);

//funckija pasirinkti rezultato isvedimo buda
template <typename Container>
void pasirinktiRezultatuIsvedimoBuda(const Container& studentai, char pasirinkimas);

//funkcija pasirinkti ivesti duomenis, nuskaityti duomenis is failo ar generuoti faila
char pasirinktiDuomenuIvedima();

//funckija iskviesti rankini ivedimo buda 
template <typename Container>
void ivedimasRanka(Container& studentas);



template <typename Container>
void skirstytiStudentusAntraStrategija(Container& studentai, Container& vargsiukai);

#endif