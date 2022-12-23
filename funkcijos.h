#ifndef funkcijos.h
#define funkcijos.h

#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <iterator>
#include <string>
#include <chrono>
#include <list>

using namespace std;

struct Studentas{
    string vard;
    string pav;
    int egz; // egzamino rez.
    vector<int> ndrez;// namų darbų rez.
    double gp;
};
unsigned int Zodziai_eiluteje(std::string const& str);
int random_pazymys();
void ivedimas(vector<Studentas>&k, int n);
double vidurkis(double visindrez, int m); // vidurkio funkcija
double median(Studentas k, int n); // medianos funkcija
double galutinis(double a, double b);
void isvedimas(vector<Studentas> k, int n);
void failo_generavimas(vector<Studentas>& k, int tempvaik);
void skaitymas_is_failo_list (list<Studentas>& k, int* ndkiekis, int tempvaik);
void skaitymas_is_failo (vector<Studentas>& k, int* ndkiekis, int tempvaik);
void isvedimas_i_faila (vector<Studentas> k, int ndkiekis);
void isvedimas_i_faila_list (list<Studentas> k, int ndkiekis);
void isvedimas_i_faila_2(vector<Studentas> k, int ndkiekis,vector <Studentas>v, int tempvaik);
void isvedimas_i_faila_list_2 (list<Studentas> k, int ndkiekis, int tempvaik);



#endif // funkcijos.h
