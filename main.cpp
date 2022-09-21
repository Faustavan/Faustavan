#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct Studentas
{
    string vardas;
    string pavarde;
    vector<int>nd;
    int egz;
    int ndkiekis=0;
};


void Nuskaitymas(int &kiekis);
double Med(Studentas mas,int studkiekis);
void Nuskaitymas(Studentas mas[],int &kiekis);
int Pazimiai(Studentas mas[]);
int Suma(vector<int>a,int studkiekis);
double Vid(double suma, int s);
double Med(Studentas mas,int studkiekis);
void Isvedimas(Studentas mas[], int n);



int main()
{
    Studentas mas[100];
    int studkiekis;
    cout<<"Iveskite studentu kieki:";
    cin>>studkiekis;
    if (studkiekis==0)
    {
        cout<<"Studentu kiekis lygus nuliui";
    }
    else
    {
        Nuskaitymas(mas,studkiekis);
    }
    Isvedimas(mas,studkiekis);
}

void Nuskaitymas(Studentas mas[],int &studkiekis)
{
    int pasirinkimas,nd;
    for (int i=0; i<studkiekis; i++)
    {
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



int Suma(vector<int>a,int studkiekis)
{
    int suma=0;
    for (int i=0; i<studkiekis; i++)
    {
        suma+=a[i];
    }
    return suma;
}
double Vid(double suma, int s)
{
    double vid;
    vid=suma/s;
    if (s==0) vid=0;
    return vid;
}

double Med(Studentas mas,int studkiekis)
{
    double med;
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

void Isvedimas(Studentas mas[], int n)
{
    cout<<left<<setw(20)<<"Vardas"<<left<<setw(20)<<"Pavarde"<<left<<setw(20)<<"Galutinis(vid.)"<<" / "<<setw(15) << "Galutinis(Med.)"<<endl;
    for (int a=0; a<n; a++)
    {
        cout<<"_";
    }
    cout<<endl;
    for (int i=0;i<n;i++)
    {
        sort(mas[i].nd.begin(),mas[i].nd.end());
        cout <<left<<setw(15)<<mas[i].vardas<<left<<setw(15)
             <<mas[i].pavarde<<left<<setw(15)<<fixed<<setprecision(2)
             <<Vid(Suma(mas[i].nd,mas[i].ndkiekis),mas[i].ndkiekis)
             <<left<<setw(15)<<Med(mas[i],mas[i].ndkiekis)<<endl;
    }
}
