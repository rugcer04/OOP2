#include "Lib.h"
#include "Stud.h"
#include "Stud.cpp"

#include <chrono>
using namespace std::chrono;

int main() {
    high_resolution_clock::time_point start, end;
    duration<double> failoKuriamoLaikas, duomenuNuskaitymoLaikas, studentuRusiavimoLaikas, studentuIsvedimoLaikas;
    
    vector<Studentas> studentai;

    //Pasirinkimas duomenims įvesti
    char duomenuIvedimoBudas;
    while (true) {
        cout << "Ar norite duomenis įvesti (I), nuskaityti iš failo (F), ar sugeneruoti failą ir jį nuskaityti (G)? ";
        cin >> duomenuIvedimoBudas;
        duomenuIvedimoBudas = toupper(duomenuIvedimoBudas);

        if (duomenuIvedimoBudas == 'I' || duomenuIvedimoBudas == 'F' || duomenuIvedimoBudas == 'G') {
            break;
        } else {
            cout << "Neteisinga įvestis, bandykite dar kartą.\n";
        }
    }
    
    //Ivesti rankiniu budu
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

    }
    //Nuskaitymas is failo
     else if (duomenuIvedimoBudas == 'F') {
        string failoPavadinimas;
        cout << "Įveskite failo pavadinimą: ";
        cin >> failoPavadinimas;
        nuskaitytiIsFailo(studentai, failoPavadinimas);
    }

    //failo generavimas ir nuskaitymas
    else if (duomenuIvedimoBudas == 'G') {
        string failoPavadinimas;
        int studentuSkaicius;

        cout << "Įveskite, kiek studentų norite sugeneruoti: ";
        cin >> studentuSkaicius;

        cout << "Įveskite failo pavadinimą: ";
        cin >> failoPavadinimas;

        start = high_resolution_clock::now();
        generuotiFaila(studentuSkaicius, failoPavadinimas);
        end = high_resolution_clock::now();
        failoKuriamoLaikas = duration_cast<duration<double>>(end - start);

        //generuotiFaila(10, failoPavadinimas);
        start = high_resolution_clock::now();
        nuskaitytiIsFailo(studentai, failoPavadinimas);
        end = high_resolution_clock::now();
        duomenuNuskaitymoLaikas = duration_cast<duration<double>>(end - start);
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

    //Surusiuojame studentus
    char parametras;
    cout << "Pasirinkite kokia tvarka norėtumėte pateikti studentus: surūšiuotus pagal vardą (V), pagal pavardę (P), pagal galutinį rezultatą mažėjamo tvarka (M) ar didėjimo tvarka (D): ";
    cin >> parametras;
    parametras = toupper(parametras);

    start = high_resolution_clock::now();
    rusiuotiStudentus(studentai, parametras);
    end = high_resolution_clock::now();
    studentuRusiavimoLaikas = duration_cast<duration<double>>(end - start);

    //Skirstyti studentus i vargsiukus ir kietiakus
    vector<Studentas> vargsiukai, kietiakai;
    skirstytiStudentus(studentai, vargsiukai, kietiakai);

    start = high_resolution_clock::now();

    //Isvesti vargsiukus i faila
    isvestiGrupesIFaila(vargsiukai, "vargsiukai.txt", pasirinkimas);

    //Isvesti kietiakus i faila
    isvestiGrupesIFaila(kietiakai, "kietiakai.txt", pasirinkimas);

    end = high_resolution_clock::now();
    studentuIsvedimoLaikas = duration_cast<duration<double>>(end - start);

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

    if (duomenuIvedimoBudas == 'G') {
        cout << "Failo generavimas užtruko: " << failoKuriamoLaikas.count() << " sekundžių\n";
        cout << "Duomenų nuskaitymas iš failo užtruko: " << duomenuNuskaitymoLaikas.count() << " sekundžių\n";
        cout << "Studentų rūšiavimas užtruko: " << studentuRusiavimoLaikas.count() << " sekundžių\n";
        cout << "Rezultatų įrašymas į failus užtruko: " << studentuIsvedimoLaikas.count() << " sekundžių\n";
    }

    return 0;
}
