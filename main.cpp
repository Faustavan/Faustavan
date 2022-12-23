#include <iostream>
#include "funkcijos.h"

using namespace std;


int main()
{
    int n,ndkiekis, temp;
    vector<Studentas> A;
    vector <Studentas>C; // vektoriaus strukturos
    list<Studentas> B;
    string pasirinkti;
    cout << "Jei norite duomenis nuskaityti is failo, rasykite 'f'. Jei sugeneruoti faila: 'g',o jei rasysite ranka,iveskite bet kokia kita raide ";
    cin >> pasirinkti;
    cout << endl;
    if(pasirinkti=="f")
    {
        cout << "Iveskite vaiku skaiciu: ";
        cin >> temp;
        cout<<"1 STRATEGIJA:"<<endl;
        skaitymas_is_failo(A, &ndkiekis, temp);
        isvedimas_i_faila(A, ndkiekis);

        cout<<"2 STRATEGIJA:"<<endl;
    }
    else if(pasirinkti=="g")
    {
        cout << "Iveskite vaiku skaiciu: ";
        cin >> temp;
        cout<<"1 STRATEGIJA:"<<endl;
        failo_generavimas(A, temp);
        skaitymas_is_failo(A, &ndkiekis, temp);
        skaitymas_is_failo_list(B, &ndkiekis, temp);
        isvedimas_i_faila(A, ndkiekis);
        isvedimas_i_faila_list(B,ndkiekis);

        cout<<"2 STRATEGIJA:"<<endl;
        failo_generavimas(A, temp);
        skaitymas_is_failo(A, &ndkiekis, temp);
        skaitymas_is_failo_list(B, &ndkiekis,temp);
        isvedimas_i_faila_2(A, ndkiekis,C,temp);
        //isvedimas_i_faila_list_2(B,ndkiekis,temp);
    }
    else
    {
        cout << "Iveskite vaiku kieki: ";
        cin >> n;
        cout<<"1 STRATEGIJA:"<<endl;
        ivedimas(A, n);
        isvedimas(A, n);

        cout<<"2 STRATEGIJA:"<<endl;
    }
    return 0;
}
