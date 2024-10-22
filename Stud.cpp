#include "Stud.h"

//funkcija galutiniam balui apskaiciuoti naudojant vidurki
double skaiciuotiGalutiniVidurkiu(const vector<int>& namuDarbai, int egzaminas) {
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
double skaiciuotiGalutiniMediana(vector<int>& namuDarbai, int egzaminas) {
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
   Lok.namuDarbai.reserve(ndSkaicius);

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

//funkcija isvesti duomenis
template <typename Container>
void isvedimas(const Container& studentai, char pasirinkimas) {
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
template void isvedimas<vector<Studentas>>(const vector<Studentas>&, char pasirinkimas);
template void isvedimas<list<Studentas>>(const list<Studentas>&, char pasirinkimas);

//funkcija skaityti duomenis is failo
template <typename Container>
void nuskaitytiIsFailo(Container& studentai, const string& failoPavadinimas) {
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
            tempStudentas.namuDarbai = move(namuDarbai);

            studentai.push_back(move(tempStudentas));
        }

   }
   failas.close();

}
template void nuskaitytiIsFailo<vector<Studentas>>(vector<Studentas>&, const string& failoPavadinimas);
template void nuskaitytiIsFailo<list<Studentas>>(list<Studentas>&, const string& failoPavadinimas);

//funckija irasyti rezultatus i faila
template <typename Container>
void isvedimasIFaila(const Container& studentai, char pasirinkimas, const string& failoPavadinimas) {
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
template void isvedimasIFaila<vector<Studentas>>(const vector<Studentas>&, char pasirinkimas, const string& failoPavadinimas);
template void isvedimasIFaila<list<Studentas>>(const list<Studentas>&, char pasirinkimas, const string& failoPavadinimas);

//Funckija generuoti failus
void generuotiFaila(int studentuSkaicius, const string& failoPavadinimas) {
   ofstream failas(failoPavadinimas);
   if (!failas) {
      cerr << "Nepavyksta sukurti failo: " << failoPavadinimas << endl;
      return;
   }

   //antraste
   failas << left << setw(15) << "Pavarde" << left << setw(15) << "Vardas";
   for (int i = 1; i <= 15; i++) {
      failas << left << setw(10) << "ND" + to_string(i);
   }
   failas << left << setw(10) << "Egzaminas" << endl;

   //duomenu generavimas
   for (int i = 1; i <= studentuSkaicius; i++) {
      string pavarde = "Pavarde" + to_string(i);
      string vardas = "Vardas" + to_string(i);
      failas << left << setw(15) << pavarde << left << setw(15) << vardas;

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

//funkcija suskirstyti studentus i dvi grupes
template <typename Container>
void skirstytiStudentus(const Container& studentai, Container& vargsiukai, Container& kietiakai) {
   for (const auto& studentas : studentai) {
      if (studentas.galutinis < 5.0) {
         vargsiukai.push_back(studentas);
      } else {
         kietiakai.push_back(studentas);
      }
   }
}
template void skirstytiStudentus<vector<Studentas>>(const vector<Studentas>&, vector<Studentas>&, vector<Studentas>&);
template void skirstytiStudentus<list<Studentas>>(const list<Studentas>&, list<Studentas>&, list<Studentas>&);

//funkcija rusiuoti studentus
template <typename Container>
void rusiuotiStudentus(Container& studentai, char parametras) {
   //vektoriaus rusiavimas
   if constexpr (is_same_v<Container, vector<Studentas>>) { //patikrinama ar konteineris yra vektorius
      if(parametras == 'V') {
         //Rusiavimas pagal varda
         sort(studentai.begin(), studentai.end(),
         [](const Studentas& a, const Studentas& b) {
               if (a.vardas == b.vardas) {
                  return a.pavarde < b.pavarde;
               }
               return a.vardas < b.vardas;
         }
      );
      } else if (parametras == 'P') {
         //Rusiavimas pagal pavarde
         sort(studentai.begin(), studentai.end(),
         [](const Studentas& a, const Studentas& b) {
               if (a.pavarde == b.pavarde) {
                  return a.vardas < b.vardas;
               }
               return a.pavarde < b.pavarde;
         }
      );
      } else if (parametras == 'M') {
         //Rusiavimas pagal galutini pazymi mazejimo tvarka
         sort(studentai.begin(), studentai.end(),
         [](const Studentas& a, const Studentas& b) {
               return a.galutinis > b.galutinis;
         }
      );
      } else if (parametras == 'D') {
         //Rusiavimas pagal galutini pazymi didejimo tvarka
         sort(studentai.begin(), studentai.end(),
         [](const Studentas& a, const Studentas& b) {
               return a.galutinis < b.galutinis;
         }
      );
      }
   } else if constexpr (is_same_v<Container, list<Studentas>>) {
      //list rusiavimas
      if(parametras == 'V') {
         //Rusiavimas pagal varda
         studentai.sort([](const Studentas& a, const Studentas& b) {
            if (a.vardas == b.vardas) {
               return a.pavarde < b.pavarde;
            }
            return a.vardas < b.vardas;
         }
      );
      } else if (parametras == 'P') {
         //Rusiavimas pagal pavarde
         studentai.sort([](const Studentas& a, const Studentas& b) {
            if (a.pavarde == b.pavarde) {
               return a.vardas < b.vardas;
            }
            return a.pavarde < b.pavarde;
         }
      );
      } else if (parametras == 'M') {
         //Rusiavimas pagal galutini pazymi mazejimo tvarka
         studentai.sort([](const Studentas& a, const Studentas& b) {
            return a.galutinis > b.galutinis;
         }
      );
      } else if (parametras == 'D') {
         //Rusiavimas pagal galutini pazymi didejimo tvarka
         studentai.sort([](const Studentas& a, const Studentas& b) {
            return a.galutinis < b.galutinis;
         }
      );
      }
   }
}
template void rusiuotiStudentus<vector<Studentas>>(vector<Studentas>&, char parametras);
template void rusiuotiStudentus<list<Studentas>>(list<Studentas>&, char parametras);

//funckija vartotojui pasirinkti galutinio balo matavimo buda
char pasirinktiGalutinioskaiciavimoMetoda() {
    char pasirinkimas;
    do {
        cout << "Pasirinkite galutinio balo skaičiavimo metodą (V- vidurkiu, M- mediana): ";
        cin >> pasirinkimas;
        pasirinkimas = toupper(pasirinkimas);
    } while (pasirinkimas != 'V' && pasirinkimas != 'M');

    return pasirinkimas;
}

//funkcija pasirinkti rusiavimo parametra
template <typename Container>
void pasirinktiRusiavimoParametra(Container& studentai) {
   char parametras;
   while (true) {
      cout << "Pasirinkite kokia tvarka norėtumėte pateikti studentus: surūšiuotus pagal vardą (V), pagal pavardę (P), pagal galutinį rezultatą mažėjimo tvarka (M) ar didėjimo tvarka (D): ";
      cin >> parametras;
      parametras = toupper(parametras);

      if (parametras == 'V' || parametras == 'P' || parametras == 'M'|| parametras == 'D') {
         break;
      } else {
         cout << "Neteisinga įvestis, bandykite dar kartą.\n";
      }
   }
   rusiuotiStudentus(studentai, parametras);
}
template void pasirinktiRusiavimoParametra<vector<Studentas>>(vector<Studentas>&);
template void pasirinktiRusiavimoParametra<list<Studentas>>(list<Studentas>&);

//funckija pasirinkti rezultato isvedimo buda
template <typename Container>
void pasirinktiRezultatuIsvedimoBuda(const Container& studentai, char pasirinkimas) {
    char isvedimoBudas;
    while (true) {
        cout << "Ar norite išvesti rezultatus į ekraną (E) ar į failą (F)? ";
        cin >> isvedimoBudas;
        isvedimoBudas = toupper(isvedimoBudas);

        if (isvedimoBudas == 'E' || isvedimoBudas == 'F') {
            break;
        } else {
            cout << "Neteisinga įvestis, bandykite dar kartą.\n";
        }
    }

    if (isvedimoBudas == 'E') {
        isvedimas(studentai, pasirinkimas);
    } else if (isvedimoBudas == 'F') {
        string failoPavadinimas;
        cout << "Įveskite failo pavadinimą rezultatams išsaugoti: ";
        cin >> failoPavadinimas;
        isvedimasIFaila(studentai, pasirinkimas, failoPavadinimas);
    }
}
template void pasirinktiRezultatuIsvedimoBuda<vector<Studentas>>(const vector<Studentas>&, char pasirinkimas);
template void pasirinktiRezultatuIsvedimoBuda<list<Studentas>>(const list<Studentas>&, char pasirinkimas);


char pasirinktiDuomenuIvedima() {
   char duomenuIvedimoBudas;
   while (true) {
      cout << "Ar norite duomenis įvesti (I), nuskaityti iš failo (F), ar sugeneruoti failą (G)? ";
      cin >> duomenuIvedimoBudas;
      duomenuIvedimoBudas = toupper(duomenuIvedimoBudas);

      if (duomenuIvedimoBudas == 'I' || duomenuIvedimoBudas == 'F' || duomenuIvedimoBudas == 'G') {
          break;
      } else {
         cout << "Neteisinga įvestis, bandykite dar kartą.\n";
      }
   }
   return duomenuIvedimoBudas;
}

template <typename Container>
void ivedimasRanka(Container& studentai) {
   cout << "Įveskite studentų skaičių: ";
        cin.ignore();
        string input;
        int studentuSk;

        while(true) {
            getline(cin, input);

            try{
                stringstream ss(input);
                if (!(ss >> studentuSk)) {
                    throw invalid_argument("įvestis nėra skaičius. ");
                }
                break;
            } catch (const invalid_argument &e){
                cout << "Klaida: " << e.what() << "Bandykite dar kartą\n";
            }
        }

        for (int i = 0; i < studentuSk; i++) {
            typename Container::value_type studentas;
            pasirinktiDuomenuIvedimoBuda(studentas);
            studentai.push_back(studentas);
        }
}
template void ivedimasRanka<vector<Studentas>>(vector<Studentas>&);
template void ivedimasRanka<list<Studentas>>(list<Studentas>&);
