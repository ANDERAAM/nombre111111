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

vector<string>Base;

LlenarVector(){
    fstream Archivo;
    Archivo.open("Parametros.txt",ios::app | ios::in);
    string x,guardar;
    while(!Archivo.eof()){
    Archivo>>x;
    if(x!="*"){
    guardar=guardar+" "+x;
    }else{
    guardar=guardar.substr(1,guardar.size()-1);
    Base.push_back(guardar);
    guardar.clear();
    x.clear();
    }
    }
    Archivo.close();
}
void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }
int  VerificarCedula(string x){
 int a=0;
 for(int i=0;i<(Base.size()/9);i++){
 if(Base[a]==" "+x){;
 return a;
 exit(1);
 }
 a=a+9;
 }
 return -1;
 }
string Entero(int x){
       // number to be converted to a string
 
 string Result;          // string which will contain the result
 
 ostringstream convert;   // stream used for the conversion
 
 convert << x;      // insert the textual representation of 'Number' in the characters in the stream
 
 Result = convert.str(); // set 'Result' to the contents of the stream
 } 
 
 
int main(){
LlenarVector();
int  a,b,c,d,e;
cin.ignore();
int P = 0; //VerificarCedula("1081827159");
/*a=Base[4];b=Base[5];c=Base[6];d=Base[7];e=Base[8]*/;string x;string y;string valor;string cod;int Valor;
//cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<endl;
b=atoi(Base[3].c_str());
ofstream Archivo;
Archivo.open("Parametros.txt",ios::app);
 gotoxy(65,8); cout<<"I N G R E S E  VA L O R E S  A  L A  N O M I N A ";
 gotoxy(71,11); cout<<"1. DEDUCCIONES     (DESCUENTOS)";
 gotoxy(71,13); cout<<"2. BONIFICACIONES  (BONOS)";
 gotoxy(73,15); cout<<"Ingrese La Opcion Que Desee : ";cin>>x;
if(x=="1"){
system("cls");
gotoxy(54,8); cout<<"A G R E G U E  E L  D E T A L L E  D E  D E S C U E N T O";
gotoxy(66,11); cout<<"1. PENSION CODIGO : A || $ 50000";
gotoxy(66,14); cout<<"2. COTIZACION DE SALUD COD : B || $ 68000";
gotoxy(66,17); cout<<"3. PRESTAMO  CODIGO : C || $ 90000";
gotoxy(66,20); cout<<"4. SEGURO    CODIGO : D || $ 78950";
gotoxy(71,23); cout<<"Ingrese La Opcion Que Desee : ";cin>>y;
if(y=="1"){y="A50000";}
if(y=="2"){y="B68000";}
if(y=="3"){y="C90000";}
if(y=="4"){y="D78950";}
cod=y.substr(0,1);
valor=y.substr(1);
Valor=atoi(valor.c_str());
Base[P+4]=cod+Base[P+4];
a=atoi(Base[P+6].c_str());
c=atoi(Base[P+7].c_str());
a=a+Valor;
int Total = atoi(Base[P+8].c_str());
Total = (Total+c)-(a);
Base[6]=Entero(a);
Archivo<<endl<<Base[P+0]<<" * "<<Base[P+1]<<" * "<<Base[P+2]<<" * "<<Base[P+3]<<" * "<<Base[P+4]<<" * "<<Base[P+5]<<" * "<<a<<" * "<<Base[P+7]<<" * "<<Total<<endl;
cout<<endl<<Base[P+0]<<" * "<<Base[P+1]<<" * "<<Base[P+2]<<" * "<<Base[P+3]<<" * "<<Base[P+4]<<" * "<<Base[P+5]<<" * "<<a<<" * "<<Base[P+7]<<" * "<<Total<<endl;
}else if(x=="2"){
system("cls");
gotoxy(60,8); cout<<" A G R E G U E  E L  D E T A L L E  D E  B O N I F I C A C I O N ";
gotoxy(66,12); cout<<"1. AUXILIO TRANSPORTE CODIGO : E || $ 30000";
gotoxy(66,15); cout<<"2. AUXILIO DE COMIDA  CODIGO : F || $ 25000";
gotoxy(66,18); cout<<"3. PREMIO  CODIGO : G || $40000";
gotoxy(71,21); cout<<"Ingrese La Opcion Que Desee : ";cin>>y;
if(y=="1"){y="E30000";}
if(y=="2"){y="F25000";}
if(y=="3"){y="G40000";}
cod=y.substr(0,1);
valor=y.substr(1);
Valor=atoi(valor.c_str());
Base[4]=cod+Base[4];
a=atoi(Base[7].c_str());
c=atoi(Base[6].c_str());
a=a+Valor;
int Total = atoi(Base[8].c_str());
Total = (Total+a)-(c);
Archivo<<endl<<Base[P+0]<<" * "<<Base[P+1]<<" * "<<Base[P+2]<<" * "<<Base[P+3]<<" * "<<Base[P+4]<<" * "<<Base[P+5]<<" * "<<Base[P+6]<<" * "<<a<<" * "<<Total<<endl;
cout<<Base[P+0]<<" * "<<Base[P+1]<<" * "<<Base[P+2]<<" * "<<Base[P+3]<<" * "<<Base[P+4]<<" * "<<Base[P+5]<<" * "<<a<<" * "<<Base[P+7]<<" * "<<Total<<endl;

}else{
system("cls");
exit(-1);
}
Archivo.close();
}
