#include "Lib.h"
#include "Stud.h"
#include "Stud.cpp"


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
        //cin.ignore();
        //system("dir *.txt");
        string failoPavadinimas;
        cout << "Įveskite failo pavadinimą: ";
        cin >> failoPavadinimas;
        nuskaitytiIsFailo(studentai, failoPavadinimas);
    }

    //failo generavimas ir nuskaitymas
    else if (duomenuIvedimoBudas == 'G') {
        vector<int> studentuDydziai = {10000000};
        char pasirinkimas;

        for (int n : studentuDydziai) {
            studentai.clear();
            string failoPavadinimas = "studentai" + to_string(n) + ".txt";

            //Generuojamas failas
            start = high_resolution_clock::now();
            generuotiFaila(n, failoPavadinimas);
            end = high_resolution_clock::now();
            failoKuriamoLaikas = duration_cast<duration<double>>(end - start);

            //Failas nuskaitomas
            start = high_resolution_clock::now();
            nuskaitytiIsFailo(studentai, failoPavadinimas);
            end = high_resolution_clock::now();
            duomenuNuskaitymoLaikas = duration_cast<duration<double>>(end - start);

            //vartotojas viena karta pasirenka galutinio balo skaiciavimo metoda ir rusiavimo parametra
            if (n == 1000) {
                pasirinkimas = pasirinktiGalutinioskaiciavimoMetoda();
                for (Studentas& studentas : studentai) {
                    skaiciuotiGalutini(studentas, pasirinkimas);
                }
                pasirinktiRusiavimoParametra(studentai);
            } else {
                for (Studentas& studentas : studentai) {
                    skaiciuotiGalutini(studentas, pasirinkimas);
                }
            }

            //Skirstyti studentus i vargsiukus ir kietiakus
            start = high_resolution_clock::now();
            vector<Studentas> vargsiukai, kietiakai;
            skirstytiStudentus(studentai, vargsiukai, kietiakai);
            end = high_resolution_clock::now();
            studentuRusiavimoLaikas = duration_cast<duration<double>>(end - start);

            start = high_resolution_clock::now();
            //Isvesti vargsiukus i faila
            isvestiGrupesIFaila(vargsiukai, "vargsiukai.txt", pasirinkimas);
            //Isvesti kietiakus i faila
            isvestiGrupesIFaila(kietiakai, "kietiakai.txt", pasirinkimas);
            end = high_resolution_clock::now();
            studentuIsvedimoLaikas = duration_cast<duration<double>>(end - start);

            spausdintiOperacijuLaikus(n, failoKuriamoLaikas, duomenuNuskaitymoLaikas, studentuRusiavimoLaikas, studentuIsvedimoLaikas);

        }
             
        //pasirenkame kaip pateikti rezultatus (faile ar terminale)
        pasirinktiRezultatuIsvedimoBuda(studentai, pasirinkimas);

        /*
        //Generuojamas ir nuskaitomas vienas failas
        string failoPavadinimas;
        int studentuSkaicius;

        cout << "Įveskite, kiek studentų norite sugeneruoti: ";
        cin >> studentuSkaicius;

        //cout << "Įveskite failo pavadinimą: ";
        //cin >> failoPavadinimas;
        failoPavadinimas = "studentai" + to_string(studentuSkaicius) + ".txt";

        start = high_resolution_clock::now();
        generuotiFaila(studentuSkaicius, failoPavadinimas);
        end = high_resolution_clock::now();
        failoKuriamoLaikas = duration_cast<duration<double>>(end - start);

        start = high_resolution_clock::now();
        nuskaitytiIsFailo(studentai, failoPavadinimas);
        end = high_resolution_clock::now();
        duomenuNuskaitymoLaikas = duration_cast<duration<double>>(end - start);
        */
    }

    if (duomenuIvedimoBudas != 'G') {
        //Pasirinkimas galutinio balo skaičiavimo metodui
        char pasirinkimas = pasirinktiGalutinioskaiciavimoMetoda();
        for (Studentas& studentas : studentai) {
        skaiciuotiGalutini(studentas, pasirinkimas);
        }

        //Surusiuojame studentus pagal pasirinkta parametra
        pasirinktiRusiavimoParametra(studentai);

        //pasirenkame kaip pateikti rezultatus (faile ar terminale)
        pasirinktiRezultatuIsvedimoBuda(studentai, pasirinkimas);

        //Skirstyti studentus i vargsiukus ir kietiakus
        vector<Studentas> vargsiukai, kietiakai;
        skirstytiStudentus(studentai, vargsiukai, kietiakai);

        //Isvesti vargsiukus i faila
        isvestiGrupesIFaila(vargsiukai, "vargsiukai.txt", pasirinkimas);

        //Isvesti kietiakus i faila
        isvestiGrupesIFaila(kietiakai, "kietiakai.txt", pasirinkimas);
    }

    return 0;
}
