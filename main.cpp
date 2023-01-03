
#include "funkcijos.h"

using namespace std;

int main()
{
    bool vid;
    string pas;
    std::vector<Studentas>studentas;
    std::cout<<"Jei norite duomenis nuskaityti is failo, rasykite 'f'. Jei sugeneruoti faila: 'g',o jei rasysite ranka,iveskite bet kokia kita raide "<<std::endl;
    std::cin>>pas;
    if (pas=="f"){
        tyrimas();
        Skaiciavimas(studentas);
    }
    else if(pas=="g"){
        //generavimo funkc
        Skaiciavimas(studentas);


    }
    else{
        Irasymas(studentas);
        Skaiciavimas(studentas);

    }


}
