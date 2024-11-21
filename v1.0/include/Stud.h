
#ifndef  STUD_H_INCLUDED
#define STUD_H_INCLUDED

#include "Lib.h"
#include "Studentas.h"


// //struktura studento duomenims saugoti
// struct Studentas {
//    string vardas;
//    string pavarde;
//    vector<int> namuDarbai;
//    int egzaminas;
//    double galutinis;
// };

//funckija sugeneruoti atsitiktinius namu darbu ir egzamino pazymius
//void generuotiDuomenis(Studentas& s, int ndSkaicius);

//funkcija ivesti studento varda ir pavarde
//void ivestiVardaPavarde(Studentas& s);

//funkcija ivesti pazymius ranka
//void ivedimas(Studentas& s);
template <typename Container>
void ivedimas(Container& studentai, string vardas, string pavarde);

//funkcija pasirinkti duomenu ivedimo buda
//void pasirinktiDuomenuIvedimoBuda(const Container& studentai, Studentas& s);
//void pasirinktiDuomenuIvedimoBuda(Studentas& s);
 
//funkcija apskaiciuoti galutini bala
void skaiciuotiGalutini(Studentas& s, char pasirinkimas);

//funkcija isvesti duomenis
template <typename Container>
void isvedimas(const Container& studentai, char pasirinkimas);

//funkcija skaityti duomenis is failo
template <typename Container>
void nuskaitytiIsFailo(Container& studentai);

//funckija irasyti rezultatus i faila
template <typename Container>
void isvedimasIFaila(const Container& studentai, char pasirinkimas, const string& failoPavadinimas);

//Funckija generuoti failus
void generuotiFaila(int studentuSkaicius, const string& failoPavadinimas);

//funkcija suskirstyti studentus i dvi grupes (pirma strategija)
template <typename Container>
void skirstytiStudentusPirmaStrategija(const Container& studentai, Container& vargsiukai, Container& kietiakai);

//funkcija suskirstyti studentus i dvi grupes (antra strategija)
template <typename Container>
void skirstytiStudentusAntraStrategija(Container& studentai, Container& vargsiukai);

//funkcija suskirstyti studentus i dvi grupes (trecia strategija)
template <typename Container>
//void skirstytiStudentusTreciaStrategija(Container& studentai, Container& vargsiukai, Container& kietiakai);
void skirstytiStudentusTreciaStrategija(Container& studentai, Container& vargsiukai);

//funkcija rusiuoti studentus
template <typename Container>
void rusiuotiStudentus(Container& studentai, char parametras);

//funckija vartotojui pasirinkti galutinio balo matavimo buda
char pasirinktiGalutinioskaiciavimoMetoda();

//funkcija pasirinkti rusiavimo parametra
char pasirinktiRusiavimoParametra();

//funckija pasirinkti rezultato isvedimo buda
template <typename Container>
void pasirinktiRezultatuIsvedimoBuda(const Container& studentai, char pasirinkimas);

//funkcija pasirinkti ivesti duomenis, nuskaityti duomenis is failo ar generuoti faila
char pasirinktiDuomenuIvedima();

//funckija iskviesti rankini ivedimo buda 
template <typename Container>
void ivedimasRanka(Container& studentas);

//funckija pasirinkti studentu dalijimo strategija
template <typename Container>
void duomenuIsvedimasPagalStrategija(Container& studentai, char pasirinkimas);


#endif