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

void Modificar(string x , string y , vector<string>b,vector<string>c){///funcion que modifica  la informacion del trabajador
Departamento.clear();NombreEmpresa.clear();
Eliminar(x);
for(int i=0;i<Auxiliar.size();i++){
string x = Auxiliar[i].substr(1,Auxiliar[i].size()-1);
Auxiliar[i]=x;
}
getch();
fflush( stdin );cin.clear();system("cls");int Opcion=0;
//cout<<Auxiliar[0]<<"--"<<Auxiliar[1]<<"--"<<Auxiliar[2]<<"--"<<Auxiliar[3]<<"--"<<Auxiliar[4]<<"--"<<Auxiliar[5]<<"--"<<endl;
char Numero[100] ; long long Cedula ;string Nombre ;string FechaNacimiento ;string y;long long Salario;
gotoxy(27,9);  cout<<" SELECCIONE  LOS DATOS DEL EMPLEADO QUE DESEA MODIFICAR ";
gotoxy(42,11);  cout<<"0. CEDULA";
gotoxy(42,13);  cout<<"1. EMPRESA A DONDE LABORA";
gotoxy(42,15); cout<<"2. NOMBRE COMPLETO";
gotoxy(42,17); cout<<"3. FECHA DE NACIMIENTO";
gotoxy(42,18); cout<<"4. DEPARTAMENTO EN DONDE LABORA EL EMPLEADO";
gotoxy(42,19); cout<<"5. SALARIO DEL EMPLEADO";
gotoxy(35,20);cout<<"Seleccione EL Departamento Deacuerdo Al Numero -> ";fflush( stdin );cin>>Numero;validar(Numero);Opcion=atoi(Numero);
system("cls");
if(Opcion>0 && Opcion>=6){
system ("cls");
gotoxy(40,9);printf("I N G R E S O  N U M E R O  V A L I D O");
gotoxy(42,15);exit(1);
}
if(Opcion==0){
gotoxy(42,7); cout<<"INGRESE LA CEDULA DEL NUEVO EMPLEADO : ";fflush( stdin );cin>>Numero;validar(Numero);y=Numero;string numero=Numero;Cedula=atoll(y.c_str());//validar(Codigo);Cedula = Convertir_letras(Cedula1);//Codifgetline(cin,Cedula1);//cin>>Cedula;cin.clear();//;Cedula1 = Codigo;//validar(Codigo);Cedula1 = Codigo;Verificar(Cedula1);
if(VerificarCedula(numero)!=-1){
system("cls");
gotoxy(50,12);printf("I N G R E S E  U N A  C E D U L A  N O  R E P E T I D A");
getch();
exit(1);
}else{
Auxiliar[0]=y;
}
}
if(Opcion==1){
Empresa1();
}
if(Opcion==2){
fflush( stdin );
gotoxy(42,9); cout<<"INGRESE EL NOMBRE DEL NUEVO EMPLEADO : ";fflush( stdin );getline(cin,Nombre);Vacio(Nombre);
Auxiliar[2]=Nombre;
}
if(Opcion==3){
fflush( stdin );
gotoxy(42,11);cout<<"INGRESE LA FECHA DE NACIMEINTO DEL NUEVO EMPLEADO : ";fflush( stdin );getline(cin,FechaNacimiento);Vacio(FechaNacimiento);Fecha(FechaNacimiento);
Auxiliar[3]=FechaNacimiento;
}
if(Opcion==4){
Departamento1();
}
if(Opcion==5){
fflush( stdin );
gotoxy(42,13);cout<<"INGRESE EL SALARIO DEL NUEVO EMPLEADO : ";fflush( stdin );cin>>Numero;validar(Numero);y=Numero;Salario=atoll(y.c_str());
Auxiliar[5]=y;
}
ofstream Archivo;
system("cls");
fflush( stdin );string w=Auxiliar[0]+" * "+Auxiliar[1]+" * "+Auxiliar[2]+" * "+Auxiliar[3]+" * "+Auxiliar[4]+" * "+Auxiliar[5]+" * ";
dato2.push_back(w);
//cout<<dato2[dato2.size()-2]<<endl;
for(int i=0;i<dato2.size();i++){
cout<<dato2[i]<<endl;
}
Archivo.open("Empleado.txt");
Archivo.close();
Archivo.open("Empleado.txt",ios::app);
for(int i=0;i<dato2.size();i++){
Archivo<<dato2[i]<<endl;
}
//Archivo<<w<<endl;//Auxiliar[0]<<" * "<<Auxiliar[1]<<" * "<<Auxiliar[2]<<" * "<<Auxiliar[3]<<" * "<<Auxiliar[4]<<" * "<<Auxiliar[5]<<" * "<<endl;
Archivo.close();
}







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
    















