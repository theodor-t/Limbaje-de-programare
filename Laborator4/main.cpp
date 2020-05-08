#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iomanip>



#define NMAX 100

using namespace std;
void creareMatrix(int matrix[NMAX][NMAX], int row, int col);
void randMatrix(int matrix[NMAX][NMAX], int row, int col);
void matrixOutput(int matrix [NMAX][NMAX], int row, int col);
void SearchMin(int matrix [NMAX][NMAX], int row, int col);
void SearchMax(int matrix [NMAX][NMAX], int row, int col);
void interschimbare_coloana(int matrix[NMAX][NMAX], int row, int col, int l1, int l2);
void generare(int matrix[NMAX][NMAX], int row, int col);
void addColum(int matrix[NMAX][NMAX], int row, int &col);
void matrixSort(int matrix[NMAX][NMAX], int &row, int &col);

int main()

{
int row, col, matrix[NMAX][NMAX];
char key, key1;
int l1, l2 ;

do
{
cout << "\t\t\tPrelucrarea datelor in matrice \n\n";
cout << "1. De afisat valoarea minima si maxima din matrice\n";
cout << "2. De interschimbat 2 coloane in matrice\n";
cout << "3. De adaugat o coloana cu ora minima\n";
cout << "4. De aranjat matricea dupa coloana adaugata\n";
cout << "5. De generat o matrice cu conditia indicata:\n";
cout << "\t|0  2   4|" <<endl;
cout << "\t|6  8 10|" <<endl;
cout << "\t|12 14 16|\n" <<endl;
cout << "0.Exit\n\n";
key = getch();
system("cls");

switch(key)
{
case '1':
do
{
cout << "\t\tDe afisat valoarea minima si maxima din matrice\n\n";
cout << "1. Matricea introdusa manual\n";
cout << "2. Matricea generata aleator\n\n";
cout << "0. Meniu initial\n\n";
key1 = getch();
system("cls");
switch(key1)
{
case '1':
cout << "Numarul de linii -> ";
cin >> row;
cout << "Numarul de coloane -> ";
cin >> col;
creareMatrix(matrix, row, col);
cout << "Matricea generata este: "<< endl;
matrixOutput(matrix, row, col);
SearchMin(matrix, row, col);
SearchMax(matrix, row, col);
cout << "\n\nEnter pentru a reveni la meniul initial\n\n";
getch();
system("cls");
break;

case '2':
cout << "Numarul de linii -> ";
cin >> row;
cout << "Numarul de coloane -> ";
cin >> col;
randMatrix(matrix, row, col);
cout << "Matricea generata este: "<< endl;
matrixOutput(matrix, row, col);
SearchMin(matrix, row, col);
SearchMax(matrix, row, col);
cout << "\n\nEnter pentru a reveni la meniul initial\n\n";
getch();
system("cls");
break;
}
}while(key1 != '0');
system("cls");
break;

case '2':
do
{
cout << "\t\t\tDe interschimbat 2 linii in matrice\n\n";
cout << "1. Matricea introdusa manual\n";
cout << "2. Matricea generata aleator\n\n";
cout << "0. Meniu initial\n\n";
key1 = getch();
system("cls");
switch(key1)
{
case '1':
cout << "Numarul de linii -> ";
cin >> row;
cout << "Numarul de coloane -> ";
cin >> col;
creareMatrix(matrix, row, col);
cout << "Matricea generata este: "<< endl;
matrixOutput(matrix, row, col);
cout << "Introduceti colonele ce trebuie de interschimbat " << endl;
cout << "col 1 -> ";
cin >> l1;
cout << "col 2 -> ";
cin >> l2;
interschimbare_coloana(matrix, row, col, l1, l2);
cout << "Matricea dupa interschimbare este: "<< endl;
cout << "\nEnter pentru a reveni la meniul initial\n\n";
getch();
system("cls");
break;

case '2':
cout << "Numarul de linii -> ";
cin >> row;
cout << "Numarul de coloane -> ";
cin >> col;
randMatrix(matrix, row, col);
cout << "Matricea generata este: "<< endl;
matrixOutput(matrix, row, col);
cout << "Introduceti colonele ce trebuie de interschimbat " << endl;
cout << "col 1 -> ";
cin >> l1;
cout << "col 2 -> ";
cin >> l2;
interschimbare_coloana(matrix, row, col, l1, l2);
cout << "Matricea dupa interschimbare este: "<< endl;
cout << "\nEnter pentru a reveni la meniul initial\n\n";
getch();
system("cls");
break;
}
}while(key1 != '0');
system("cls");
break;

case '3':
do
{
cout << "\t\tDe adaugat o coloana cu ora minima\n\n";
cout << "1. Matricea introdusa manual\n";
cout << "2. Matricea generata aleator\n\n";
cout << "0. Meniu initial\n\n";
key1 = getch();
system("cls");
switch(key1)
{
case '1':
cout << "Numarul de linii -> ";
cin >> row;
cout << "Numarul de coloane -> ";
cin >> col;
creareMatrix(matrix, row, col);
cout << "Matricea creata este: "<< endl;
matrixOutput(matrix, row, col);
addColum( matrix, row, col);
cout << "Matricea cu coloana adaugata este:" <<endl;
matrixOutput(matrix, row, col);
cout << "\n\nEnter pentru a reveni la meniul initial\n\n";
getch();
system("cls");
break;

case '2':
cout << "Numarul de linii -> ";
cin >> row;
cout << "Numarul de coloane -> ";
cin >> col;
generare(matrix, row, col);
cout << "Matricea generata este: "<< endl;
matrixOutput(matrix, row, col);
addColum( matrix, row, col);
cout << "Matricea cu coloana adaugata este:" <<endl;
matrixOutput(matrix, row, col);
cout << "\n\nEnter pentru a reveni la meniul initial\n\n";
getch();
system("cls");
break;
}
}while(key1 != '0');
system("cls");
break;

case '4':
do
{
cout << "\t\tDe aranjat matricea dupa coloana adaugata\n\n";
cout << "1. Matricea introdusa manual\n";
cout << "2. Matricea generata aleator\n\n";
cout << "0. Meniu initial\n\n";
key1 = getch();
system("cls");
switch(key1)
{
case '1':

cout << "Numarul de linii -> ";
cin >> row;
cout << "Numarul de coloane -> ";
cin >> col;
creareMatrix(matrix, row, col);
cout << "Matricea generata este: "<< endl;
matrixOutput(matrix, row, col);
addColum(matrix, row, col);
cout << "Matricea cu coloana adaugata este:" << endl;
matrixOutput(matrix, row, col);
cout << "Matricea cu coloana sortata:" << endl;
matrixSort(matrix, row, col);
matrixOutput(matrix, row, col);
cout << "\nEnter pentru a reveni la meniul initial\n\n";
getch();
system("cls");
break;

case '2':
cout << "Numarul de linii -> ";
cin >> row;
cout << "Numarul de coloane -> ";
cin >> col;
generare(matrix, row, col);
cout << "Matricea generata este: "<< endl;
matrixOutput(matrix, row, col);
addColum( matrix, row, col);
cout << "Matricea cu coloana adaugata este:" <<endl;
matrixOutput(matrix, row, col);
cout << "Matricea cu coloana sortata:" << endl;
matrixSort(matrix, row, col);
matrixOutput(matrix, row, col);
cout << "\n\nEnter pentru a reveni la meniul initial\n\n";
getch();
system("cls");
break;
}
}while(key1 != '0');
system("cls");
break;

case '5':
cout << "Numarul de linii -> ";
cin >> row;
cout << "Numarul de coloane -> ";
cin >> col;
cout << "Matricea generata este: "<<endl;
generare(matrix, row, col);
matrixOutput(matrix, row, col);
cout << "\nEnter pentru a reveni la meniul initial\n\n";
getch();
system("cls");
break;
}
}while(key != '0');
return 1;
}

void creareMatrix(int matrix[NMAX][NMAX], int row, int col){
int i, j;

cout<<" Introduceti matricea:"<<endl;
for(i = 0; i < row; i++){
for(j = 0; j < col; j++){

cout <<"[ "<< i + 1 << ";" << j + 1 << " ] = ";
cin >> matrix[i][j];

}
cout << endl;
}

}

void randMatrix(int matrix[NMAX][NMAX], int row, int col){
int i, j;

cout<<" Introduceti matricea:"<<endl;
for(i = 0; i < row; i++){

for(j = 0; j < col; j++){


matrix[i][j] = rand() % 8 + 3;

}
cout << endl;
}

}

void matrixOutput(int matrix [NMAX][NMAX], int row, int col){

for(int i = 0; i < row; i++)
{
for (int j = 0; j < col; j++ )
{
cout << setw(4) << matrix[i][j];
}
cout << endl;
}
cout << endl;
}

void SearchMin(int matrix [NMAX][NMAX], int row, int col){
int min, i, j;
int imin;
int jmin;
min = matrix[0][0];

for( i = 0; i < row; i++)
{
for ( j = 0; j < col; j++ )
{
if(matrix[i][j] < min ){
min = matrix[i][j];

imin = i;
jmin = j;
}
}
}

cout << "Elementul minim = " << min << " pe pozitia: [ "<< imin + 1 << ";" << jmin + 1 <<" ]" <<endl;
}

void SearchMax(int matrix [NMAX][NMAX], int row, int col){
int max, i, j;
int imax;
int jmax;
max = matrix[0][0];

for( i = 0; i < row; i++)
{
for ( j = 0; j < col; j++ )
{
if(matrix[i][j] > max ){
max = matrix[i][j];
imax = i;
jmax = j;
}
}
}

cout << "Elementul maxim = " << max << " pe pozitia: [ "<< imax + 1 << ";" << jmax + 1 <<" ]" <<endl;
}

void interschimbare_coloana(int matrix[NMAX][NMAX], int row, int col, int l1, int l2){
int temp;
for (int i = 0; i < row; i++)
{
temp = matrix[i][l1-1];
matrix[i][l1-1] = matrix[i][l2-1];
matrix[i][l2-1] = temp;
}
matrixOutput(matrix, row, col);
}

void generare(int matrix[NMAX][NMAX], int row, int col){
int value = -2;
	for ( int i = 0; i < row; i++ ) {
		for ( int j = 0; j < col; j++ ) {
			value += 2;
			matrix[i][j] = value;
		}
}
}

void addColum(int matrix[NMAX][NMAX], int row, int &col ){
int nr, i, j, min, jmin, imin;

for( i = 0; i < row; i++)
{
min=matrix[i][0];
for ( j = 0; j < col; j++ )
{
if(matrix[i][j] < min ){
min = matrix[i][j];
imin = i;
jmin = j;
}
matrix[i][col] = min;
}

}

col++;
}
void matrixSort(int matrix[NMAX][NMAX], int &row, int &col){
int k,temp;
bool change;
k = 0;
do{
k ++;
change = 0;
for( int i = 0; i < row - k; i++){
if(matrix[i][col-1] > matrix[i + 1][col - 1]){
for(int j = 0; j < col; j ++){
temp = matrix[i][j];
matrix[i][j] = matrix[i+1][j];
matrix[i+1][j] = temp;
}
change = 1;
}
}
}while(change);

}
