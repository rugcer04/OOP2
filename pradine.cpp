#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

//struktura studento duomenims saugoti
struct Studentas {
   string vardas;
   string pavarde;
   vector<int> namuDarbai;
   int egzaminas;
   double galutinis;
};