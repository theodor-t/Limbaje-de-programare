#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <conio.h>

using namespace std;

void stergeDinFisier(string propozitie);
int contorNrCuv(string propozitie);
void minLitere(string propozitie);
bool conditia(string word);
string stergeMinLitere(string& propozitie);
int nrCuvInFisier();
void scrieInFisier(string& propozitie);

int main()
{
	string text;
	int key;

	cout << "Dati stringul" << endl;
	getline(cin, text);

	do {
		system("cls");
		cout << "1. De determinat numarul de cuvinte din fraza." << endl;
		cout << "2. De determinat cuvintele dintr-o fraza care au mai putin de 5 litere." << endl;
		cout << "3. De sters cuvintele dintr-o fraza care au mai putin de 5 litere." << endl;
		cout << "4. In fisier de determinat numarul de cuvinte." << endl;
		cout << "5. De inscris in alt fisier cuvintele care au mai putin de 5 litere." << endl;
		cout << "6. De sters cuvintele dintr-un fisier text care au mai putin de 5 litere." << endl;
		cout << "0. Exit" << endl;

		cout << "\t\t Selecteaza Optiunea ==> ";
		cin >> key;

		switch (key) {
		case 1:
			system("cls");
			cout << "Numarul de cuvinte in fraza sunt: " << contorNrCuv(text);
			_getch();
			break;

		case 2:
			system("cls");
			cout << "Cuvintele care au mai putin de 5 litere:\n";
			minLitere(text);
			_getch();
			break;

		case 3:
			system("cls");
			cout << "Cuvintele cu mai putin de 5 litere sunt sterse,cuvintele care au ramas: \n" << stergeMinLitere(text);
			_getch();
			break;

		case 4:
			system("cls");
			cout << "Numarul de cuvinte in fisier: \n" << nrCuvInFisier();
			_getch();
			break;

		case 5:
			system("cls");
			scrieInFisier(text);
			cout << "In fisier au fost inscrise cuvintele ce satisfac conditia.";
			_getch();
			break;

		case 6:
			system("cls");
			stergeDinFisier(text);
			cout << "Au fost sterse cuvintele ce satisfac conditia." << endl;
			_getch();
			break;
		}
	} while (key != 0);

}

int contorNrCuv(string propozitie) {
	int numberOfWords = 0;
	size_t i;

	if (isalpha(propozitie[0])) {
		numberOfWords++;
	}

	for (i = 1; i < propozitie.length(); i++) {
		if ((isalpha(propozitie[i])) && (!isalpha(propozitie[i - 1]))) {
			numberOfWords++;
		}
	}
	return numberOfWords;
}

void minLitere(string propozitie) {
	size_t i;
	char c;
	istringstream ss(propozitie);

	do {
		string word;
		ss >> word;
		if (word.length() < 5) {
			cout << word << endl;
		}
	} while (ss);
}

bool conditia(string word) {
	size_t i;
	int count = 0;
	bool flag = true;
	if (word.length() < 5) {
		return true;
	}
	else return false;
}


string stergeMinLitere(string& propozitie) {
	string result;
	size_t i;
	istringstream ss(propozitie);
	do {
		string word;
		ss >> word;
		cout << word << endl;
		if (!conditia(word)) {
			result += " " + word;
		}
	} while (ss);
	propozitie = result;
	return propozitie;
}

int nrCuvInFisier() {
	int sum = 0;
	string line;
	ifstream MyReadFile("ex.txt");
	while (getline(MyReadFile, line)) {
		sum += contorNrCuv(line);
	}
	MyReadFile.close();
	return sum;
}

void scrieInFisier(string& propozitie) {
	size_t i;
	ofstream out("out.txt");
	istringstream ss(propozitie);
	do {
		string word;
		ss >> word;
		if (word.length() < 5) {
			out << word << " ";
		}
	} while (ss);
	out.close();
}
void stergeDinFisier(string propozitie) {
	size_t i;
	ofstream out("out.txt");
	out << stergeMinLitere(propozitie) << " ";
	out.close();
}

