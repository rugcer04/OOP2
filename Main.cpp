#include "Lib.h"
#include "Stud.h"
#include "Timer.h"

int main() {
    vector<Studentas> studentai;

    //Pasirinkimas duomenims įvesti
    char duomenuIvedimoBudas;
    while (true) {
        cout << "Ar norite duomenis įvesti (I), nuskaityti iš failo (F), ar sugeneruoti failą (G)? ";
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
        //system("dir /b *.txt");
        string failoPavadinimas;
        cout << "Įveskite failo pavadinimą: ";
        cin >> failoPavadinimas;

        Timer t1;
        nuskaitytiIsFailo(studentai, failoPavadinimas);
        cout << "Failo su " << studentai.size() << " įrašų nuskaitymo laikas: " << t1.elapsed() << " s\n" << endl;
    }

    //failo generavimas
    else if (duomenuIvedimoBudas == 'G') {
        vector<int> studentuDydziai = {1000, 10000, 100000, 1000000, 10000000};
        char pasirinkimas;

        for (int n : studentuDydziai) {
            studentai.clear();
            string failoPavadinimas = "studentai" + to_string(n) + ".txt";

            Timer t2;
            generuotiFaila(n, failoPavadinimas);
            cout << "Failo su " << n << " įrašų generavimo laikas: " << t2.elapsed() << " s\n" << endl;        
        }
    return 0;
    }

    //Pasirenkame galutinio pazymio skaiciavimo metoda
    char pasirinkimas = pasirinktiGalutinioskaiciavimoMetoda();
    for (Studentas& studentas : studentai) {
        skaiciuotiGalutini(studentas, pasirinkimas);
    }

    //Pasirenkame studentu rusiavimo parametra
    pasirinktiRusiavimoParametra(studentai);

    //Skirstyti studentus i vargsiukus ir kietiakus
    Timer t3;
    vector<Studentas> vargsiukai, kietiakai;
    skirstytiStudentus(studentai, vargsiukai, kietiakai);
    cout << "Failo su " << studentai.size() << " įrašų surūšiavimo į dvi grupes laikas: " << t3.elapsed() << " s\n" << endl;

    Timer t4;
    //Isvesti vargsiukus i faila
    isvedimasIFaila(vargsiukai, pasirinkimas, "vargsiukai.txt");
    //Isvesti kietiakus i faila
    isvedimasIFaila(kietiakai, pasirinkimas, "kietiakai.txt");
    cout << "Failo su " << studentai.size() << " įrašų išvedimo į failus laikas: " << t4.elapsed() << " s\n" << endl;

    //pasirenkame kaip pateikti rezultatus (faile ar terminale)
    if (duomenuIvedimoBudas == 'I') {
        pasirinktiRezultatuIsvedimoBuda(studentai, pasirinkimas);
    } else {
        string failoPavadinimas = "studrez.txt";
        isvedimasIFaila(studentai, pasirinkimas, failoPavadinimas);
    }

    return 0;
}
