
#ifndef  STUD_H_INCLUDED
#define STUD_H_INCLUDED

#include "Lib.h"
#include "Studentas.h"


// //struktura studento duomenims saugoti
// struct Studentas {
//    string vardas;
//    string pavarde;
//    vector<int> namuDarbai;
//    int egzaminas;
//    double galutinis;
// };

/**
 * @brief Leidžia vartotojui įvesti studento pažymius (namų darbų pažymius ir egzamino rezultatą) ranka.
 * 
 * Ši funkcija leidžia vartotojui ranka įvesti studento namų darbų pažymius ir egzamino rezultatą.
 * Įvedus šiuos duomenis, jie išsaugomi paduotame konteineryje.
 * 
 * @tparam Container Konteinerio tipas, kuriame bus saugoma studentų informacija (pvz., std::vector arba std::list).
 * @param studentai Konteineris, kuriame bus išsaugoti įvesti studentai.
 * @param vardas Studentų vardas.
 * @param pavarde Studentų pavardė.
 */
template <typename Container>
void ivedimas(Container& studentai, string vardas, string pavarde);
 

 /**
 * @brief Funkcija apskaičiuoti galutinį balą studentui.
 * 
 * Ši funkcija leidžia apskaičiuoti studento galutinį balą naudojant 
 * vidurkį arba medianą, priklausomai nuo vartotojo pasirinkimo.
 * 
 * @param s Studentas, kurio galutinis balas bus apskaičiuotas.
 * @param pasirinkimas Pasirinkimo reikšmė, kuri nurodo skaičiavimo metodą:
 * - 'V': Skaičiuoti galutinį balą vidurkiu.
 * - 'M': Skaičiuoti galutinį balą mediana.
 */
void skaiciuotiGalutini(Studentas& s, char pasirinkimas);


/**
 * @brief Funkcija išvesti studentų duomenis į terminalą.
 * 
 * Ši funkcija išveda studentų pavardes, vardus, galutinius balus 
 * (vidurkiu arba mediana) ir jų atminties adresus.
 * 
 * @tparam Container Konteinerio tipas, kuriame saugomi studentų duomenys.
 * @param studentai Konteineris, kuriame yra studentų objektai.
 * @param pasirinkimas Pasirinkimo simbolis, kuris nurodo, kokią antraštę naudoti galutinį balą išvesti:
 * - 'V': Galutinis balas apskaičiuotas vidurkiu.
 * - 'M': Galutinis balas apskaičiuotas mediana.
 */
template <typename Container>
void isvedimas(const Container& studentai, char pasirinkimas);


/**
 * @brief Funkcija skaityti studentų duomenis iš failo.
 * 
 * Ši funkcija nuskaito studentų duomenis iš tekstinio failo ir užpildo 
 * pateiktą konteinerį studentų objektais.
 * 
 * @tparam Container Konteinerio tipas, kuriame bus saugomi studentų objektai (pvz., std::vector arba std::list).
 * @param studentai Konteineris, į kurį bus įrašomi nuskaitomi studentų duomenys.
 * 
 * @details
 * - Vartotojui prašoma įvesti failo pavadinimą. Jei failo atidaryti nepavyksta, išmetama klaida ir leidžiama bandyti dar kartą.
 * - Failo pirmoji eilutė (antraštė) praleidžiama.
 * - Kiekviena kita eilutė apdorojama: pirmieji du žodžiai interpretuojami kaip pavardė ir vardas, o likę skaičiai – kaip pažymiai.
 * - Paskutinis pažymys laikomas egzamino rezultatu; kiti įrašomi į namų darbų sąrašą.
 * - Netinkamos reikšmės (simboliai ar pažymiai už intervalo) ignoruojamos ir apie tai pranešama vartotojui.
 * - Laikmatis matuoja, kiek laiko užtruko failo nuskaitymas.
 * 
 * @exception
 * - Išimtis `std::runtime_error` išmetama, jei nepavyksta atidaryti failo.
 * - Klaidos dėl netinkamų reikšmių (pvz., `invalid_argument` ar `out_of_range`) yra tvarkomos lokaliai ir apie jas informuojamas vartotojas.
 */
template <typename Container>
void nuskaitytiIsFailo(Container& studentai);


/**
 * @brief Funkcija įrašyti studentų rezultatus į failą.
 * 
 * Ši funkcija įrašo pateiktame konteineryje esančių studentų duomenis 
 * į nurodytą failą. Galutinis balas gali būti apskaičiuotas vidurkiu arba mediana, 
 * priklausomai nuo vartotojo pasirinkimo.
 * 
 * @tparam Container Konteinerio tipas, kuriame saugomi studentų duomenys (pvz., vector arba list).
 * @param studentai Konteineris, kuriame yra studentų objektai.
 * @param pasirinkimas Pasirinkimo simbolis, kuris nurodo, kokį galutinį balą įrašyti:
 * - 'V': Galutinis balas apskaičiuotas vidurkiu.
 * - 'M': Galutinis balas apskaičiuotas mediana.
 * @param failoPavadinimas Failo pavadinimas, į kurį bus įrašomi rezultatai.
 * 
 * @exception
 * - Jei failo nepavyksta atidaryti, klaida pranešama per standartinį klaidų srautą (`std::cerr`).
 */
template <typename Container>
void isvedimasIFaila(const Container& studentai, char pasirinkimas, const string& failoPavadinimas);


/**
 * @brief Funkcija generuoti failą su atsitiktiniais studentų duomenimis.
 * 
 * Ši funkcija sukuria tekstinį failą su studentų pavardėmis, vardais, 15 namų darbų
 * įvertinimais ir egzamino balais. Sugeneruoti duomenys yra išsaugomi nurodytame faile.
 * 
 * @param studentuSkaicius Studentų įrašų, kuriuos reikia sugeneruoti, skaičius.
 * @param failoPavadinimas Failo, kuriame bus saugomi sugeneruoti duomenys, pavadinimas.
 * 
 * @details
 * Funkcijos veikimo eiga:
 * - Į failą rašoma antraštė su stulpelių pavadinimais: "Pavarde", "Vardas", 15 namų darbų (ND1-ND15) ir "Egzaminas".
 * - Ciklo pagalba sugeneruojami studentų duomenys:
 *   - Vardas ir pavardė formuojami kaip "Vardas1", "Pavarde1" ir pan.
 *   - Atsirtiktinai sugeneruojami 15 namų darbų įvertinimų ir vienas egzamino balas.
 *   - Visi sugeneruoti duomenys įrašomi į failą formatuotu būdu.
 */
void generuotiFaila(int studentuSkaicius, const string& failoPavadinimas);


/**
 * @brief Funkcija studentų skirstymui į dvi grupes naudojant pirmąją strategiją.
 * 
 * Ši funkcija studentus padalina į dvi grupes: "vargšiukai" (studentai, kurių galutinis balas mažesnis už 5) 
 * ir "kietiakai" (studentai, kurių galutinis balas yra 5 arba didesnis).
 * 
 * @tparam Container Konteinerio, kuriame saugomi studentų duomenys, tipas (pvz., `std::vector` arba `std::list`).
 * @param studentai Pirminis konteineris su visais studentų duomenimis.
 * @param vargsiukai Konteineris, į kurį bus perkelti studentai su galutiniu balu mažesniu nei 5.
 * @param kietiakai Konteineris, į kurį bus perkelti studentai su galutiniu balu 5 arba didesniu.
 * 
 * @details
 * Funkcijos veikimo eiga:
 * - Pereinama per kiekvieną studentą iš pradinio konteinerio `studentai`.
 * - Pagal studento galutinį balą, gautą per metodą `getGalutinis()`, studentas įtraukiamas į atitinkamą grupę:
 *   - Jei galutinis balas < 5.0, studentas perkeliamas į konteinerį `vargsiukai`.
 *   - Priešingu atveju, studentas perkeliamas į konteinerį `kietiakai`.
 * 
 * @note Funkcija nekeičia pradinio `studentai` konteinerio turinio.
 */
template <typename Container>
void skirstytiStudentusPirmaStrategija(const Container& studentai, Container& vargsiukai, Container& kietiakai);


/**
 * @brief Funkcija studentų skirstymui į dvi grupes naudojant antrąją strategiją.
 * 
 * Ši funkcija studentus padalina į dvi grupes: "vargšiukai" (studentai, kurių galutinis balas mažesnis už 5) 
 * ir likusieji studentai. Studentai rūšiuojami pagal galutinį balą mažėjančia tvarka, o "vargšiukai" 
 * perkeliami iš pradinio konteinerio į atskirą konteinerį.
 * 
 * @tparam Container Konteinerio, kuriame saugomi studentų duomenys, tipas (pvz., `std::vector` arba `std::list`).
 * @param studentai Pradinis konteineris su visais studentų duomenimis.
 * @param vargsiukai Konteineris, į kurį bus perkelti studentai su galutiniu balu mažesniu nei 5.
 * 
 * @details
 * Funkcijos veikimo eiga:
 * - Studentai rūšiuojami pagal galutinį balą mažėjančia tvarka
 * - Pereinama per konteinerį `studentai` nuo galo:
 *   - Jei studento galutinis balas < 5.0, jis perkeliamas į konteinerį `vargsiukai`.
 *   - Kai randamas pirmasis studentas su balu >= 5.0, iteracija nutraukiama, nes likę studentai taip pat turi balus >= 5.0.
 * 
 * @note Funkcija modifikuoja pradinį `studentai` konteinerį, pašalindama iš jo studentus, kurie perkeliami į `vargsiukai`.
 */
template <typename Container>
void skirstytiStudentusAntraStrategija(Container& studentai, Container& vargsiukai);


/**
 * @brief Funkcija studentų skirstymui į dvi grupes naudojant trečiąją strategiją.
 * 
 * Ši funkcija studentus padalina į dvi grupes: "vargšiukai" (studentai, kurių galutinis balas mažesnis už 5) 
 * ir likusieji studentai. Naudojamas `std::stable_partition`, kad būtų paspartinas funkcijos veikimo laikas.
 * 
 * @tparam Container Konteinerio, kuriame saugomi studentų duomenys, tipas (pvz., `std::vector` arba `std::list`).
 * @param studentai Pradinis konteineris su visais studentų duomenimis.
 * @param vargsiukai Konteineris, į kurį bus perkelti studentai su galutiniu balu mažesniu nei 5.
 * 
 * @details
 * Funkcijos veikimo eiga:
 * - Naudojama `std::stable_partition`, kad išskirstytų studentus į dvi dalis:
 *   - Studentai, kurių galutinis balas >= 5.0, lieka priekyje.
 *   - Studentai, kurių galutinis balas < 5.0, perkelti į pabaigą.
 * - Pereinama per konteinerį `studentai` nuo galo:
 *   - Jei studento galutinis balas < 5.0, jis perkeliamas į konteinerį `vargsiukai` ir pašalinamas iš `studentai`.
 *   - Kai randamas pirmasis studentas su balu >= 5.0, iteracija nutraukiama.
 * 
 * @note Funkcija modifikuoja pradinį `studentai` konteinerį, pašalindama iš jo studentus, kurie perkeliami į `vargsiukai`.
 */
template <typename Container>
void skirstytiStudentusTreciaStrategija(Container& studentai, Container& vargsiukai);


/**
 * @brief Funkcija studentų rūšiavimui pagal pasirinktą parametrą.
 * 
 * Ši funkcija rūšiuoja studentus pagal nurodytą kriterijų (`vardas`, `pavardė` arba `galutinis pažymys`
 * (didėjančia arba mažėjančia tvarka)). Funkcija automatiškai pritaiko tinkamą rūšiavimo algoritmą, 
 * atsižvelgdama į naudojamo konteinerio tipą (`std::vector` arba `std::list`).
 * 
 * @tparam Container Konteinerio, kuriame saugomi studentų duomenys, tipas (pvz., `std::vector` arba `std::list`).
 * @param studentai Konteineris su studentų duomenimis, kuris bus surūšiuotas.
 * @param parametras Rūšiavimo kriterijus:
 * - `'V'` - rūšiavimas pagal vardą (abėcėlės tvarka). Jei vardai sutampa, rūšiuojama pagal pavardę.
 * - `'P'` - rūšiavimas pagal pavardę (abėcėlės tvarka). Jei pavardės sutampa, rūšiuojama pagal vardą.
 * - `'M'` - rūšiavimas pagal galutinį pažymį mažėjimo tvarka.
 * - `'D'` - rūšiavimas pagal galutinį pažymį didėjimo tvarka.
 */
template <typename Container>
void rusiuotiStudentus(Container& studentai, char parametras);


/**
 * @brief Funkcija leidžia vartotojui pasirinkti galutinio balo skaičiavimo metodą.
 * 
 * Ši funkcija prašo vartotojo pasirinkti, kuris metodas bus naudojamas galutiniam balui apskaičiuoti: 
 * vidurkiu arba mediana. Pasirinktas metodas grąžinamas kaip simbolis.
 * 
 * @return char Grąžinamas vartotojo pasirinktas metodas:
 * - `'V'` - galutinio balo skaičiavimas naudojant vidurkį.
 * - `'M'` - galutinio balo skaičiavimas naudojant medianą.
 * 
 * @note Funkcija užtikrina, kad grąžinama reikšmė visada bus validi (`V` arba `M`).
 */
char pasirinktiGalutinioskaiciavimoMetoda();


/**
 * @brief Funkcija leidžia vartotojui pasirinkti studentų rūšiavimo parametrą.
 * 
 * Ši funkcija prašo vartotojo pasirinkti, pagal kokį parametrą studentai bus surūšiuoti: 
 * pagal vardą, pavardę arba galutinį rezultatą mažėjimo ar didėjimo tvarka.
 * 
 * @return char Grąžinamas vartotojo pasirinktas rūšiavimo parametras:
 * - `'V'` - rūšiavimas pagal vardą.
 * - `'P'` - rūšiavimas pagal pavardę.
 * - `'M'` - rūšiavimas pagal galutinį rezultatą mažėjimo tvarka.
 * - `'D'` - rūšiavimas pagal galutinį rezultatą didėjimo tvarka.
 * 
 * @note Funkcija užtikrina, kad grąžinama reikšmė visada bus validi (`V`, `P`, `M`, arba `D`).
 */
char pasirinktiRusiavimoParametra();

//funckija pasirinkti rezultato isvedimo buda
template <typename Container>
void pasirinktiRezultatuIsvedimoBuda(const Container& studentai, char pasirinkimas);

//funkcija pasirinkti ivesti duomenis, nuskaityti duomenis is failo ar generuoti faila
char pasirinktiDuomenuIvedima();

// funkcija ivesti studentu duomenis ranka
template <typename Container>
void ivedimasRanka(Container& studentas);

//funckija skirstyti studentus i vargsiukus ir kietiakus, surusiuoti pagal pasirinkta parametra ir isvesti i failus pagal pasirinkta strategija
template <typename Container>
void duomenuIsvedimasPagalStrategija(Container& studentai, char pasirinkimas);


#endif