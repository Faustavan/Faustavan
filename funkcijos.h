#ifndef funkcijos.h
#define funkcijos.h
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <cmath>
#include <chrono>
#include <numeric>
#include <sstream>
#include <istream>
#include <string>

using namespace std::chrono;

class Studentas {
private:
	std::string vardas;
	std::string pavarde;
	int n;
	std::vector <int> pazymiai;
	int egzas;
	double final;
public:
	Studentas() : final(0) { } // def konstruktorius
	Studentas(std::string name, std::string surname);
	// -------------------- Getteriai ----------------------
	inline std::string getVardas() const { return vardas; }
	inline std::string getPavarde() const { return pavarde; }
	inline std::vector<int> getPazymiai() const { return pazymiai; }
	inline int getEgzas() const { return egzas; }
	inline int getN() const { return n; }
	inline int getFinal() const { return final; }

	// -------------------- Setteriai -----------------------
	inline void setVardas(std::string vardas) { Studentas::vardas = vardas; }
	inline void setPavarde(std::string pavarde) { Studentas::pavarde = pavarde; }
	inline void setPazymiai(std::vector<int> nd) { Studentas::pazymiai = nd; }
	inline void setEgzas(int egzas) { Studentas::egzas = egzas; }
	inline void setN(int n) { Studentas::n = n; }
	inline void setFinal(double final) { Studentas::final = final; }
};
//void tikrinimas();
void tyrimas();
void Kurimas(int m,std::string fileName);
void tiriama_su_vec(bool generavimas);
void tiriama_su_list(bool generavimas);
template <class T>
void mainFunc(T studentas,T protingi, T vargsai,bool generavimas);
template <class T>
void Ivedimas(T& studentas, std::string fileName);
template <class T>
void Grupavimas(T& studentas, T& vargsai, int n);
template <class T>
void mainFuncList(T studentas, T protingi, T vargsai, bool generavimas);
double skaiciuoti(std::vector<int>pazymiai, int egz, int n);
void Skaiciavimas(std::vector <Studentas>studentas);
void Irasymas(std:: vector<Studentas>& studentas);
template <class T>
void Spausdinimas(T studentas, std::string failas);
template <class T>
void Grupavimas2(T& studentas, T& vargsai, int num);
#endif // funkcijos.h
