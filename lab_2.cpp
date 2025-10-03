#include <iostream>
#include <string>

using namespace std;

struct Student{

    string ime, prezime;
    int index;
    string polaga;
    void init(string i, string p, int ind, string pred){

        ime=i;
        prezime=p;
        index=ind;
        polaga=pred;

    }

    void pechati(){
        cout<<"Studentot "<<ime<<prezime<<" so broj na index "<<index<<" go polaga predmetot"<<polaga<<endl;
    }
};

Student defaultS[1]={"Name", "Lastname", 1112022, "Matematika 1"};

struct Prostorija{

    string ime;
    int rabMesta;
    Student listaStudenti[10];
    void init(string i, int m, Student *s= defaultS){

        ime=i;
        rabMesta=m;
        for(int j=0; j<rabMesta; j++){
            listaStudenti[j]=s[j];
        }

    }

    void pechati1(){
        cout<<"Prostorijata so ime "<<ime<<" ima 10 rabotni mesta od koi aktivni se "<<rabMesta<<endl;
        cout<<"Studentite koi polagaat vo ovaa prostorija se: "<<endl;
        for(int i=0;i<rabMesta;i++){
            listaStudenti[i].pechati();
        }
    }
     void pechati(int x=10){
        cout<<"Prostorijata: "<<ime<<" ima 10 rabotni mesta od koi aktivni "<<rabMesta<<endl;
        cout<<"Prvite "<<x<<" studenti koi polagaat vo ovaa prostorija se: "<<endl;
        for(int i=0;i<x;i++){
            listaStudenti[i].pechati();
        }
    }
};

void najOptovarenaProstorija(Prostorija lista[], int brojProst){
    int max= 0;
    for(int i=0; i<brojProst-1; i++){

        if(lista[i].rabMesta > lista[i+1].rabMesta){
            max=i;
        }

    }
     lista[max].pechati(lista[max].rabMesta);
}

int main(){

    Student listaStudenti[10];
    Prostorija listaProstorii[2];
    string imeS, imeP, prezime, predmet;
    int index, brojMesta, i, j;
    for(i=0;i<2;i++){
        cout<<"Inicijalizirajte gi studentite vo prostorija "<<i+1<<endl;
        cout<<"Kolku studenti ima vo prostorijata?"<<endl;
        cin>>brojMesta;
        for(j=0;j<brojMesta;j++){
            cout<<"Ime i prezime: ";
            cin>>imeS;
            cin>>prezime;
            cout<<endl<<"Broj na index(samo cifri): ";
            cin>>index;
            cout<<endl<<"Predmet koj se polaga: ";
            cin>>predmet;
            listaStudenti[j].init(imeS, prezime, index, predmet);
        }
        cout<<"Inicijaliziraj ja prostorijata broj"<<i+1<<endl;
        cout<<"Ime na prostorijata: ";
        cin>>imeP;
        cout<<"Prostorijata ima 10 rabotni mesta od koi aktivni se: ";
        cin>>brojMesta;
        listaProstorii[i].init(imeP, brojMesta, listaStudenti);

    }
    listaProstorii[0].pechati1();
    listaProstorii[1].pechati(3);
    najOptovarenaProstorija(listaProstorii, 2);
    return 0;
}