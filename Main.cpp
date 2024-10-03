#include "Lib.h"
#include "Stud.h"
#include "Stud.cpp"

int main() {
    vector<Studentas> studentai;

    //Pasirinkimas duomenims įvesti
    char duomenuIvedimoBudas;
    while (true) {
        cout << "Ar norite duomenis įvesti (I) ar nuskaityti iš failo (F)? ";
        cin >> duomenuIvedimoBudas;
        duomenuIvedimoBudas = toupper(duomenuIvedimoBudas);

        if (duomenuIvedimoBudas == 'I' || duomenuIvedimoBudas == 'F') {
            break;
        } else {
            cout << "Neteisinga įvestis, bandykite dar kartą.\n";
        }
    }
    
    if (duomenuIvedimoBudas == 'I') {
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

    //Pasirinkimas galutinio balo skaičiavimo metodui
    char pasirinkimas;
    do {
      cout << "Pasirinkite galutinio balo skaičiavimo metodą (V- vidurkiu, M- mediana): ";
      cin >> pasirinkimas;
      pasirinkimas = toupper(pasirinkimas);
    } while (pasirinkimas != 'V' && pasirinkimas != 'M');

    for (Studentas& studentas : studentai) {
        skaiciuotiGalutini(studentas, pasirinkimas);
    }

    //Surūšiuojame studentus pagal pavardę
    sort(studentai.begin(), studentai.end(),
        [](const Studentas& a, const Studentas& b) {
            if (a.pavarde == b.pavarde) {
                return a.vardas < b.vardas; //jei pavardes vienodos, rusiuojame pagal vardus
            }
            return a.pavarde < b.pavarde;
        }
    );

    //Pasirinkimas rezultatų išvedimui
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
    } else if (isvedimoBudas = 'F') {
      string failoPavadinimas;
      cout << "Įveskite failo pavadinimą rezultatams išsaugoti: ";
      cin >> failoPavadinimas;
      isvedimasIFaila(studentai, pasirinkimas, failoPavadinimas);
    }

    return 0;
}
