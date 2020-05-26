#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    int a;
    char ch;
    string path = "myFile.txt";
   /* ofstream fout;
    
    fout.open(path,ofstream::app);
    if (!fout.is_open())
    {
        cout << "Eroare de deschidere a fisierului!" << endl;
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            cout << "Introduceti text: " ;
            cin >> a;
            fout << a;
            fout << "\n";
        }
        
    }
    fout.close();
    */

    ifstream fin;
    fin.open(path);
    if (!fin.is_open())
    {
        cout << "Eroare de deschidere a fisierului!" << endl;
    }
    else
    {
        cout << "Fisierul a fost deschis cu succes!" << endl;
        while(fin.get(ch))
        {
            cout << ch;
        }
    }
    fin.close();
    return 0;
}

