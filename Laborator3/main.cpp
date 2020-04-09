#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <cmath>
#include <bits/stdc++.h>
#define nmax  50
using namespace std;

int creare_vector(int v[], int n);
int generare_vector(int v[], int n);
void afisare_vector(int v[], int n);
int Minimum(int v[], int n);
int Maximum(int v[], int n);
double media(int v[], int n);
int Sortare_bubble_optimizata(int v[], int n);
int Sortare_insertiei(int v[], int n);
int Rotire_Dreapta(int v[],int n);
int Inserare(int n, int v[], int k);
int Stergere(int v[], int n);
int Caracteristica(int v[], int n, int a, int b, int &count);
void onRoute(int v[], int n);
int main(){

    int key, n, aux, k, a, b, el;
    int v[nmax];
    int intervalStart;
    int intervalEnd;
    int count = 0;
    int value;


  do {
        system("CLS");
    cout << "1.De determinat într-un tabel de numere valorile minimă şi maximă " <<endl;
    cout << "2.De determinat într-un tabel de numere media aritmetică " <<endl;
    cout << "3.De aranjat un tabel de numere în ordine crescătoare sau descrescătoare, utilizând una dintre metodele de sortare " <<endl;
    cout << "4.De efectuat rotirea la stânga (variantele impare) sau la dreapta (variantele pare) a elementelor tabelului de k ori" <<endl;
    cout << "5.De adăugat date în tabelul de numerele " <<endl;
    cout << "6.De șters date din tabelul de numerele." <<endl;
    cout << "7.De calculat nr. de trenuri ce pleaca intr-un interval de timp" <<endl;
    cout << "\t\tSelecteaza o optiune ==> ";
    cin  >> key;
    switch (key){
        case 1:
            system("CLS");
            cout << "Introduceti dimensiunea vectorului = ";
            cin >> n;
            generare_vector(v, n);
            cout << "Tabelul : ";
            afisare_vector(v, n);
            cout << "Valoarea minima este = " << Minimum(v, n) << endl;
            cout << "Valoarea maxima este = "  << Maximum(v, n) << endl;
            getch();
        break;
        case 2:
            system("CLS");
            cout << "Introduceti dimensiunea vectorului = ";
            cin >> n;
            //creare_vector(v, n);
            generare_vector(v, n);
            cout << "Tabelul : ";
            afisare_vector(v, n);
            cout << "Media elementelor este = " << media(v, n);
            getch();
        break;
        case 3:
            system("CLS");
            cout << "Introduceti dimensiunea vectorului = ";
            cin >> n;
            //creare_vector(v, n);
            generare_vector(v, n);
            cout << "Tabelul initial: ";
            afisare_vector(v, n);
            cout << "Tabelul sortat crescator: ";
            Sortare_insertiei(v, n);
            cout << "Tabelul sortat descrescator: ";
            Sortare_bubble_optimizata(v, n);
            getch();
        break;
        case 4:
            system("CLS");
            cout << "Introduceti dimensiunea vectorului = ";
            cin >> n;
            generare_vector(v, n);
            cout << "Tabelul initial: ";
            afisare_vector(v, n);
            cout << "Rotirea la dreapta: ";
            Rotire_Dreapta( v,  n);
            getch();
        break;
        case 5:
            system("CLS");
            cout << "Introduceti dimensiunea vectorului = ";
            cin >> n;
            generare_vector(v, n);
            cout << "Tabelul initial: ";
            afisare_vector(v, n);
            cout << "Inserarea unui element: ";
            cin >> k;
            Inserare( n, v, k);
            getch();
        break;
        case 6:
            system("CLS");
            cout << "Introduceti dimensiunea vectorului = ";
            cin >> n;
            generare_vector(v, n);
            cout << "Tabelul initial: ";
            afisare_vector(v, n);
            cout << "Stergerea ultimului element: ";
            Stergere(v, n);
            getch();
        break;
        case 7:
            system("CLS");
            cout << "Introduceti dimensiunea vectorului = ";
            cin >> n;
            generare_vector(v, n);
            cout << "Tabelul initial: ";
            afisare_vector(v, n);
            cout << "Dati valoare de determinare a trenurilor la ora anumita" << endl;
            cin >> value;
            onRoute(v, n);
            getch();
        break;
    }
  } while(key !=0);
    return 1;
}

int creare_vector(int v[], int n)
{
     cout << "Dati elementele tabelului \n";
        for(int i=0; i<n; i++){
        cout << "V[ "<<i+1<<" ] = ";
        cin >> v[i];
        }

 return 1;
}

int generare_vector(int v[], int n)
{

for(int i=0; i<n; i++)
    v[i] =  rand()%  -10 +10;


   return 1;
}

void afisare_vector(int v[], int n){

for(int i=0; i<n; i++)
cout << setw(8) << v[i];
        cout << endl;
}

int Minimum(int v[], int n )
{
int i, min;
min = v[0];
for(i=1; i<n; i++)
if(v[i]<min)
min = v[i];
return min;
}

int Maximum(int v[], int n )
{
int i, max;
max = v[0];
for(i=1; i<n; i++)
if(v[i]>max)
max = v[i];
return max;
}

double media(int v[], int n){
    int i, media= 0;
    for(i=0; i<n; i++){
        media+=v[i];
    }
    return (double)media/n;
}

int Sortare_bubble_optimizata(int v[], int n ) {
int i, j=0, m, aux;
do
{
m = 0; j++;
for(i=0; i<n-j; i++)
if(v[i]<v[i+1]) {
aux = v[i];
v[i] = v[i+1];
v[i+1] = aux;
m = 1;
}
} while(m);
afisare_vector(v, n);
return 1;
}

int Sortare_insertiei(int v[], int n ) {
 int key, j;
   for(int i = 1; i<n; i++) {
      key = v[i];
      j = i;
      while(j > 0 && v[j-1]>key) {
         v[j] = v[j-1];
         j--;
      }
     v[j] = key;
   }
 afisare_vector(v, n);
return 1;
}

int Rotire_Dreapta(int v[], int n)
{
int i, aux;
if(n==0) return 0;

aux = v[n-1];
for(i=n-1; i>0; i--)
v[i] = v[i-1];

v[0] = aux;

afisare_vector(v, n);
return 1;
}

int Inserare(int n, int v[], int k)
{
int i;
if(n==0) return 0;
n++;
for(i=n-1; i>0; i--)
v[i] = v[i-1];
v[0] = k;
afisare_vector(v, n);
return 1;
}
void onRoute(int v[], int n, int count, int ora){
for (int i = 0; i < n; i++)
if (v[i] == ora) { count++;}
cout <<"Nr. de trenuri la ora anumita: " << count;
}

int Stergere(int v[], int n)
{
int i;
if(n==0) return 0;
n--;
for(i=0; i<n; i++)
v[i] = v[i+1];
afisare_vector(v, n);
return 1;


}
