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
double skaiciuotiGalutiniVidurkiu(const vector<int> namuDarbai, int egzaminas) {
   double vidurkis = 0.0;
   for (int nd: namuDarbai) {
      vidurkis += nd;
   }

   vidurkis /= namuDarbai.size();

   return vidurkis * 0.4 + egzaminas * 0.6;
}

//funkcija ivesti duomenims
void ivedimas(Studentas &Lok) {
   cout << "Įveskite studento vardą: " << endl;
   cin >> Lok.vardas;
   cout << "Įveskite studento pavardę: " << endl;
   cin >> Lok.pavarde;

   int ndSk;
   cout << "Įveskite namų darbų skaičių: " << endl;
   cin >> ndSk;

   Lok.namuDarbai.resize(ndSk);
   for (int j = 0; j < ndSk; ++j) {
      cout << "Įveskite " << j+1 << "-ojo namų darbo pažymį: " << endl;
      cin >> Lok.namuDarbai[j];
   }

   cout << "Įveskite egzamino rezultatą: " << endl;
   cin >> Lok.egzaminas;

   Lok.galutinis = skaiciuotiGalutiniVidurkiu(Lok.namuDarbai, Lok.egzaminas);
}

//funkcija isvesti duomenis
void isvedimas(const vector<Studentas>& studentai) {
   cout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(15) << "Galutinis (Vid.)" << endl;
   cout << "---------------------------------------------" << endl;
   for (const auto& Lok: studentai) {
      cout << left << setw(15) << Lok.pavarde << setw(15) << Lok.vardas << fixed << setprecision(2) << Lok.galutinis  << endl;
   }
}

int main() {
   cout << "Įveskite studentų skaičių: " << endl;
    int studentuSk;
    cin >> studentuSk;

    vector<Studentas> studentai(studentuSk);

    for (int i = 0; i < studentuSk; i++) {
        ivedimas(studentai[i]);
    }

    isvedimas(studentai);

    return 0;

}