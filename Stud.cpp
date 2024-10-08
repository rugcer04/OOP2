#include "Stud.h"

//funkcija galutiniam balui apskaiciuoti naudojant vidurki
double skaiciuotiGalutiniVidurkiu(const vector<int> namuDarbai, int egzaminas) {
   if (namuDarbai.empty()) {
      return egzaminas * 0.6;
   }

   double vidurkis = 0.0;
   for (int nd: namuDarbai) {
      vidurkis += nd;
   }

   vidurkis /= namuDarbai.size();

   return vidurkis * 0.4 + egzaminas * 0.6;
}

//funkcija galutiniam balui apskaiciuoti naudojant mediana
double skaiciuotiGalutiniMediana(vector<int> namuDarbai, int egzaminas) {
   if (namuDarbai.empty()) {
      return egzaminas * 0.6;
   }

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

random_device rd_generator;
uniform_int_distribution<int> Results_interval(1, 10);

//funckija sugeneruoti atsitiktinius namu darbu ir egzamino pazymius
void generuotiDuomenis(Studentas& Lok, int ndSkaicius) {
   Lok.namuDarbai.clear();
   cout << "Sugeneruoti namų darbų pažymiai: ";
   for (int i = 0; i < ndSkaicius; i++) {
      int pazymys = Results_interval(rd_generator);
      Lok.namuDarbai.push_back(pazymys);
      cout << pazymys << " ";
   }
   Lok.egzaminas = Results_interval(rd_generator);
   cout << "\nSugeneruotas egzamino rezultatas: " << Lok.egzaminas << endl;
}

//funkcija ivesti studento varda ir pavarde
void ivestiVardaPavarde(Studentas& Lok) {
   cout << "Įveskite studento vardą: " << endl;
   cin >> Lok.vardas;
   cout << "Įveskite studento pavardę: " << endl;
   cin >> Lok.pavarde;
   cin.ignore();
}

//funkcija ivesti pazymius ranka
void ivedimas(Studentas &Lok) {
   ivestiVardaPavarde(Lok);

   cout << "Įveskite namų darbų pažymius (Kai baigsite įvedimą, spauskite dukart Enter klavišą):" << endl;

   Lok.namuDarbai.clear();
   string input;
   int pazymys;

   while (true) {
      getline(cin, input);   //naudojama perskaityti visa eilute input, iskaiciuojant tarpus
      if (input.empty()) {
         break;
      }

      try {
         stringstream ss(input);
         if (!(ss >> pazymys)) {  //bandoma extractint skaiciu
            throw invalid_argument("Netinkama įvestis");
         }

         if (pazymys < 1 || pazymys > 10) {
            throw out_of_range("Pažymys turi būti tarp 1 ir 10");
         }

         Lok.namuDarbai.push_back(pazymys);

      } catch (const invalid_argument& e) {
         cout << "Klaida: įvesta ne skaičius. Bandykite dar kartą." << endl;
      } catch (const out_of_range& e) {
         cout << "Klaida: pažymys turi būti tarp 1 ir 10. Bandykite dar kartą." << endl;
      }

   }

   cout << "Įveskite egzamino rezultatą: " << endl;
   while (true) {
      cin >> input;

      try {
         stringstream ss(input);
         if (!(ss >> pazymys)) {
            throw invalid_argument("Netinkama įvestis");
         }

         if (pazymys < 1 || pazymys > 10) {
            throw out_of_range("Egzamino pažymys turi būti tarp 1 ir 10");
         }

         Lok.egzaminas = pazymys;
         break;

      } catch (const invalid_argument& e) {
         cout << "Klaida: įvesta ne skaičius. Bandykite dar kartą." << endl;
      } catch (const out_of_range& e) {
         cout << "Klaida: pažymys turi būti tarp 1 ir 10. Bandykite dar kartą." << endl;
      }
   }

};

//funkcija pasirinkti duomenu ivedimo buda
void pasirinktiDuomenuIvedimoBuda(Studentas& Lok) {
   char pasirinkimas;
   while (true) {
      cout << "Ar norite įvesti pažymius rankiniu būdu (R) ar generuoti automatiškai (A)? ";
      cin >> pasirinkimas;
      pasirinkimas = toupper(pasirinkimas);
      if (pasirinkimas == 'R' || pasirinkimas == 'A') {
            break;
        } else {
            cout << "Neteisinga įvestis, bandykite dar kartą.\n";
        }
   }

   if (pasirinkimas == 'R') {
      ivedimas(Lok);
   } else if (pasirinkimas == 'A') {
      ivestiVardaPavarde(Lok);
      cout << "Įveskite, kiek namų darbų pažymių sugeneruoti: ";
      //cin.ignore();
      
      int ndSkaicius;
      string input;

        while(true) {
            getline(cin, input);

            try{
                stringstream ss(input);
                if (!(ss >> ndSkaicius)) {
                    throw invalid_argument("įvestis nėra skaičius. ");
                }
                break;
            } catch (const invalid_argument &e){
                cout << "Klaida: " << e.what() << "Bandykite dar kartą\n";
            }
        }

      generuotiDuomenis(Lok, ndSkaicius);
   }

}


//funkcija apskaiciuoti galutini bala
void skaiciuotiGalutini(Studentas& Lok, char pasirinkimas) {
     if (pasirinkimas == 'V') {
      Lok.galutinis = skaiciuotiGalutiniVidurkiu(Lok.namuDarbai, Lok.egzaminas);
   } else if (pasirinkimas == 'M') {
      Lok.galutinis = skaiciuotiGalutiniMediana(Lok.namuDarbai, Lok.egzaminas);
   }
}
/*
void isvestiAntraste(char pasirinkimas) {
    if (pasirinkimas == 'V') {
        cout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(15) << "Galutinis (Vid.)" << endl;
    } else if (pasirinkimas == 'M') {
        cout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(15) << "Galutinis (Med.)" << endl;
    }
    cout << "-----------------------------------------------" << endl;
}

void isvestiDuomenis(const vector<Studentas>& studentai) {
    for (const auto& studentas : studentai) {
        cout << left << setw(15) << studentas.pavarde << setw(15) << studentas.vardas << fixed << setprecision(2) << studentas.galutinis << endl;
    }
}

void isvedimas(const vector<Studentas>& studentai, char pasirinkimas) {
    // Išvesti antraštę pagal pasirinkimą (Vidurkis ar Mediana)
    isvestiAntraste(pasirinkimas);

    // Išvesti studentų duomenis
    isvestiDuomenis(studentai);
}
*/

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

//funkcija skaityti duomenis is failo
void nuskaitytiIsFailo(vector<Studentas>& studentai, const string& failoPavadinimas) {
   ifstream failas(failoPavadinimas);  //bandoma atidaryti faila
   if (!failas) {
      cerr << "Nepavyko atidaryti failo: " << failoPavadinimas << endl;
      return;
   }

   //perskaitoma pirma eilute(header) ir praleidziama
   string eilute;
   getline(failas, eilute);

   while (getline(failas, eilute)) {
      stringstream ss(eilute);
      Studentas tempStudentas;
      ss >> tempStudentas.pavarde >> tempStudentas.vardas; //pirmi du elementai eiluteje yra pavarde ir vardas, todel jie yra priskiriami pavardei ir vardui

      string reiksme;
      vector<int> namuDarbai;

      while (ss >> reiksme) {
         try {
            int pazymys = stoi(reiksme);

            if (pazymys >= 1 && pazymys <= 10) {
               namuDarbai.push_back(pazymys);
            } else {
               cerr << "Netinkamas pažymys (" << pazymys << "), praleidžiama reikšmė" << endl;
            }
         } catch (invalid_argument&) {
            cerr << "Netinkamas simbolis (" << reiksme << "), praleidžiama reikšmė." << endl;
         } catch (out_of_range&) {
            cerr << "Pažymys už intervalo ribų, praleidžiama reikšmė." << endl;
         }
      }

      if (!namuDarbai.empty()) {
            //Paskutinis skaičius yra egzamino pažymys
            tempStudentas.egzaminas = namuDarbai.back();
            namuDarbai.pop_back();
            tempStudentas.namuDarbai = namuDarbai;

            studentai.push_back(tempStudentas);
        }

   }
   failas.close();

}

//funckija irasyti rezultatus i faila
void isvedimasIFaila(const vector<Studentas>& studentai, char pasirinkimas, const string& failoPavadinimas) {
   ofstream failas(failoPavadinimas);
   if (!failas) {
      cerr << "Nepavyko sukurti failo: " << failoPavadinimas << endl;
      return;
   }

   if (pasirinkimas == 'V') {
      failas << left << setw(15) << "Pavardė" << setw(15) << "Vardas" << setw(15) << "Galutinis (Vid.)" << endl;
   } else if (pasirinkimas == 'M') {
      failas << left << setw(15) << "Pavardė" << setw(15) << "Vardas" << setw(15) << "Galutinis (Med.)" << endl;
   }

   failas << "----------------------------------------------" << endl;
   for (const auto& Lok : studentai)  {
      failas << left << setw(15) << Lok.pavarde << setw(15) << Lok.vardas << fixed << setprecision(2) << Lok.galutinis << endl;
   }

   failas.close();
   cout << "Rezultatai sėkmingai išsaugoti faile: " << failoPavadinimas << endl;
}

//Funckija generuoti failus
void generuotiFaila(int studentuSkaicius, const string& failoPavadinimas) {
   ofstream failas(failoPavadinimas);
   if (!failas) {
      cerr << "Nepavyksta sukurti failo: " << failoPavadinimas << endl;
      return;
   }

   failas << left << setw(15) << "Pavarde" 
           << left << setw(15) << "Vardas" 
           << left << setw(10) << "ND1"
           << left << setw(10) << "ND2"
           << left << setw(10) << "ND3"
           << left << setw(10) << "ND4"
           << left << setw(10) << "ND5"
           << left << setw(10) << "ND6"
           << left << setw(10) << "ND7"
           << left << setw(10) << "ND8"
           << left << setw(10) << "ND9"
           << left << setw(10) << "ND10"
           << left << setw(10) << "ND11"
           << left << setw(10) << "ND12"
           << left << setw(10) << "ND13"
           << left << setw(10) << "ND14"
           << left << setw(10) << "ND15"
           << left << setw(10) << "Egzaminas" 
           << endl;

   for (int i = 1; i <= studentuSkaicius; i++) {
      string pavarde = "Pavarde" + to_string(i);
      string vardas = "Vardas" + to_string(i);
      failas << left << setw(15) << pavarde
             << left << setw(15) << vardas;

      for (int j = 0; j < 15; ++j) {
         int pazymys = Results_interval(rd_generator);
         failas << left << setw(10) << pazymys;
      }

      int egzaminas = Results_interval(rd_generator);
      failas << left << setw(10) << egzaminas << "\n";
   }

   failas.close();
   cout << "Failas " << failoPavadinimas << " sėkmingai sukurtas" << endl;
}

/*
//funkcija suskirstyti studentus i kategorijas
void KategorijosPriskirimas(vector<Studentas> &stud, int n) {
   for (int i = 0; i < n; i++) {
      if (stud[i].galutinis < 5.0) {
         stud[i].kategorija = Studentas::Kategorija::Vargsiukai;
      } else {
         stud[i].kategorija = Studentas::Kategorija::Kietiakai;
      }
   }
}

//funkcija isvesti skirtingas kategorijas i failus
void IsvedimasIKategorijosFailus(const vector<Studentas>& studentai, const string& vargsiukuFailas, const string& kietiakuFailas) {
   ofstream vargsiukai(vargsiukuFailas);
   ofstream kietiakai(kietiakuFailas);

   if (!vargsiukai || !kietiakai) {
      cerr << "Nepavyko sukurti vieno iš failų!" << endl;
      return;
   }

   //antrastes
   vargsiukai << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(15) << "Galutinis (Vid.)" << endl;
   vargsiukai << "---------------------------------------------" << endl;

   kietiakai << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(15) << "Galutinis (Vid.)" << endl;
   kietiakai << "---------------------------------------------" << endl;

   for (const auto& studentas : studentai) {
      if (studentas.kategorija == Studentas::Kategorija::Vargsiukai) {
         vargsiukai << left << setw(15) << studentas.pavarde << setw(15) << studentas.vardas << fixed << setprecision(2) << studentas.galutinis << endl;
      } else if (studentas.kategorija == Studentas::Kategorija::Kietiakai) {
         kietiakai << left << setw(15) << studentas.pavarde << setw(15) << studentas.vardas << fixed << setprecision(2) << studentas.galutinis << endl;
      }
   }

   vargsiukai.close();
   kietiakai.close();

   cout << "Vargsiukai sėkmingai išsaugoti faile: " << vargsiukuFailas << endl;
   cout << "Kietiakai sėkmingai išsaugoti faile: " << kietiakuFailas << endl;
}
*/


void skirstytiStudentus(const vector<Studentas>& studentai, vector<Studentas>& vargsiukai, vector<Studentas>& kietiakai) {
   for (const auto& studentas : studentai) {
      if (studentas.galutinis < 5.0) {
         vargsiukai.push_back(studentas);
      } else {
         kietiakai.push_back(studentas);
      }
   }
}

void isvestiGrupesIFaila(const vector<Studentas>& studentai, const string& failoPavadinimas, char pasirinkimas) {
   ofstream failas(failoPavadinimas);
   if (!failas) {
      cerr << "Nepavyko sukurti failo: " << failoPavadinimas << endl;
      return;
   }

   if (pasirinkimas == 'V') {
      failas << left << setw(15) << "Pavardė" << setw(15) << "Vardas" << setw(15) << "Galutinis (Vid.)" << endl;
   } else if (pasirinkimas == 'M') {
      failas << left << setw(15) << "Pavardė" << setw(15) << "Vardas" << setw(15) << "Galutinis (Med.)" << endl;
   }

   //failas << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(15) << "Galutinis" << endl;
   //failas << "----------------------------------------------" << endl;

   for (const auto& studentas : studentai) {
      failas << left << setw(15) << studentas.pavarde << setw(15) << studentas.vardas << fixed << setprecision(2) << studentas.galutinis << endl;
   }

   failas.close();
   cout << "Rezultatai sėkmingai išsaugoti faile: " << failoPavadinimas << endl;
}
