#include <iostream>
#include <string.h>
#include <windows.h>
#include <fstream>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <sstream>
using namespace std;


vector<string>dato1;
vector<string>dato2;
vector<string>datoa;
vector<string>datob;
vector<string>Auxiliar;


void BaseExtra(){             /// ALMACENA LOS DATOS DEL FICHERO EMPLEADO EN DOS VECTORES DINAMICOS
dato1.clear();dato2.clear();
ifstream Archivo;
Archivo.open("Empleado.txt",ios::in);fflush( stdin );string a1;int c=0;string letra;string guardar;string x;//cin.clear();
Archivo>>letra;
if(letra!=""){
while(!Archivo.eof()){
if(letra!="*"){
guardar=guardar+" "+letra;
}else{
dato1.push_back(guardar);
guardar.clear();
letra.clear();
}
Archivo >> letra;
}
letra.clear();guardar.clear();
Archivo.close();
system("cls");c=0;guardar.clear();int a=0;
for(int i=0;i<dato1.size()/6;i++){
    for(int p=0;p<6;p++){
        dato1[a] = dato1[a].substr(1);
        guardar=guardar+" "+dato1[a]+" * ";
        a++;
    }
    dato2.push_back(guardar);
    guardar.clear();
}
}
}
void BaseExtra2(){            /// ALMACENA LOS DATOS DEL FICHERO PARAMETROS EN DOS VECTORES DINAMICOS
datoa.clear();datob.clear();
ifstream Archivo;
Archivo.open("Parametros.txt",ios::app | ios::in);fflush( stdin );string a1;int c=0;string letra;string guardar;string x;//cin.clear();
Archivo>>letra;
if(letra!=""){
while(!Archivo.eof()){
if(letra!="*"){
guardar=guardar+" "+letra;
}else{
fflush(stdin);datoa.push_back(guardar);
guardar.clear();
letra.clear();
}
Archivo >> letra;
}
}
Archivo.close();
system("cls");c=0;guardar.clear();int a=0;
for(int i=0;i<datoa.size()/9;i++){
    for(int p=0;p<9;p++){
        guardar=guardar+" "+datoa[a]+" * ";
        a++;
    }
    //cout<<guardar<<endl;
    datob.push_back(guardar);
    guardar.clear();
}
}

int  VerificarCedula(string x,vector<string>b){
int a=0;int tam=0;int d=0;int e=-1;fflush( stdin );cin.clear();
if(b[2]=="SISTEMA" || b[2]=="NOMINA" || b[2]=="GESTION HUMANA" || b[2]=="PRODUCCION" || b[2]=="CONTABILIDAD"){
    a=0;
    for(int i=0;i<b.size();i++){
        if(b[a]==x){
        return a;
        exit(-1);
        }
        a=a+9;
    }
}else{
    a=0;
    for(int i=0;i<b.size();i++){
        if(b[a]==x){
        return a;
        exit(-1);
        }
        a=a+6;
    }
    //cout<<"hola papu"<<b[a]<<endl;getch();
}    
return -1;
}
void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }
void Eliminar(string x , string y , vector<string>b,vector<string>c){ ///funcion que elimina la informacion completa del trabajador
fflush( stdin );cin.clear();
int P = VerificarCedula(x,b);
if(P!=-1){
int Posicion = VerificarCedula(x,b);
Auxiliar.clear();
if(b[2]=="SISTEMA" || b[2]=="NOMINA" || b[2]=="GESTION HUMANA" || b[2]=="PRODUCCION" || b[2]=="CONTABILIDAD"){
Auxiliar.assign(b.begin()+Posicion,b.begin()+Posicion+9);
b.erase(b.begin()+Posicion,b.begin()+Posicion+9);
c.erase(c.begin()+(Posicion/9));
}else{
Auxiliar.assign(b.begin()+Posicion,b.begin()+Posicion+6);    
b.erase(b.begin()+Posicion,b.begin()+Posicion+6);
c.erase(c.begin()+(Posicion/6));
}
fstream Archivo;
Archivo.open(y,ios::out);
for(int i=0;i<c.size();i++){
Archivo<<c[i]<<endl;
}
Archivo.close();
}else{
system("cls");
gotoxy(50,12);printf("LA CEDULA NO SE ENCUENTRA EN EL SISTEMA");
getch();
exit(-1);
 }
}
nn

int main(){
 fflush( stdin );cin.clear();    
BaseExtra();
BaseExtra2();

Eliminar("2015114101","Empleado.txt",dato1,dato2);

//for(int i=0;i<dato1.size();i++){
//    cout<<dato1[i]<<endl;
//}

//int P = VerificarCedula("2015114",dato1);
//cout<<P<<endl;

getch();
}
    















