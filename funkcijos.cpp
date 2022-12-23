#include "funkcijos.h"
#include <string>
using namespace std;

unsigned int Zodziai_eiluteje(std::string const& str)
{
    std::stringstream stream(str);
    return std::distance(std::istream_iterator<std::string>(stream), std::istream_iterator<std::string>());
}


int random_paz()
{
	return rand() % 10 + 1;
}


void ivedimas(vector<Studentas>&k, int n)
{
    int temp; // konkretaus namu darbo rezultatas
    for(int i=0; i<n; i++){
        k.resize(k.size()+1);
        cout << "Iveskite vaiko varda: ";
        cin >> k[i].vard;
        cout << "Iveskite vaiko pavarde: ";
        cin >> k[i].pav;
        cout << "Iveskite vaiko egzamino rezultata: ";
        cin >> k[i].egz;
        string pasirinkti;
        cout << "Pasirinkite ar namu darbu rezultatus ivedinesite ranka(t), ar generuosite automatiskai(n)?" << endl;
        cin >> pasirinkti;
        if(pasirinkti == "t"){
            while(true) // ivesti arba randominiai skaiciai sukeliami i vektoriaus pabaiga
            {
            cout << "Iveskite namu darbo pazymi, jeigu daugiau pazymiu nera, iveskite : 15" << endl;
            cin >> temp;
            if(temp == 15){
                break;
                }
            k[i].ndrez.push_back(temp);
            }
            if(k[i].ndrez.size()<1)
            {
                cout << "Mokinys neturi nei vieno namu darbu pazymio" << endl;
            }
        }
        else
        {

            for(int z=0; z<(rand()%10+1); z++){
            k[i].ndrez.push_back(rand()%10+1);
            }
            }
        }
}
double vidurkis(double visindrez, int m) // vidurkio funkcija
{
    double vid;
    vid = visindrez/m;
    if(m==0)
        vid = 0;
    return vid;
}
double median(Studentas k, int n){ // medianos funkcija
    double mediana;
    if(k.ndrez.size()==0){
        mediana=0;
    }
    else{
        if(k.ndrez.size()%2==0)
        {
            int p = k.ndrez.size()/2;
            mediana=(k.ndrez[p]+k.ndrez[p-1])/2.0;
        }
        else
            mediana = k.ndrez[k.ndrez.size()/2];
    }
    return mediana;
}
double galutinis(double a, double b){
    double gpaz;
    gpaz = (0.4*a)+(0.6*b);
    return gpaz;
}
/*
double galutinis_su_vec(vector<int> balai) {
	vaikas eilute;
	eilute.gp = 0.4 * accumulate(balai.begin(), balai.end(), 0) / balai.size() + 0.6 * random_pazymys();
	return eilute.gp;
}
*/

void isvedimas(vector<Studentas> k, int n){
    cout << left << setw(15) << "Vardas" << left << setw(15) << "pavarde" << left << setw(15) <<"Galutinis (Vid.)" << " / " << setw(15) << "Galutinis (Med.)" << endl;
    for(int k=0; k<60; k++){
    cout << "_";
    }
    for(int i=0; i<n; i++){

        double suma; // vektoriaus elementu suma
        suma = accumulate(k[i].ndrez.begin(), k[i].ndrez.end(), 0);
        sort(k[i].ndrez.begin(), k[i].ndrez.end());
        cout << left << setw(15) << k[i].vard << left << setw(15) << k[i].pav << left << setw(15) << fixed << setprecision(2) << galutinis(vidurkis(suma, k[i].ndrez.size()), k[i].egz)<< left << setw(15) << galutinis(median(k[i], k[i].ndrez.size()), k[i].egz) << endl;
    }
}

void failo_generavimas(vector<Studentas>& k, int temp)
{
    int randsk;
    randsk = rand()% 3 + 3;
    string failas = "Studentai" + to_string(temp)+".txt";
    ofstream w1(failas);
    w1 << setw(16) << left << "Vardas"
		<< setw(16) << left << "Pavarde";
    for(int n=0; n<randsk; n++)
    {
        w1 << setw(5) << "ND" + to_string(n+1);
    }
    w1 << "Egz." << endl;
    for (int j=0; j<temp; j++)
    {
        w1 << setw(16) << "Vardas" + to_string(j+1)
			<< setw(16) << "Pavarde" + to_string(j+1);
        for(int s=0; s<randsk; s++)
        {
            w1 << setw(5) << random_paz();
        }
        w1 << setw(5) << random_paz() << endl;
    }
}
void skaitymas_is_failo_list (list<Studentas>& k, int* ndkiekis, int tempkiek)
{
    auto start = std::chrono::high_resolution_clock::now();
    string buff, eilute;
    int temp;
    int vaikusk = 0;
    string failas = "Studentai" + to_string(tempkiek)+".txt";
    ifstream r;
    try{
        r.open(failas);
        if(!r)
            throw std::runtime_error("Nepavyko rasti failo");

        getline(r >> ws, buff);
        *ndkiekis = Zodziai_eiluteje(buff) - 3;

        while(true)
        {
            if(r.eof())
            {
                k.pop_back();
                break;
            }
            Studentas mok;
            r >> mok.vard >> mok.pav;

            for(int i=0; i<*ndkiekis; i++)
            {
                r >> temp;
                mok.ndrez.push_back(temp);
            }
            r >> mok.egz;

            k.push_back(mok);
            vaikusk +=1;
        }
    }
    catch(int e){}
     auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
	std::cout << "Duomenu nuskaitymas su listu uztruko: " << diff.count() << " s\n";
}
void skaitymas_is_failo (vector<Studentas>& k, int* ndkiekis, int tempvaik)
{
    auto start = std::chrono::high_resolution_clock::now();

    int temp;
    int vaikusk = 0;
    string buff;
    ifstream r;
    string failas = "Studentai" + to_string(tempvaik)+".txt";
    try{
        r.open(failas);
        if(!r)
            throw std::runtime_error("Nepavyko rasti failo");

            getline(r >> std::ws, buff);
            *ndkiekis = Zodziai_eiluteje(buff) - 3;
            while(true)
            {
                k.resize(k.size()+1);
                r >> k.at(vaikusk).vard;
                if(r.eof())
                {
                    k.pop_back();
                    break;
                }
                r >> k.at(vaikusk).pav;
                for(int i=0; i<*ndkiekis; i++)
                {
                    r >> temp;
                    k.at(vaikusk).ndrez.push_back(temp);
                }
                r >> k.at(vaikusk).egz;
                vaikusk += 1;
            }
            r.close();
    }
    catch(int e){}
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
	std::cout << "Duomenu nuskaitymas su vektorium uztruko: " << diff.count() << " s\n";
}

void isvedimas_i_faila(vector<Studentas> k, int ndkiekis)
{
    auto start1 = std::chrono::high_resolution_clock::now();
    ofstream w1, w2;
    w1.open("vargsiukai.txt");
    w2.open("kietiakai.txt");
    w1 << left << setw(17) << "Vardas" << left << setw(17) << "Pavarde"
        << left << setw(22) << "Galutinis(vid.)/" << left << setw(22)
        << "Galutinis(med.)\n";

    w2 << left << setw(17) << "Vardas" << left << setw(17) << "Pavarde"
        << left << setw(22) << "Galutinis(vid.)/" << left << setw(22)
        << "Galutinis(med.)\n";

    for(int s=0; s<70; s++)
    {
        w1 << "_" ;
        w2 << "_" ;
    }
    w1 << endl;
    w2 << endl;


    for(int i=0; i<k.size(); i++)
    {
        double suma; // vektoriaus elementu suma
        suma = accumulate(k[i].ndrez.begin(), k[i].ndrez.end(), 0);
        sort(k[i].ndrez.begin(), k[i].ndrez.end());

        if(galutinis(vidurkis(suma, k[i].ndrez.size()),k[i].egz)<5)
           {
                w1 << left << setw(17) << k[i].vard << left << setw(17) << k[i].pav
                    <<left << setw(22) << fixed << setprecision(2) << galutinis(vidurkis(suma, k[i].ndrez.size()), k[i].egz)
                    << left << setw(22) << fixed << setprecision(2) << galutinis(median(k[i], k[i].ndrez.size()), k[i].egz) << endl;
           }
           else
            {
                w2 << left << setw(17) << k[i].vard << left << setw(17) << k[i].pav
                    <<left << setw(22) << fixed << setprecision(2) << galutinis(vidurkis(suma, k[i].ndrez.size()), k[i].egz)
                    << left << setw(22) << fixed << setprecision(2) << galutinis(median(k[i], k[i].ndrez.size()), k[i].egz) << endl;
            }
    }

    w1.close();
    w2.close();
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff1 = end1 - start1;
    std::cout << "Duomenu isvedimas i du failus su vektorium uztruko: " << diff1.count() << " s\n";
}




void isvedimas_i_faila_list (list<Studentas> k, int ndkiekis)
{
    auto start1 = std::chrono::high_resolution_clock::now();
    ofstream w1, w2;
    w1.open("vargsiukaiL.txt");
    w2.open("kietiakaiL.txt");
    w1 << left << setw(17) << "Vardas" << left << setw(17) << "Pavarde"
        << left << setw(22) << "Galutinis(vid.)/" << left << setw(22)
        << "Galutinis(med.)\n";

    w2 << left << setw(17) << "Vardas" << left << setw(17) << "Pavarde"
        << left << setw(22) << "Galutinis(vid.)/" << left << setw(22)
        << "Galutinis(med.)\n";

    for(int s=0; s<70; s++)
    {
        w1 << "_" ;
        w2 << "_" ;
    }
    w1 << endl;
    w2 << endl;


    double suma;
    vector<int> temp1;
    for(std::list<Studentas>::iterator it = k.begin(); it != k.end(); ++it){
        temp1 = it->ndrez;

        suma = accumulate(temp1.begin(), temp1.end(), 0);
        sort(temp1.begin(), temp1.end());

        if(galutinis(vidurkis(suma, temp1.size()),it->egz)<5)
           {
                w1 << left << setw(17) << it->vard << left << setw(17) << it->pav
                    << left << setw(22) << fixed << setprecision(2) << galutinis(vidurkis(suma, it->ndrez.size()), it->egz)
                    << left << setw(22) << fixed << setprecision(2) << galutinis(median(*it, it->ndrez.size()), it->egz) << endl;
           }
           else
            {
                w2 << left << setw(17) << it->vard << left << setw(17) << it->pav
                    << left << setw(22) << fixed << setprecision(2) << galutinis(vidurkis(suma, it->ndrez.size()), it->egz)
                    << left << setw(22) << fixed << setprecision(2) << galutinis(median(*it, it->ndrez.size()), it->egz) << endl;
            }
    }
     w1.close();
     w2.close();

    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff1 = end1 - start1;
    std::cout << "Duomenu isvedimas i du failus su listu uztruko: " << diff1.count() << " s\n";

}
void isvedimas_i_faila_2(vector<Studentas> k, int ndkiekis,vector <Studentas>v, int tempvaik){

auto start1 = std::chrono::high_resolution_clock::now();
    ofstream w1,w2;
    w1.open("vargsiukai.txt");
    string failas = "Studentai" + to_string(tempvaik)+".txt";
    string naujas="kietiakai.txt";
    w2.open(failas);
    w1 << left << setw(17) << "Vardas" << left << setw(17) << "Pavarde"
        << left << setw(22) << "Galutinis(vid.)/" << left << setw(22)
        << "Galutinis(med.)\n";
    w2 << left << setw(17) << "Vardas" << left << setw(17) << "Pavarde"
        << left << setw(22) << "Galutinis(vid.)/" << left << setw(22)
        << "Galutinis(med.)\n";
     for(int s=0; s<70; s++)
    {
        w1 << "_" ;
    }
    w1 << endl;

    for(int i=0; i<k.size(); i++)
    {
        double suma; // vektoriaus elementu suma
        suma = accumulate(k[i].ndrez.begin(), k[i].ndrez.end(), 0);
        sort(k[i].ndrez.begin(), k[i].ndrez.end());

        if(galutinis(vidurkis(suma, k[i].ndrez.size()),k[i].egz)<5)
           {
                w1 << left << setw(17) << k[i].vard << left << setw(17) << k[i].pav
                    <<left << setw(22) << fixed << setprecision(2) << galutinis(vidurkis(suma, k[i].ndrez.size()), k[i].egz)
                    << left << setw(22) << fixed << setprecision(2) << galutinis(median(k[i], k[i].ndrez.size()), k[i].egz) << endl;

                k.erase(k.begin()+i);

           }

        else {
            w2 << left << setw(17) << k[i].vard << left << setw(17) << k[i].pav
                    <<left << setw(22) << fixed << setprecision(2) << galutinis(vidurkis(suma, k[i].ndrez.size()), k[i].egz)
                    << left << setw(22) << fixed << setprecision(2) << galutinis(median(k[i], k[i].ndrez.size()), k[i].egz) << endl;
        }
    }



    w1.close();
    w2.close();
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff1 = end1 - start1;
    std::cout << "Duomenu isvedimas i du failus su vektorium uztruko: " << diff1.count() << " s\n";
    }









/*void isvedimas_i_faila_list_2 (list<Studentas> k, int ndkiekis,int tempvaik){

    auto start1 = std::chrono::high_resolution_clock::now();
        ofstream w1, w2;
        w1.open("vargsiukaiL.txt");
        string failas = "Studentai" + to_string(tempvaik)+".txt";
        string naujas="kietiakaiL.txt";
        w1 << left << setw(17) << "Vardas" << left << setw(17) << "Pavarde"
            << left << setw(22) << "Galutinis(vid.)/" << left << setw(22)
            << "Galutinis(med.)\n";

        for(int s=0; s<70; s++)
        {
            w1 << "_" ;
            w2 << "_" ;
        }
        w1 << endl;
        w2 << endl;


        double suma;
        vector<int> temp1;
        for(std::list<Studentas>::iterator it = k.begin(); it != k.end(); ++it){
            temp1 = it->ndrez;

            suma = accumulate(temp1.begin(), temp1.end(), 0);
            sort(temp1.begin(), temp1.end());

            if(galutinis(vidurkis(suma, temp1.size()),it->egz)<5)
               {
                    w1 << left << setw(17) << it->vard << left << setw(17) << it->pav
                        << left << setw(22) << fixed << setprecision(2) << galutinis(vidurkis(suma, it->ndrez.size()), it->egz)
                        << left << setw(22) << fixed << setprecision(2) << galutinis(median(*it, it->ndrez.size()), it->egz) << endl;
               }
               else
                {
                    w2 << left << setw(17) << it->vard << left << setw(17) << it->pav
                        << left << setw(22) << fixed << setprecision(2) << galutinis(vidurkis(suma, it->ndrez.size()), it->egz)
                        << left << setw(22) << fixed << setprecision(2) << galutinis(median(*it, it->ndrez.size()), it->egz) << endl;
                }
        }
         w1.close();
         w2.close();

        auto end1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff1 = end1 - start1;
        std::cout << "Duomenu isvedimas i du failus su listu uztruko: " << diff1.count() << " s\n";






}*/
