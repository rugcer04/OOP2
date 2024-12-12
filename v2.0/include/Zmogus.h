#ifndef  ZMOGUS_H_INCLUDED
#define ZMOGUS_H_INCLUDED
#include <iostream>
#include <string>

using std::string;

/**
 * @brief Abstrakti bazinė klasė žmogaus duomenims saugoti.
 * 
 * Klasė apibrėžia bendras savybes ir metodus, reikalingus žmogaus duomenims apdoroti, negalima sukurti žmogaus tipo objektų, o tik objektus iš jos išvestinių klasių.
 * Klasė apibrėžia pagrindinius atributus (vardas, pavardė). Ji yra abstrakti, nes turi virtualią funkciją, kuri turi būti įgyvendinta išvestinėje klasėse.
 */
class Zmogus{
    protected:
        /**
         * @brief Žmogaus vardas.
         */
        string vardas_;

        /**
        * @brief Žmogaus pavardė.
        */
        string pavarde_;

        /**
        * @brief Numatytasis konstruktorius.
        * 
        * Konstruktoriumi galima naudotis tik išvestinėse klasėse.
        */
        Zmogus(){ };

        /**
        * @brief Konstruktorius su parametrais.
        * 
        * Inicializuoja vardą ir pavardę pateiktais parametrais.
        * 
        * @param vardas Žmogaus vardas.
        * @param pavarde Žmogaus pavardė.
        */
        Zmogus(const string& vardas, const string& pavarde)
            : vardas_(vardas), pavarde_(pavarde) {}

    public:
        /**
        * @brief Virtualus destruktorius.
        * 
        * Naudojamas atminties atlaisvinimui paveldėtose klasėse.
        */
        virtual ~Zmogus() = default;

        /**
        * @brief Grynai virtuali funkcija žmogaus vardui gauti.
        * 
        * Ši funkcija turi būti įgyvendinta išvestinėse klasėse.
        * 
        * @return Žmogaus vardas kaip string.
        */
        virtual string getVardas() const = 0;

        /**
        * @brief Grynai virtuali funkcija žmogaus pavardei gauti.
        * 
        * Ši funkcija turi būti įgyvendinta išvestinėse klasėse.
        * 
        * @return Žmogaus pavardė kaip string.
        */
        virtual string getPavarde() const = 0;
};

#endif