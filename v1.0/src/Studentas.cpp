#include "../include/Stud.h"
#include "../include/Studentas.h"

Studentas::Studentas(const string& vardas, const string& pavarde, const vector<int>& namudarbai, double egzaminas){
   vardas_ = vardas;
   pavarde_ = pavarde;
   namudarbai_ = namudarbai;
   egzaminas_ = egzaminas;
   galutinis_ = 0.0;
}

//konstruktorius generuojantis ivertinimus
Studentas::Studentas(const string& vardas, const string& pavarde, int ndSkaicius){
   random_device rd_generator;
   uniform_int_distribution<int> Results_interval(1, 10);

   vardas_ = vardas;
   pavarde_ = pavarde;

   cout << "Sugeneruoti namų darbų pažymiai: ";
   for (int i = 0; i < ndSkaicius; i++) {
      int pazymys = Results_interval(rd_generator);
      namudarbai_.push_back(pazymys);
      cout << pazymys << " ";
   }

   int egzaminas = Results_interval(rd_generator);
   cout << "\nSugeneruotas egzamino rezultatas: " << egzaminas << endl;
   egzaminas_ = egzaminas;
}

//destruktorius
Studentas::~Studentas(){
   vardas_.clear();
   pavarde_.clear();
   namudarbai_.clear();
   egzaminas_ = 0;
   galutinis_ = 0.0;
}

//metodas skaiciuoti galutini pagal vidurki
void Studentas::skaiciuotiGalutiniVidurkiu(){
   if (namudarbai_.empty()){
      galutinis_ = egzaminas_ * 0.6;
   } else {
      double vidurkis = 0.0;

      for (int nd : namudarbai_){
         vidurkis += nd;
      }

      vidurkis /= namudarbai_.size();
      galutinis_ = vidurkis * 0.4 + egzaminas_ * 0.6;
   }

   //return s.getGalutinis();
}

//metodas skaiciuoti galutini pagal mediana
void Studentas::skaiciuotiGalutiniMediana() {
   if (namudarbai_.empty()) {
      galutinis_ = egzaminas_ * 0.6;
   }

   sort(namudarbai_.begin(), namudarbai_.end()) ;
   double mediana;
   int size = namudarbai_.size();

   if (size % 2 == 0) {
      mediana = (namudarbai_[size / 2 - 1] + namudarbai_[size / 2]) / 2.0; 
   } else {
      mediana = namudarbai_[size / 2];
   }

   galutinis_ = mediana * 0.4 + egzaminas_ * 0.6;
}

// Studentas::Studentas(istream& is) {
//    string vardas, pavarde;
//    is >> pavarde >> vardas;

//    string reiksme;
//    vector<int> namudarbai;
//    while (is >> reiksme) {
//       try {
//          int pazymys = stoi(reiksme);
//          if (pazymys >= 1 && pazymys <= 10) {
//             namudarbai.push_back(pazymys);
//          } else {
//             cerr << "Netinkamas pažymys (" << pazymys << "), praleidžiama reikšmė" << endl;
//          }
//       } catch (invalid_argument&) {
//          cerr << "Netinkamas simbolis (" << reiksme << "), praleidžiama reikšmė." << endl;
//       } catch (out_of_range&) {
//          cerr << "Pažymys už intervalo ribų, praleidžiama reikšmė." << endl;
//       }
      
//    }

//    if (!namudarbai.empty()) {
//       egzaminas_ = namudarbai.back();
//       namudarbai.pop_back();
//       namudarbai_ = move(namudarbai);
//    }

//    vardas_ = vardas;
//    pavarde_ = pavarde;
// }