#ifndef  STUDENTAS_H_INCLUDED
#define STUDENTAS_H_INCLUDED

#include "Lib.h"
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
      // Studentas() : egzaminas_(0), galutinis_(0.0) { }
      // Studentas(const string& vardas, const string& pavarde, const vector<int>& namudarbai, double egzaminas):
      // vardas_(vardas), pavarde_(pavarde), namudarbai_(move(namudarbai)), egzaminas_(egzaminas), galutinis_(0.0) { }
      //Studentas(istream& is); //constructor that takes an input stream, allowing the student data to be read from a stream
      Studentas(const string& vardas, const string& pavarde, const vector<int>& namudarbai, double egzaminas);
      ~Studentas();

      // seteriai
      void setVardas(const string& vardas) { vardas_ = vardas; }
      void setPavarde(const string& pavarde) { pavarde_ = pavarde; }
      void setNamuDarbai(const vector<int>& namudarbai) { namudarbai_ = namudarbai;}
      void setEgzaminas(const int& egzaminas) { egzaminas_ = egzaminas; }
      void setGalutinis(const double& galutinis){ galutinis_ = galutinis;}

      // geteriai
      inline string getVardas() const { return vardas_; }
      inline string getPavarde() const { return pavarde_; }
      inline vector<int> getNamudarbai() const { return namudarbai_; }
      inline int getEgzaminas() const { return egzaminas_; }
      inline double getGalutinis() const { return galutinis_; }

      // metodai
      void skaiciuotiGalutiniVidurkiu();
      void skaiciuotiGalutiniMediana();

};

#endif