
#include <iostream>
#include <iomanip> // setw()
#include <string>
#include <vector>
#include <algorithm> //sort()

using namespace std;

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
double skaiciuotiGalutiniVidurkiu(const vector<int>& namuDarbai, int egzaminas) {
    double vidurkis = 0.0;
    for(int nd : namuDarbai) {
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


void ivedimas(Studentas &Lok, char pasirinkimas) {
    cout << "Iveskite studento varda: " << endl;
    cin >> Lok.vardas;
    cout << "Iveskite studento pavarde: " << endl;
    cin >> Lok.pavarde;

    int ndSk;
    cout << "Iveskite namu darbu skaiciu: " << endl;
    cin >> ndSk;

    Lok.namuDarbai.resize(ndSk);
    for (int j = 0; j < ndSk; ++j) {
        cout << "Iveskite " << j+1 << "-ojo namu darbo pazymi: ";
        cin >> Lok.namuDarbai[j] ;
    }

    cout << "Iveskite egzamino rezultata: " << endl;
    cin >> Lok.egzaminas;

    if (pasirinkimas == 'V') {
        Lok.galutinis = skaiciuotiGalutiniVidurkiu(Lok.namuDarbai, Lok.egzaminas);
    } else if (pasirinkimas == 'M') {
        Lok.galutinis = skaiciuotiGalutiniMediana(Lok.namuDarbai, Lok.egzaminas);
    }


//    cout << "Input name, surname and egzam point:";
//    cin >> Lok.vardas >> Lok.pavarde >> Lok.egzaminas;
}

void isvedimas(const vector<Studentas>& studentai, char pasirinkimas) {
    if (pasirinkimas == 'V') {
        cout << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(20) << "Galutinis (vid.)" << endl;
    } else if (pasirinkimas == 'M') {
        cout << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(20) << "Galutinis (med.)" << endl;
    }
    cout << "----------------------------------------------" << endl;
    for(const auto& Lok : studentai) {
        cout << setw(15) << Lok.pavarde << setw(15) << Lok.vardas << setw(15) << Lok.galutinis  << endl;
    }
//    cout << "Student data: Name: " << Lok.vardas <<" Surname: " << Lok.pavarde << " Egzam point: " << Lok.egzaminas << endl;
}

void valymas(Studentas &Lok) {
    Lok.vardas.clear();
    Lok.pavarde.clear();
    Lok.namuDarbai.clear();
}


int main() {
    cout << "Iveskite studentu skaiciu: " << endl;
    int studentuSk;
    cin >> studentuSk;

    vector<Studentas> studentai(studentuSk);

    char pasirinkimas;
    do {
        cout << "Pasirinkite galutinio balo skaiciavimo metoda (V - vidurkiu, M - mediana): ";
        cin >> pasirinkimas;
        pasirinkimas = toupper(pasirinkimas);
    } while (pasirinkimas != 'V' && pasirinkimas != 'M');

    for (int i = 0; i < studentuSk; i++) {
        ivedimas(studentai[i], pasirinkimas);
    }

    isvedimas(studentai, pasirinkimas);

    return 0;


//    vector<Studentas> Vektorius;
//    Studentas Temp;
//    cout << "How many students you have?\n";
//    int n;
//    cin >> n;

//   for (int i = 0; i < n; i++) {
//        cout << "Please input user data" << endl;
//        ivedimas(Temp);
//        Vektorius.push_back(Temp);
//        valymas(Temp);
//    }
//   for (int i = 0; i < n; i++) 
//        isvedimas(Vektorius.at(i)); 
   
    
//    system("pause");
}


