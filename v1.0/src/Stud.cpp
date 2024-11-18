#include "../include/Stud.h"
#include "../include/Timer.h"

//funkcija galutiniam balui apskaiciuoti naudojant vidurki
double skaiciuotiGalutiniVidurkiu(Studentas &s){
   const vector<int>& namudarbai = s.getNamudarbai();
   int egzaminas = s.getEgzaminas();

   if (namudarbai.empty()){
      s.setGalutinis(egzaminas * 0.6);
   } else {
      double vidurkis = 0.0;

      for (int nd : namudarbai){
         vidurkis += nd;
      }

      vidurkis /= namudarbai.size();
      s.setGalutinis(vidurkis * 0.4 + egzaminas * 0.6);
   }

   return s.getGalutinis();
}

//funkcija galutiniam balui apskaiciuoti naudojant mediana
double skaiciuotiGalutiniMediana(Studentas &s) {
   const vector<int>& namudarbai = s.getNamudarbai();
   int egzaminas = s.getEgzaminas();

   if (namudarbai.empty()) {
      s.setGalutinis(egzaminas * 0.6);
   }

   sort(namudarbai.begin(), namudarbai.end()) ;
   double mediana;
   int size = namudarbai.size();

   if (size % 2 == 0) {
      mediana = (namudarbai[size / 2 - 1] + namudarbai[size / 2]) / 2.0; 
   } else {
      mediana = namudarbai[size / 2];
   }

   s.setGalutinis(mediana * 0.4 + egzaminas * 0.6);

   return s.getGalutinis();

}

random_device rd_generator;
uniform_int_distribution<int> Results_interval(1, 10);

//funckija sugeneruoti atsitiktinius namu darbu ir egzamino pazymius
void generuotiDuomenis(Studentas& s, int ndSkaicius) {
   vector<int> namudarbai;
   namudarbai.reserve(ndSkaicius);

   cout << "Sugeneruoti namų darbų pažymiai: ";
   for (int i = 0; i < ndSkaicius; i++) {
      int pazymys = Results_interval(rd_generator);
      namudarbai.push_back(pazymys);
      cout << pazymys << " ";
   }
   s.setNamuDarbai(namudarbai);

   int egzaminas = Results_interval(rd_generator);
   s.setEgzaminas(egzaminas);
   cout << "\nSugeneruotas egzamino rezultatas: " << egzaminas << endl;
}

//funkcija ivesti studento varda ir pavarde
void ivestiVardaPavarde(Studentas& s) {
   string vardas, pavarde;
   cout << "Įveskite studento vardą: " << endl;
   cin >> vardas;
   cout << "Įveskite studento pavardę: " << endl;
   cin >> pavarde;
   cin.ignore();

   s.setVardas(vardas);
   s.setPavarde(pavarde);
}

//funkcija ivesti pazymius ranka
void ivedimas(Studentas& s) {
   ivestiVardaPavarde(s);

   cout << "Įveskite namų darbų pažymius (Kai baigsite įvedimą, spauskite dukart Enter klavišą):" << endl;

   vector<int> namudarbai;
   //s.namuDarbai.clear();
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

         //Lok.namuDarbai.push_back(pazymys);
         namudarbai.push_back(pazymys);

      } catch (const invalid_argument& e) {
         cout << "Klaida: įvesta ne skaičius. Bandykite dar kartą." << endl;
      } catch (const out_of_range& e) {
         cout << "Klaida: pažymys turi būti tarp 1 ir 10. Bandykite dar kartą." << endl;
      }

   }

   s.setNamuDarbai(namudarbai);

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

         //Lok.egzaminas = pazymys;
         s.setEgzaminas(pazymys);
         break;

      } catch (const invalid_argument& e) {
         cout << "Klaida: įvesta ne skaičius. Bandykite dar kartą." << endl;
      } catch (const out_of_range& e) {
         cout << "Klaida: pažymys turi būti tarp 1 ir 10. Bandykite dar kartą." << endl;
      }
   }

}

//funkcija pasirinkti duomenu ivedimo buda
void pasirinktiDuomenuIvedimoBuda(Studentas& s) {
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
      ivedimas(s);
   } else if (pasirinkimas == 'A') {
      ivestiVardaPavarde(s);
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

      generuotiDuomenis(s, ndSkaicius);
   }

}

//funkcija apskaiciuoti galutini bala
void skaiciuotiGalutini(Studentas& s, char pasirinkimas) {
     if (pasirinkimas == 'V') {
      s.setGalutinis(skaiciuotiGalutiniVidurkiu(s));
   } else if (pasirinkimas == 'M') {
      s.setGalutinis(skaiciuotiGalutiniMediana(s));
   }
}

//funkcija isvesti duomenis
template <typename Container>
void isvedimas(const Container& studentai, char pasirinkimas) {
   if (pasirinkimas == 'V') {
      cout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(20) << "Galutinis (Vid.)" << setw(50) << left << "Adresas atmintyje" << endl;
   } else if (pasirinkimas == 'M') {
      cout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(20) << "Galutinis (Med.)" << setw(50) << left << "Adresas atmintyje" << endl;
   }

   cout << "-------------------------------------------------------------------" << endl;
   for (const auto& s: studentai) {
      cout << left << setw(15) << s.getPavarde() << setw(15) << s.getVardas() << fixed << setprecision(2) << setw(20) << s.getGalutinis() << setw(50) << left << &s << endl;
   }
}


//funkcija skaityti duomenis is failo
template <typename Container>
void nuskaitytiIsFailo(Container& studentai) {
   string failoPavadinimas;
   ifstream failas;

   while (true) {
      try {
         cout << "Įveskite failo pavadinimą: ";
         cin >> failoPavadinimas;
         failas.open(failoPavadinimas);

         if (!failas) {
            throw runtime_error("Nepavyko atidaryti failo: " + failoPavadinimas);
         }

         break;

      } catch (const runtime_error& e) {
         cerr << e.what() << " Bandykite dar kartą." << endl;
      }
   }

   Timer t1;
   //perskaitoma pirma eilute(header) ir praleidziama
   string eilute;
   getline(failas, eilute);

   while (getline(failas, eilute)) {
      stringstream ss(eilute);
      string vardas, pavarde;
      //Studentas tempStudentas;
      ss >> pavarde >> vardas; //pirmi du elementai eiluteje yra pavarde ir vardas, todel jie yra priskiriami pavardei ir vardui

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
            Studentas tempS;
            tempS.setVardas(vardas);
            tempS.setPavarde(pavarde);

            tempS.setEgzaminas(namuDarbai.back());
            namuDarbai.pop_back();
            tempS.setNamuDarbai(move(namuDarbai));

            studentai.push_back(move(tempS));
      }

   }
   failas.close();
   cout << "Failo su " << studentai.size() << " įrašų nuskaitymo laikas: " << t1.elapsed() << " s\n" << endl;

}
template void nuskaitytiIsFailo<vector<Studentas>>(vector<Studentas>&);
template void nuskaitytiIsFailo<list<Studentas>>(list<Studentas>&);

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
   for (const auto& s : studentai)  {
      failas << left << setw(15) << s.getPavarde() << setw(15) << s.getVardas() << fixed << setprecision(2) << s.getGalutinis() << endl;
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

//funkcija suskirstyti studentus i dvi grupe (pirma strategija)
template <typename Container>
void skirstytiStudentusPirmaStrategija(const Container& studentai, Container& vargsiukai, Container& kietiakai) {
   for (const auto& studentas : studentai) {
      if (studentas.getGalutinis() < 5.0) {
         vargsiukai.push_back(studentas);
      } else {
         kietiakai.push_back(studentas);
      }
   }
}

//funkcija suskirstyti studentus i dvi grupe (antra strategija)
template <typename Container>
void skirstytiStudentusAntraStrategija(Container& studentai, Container& vargsiukai) {
   if constexpr(is_same_v<Container, vector<Studentas>>) {
      sort(studentai.begin(), studentai.end(),
      [](const Studentas& a, const Studentas& b) {
         return a.getGalutinis() > b.getGalutinis();
      });

   } else if constexpr (is_same_v<Container, list<Studentas>>){
      studentai.sort([](const Studentas& a, const Studentas& b){
         return a.getGalutinis() > b.getGalutinis();
      });
   }

   while (!studentai.empty()){
      if(studentai.back().getGalutinis() < 5.0){
         vargsiukai.push_back(studentai.back());
         studentai.pop_back();
      } else {
         break;
      }
   }
   // auto it = studentai.begin();
   // while (it != studentai.end()) {
   //    if (it->galutinis < 5.0) {
   //       vargsiukai.push_back(*it);
   //       it = studentai.erase(it);
   //    } else {
   //       ++it;
   //    }
   // }
}

//funkcija suskirstyti studentus i dvi grupe (trecia strategija)
// template <typename Container>
// void skirstytiStudentusTreciaStrategija(Container& studentai, Container& vargsiukai, Container& kietiakai){
//    if constexpr(is_same_v<Container, vector<Studentas>>) {
//       auto it = stable_partition(studentai.begin(), studentai.end(), [](const Studentas& Lok){
//          return Lok.galutinis < 5.0;
//       });
//       vargsiukai.assign(studentai.begin(), it);
//       kietiakai.assign(it, studentai.end());   
//    } else if constexpr (is_same_v<Container, list<Studentas>>){
//       auto it = studentai.begin();
//       while (it != studentai.end()) {
//          if (it->galutinis < 5.0) {
//             vargsiukai.push_back(*it);
//             it = studentai.erase(it);
//          } else {
//             ++it;
//          }
//       }
//    }
// }

//TRECIA STRATEGIJA PAGAL 2
template <typename Container>
void skirstytiStudentusTreciaStrategija(Container& studentai, Container& vargsiukai){
   auto it = stable_partition(studentai.begin(), studentai.end(), [](const Studentas& s) {
      return s.getGalutinis() >= 5.0; 
   });

   while(!studentai.empty()){
      if(studentai.back().getGalutinis() < 5.0){
         vargsiukai.push_back(studentai.back());
         studentai.pop_back();
      } else {
         break;
      }
   }

   // while(it != studentai.end()){
   //    if(it -> galutinis < 5.0){
   //       vargsiukai.push_back(*it);
   //       studentai.pop_back();
   //    } else {
   //       break;
   //    }
   // }

   //vargsiukai.insert(vargsiukai.end(), it, studentai.end());
   // while (it != studentai.end() && it->galutinis < 5.0) {
   //    vargsiukai.push_back(*it);
   //    studentai.pop_back(); 
   // }

}

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

char pasirinktiRusiavimoParametra() {
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
   return parametras;
}

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


//funkcija pasirinkti ivesti duomenis, nuskaityti duomenis is failo ar generuoti faila
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

//funckija iskviesti rankini ivedimo buda 
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

//funckija pasirinkti studentu dalijimo strategija
template <typename Container>
void duomenuIsvedimasPagalStrategija(Container& studentai, char pasirinkimas){
   //Skirstyti studentus i vargsiukus ir kietiakus ir isvesti i failus pagal pasirinkta strategija
   int strategija;
   while (true){
      cout << "Pasirinkite studentų dalijimo į dvi kategorijas strategiją: (1 - pirma, 2 - antra, 3 - trečia strategijos): ";
      int temp;
      cin >> temp;

      if (cin.fail()){
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         cout << "Neteisinga įvestis, bandykite dar kartą. " << endl;
         continue;
      }
      if (temp >= 1 && temp <= 3) {
         strategija = temp;
         break;
      } else {
         cout << "Neteisinga įvestis, bandykite dar kartą. " << endl;
      }
   }

   int kiekis = studentai.size();
   if (strategija == 1){
      Timer t3;
      Container vargsiukai, kietiakai;
      skirstytiStudentusPirmaStrategija(studentai, vargsiukai, kietiakai);
      cout << "Failo su " << kiekis << " įrašų surūšiavimo į dvi grupes laikas: " << t3.elapsed() << " s\n" << endl;

      char parametras = pasirinktiRusiavimoParametra();
      rusiuotiStudentus(vargsiukai, parametras);
      rusiuotiStudentus(kietiakai, parametras);

      Timer t4;
      //Isvesti vargsiukus i faila
      isvedimasIFaila(vargsiukai, pasirinkimas, "vargsiukai.txt");
      //Isvesti kietiakus i faila
      isvedimasIFaila(kietiakai, pasirinkimas, "kietiakai.txt");
      cout << "Failo su " << kiekis << " įrašų išvedimo į failus laikas: " << t4.elapsed() << " s\n" << endl;

   } else if (strategija == 2){
      Timer t3;
      Container vargsiukai;
      skirstytiStudentusAntraStrategija(studentai, vargsiukai);
      cout << "Failo su " << kiekis << " įrašų surūšiavimo į dvi grupes laikas: " << t3.elapsed() << " s\n" << endl;

      char parametras = pasirinktiRusiavimoParametra();
      rusiuotiStudentus(vargsiukai, parametras);
      rusiuotiStudentus(studentai, parametras);

      Timer t4;
      //Isvesti vargsiukus i faila
      isvedimasIFaila(vargsiukai, pasirinkimas, "vargsiukai.txt");
      //Isvesti kietiakus i faila
      isvedimasIFaila(studentai, pasirinkimas, "kietiakai.txt");
      cout << "Failo su " << kiekis << " įrašų išvedimo į failus laikas: " << t4.elapsed() << " s\n" << endl;

   } else if (strategija == 3){
      Timer t3;
      Container vargsiukai, kietiakai;
      skirstytiStudentusTreciaStrategija(studentai, vargsiukai);
      cout << "Failo su " << kiekis << " įrašų surūšiavimo į dvi grupes laikas: " << t3.elapsed() << " s\n" << endl;

      char parametras = pasirinktiRusiavimoParametra();
      rusiuotiStudentus(vargsiukai, parametras);
      rusiuotiStudentus(studentai, parametras);

      Timer t4;
      //Isvesti vargsiukus i faila
      isvedimasIFaila(vargsiukai, pasirinkimas, "vargsiukai.txt");
      //Isvesti kietiakus i faila
      isvedimasIFaila(studentai, pasirinkimas, "kietiakai.txt");
      cout << "Failo su " << kiekis << " įrašų išvedimo į failus laikas: " << t4.elapsed() << " s\n" << endl;
   }
}
template void duomenuIsvedimasPagalStrategija<vector<Studentas>>(vector<Studentas>&, char pasirinkimas);
template void duomenuIsvedimasPagalStrategija<list<Studentas>>(list<Studentas>&, char pasirinkimas);