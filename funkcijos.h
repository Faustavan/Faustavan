#ifndef funkcijos.h
#define funkcijos.h
#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>

struct Studentas
{
    std::string vardas,pavarde;
    std::vector<int>nd;
    int egz;
    int ndkiekis=0;
    double galutinisvid;
    double galutinismed;
};
unsigned int zodziu_skaicius(std::string const& str);
void Nuskaitymasf(std::vector<Studentas>&mas,int *ndkiekis);
void Nuskaitymasr(std::vector<Studentas >&mas,int &studkiekis);
double Sumar(std::vector<int>a);
double Vidr(double suma, int s);
double Medr(Studentas mas);
float Medf(std::vector<int> nd);
void Isvedimasr(std::vector<Studentas>mas, int n);
void Isvedimasf(std::vector<Studentas>mas,int ndkiekis);



#endif // funkcijos.h
