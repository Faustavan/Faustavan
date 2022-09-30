#include<stdio.h>
#include"funkcijos.h"
using namespace std;

unsigned int zodziu_skaicius(std::string const& str)
{
    std::stringstream stream(str);
    return std::distance(std::istream_iterator<std::string>(stream), std::istream_iterator<std::string>());
}
void Nuskaitymasf(std::vector<Studentas>&mas,int *ndkiekis)
{    int studkiekis=0;
    int temp;
    std:: ifstream fnusk;
    std:: string buff;
    fnusk.open("studentai10000.txt.txt");
    try{
        if (fnusk.is_open()){
            getline(fnusk>>std::ws, buff);
            *ndkiekis= zodziu_skaicius(buff)-3;
            while(true)
            {
                mas.resize(mas.size()+1);
                fnusk>>mas.at(studkiekis).vardas;
                if(fnusk.eof())
                {   mas.pop_back();
                    break;
                }
                fnusk>>mas.at(studkiekis).pavarde;
                for (int i=0; i<*ndkiekis; i++)
                {   fnusk>>temp;
                    mas.at(studkiekis).nd.push_back(temp);
                }
                fnusk>>mas.at(studkiekis).egz;
                mas.at(studkiekis).galutinisvid=mas.at(studkiekis).galutinisvid/ *ndkiekis;
                mas.at(studkiekis).galutinisvid=mas.at(studkiekis).galutinisvid*0.4+0.6*mas.at(studkiekis).egz;
                studkiekis++;
            }
            fnusk.close();
        }
        else throw 99;
        }
    catch(int x){
        std::cout<<"Failo nera, ERROR:"<<x<<endl;}
    }

//Nuskaitymas vedant ranka:

void Nuskaitymasr(std::vector<Studentas >&mas,int &studkiekis)
{
    int pasirinkimas,nd;
    for (int i=0; i<studkiekis; i++)
    {   mas.resize(mas.size()+1);
        cout<<"Iveskite varda:";
        cin>>mas[i].vardas;
        cout<<"Iveskite pavarde:";
        cin>>mas[i].pavarde;
        cout<<"Iveskite egzamino pazimi:";
        cin>>mas[i].egz;
        cout<<"Iveskite ar  namu darbu pazimiai bus generuojami automatiskai(1) ar vedami ranka(0) : "<<endl;
        cin>>pasirinkimas;
        if (pasirinkimas==0)
        {
            while (true)
            {
                cout<<" Iveskite pazimi (0-10), jei daugiau pazimiu nera, rasykite 15"<<endl;
                cin>>nd;
                if(nd==15) break;
                mas[i].ndkiekis++;
                mas[i].nd.push_back(nd);
            }
            if (mas[i].ndkiekis==0)
                cout<<"pazymiu neturi"<<endl;
        }
        else if(pasirinkimas==1)
        {
            for (int j=0; j<rand()%10+1; j++)
            {
                mas[j].nd.push_back(rand()%10+1);
                mas[j].ndkiekis++;
            }
        }
    }
}
double Sumar(vector<int>a)
{int suma;
    suma=std::accumulate(a.begin(),a.end(),0);
    return suma;
}
double Vidr(double suma, int s)
{    double vid;
    vid=suma/s;
    if (s==0) vid=0;
    return vid;
}

double Medr(Studentas mas)
{    double med;
    if (mas.ndkiekis==0) med=0;
    else
    {
        if(mas.ndkiekis%2==0)
        {
            int u=mas.ndkiekis/2;
            med=(mas.nd[u]+mas.nd[u-1])/2.0;
        }
        else
            med=mas.nd[mas.ndkiekis/2];
    }
    return med;
}

float Medf(std::vector<int> nd){
    int c=0;
    for (int i=0;i<10;i++){
        if(nd[i]!=0) c++;
        if(nd[i]==-1){
            nd[i]=0;
            c--;
            break;
        }
    }
    if(c%2==0){
        return  float(((nd[c/2-1])+(nd[(c/2)]))/2.0);
    }
    else{
        return float(nd[(c/2)]);
    }
}

//Isvedimas vedant ranka:

void Isvedimasr(std::vector<Studentas>mas, int n)
{    cout<<n<<endl;
    cout<<left<<setw(15)<<"Vardas"<<left<<setw(15)<<"Pavarde"<<left<<setw(15)<<"Galutinis(vid.)"<<" / "<<setw(15) << "Galutinis(Med.)"<<endl;
    for (int a=0; a<80; a++)
    {cout<<"_";    }
    cout<<endl;
    for (int i=0; i<n; i++)
    {
        mas[i].galutinismed=0.4*Medr(mas[i])+0.6*mas[i].egz;
        mas[i].galutinisvid=0.4*Vidr(Sumar(mas[i].nd),mas[i].ndkiekis)+0.6*mas[i].egz;
        sort(mas[i].nd.begin(),mas[i].nd.end());
        cout <<left<<setw(15)<<mas[i].vardas<<left<<setw(15)
             <<mas[i].pavarde<<left<<setw(15)<<fixed<<setprecision(2)
             <<mas[i].galutinisvid<<left<<setw(15)<<mas[i].galutinismed<<endl;
    }
}

//Isvedimas nuskaitant is failo:

void Isvedimasf(std::vector<Studentas>mas,int ndkiekis) {
    std::ofstream output;
    output.open("rezultatai.txt");
    output << std::setw(20) << std::left << "Vardas"
        << std::setw(20) << std::left << "Pavarde"
        << std::setw(18) << std::left << "Galutinis(vid.)/"
        << std::left << "Galutinis(med.)\n"

<< "--------------------------------------------------------------------------\n";
    for (int i=0;i<mas.size();i++){
            output << std::setw(20) << std::left << mas[i].vardas
            << std::setw(20) << std::left <<mas[i].pavarde
            << std::setw(18) << std::left << mas[i].galutinisvid
            << Medf(mas[i].nd) << std::endl;
    }
    output << "\n\n";
}
