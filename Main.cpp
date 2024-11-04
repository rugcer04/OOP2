#include "Lib.h"
#include "Stud.h"
#include "Timer.h"

int main() {
    char konteinerioPasirinkimas;
    while (true) {
        cout << "Norite naudoti vector (V) ar list (L)? ";
        cin >> konteinerioPasirinkimas;
        konteinerioPasirinkimas = toupper(konteinerioPasirinkimas);

        if (konteinerioPasirinkimas == 'V' || konteinerioPasirinkimas == 'L') {
            break;
        } else {
            cout << "Neteisinga įvestis, bandykite dar kartą.\n";
        }
    }

    //Darbas su vektoriumi
    if (konteinerioPasirinkimas == 'V') {
        vector<Studentas> studentai;
        char duomenuIvedimoBudas = pasirinktiDuomenuIvedima();
    
        //Ivesti rankiniu budu
        if (duomenuIvedimoBudas == 'I') {
            ivedimasRanka(studentai);

            //Pasirenkame galutinio pazymio skaiciavimo metoda
            char pasirinkimas = pasirinktiGalutinioskaiciavimoMetoda();
            for (Studentas& studentas : studentai) {
            skaiciuotiGalutini(studentas, pasirinkimas);
            }

            //Pasirenkame studentu rusiavimo parametra
            pasirinktiRusiavimoParametra(studentai);

            //pasirenkame kaip pateikti rezultatus (faile ar terminale)
            if (duomenuIvedimoBudas == 'I') {
                pasirinktiRezultatuIsvedimoBuda(studentai, pasirinkimas);
            } else {
                string failoPavadinimas = "studrez.txt";
                isvedimasIFaila(studentai, pasirinkimas, failoPavadinimas);
            }    
        }

        //Nuskaitymas is failo
        else if (duomenuIvedimoBudas == 'F') {
            //system("dir *.txt");
            string failoPavadinimas;
            cout << "Įveskite failo pavadinimą: ";
            cin >> failoPavadinimas;

            Timer t1;
            nuskaitytiIsFailo(studentai, failoPavadinimas);
            cout << "Failo su " << studentai.size() << " įrašų nuskaitymo laikas: " << t1.elapsed() << " s\n" << endl;

            //Pasirenkame galutinio pazymio skaiciavimo metoda
            char pasirinkimas = pasirinktiGalutinioskaiciavimoMetoda();
            for (Studentas& studentas : studentai) {
                skaiciuotiGalutini(studentas, pasirinkimas);
            }

            //Pasirenkame studentu rusiavimo parametra
            pasirinktiRusiavimoParametra(studentai);

            //isvedame rezultatus i faila
            failoPavadinimas = "studrez.txt";
            isvedimasIFaila(studentai, pasirinkimas, failoPavadinimas);

            //Skirstyti studentus i vargsiukus ir kietiakus ir isvesti i failus pagal pasirinkta strategija
            duomenuIsvedimasPagalStrategija(studentai, pasirinkimas);
        }

        //Failu generavimas
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
        

    //Darbas su sarasu
    } else if (konteinerioPasirinkimas == 'L') {
        list<Studentas> studentai;
        char duomenuIvedimoBudas = pasirinktiDuomenuIvedima();
    
        //Ivesti rankiniu budu
        if (duomenuIvedimoBudas == 'I') {
            ivedimasRanka(studentai);

            //Pasirenkame galutinio pazymio skaiciavimo metoda
            char pasirinkimas = pasirinktiGalutinioskaiciavimoMetoda();
            for (Studentas& studentas : studentai) {
            skaiciuotiGalutini(studentas, pasirinkimas);
            }

            //Pasirenkame studentu rusiavimo parametra
            pasirinktiRusiavimoParametra(studentai);

            //pasirenkame kaip pateikti rezultatus (faile ar terminale)
            if (duomenuIvedimoBudas == 'I') {
                pasirinktiRezultatuIsvedimoBuda(studentai, pasirinkimas);
            } else {
                string failoPavadinimas = "studrez.txt";
                isvedimasIFaila(studentai, pasirinkimas, failoPavadinimas);
            }
        }

        //Nuskaitymas is failo
        else if (duomenuIvedimoBudas == 'F') {
            //system("dir *.txt");
            string failoPavadinimas;
            cout << "Įveskite failo pavadinimą: ";
            cin >> failoPavadinimas;

            Timer t1;
            nuskaitytiIsFailo(studentai, failoPavadinimas);
            cout << "Failo su " << studentai.size() << " įrašų nuskaitymo laikas: " << t1.elapsed() << " s\n" << endl;

            //Pasirenkame galutinio pazymio skaiciavimo metoda
            char pasirinkimas = pasirinktiGalutinioskaiciavimoMetoda();
            for (Studentas& studentas : studentai) {
                skaiciuotiGalutini(studentas, pasirinkimas);
            }

            //Pasirenkame studentu rusiavimo parametra
            pasirinktiRusiavimoParametra(studentai);

            //isvedame rezultatus i faila
            failoPavadinimas = "studrez.txt";
            isvedimasIFaila(studentai, pasirinkimas, failoPavadinimas);

            //Skirstyti studentus i vargsiukus ir kietiakus ir isvesti i failus pagal pasirinkta strategija
            duomenuIsvedimasPagalStrategija(studentai, pasirinkimas);
        }

        //Failu generavimas
        else if (duomenuIvedimoBudas == 'G') {
            list<int> studentuDydziai = {1000, 10000, 100000, 1000000, 10000000};
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
    }
    

    return 0;
}
