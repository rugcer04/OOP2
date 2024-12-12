#ifndef  STUDENTAS_H_INCLUDED
#define STUDENTAS_H_INCLUDED

#include "../include/Zmogus.h"

/**
 * @class Studentas
 * @brief Klasė, reprezentuojanti studento informaciją.
 * 
 * @details
 * Klasė paveldi iš bazinės klasės "Zmogus" ir saugo informaciją
 * apie studento namų darbus, egzamino rezultatą bei galutinį įvertinimą.
 */
class Studentas : public Zmogus{
   private:

      /// Vektorius, saugantis studento namų darbų įvertinimus.
      vector<int> namudarbai_;

      /// Egzamino įvertinimas (skaicius nuo 0 iki 10).
      int egzaminas_;

      /// Galutinis studento įvertinimas (skaicius nuo 0 iki 10).
      double galutinis_;

   public:
      // konstruktoriai
      /**
      * @brief Numatytasis konstruktorius.
      */
      Studentas(){ };

      /**
      * @brief Pilnas konstruktorius.
      * 
      * @param vardas Studentų vardas.
      * @param pavarde Studentų pavardė.
      * @param namudarbai Namų darbų įvertinimų vektorius.
      * @param egzaminas Egzamino įvertinimas.
      */
      Studentas(const string& vardas, const string& pavarde, const vector<int>& namudarbai, double egzaminas);

      /**
      * @brief Konstruktorius, sugeneruojantis namų darbų įvertinimus.
      * 
      * @param vardas Studentų vardas.
      * @param pavarde Studentų pavardė.
      * @param ndSkaicius Namų darbų skaičius, kuriam sugeneruojami įvertinimai.
      */
      Studentas(const string& vardas, const string& pavarde, int ndSkaicius);

      /**
      * @brief Kopijavimo konstruktorius.
      * 
      * @param kitas Kitas "Studentas" klasės objektas, kurio reikšmės kopijuojamos.
      */
      Studentas(const Studentas& kitas);

      /**
      * @brief Destruktorius.
      * 
      * @details Atlaisvina "Studentas" klasės objektų resursus.
      */
      ~Studentas();

      // operatoriai
      /**
      * @brief Išvedimo operatorius.
      * 
      * @details Formatuotai išveda studento informaciją (pavardę, vardą ir galutinį įvertinimą) į srautą.
      * 
      * @param os Išvedimo srautas (pavyzdžiui, std::cout).
      * @param s Studentas, kurio informacija bus išvedama.
      * @return Nuoroda į išvedimo srautą.
      */
      friend ostream& operator<< (ostream& os, const Studentas& s);

      /**
      * @brief Įvedimo operatorius.
      * 
      * @details Leidžia įvesti studento informaciją iš srauto (pavyzdžiui, std::cin ar failo). Jei įvestis
      * yra iš konsolės, vartotojui pateikiami klausimai ir pasirinkimai apie duomenų įvedimą.
      * 
      * @param is Įvedimo srautas (pavyzdžiui, std::cin).
      * @param s Studentas, kurio duomenys bus įvedami.
      * @return Nuoroda į įvedimo srautą.
      */
      friend istream& operator>> (istream& is, Studentas& s);

      /**
      * @brief Priskyrimo operatorius.
      * 
      * @details Priskiria vieno "Studentas" objekto reikšmes kitam objektui.
      * 
      * @param kitas Kitas "Studentas" klasės objektas, kurio reikšmės priskiriamos.
      * @return Nuoroda į patį "Studentas" objektą.
      */
      Studentas& operator=(const Studentas& kitas);

      // seteriai
      // Seteriai

      /// \brief Nustato studento vardą.
      /// \param vardas Naujas studento vardas.
      void setVardas(const string& vardas) { vardas_ = vardas; }

      /// \brief Nustato studento pavardę.
      /// \param pavarde Nauja studento pavardė.
      void setPavarde(const string& pavarde) { pavarde_ = pavarde; }

      /// \brief Nustato studento namų darbų pažymius.
      /// \param namudarbai Vektorius, kuriame yra namų darbų pažymiai.
      void setNamuDarbai(const vector<int>& namudarbai) { namudarbai_ = namudarbai;}

      /// \brief Nustato studento egzamino pažymį.
      /// \param egzaminas Egzamino pažymio reikšmė.
      void setEgzaminas(const int& egzaminas) { egzaminas_ = egzaminas; }

      /// \brief Nustato studento galutinį pažymį.
      /// \param galutinis Galutinio pažymio reikšmė.
      void setGalutinis(const double& galutinis){ galutinis_ = galutinis;}

      // geteriai

      /// \brief Grąžina studento namų darbų pažymius.
      /// \return Vektorius su namų darbų pažymiais.
      inline vector<int> getNamudarbai() const { return namudarbai_; }

      /// \brief Grąžina studento egzamino pažymį.
      /// \return Egzamino pažymio reikšmė.
      inline int getEgzaminas() const { return egzaminas_; }

      /// \brief Grąžina studento galutinį pažymį.
      /// \return Galutinio pažymio reikšmė.
      inline double getGalutinis() const { return galutinis_; }

      // implementuoti virtualus geteriai
      /// \brief Grąžina studento vardą.
      /// \return Studentą reprezentuojantis vardas.
      string getVardas() const override { return vardas_; }

      /// \brief Grąžina studento pavardę.
      /// \return Studentą reprezentuojanti pavardė.
      string getPavarde() const override { return pavarde_; }

      // metodai
      /**
      * @brief Skaiciuoja galutinį įvertinimą pagal vidurkį.
      * 
      * @details 
      * Jei namų darbų sąrašas yra tuščias, galutinis įvertinimas skaičiuojamas
      * tik iš egzamino balo. Jei yra namų darbų balai, jie vidurkinami ir sudaromas
      * galutinis įvertinimas, kur 40% sudaro vidurkis, o 60% - egzamino balas.
      */
      void skaiciuotiGalutiniVidurkiu();

      /**
      * @brief Skaiciuoja galutinį įvertinimą pagal medianą.
      * 
      * @details 
      * Jei namų darbų sąrašas yra tuščias, galutinis įvertinimas skaičiuojamas
      * tik iš egzamino balo. Jei yra namų darbų balai, jie surūšiuojami ir apskaičiuojama
      * mediana, kuri sudaro 40% galutinio įvertinimo, o likusieji 60% - egzamino balas.
      */
      void skaiciuotiGalutiniMediana();

};

#endif