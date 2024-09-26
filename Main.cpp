
#include "Lib.h"
#include "Stud.h"
#include "Stud.cpp"



int main() {
   srand(time(0));

    vector<Studentas> studentai;

    //Pasirinkimas duomenims įvesti
    char duomenuIvedimoBudas;
    cout << "Ar norite duomenis įvesti (I) ar nuskaityti iš failo (F)? ";
    cin >> duomenuIvedimoBudas;
    duomenuIvedimoBudas = toupper(duomenuIvedimoBudas);
    
    if (duomenuIvedimoBudas == 'I') {
        cout << "Įveskite studentų skaičių: ";
        int studentuSk;
        cin >> studentuSk;
        studentai.resize(studentuSk);

        for (int i = 0; i < studentuSk; i++) {
            pasirinktiDuomenuIvedimoBuda(studentai[i]);
        }

    } else if (duomenuIvedimoBudas == 'F') {
        string failoPavadinimas;
        cout << "Įveskite failo pavadinimą: ";
        cin >> failoPavadinimas;
        nuskaitytiIsFailo(studentai, failoPavadinimas);
    }

    //Pasirinkimas galutio balo skaičiavimo metodui
    char pasirinkimas;
    do {
      cout << "Pasirinkite galutinio balo skaičiavimo metodą (V- vidurkiu, M- mediana): ";
      cin >> pasirinkimas;
      pasirinkimas = toupper(pasirinkimas);
    } while (pasirinkimas != 'V' && pasirinkimas != 'M');

    for (Studentas& studentas : studentai) {
        skaiciuotiGalutini(studentas, pasirinkimas);
    }

    //Pasirinkimas rezultatų išvedimui
    char isvedimoBudas;
    cout << "Ar norite išvesti rezultatus į ekraną (E) ar į failą (F)? ";
    cin >> isvedimoBudas;
    isvedimoBudas = toupper(isvedimoBudas);

    if (isvedimoBudas == 'E') {
      isvedimas(studentai, pasirinkimas);
    } else if (isvedimoBudas = 'F') {
      string failoPavadinimas;
      cout << "Įveskite failo pavadinimą rezultatams išsaugoti: ";
      cin >> failoPavadinimas;
      isvedimasIFaila(studentai, pasirinkimas, failoPavadinimas);
    }

    return 0;

}
