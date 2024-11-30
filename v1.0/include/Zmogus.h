#ifndef  ZMOGUS_H_INCLUDED
#define ZMOGUS_H_INCLUDED
#include <iostream>
#include <string>

using std::string;

class Zmogus{
   protected:
      string vardas_;
      string pavarde_;

      Zmogus(const string& vardas, const string& pavarde)
      : vardas_(vardas), pavarde_(pavarde) {}

   public:
      virtual ~Zmogus() = default;

      string getVardas() const { return vardas_; }
      string getPavarde() const { return pavarde_; }
};

#endif