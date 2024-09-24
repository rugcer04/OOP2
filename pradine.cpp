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

//funkcija galutiniam balui apskaiciuoti naudojant mediana
double skaiciuotiGalutiniMediana(vector<int> namuDarbai, int egzaminas) {
    sort(namuDarbai.begin(), namuDarbai.end()) ;
    double mediana;
    int size = namuDarbai.size();

    if (size % 2 == 0) {
        mediana = (namuDarbai[size / 2 - 1] + namuDarbai[size / 2]) / 2.0; 
    } else {
        mediana = namuDarbai[size / 2];
    }

    return mediana * 0.4 + egzaminas * 0.6;

}

//funkcija ivesti duomenims
void ivedimas(Studentas &Lok, char pasirinkimas) {
   cout << "Įveskite studento vardą: " << endl;
   cin >> Lok.vardas;
   cout << "Įveskite studento pavardę: " << endl;
   cin >> Lok.pavarde;
   cin.ignore();

   cout << "Įveskite namų darbų pažymius (Kai baigsite įvedimą, spauskite dukart Enter klavišą):" << endl;

   Lok.namuDarbai.clear();
   string input;
   int pazymys;

   while (true) {
      getline(cin, input);
      if (input.empty()) {
         break;
      }
      stringstream ss(input);
      if (ss >> pazymys) {
         Lok.namuDarbai.push_back(pazymys);
      } else {
         cout << "Netinkama įvestis, bandykite dar kartą." << endl;
      }

   }

   //int ndSk;
   //cout << "Įveskite namų darbų skaičių: " << endl;
   //cin >> ndSk;

   //Lok.namuDarbai.resize(ndSk);
   //for (int j = 0; j < ndSk; ++j) {
   //   cout << "Įveskite " << j+1 << "-ojo namų darbo pažymį: " << endl;
   //   cin >> Lok.namuDarbai[j];
   //}

   cout << "Įveskite egzamino rezultatą: " << endl;
   cin >> Lok.egzaminas;

   if (pasirinkimas == 'V') {
      Lok.galutinis = skaiciuotiGalutiniVidurkiu(Lok.namuDarbai, Lok.egzaminas);
   } else if (pasirinkimas == 'M') {
      Lok.galutinis = skaiciuotiGalutiniMediana(Lok.namuDarbai, Lok.egzaminas);
   }

}

//funkcija isvesti duomenis
void isvedimas(const vector<Studentas>& studentai, char pasirinkimas) {
   if (pasirinkimas == 'V') {
      cout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(15) << "Galutinis (Vid.)" << endl;
   } else if (pasirinkimas == 'M') {
      cout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(15) << "Galutinis (Med.)" << endl;
   }

   cout << "-----------------------------------------------" << endl;
   for (const auto& Lok: studentai) {
      cout << left << setw(15) << Lok.pavarde << setw(15) << Lok.vardas << fixed << setprecision(2) << Lok.galutinis  << endl;
   }
}

int main() {
   cout << "Įveskite studentų skaičių: " << endl;
    int studentuSk;
    cin >> studentuSk;

    vector<Studentas> studentai(studentuSk);

    char pasirinkimas;
    do {
      cout << "Pasirinkite galutinio balo skaičiavimo metodą (V- vidurkiu, M- mediana): ";
      cin >> pasirinkimas;
      pasirinkimas = toupper(pasirinkimas);
    } while (pasirinkimas != 'V' && pasirinkimas != 'M');

    for (int i = 0; i < studentuSk; i++) {
        ivedimas(studentai[i], pasirinkimas);
    }

    isvedimas(studentai, pasirinkimas);

    return 0;

}