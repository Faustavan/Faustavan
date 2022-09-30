#include"funkcijos.h"

using namespace std;

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{    std:: vector<Studentas>mas;
    int studkiekis,ndkiekis = 0;
    string pasirinkimas;
    cout<<"Jei norite nuskaityti is failo, rasykite f, jei generuoti automatiskai,ar rasyti ranka, rasykite r : "<<endl;
    cin>>pasirinkimas;
    if (pasirinkimas=="r")
    {   cout<<"Iveskite studentu kieki:";
        cin>>studkiekis;
        if (studkiekis==0)
            cout<<"Studentu kiekis lygus nuliui";
        else if(studkiekis>100 || studkiekis<0)
            cout<<"netinkamas mokiniu skaicius"<<endl;
        else
        {Nuskaitymasr(mas,studkiekis);
        Isvedimasr(mas,studkiekis);
        }
    }
    else if(pasirinkimas=="f")
    {   Nuskaitymasf(mas,&ndkiekis);
        Isvedimasf(mas,ndkiekis);
    }
    else cout<<"Blogai ivedete"<<endl;
}
