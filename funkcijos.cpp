#include "funkcijos.h"
void tyrimas(){
    bool generavimas;
    std::cout<<"1 STRATEGIJA"<<std::endl;
    tiriama_su_vec(generavimas);
    tiriama_su_list(generavimas);
    std::cout<<"2 STRATEGIJA"<<std::endl;



}
//void tikrinimas(){
//    char pas;
//    std::cin>>pas;
//
//    }
void Kurimas(int m,std::string fileName){
int a= rand()%10;
std::ofstream out(fileName);
out<<std::left<<std::setw(20)<< "Vardas" << std::setw(20) << "Pavarde";
for (int i = 0; i < a; i++)
	{
		out << std::setw(8) << "ND" + std::to_string(i + 1);
	}
	out << std::setw(8) << "Egz." << std::endl;

	for (int i = 0; i < m; i++)
	{
		out << std::left << std::setw(20) << "Vardenis" + std::to_string(i + 1) << std::setw(20) << "Pavardenis" + std::to_string(i + 1);
		for (int j = 0; j <= a; j++)
		{
			out << std::setw(8) << rand() % 10 + 1;
		}
		out << std::endl;
	}
	out.close();
}
//NewStudent
void Irasymas(std:: vector<Studentas>& studentas){
bool egz,l,ndkiek,studkiek;
Studentas stud;
std::string vardas,pavarde;
std::vector<int>nd;
std::cout<<"Kiek yra studentu?"<<std::endl;
std::cin>>studkiek;
std::cout << "Kiek pazymiu yra? "<<std::endl;
std::cin>>ndkiek;
for (int j=0;j<studkiek;j++){
    std::cout << "Iveskite studento varda: "<< std::endl;
    std::cin >> vardas;
    std::cout << "Iveskite studento pavarde: "<< std::endl;
    std::cin >> pavarde;
    stud.setVardas(vardas);
    stud.setPavarde(pavarde);

    for (int i=0;i<ndkiek;i++){
        std::cout<<"Iveskite pazymi"<<std::endl;
        std::cin>>l;
        if(l<0 && l>10){
            std::cout << "Blogai ivedete" << std::endl;
            break;

        }
        else std::cin>>nd[i];
    }
    stud.setPazymiai(nd);
    std::cout<<"Iveskite egzamino pazymi:"<<std::endl;
    std::cin>>egz;
    stud.setEgzas(egz);
}
studentas.push_back(stud);
	nd.clear();
}


void Skaiciavimas(std::vector <Studentas>studentas){
std::cout << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde" << std::setw(18);
std::cout << "Galutinis (vid.)" << std::setw(18) << "Galutinis (med.)" << std::endl;
std::cout << "----------------------------------------------------------------" << std::endl;
for (int i = 0; i < studentas.size(); i++)
	{
		double galutinisVid = 0;
		double galutinisMed = 0;
		double sum = 0;		//calc vid
		int size = studentas[i].getPazymiai().size();
		for (int j = 0; j < size; j++)
		{
			sum = sum + studentas[i].getPazymiai()[j];
		}
		double average = sum / size;
		galutinisVid = studentas[i].getEgzas() * 0.6 + average * 0.4;
		int vidI = (size / 2) - 1;			//calc med
		sort(studentas[i].getPazymiai().begin(), studentas[i].getPazymiai().end());
		if (size != 0)
		{
			galutinisMed = studentas[i].getPazymiai()[vidI] * 0.4 + studentas[i].getEgzas() * 0.6;
		}
		else
		{
			galutinisMed = ((studentas[i].getPazymiai()[vidI] + studentas[i].getPazymiai()[vidI + 1]) / 2) * 0.4 + studentas[i].getEgzas() * 0.6;
		}
		std::cout << std::left << std::setw(15) << studentas[i].getVardas() << std::setw(15) << studentas[i].getPavarde() << std::setw(18);
		std::cout << std::fixed << std::setprecision(2) << galutinisVid << std::setw(18) << std::setprecision(2) << galutinisMed << std::endl;
	}

}
void tiriama_su_vec(bool generavimas){
std::vector <Studentas> studentas;
	std::vector <Studentas> protingi;
	std::vector <Studentas> vargsai;
	mainFunc(studentas, protingi, vargsai, generavimas);
	studentas.clear();
	protingi.clear();
	vargsai.clear();
}
void tiriama_su_list(bool generavimas)
{
	std::list <Studentas> studentas;
	std::list <Studentas> protingi;
	std::list <Studentas> vargsai;
	mainFuncList(studentas, protingi, vargsai, generavimas);
	studentas.clear();
	protingi.clear();
	vargsai.clear();
}
template <class T>
void mainFunc(T studentas,T protingi, T vargsai,bool generavimas){
int a = 4;
	int size[4] = { 1000, 10000, 100000, 1000000 };

for (int i = 0; i < a; i++)
		{
			std::string studentai = "Studentai_" + std::to_string(size[i]) + ".txt";
			high_resolution_clock::time_point t1 = high_resolution_clock::now();
			std::cout << std::endl << "Failas " << studentai << std::endl;
				Kurimas(size[i], studentai);
				Ivedimas(studentas, studentai);
				Grupavimas(studentas, vargsai, size[i]);
				Spausdinimas(protingi, "Protingi_" + studentai);
				Spausdinimas(vargsai, "Vargsai_" + studentai);
				std::cout << "Bendras failo " << studentai << " testavimo laikas: " <<
					std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - t1).count() / 1000. << "sekundes" << std::endl;


		}
}

template <class T>
void Ivedimas(T& studentas, std::string fileName){

std::ifstream file;
	try
	{
		file.open(fileName);
		if (!file)
		{
			throw 1;
		}
		std::string line;
		getline(file, line);
		while (getline(file, line))
		{
			Studentas stud;
			std::string vardas, pavarde;
			std::istringstream iss(line);
			iss >> vardas >> pavarde;
			stud.setVardas(vardas);
			stud.setPavarde(pavarde);
			std::vector<int> nd;
			int g;
			while (iss >> g)
			{
				nd.push_back(g);
			}
			if (nd.size() == 0)
			{
				throw 2;
			}

			nd.pop_back();
			stud.setEgzas(g);
			stud.setPazymiai(nd);
			stud.setN(stud.getPazymiai().size());
			stud.setFinal(skaiciuoti(stud.getPazymiai(), stud.getEgzas(), stud.getN()));
			studentas.push_back(stud);
		}
	}
	catch (int e)
	{
		switch (e)
		{
		case 1:
			std::cout << "Failas nerastas." << std::endl << std::endl << "Baigiamas programos veikimas." << std::endl;
			break;
		case 2:
			std::cout << "Failas nuskaitytas netinkamai." << std::endl;
			break;
		}
		exit(1);
	}
	file.close();


}
template <class T>
void Grupavimas(T& studentas, T& vargsai, int n)
{
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	auto it = stable_partition(studentas.begin(), studentas.end(), [](Studentas const& stud) {return stud.getFinal() >= 5; });
	vargsai.assign(it, studentas.end());
	studentas.erase(it, studentas.end());
	std::cout << "Studentu rusiavimas i dvi grupes uztruko: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - t1).count() / 1000. << " s." << std::endl;
}

template <class T>
void mainFuncList(T studentas, T protingi, T vargsai, bool generavimas)
{
	int a = 4;
	int size[4] = { 1000, 10000, 100000, 1000000 };
		for (int i = 0; i < a; i++)
		{
			std::string studentai = "Studentai_" + std::to_string(size[i]) + ".txt";
			high_resolution_clock::time_point t1 = high_resolution_clock::now();
			std::cout << std::endl << "Failas " << studentai << std::endl;

				Kurimas(size[i], studentai);
				Ivedimas(studentas, studentai);
				Grupavimas2(studentas, vargsai, size[i]);
				Spausdinimas(protingi, "Protingi_" + studentai);
				Spausdinimas(vargsai, "Vargsai_" + studentai);
				std::cout << "Bendras failo " << studentai << " testavimo laikas: " <<
					std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - t1).count() / 1000. << " s." << std::endl;


		}
	}

double skaiciuoti(std::vector<int>pazymiai, int egz, int n){
double final;
int sum;
sum=accumulate(pazymiai.begin(),pazymiai.end(),0);
final=(sum*1.0/n)*0.4+egz*0.6;
return final;

}
template <class T>
void Spausdinimas(T studentas, std::string failas){
std::ofstream out(failas);
out << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(18) << "Galutinis(vid.)" << std::endl;

	for (auto stud : studentas)
	{
		out << std::left << std::setw(20) << stud.getVardas() <<
			std::setw(20) << stud.getPavarde() <<
			std::setw(18) << std::fixed << std::setprecision(2) << stud.getFinal() << std::endl;
	}




}
template <class T>
void Grupavimas2(T& studentas, T& vargsai, int num){
high_resolution_clock::time_point t1 = high_resolution_clock::now();
	auto it = stable_partition(studentas.begin(), studentas.end(), [](Studentas const& stud) {return stud.getFinal() >= 5; });
	vargsai.assign(it, studentas.end());
	studentas.erase(it, studentas.end());
	std::cout << "Studentu rusiavimas i dvi grupes uztruko: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - t1).count() / 1000. << " s." << std::endl;
}

