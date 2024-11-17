
#ifndef  STUD_H_INCLUDED
#define STUD_H_INCLUDED

#include "Lib.h"
using std::istream;

// studento klase
class Studentas{
   private:
      string vardas_;
      string pavarde_;
      vector<int> namudarbai_;
      int egzaminas_;
      double galutinis_;

   public:
      // konstruktoriai
      Studentas() : egzaminas_(0), galutinis_(0.0) { }
      Studentas(const string& vardas, const string& pavarde, const vector<int> namudarbai, double egzaminas):
      vardas_(vardas), pavarde_(pavarde), namudarbai_(namudarbai), egzaminas_(egzaminas), galutinis_(0.0) { }
      // Studentas(istream& is); //constructor that takes an input stream, allowing the student data to be read from a stream

      // seteriai
      void setVardas(const string& vardas) { vardas_ = vardas; }
      void setPavarde(const string& pavarde) { pavarde_ = pavarde; }
      void setNamuDarbai(const vector<int>& namudarbai) { namudarbai_ = namudarbai;}
      void setEgzaminas(const int& egzaminas) { egzaminas_ = egzaminas; }

      // geteriai
      inline string getVardas() const { return vardas_; }
      inline string getPavarde() const { return pavarde_; }
      inline vector<int> getNamudarbai() const { return namudarbai_; }
      inline int getEgzaminas() const { return egzaminas_; }

      // funckijos
      double skaiciuotiGalutiniVidurkiu();
};

//struktura studento duomenims saugoti
// struct Studentas {
//    string vardas;
//    string pavarde;
//    vector<int> namuDarbai;
//    int egzaminas;
//    double galutinis;
// };

//funkcija galutiniam balui apskaiciuoti naudojant vidurki
//double skaiciuotiGalutiniVidurkiu(const vector<int>& namuDarbai, int egzaminas);

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