#include <iostream>
#include <conio.h>
#include <cstdlib>
using namespace std;
bool checkArmstrongNumber(int num);
bool nrPrim(int n);
int main()
{
    int key,num;
    int a,b,i,j,n;
    int max,min;
    int verifContor,count;
    int valInitiala,valFinala;
    int cont = 0;
    max = 0;
    min = 999999;

    bool flag;
    do {
        system("cls");
        cout << "1. De verificat daca numarul satisface conditia" << endl;
        cout << "2. De afisat toate numerele din intervalul[a,b] care satisface conditia " << endl;
        cout << "3. De afisat primele n numere care satisface conditia" << endl;
        cout << "4. De afisat toate numerele din intervalul [a,b] care satisfac II variante " << endl;
        cout << "5. De afisat valoarea maxima care satisface conditiei" << endl;
        cout << "0. Exit" << endl;
        cout << "\t\t Selecteaza Optiunea ==> " ;
        cin >> key;

        switch(key) {
        case 1:
            system("cls");
            cout << "Introduceti numarul ce trebue varificat = ";
            cin >> num;
            flag = checkArmstrongNumber(num);
            if(flag == true)
                cout<<num<<" este numar Armstrong.";
            else
                cout<<num<<" nu este numar Armstrong";
            getch();
            break;
        case 2:
            system("cls");
            cout <<"Introduceti limita de stanga a intervalului: ";
            cin >> a;
            cout <<"Introduceti limita de dreapta a intervalului: ";
            cin >> b;
            cout << "In intervalul dat sunt urmatoarele numere " <<endl;
            for(i = a; i<=b; i++) {
                if(checkArmstrongNumber(i)) {
                    cout << i <<" ";
                    cont++;
                }
            }
            cout<<endl;
            if(cont == 0)
                cout << "In intervalul dat nu sunt numere Armstrong."<<endl;
            else
                cout << "In intervalul [" <<a<< ";"<<b<<"] sunt " << cont << " numere Armstrong"<<endl;
            getch();
            break;
        case 3:
            system("cls");
            j = 1;
            verifContor = 0;
            cout << "Dati N a primelor numere Armstrong: ";
            cin >> count;
            cout << "Primele " << count << " numere sunt: ";
            while (count != verifContor) {
                if (checkArmstrongNumber(j) == 1) {
                    verifContor++;
                    cout << j << " ";
                }
                j++;
            }
            getch();
            break;
        case 4:
            system("cls");
            cout << "Dati a al intervalului [a; b]" << endl;
            cin >> valInitiala;
            cout << "Dati b al intervalului [a; b]" << endl;
            cin >> valFinala;
            cout << "Numerele Armstrong din intervalul [" << valInitiala << ";" <<
                 valFinala << "] care satisfac conditia a II sunt:" << endl;
            for (int i = valInitiala; i < valFinala; i++)
            {
                if (checkArmstrongNumber(i) == 1 && nrPrim(i))
                {
                    cout << i << " ";
                }
            }
            getch();
            break;
        case 5:
            system("cls");
            a = 0;
            b = 10000;
            for(i = a; i<=b; i++) {
                if(checkArmstrongNumber(i)) {
                    (i > max) ? max = i : 0;
                    (i < min) ? min = i : 0;

                }

            }
            cout << "Numerele Armstrong din 3 cifre au valoarea maxima: " << max << endl;
            getch();
            break;
        }
    } while(key !=0);
    return 0;
}

bool checkArmstrongNumber(int num)
{
    int temp, sum=0, digit;
    bool isArm;

    temp = num;
    while(temp != 0) {
        digit = temp % 10;
        sum = sum +(digit * digit * digit);
        temp = temp/10;
    }
    if (sum==num)
        isArm = true;
    else
        isArm = false;

    return isArm;
}
bool nrPrim(int n) {

  if (n <= 1)

    return false;

  for (int i = 2; i < n; i++)

    if (n % i == 0)

      return false;

  return true;

}
