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

struct Empleados{
   long long Cedula ;
   string Nombre ;
   string NombreEmpresa ;
   string FechaNacimiento;
   string Departamento;
   long long Salario;
   struct Empleados *izq , *der ;
};

vector<string>dato1;
vector<string>dato2;
vector<string>datoa;
vector<string>datob;
vector<string>Auxiliar;


Empleados *CrearEmpleados(Empleados *&Arbol ,long long Cedula ,string Nombre ,string NombreEmpresa , string FechaNacimiento , string Departamento , long Salario){//ESTA FUNCION ES PARA ALMACENAR LOS DATOS DE LOS EMPLEADOS EN LA EMPRESA C
    Empleados *Empleado              =   new Empleados();
    Empleado->Nombre                 =   Nombre;
    Empleado->Cedula                 =   Cedula;
    Empleado->NombreEmpresa          =   NombreEmpresa;
    Empleado->FechaNacimiento        =   FechaNacimiento;
    Empleado->Departamento           =   Departamento;
    Empleado->Salario                =   Salario;
    Empleado->der                    =   NULL;
    Empleado->izq                    =   NULL;
    return Empleado;
}
void InsertarEmpleados(Empleados *&Arbol,long long Cedula ,string Nombre ,string NombreEmpresa , string FechaNacimiento , string Departamento , long Salario){//INSERTA LA INFORMACION DEL EMPLEADO EN LOS DIFERENTES ARBOLES
 if   (Arbol == NULL){
      Arbol = CrearEmpleados(*&Arbol,Cedula ,Nombre ,NombreEmpresa ,FechaNacimiento ,Departamento ,Salario);
      }else if (Cedula < Arbol->Cedula) {
      InsertarEmpleados(Arbol->izq,Cedula ,Nombre ,NombreEmpresa ,FechaNacimiento ,Departamento ,Salario);
	  }else if (Cedula > Arbol->Cedula) {
      InsertarEmpleados(Arbol->der,Cedula,Nombre,NombreEmpresa,FechaNacimiento,Departamento, Salario);
      }
}

Empleados *Arbol1 = NULL;
Empleados *Arbol2 = NULL;
Empleados *Arbol3 = NULL;


void CrearEm();
void Eliminar(string x , vector<string>b,vector<string>c);
void Modificar(string x);

void PreOrden(Empleados *&Arbol){
     if(Arbol!=NULL)
     {
           cout <<"{"<<Arbol->Cedula<<"}"<<" -> "<<"{"<<Arbol->Nombre<<"}"<<" -> "<<"{"<<Arbol->NombreEmpresa<<"}"<<" -> "<<"{"<<Arbol->FechaNacimiento<<"}"<<" -> "<<"{"<<Arbol->Departamento<<"}"<<" -> "<<"{"<<Arbol->Salario<<"}"<<endl;
           PreOrden(Arbol->izq);
           PreOrden(Arbol->der);
     }
}

void VisualizarEmpleados();
void BaseExtra();
void BaseArbol();
void BaseExtra2();

void Parametros();
void InsertarArchivo2(string Cedula,string NombreEmpresa,string NombreDepartamento,string Salario);

void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }
void validar(char num[]){
for (int i = 0; i < strlen(num); i++){
if(!isdigit(num[i]) ) {
system ("cls");
gotoxy(40,9);printf("I N G R E S E  U N  N U M E R O  V A L I D O ");
cout<<endl;
gotoxy(42,15);exit(1);
}
}
}
void Vacio(string letra){
if (letra==""){
      system ("cls");
      gotoxy(40,9);printf("C A M P O  V A C I O  E R R O R ");
      gotoxy(42,15);exit(1);
    }

}
int  VerificarCedula(string x,vector<string>b,vector<string>c){
int a=0;int tam=0;int d=0;int e=0;
if(b[2]=="ECOPETROL EMPRESA A" || b[2]=="CEMENTOS ARGOS EMPRESA C" || b[2]=="BAVARIA EMPRESA B" ){
for(int i=0;i<b.size();i++){
if(b[a]==" "+x){
return a;
}
a=a+9;
}
return -1;
}else{
a=0;
for(int i=0;i<b.size();i++){
if(b[a]==" "+x){
return a;
}
a=a+6;
}
}
return -1;
}
string CedulaC(long long x){
string Result;          // string which will contain the result
ostringstream convert;   // stream used for the conversion
convert << x;      // insert the textual representation of 'Number' in the characters in the stream
return  Result = convert.str(); // set 'Result' to the contents of the stream

}
void MesD(string mes , int dia,int anio){ // verifica si los datos ingresados de la fecha coinciden con lo establecido por el calendario
if((mes=="ENERO" || mes=="FEBRERO" || mes=="MARZO" || mes=="ABRIL" || mes=="MAYO" || mes=="NOVIEMBRE"
||  mes=="JUNIO" || mes=="JULIO" ||  mes=="AGOSTO" || mes=="SEPTIEMBRE" || mes=="OCTUBRE" || mes=="DICIEMBRE") && anio>=1959 && anio<=2001){
if( (mes=="FEBRERO" && (dia!=0 || dia<=28))  || mes=="FEBRERO" && (anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0)) && (dia!=0 || dia<=29) ){
}
if( (mes=="ENERO" || mes=="MARZO" || mes=="MAYO" || mes=="AGOSTO" || mes=="JULIO" || mes=="OCTUBRE" || mes=="DICIEMBRE") && (dia!=0 || dia<=31) ){
}
if( (mes=="ABRIL" || mes=="JUNIO" || mes=="SEPTIEMBRE" || mes=="NOVIEMBRE") && (dia!=0 || dia<=30)){
}
}else{
	 system ("cls");
            gotoxy(40,9);printf("INGRESE FECHA DE NACIMIENTO VALIDA");
            gotoxy(40,13);printf("ESCRIBA LA FECHA EN MAYUSCULA Y ESPACIOS COMO SE MUESTRA A CONTINUACION  : 21 DICIEMBRE 1996");
            cout<<endl;
            gotoxy(42,15);exit(1);

}
}
void Fecha(string fecha){ // recibe la informacion de la fecha la divide en un en dos enteros en un string para luego validarlas
string dato[3];int dia,anio,contador=0;
string a;
for(int i=0;i<fecha.size();i++){
	if(fecha[i]!=' '){
    a=a+fecha[i];
	}else{
	dato[contador]=a;
	contador++;
	a.clear();
	}
}
dato[2]=a;
char* cadena1;char *cadena2;
cadena1 = (char *)a.c_str();
cadena2 = (char *)dato[0].c_str();
validar(cadena1);
validar(cadena2);
anio = atoi(a.c_str());
dia =  atoi(dato[0].c_str());
MesD(dato[1],dia,anio);
}
string Entero(int x){
      // number to be converted to a string

string Result;          // string which will contain the result

ostringstream convert;   // stream used for the conversion

convert << x;      // insert the textual representation of 'Number' in the characters in the stream

Result = convert.str(); // set 'Result' to the contents of the stream
}

void Menu();
void Vista(){
    gotoxy(50,4);printf("\t\t\t________________________________________________________\n");
    gotoxy(56,6);printf("\t\t\t    S I S T E M A  N O M I N A  V2.0               \n");
    gotoxy(50,8);printf("\t\t\t_______________________________________________________\n");
}

int main() {
fflush(stdin);cin.clear();
BaseExtra();
BaseExtra2();
BaseArbol();
Parametros();
//Vista();
//Menu();
getch();
}

void Menu(){
system("cls");fflush(stdin);cin.clear();int i=80;char Op[10];string op;int y=8;
Vista();
gotoxy(i,y+5);cout<<" 1  -> REGISTRAR NUEVO EMPLEADO";
gotoxy(i,y+7);cout<<" 2  -> MODIFICAR REGISTRO DEL EMPLEADO";
gotoxy(i,y+9);cout<<" 3  -> ELIMINAR REGISTRO DEL EMPLEADO";
gotoxy(i+1,y+11);cout<<"4  -> REGISTRAR LA NOMINA DEL EMPLEADO";
gotoxy(i,y+13);cout<<" 5  -> VER REPORTE #1";
gotoxy(i,y+15);cout<<" 6  -> VER REPORTE #2";
gotoxy(i,y+17);cout<<" 7  -> VER REPORTE #3";
gotoxy(i,y+19);cout<<" 8  -> SALIR";
gotoxy(i+5,y+21);cout<<"Elija una opcion...: ";cin>>Op;op=Op;
if(op=="1"){
fflush(stdin);cin.clear();
system("cls");
    system("color 0");
    CrearEm();
    gotoxy(58,22);cout<<"::: R E G I S T R O  A G R E G A D O   C O N   E X I T O :::";
	getch();
//	Menu();
}if(op=="2"){
system("cls");
cout<<"INGGRESE UNA CEDULA";cin>>Op;
Modificar(Op);
fflush(stdin);cin.clear();
system("cls");
}
if(op=="3"){
    system("color 0");
     system("cls");
     cout<<"INGGRESE UNA CEDULA";cin>>Op;
     Modificar(Op);
    gotoxy(54,22);cout<<"::: R E G I S T R O   M O D I F I C A D O    C O N   E X I T O :::";
	getch();
}if(op=="4"){
fflush(stdin);cin.clear();
	system("cls");
    system("color 0");
     cout<<"INGGRESE UNA CEDULA";cin>>Op;
     Eliminar(Op);
	 gotoxy(58,22);cout<<"::: R E G I S T R O   E L I M I N A D O    C O N   E X I T O :::";
	getch();
}if(op=="5"){
fflush(stdin);cin.clear();
	system("cls");
    system("color 0");
    gotoxy(58,22);cout<<"::: O P E R A C I O N    E X I T O S A  :::";
	getch();
}if(op=="6"){
fflush(stdin);cin.clear();
	system("cls");
    system("color 0");
    gotoxy(58,22);cout<<"::: O P E R A C I O N    E X I T O S A  :::";
	getch();
}if(op=="7"){
fflush(stdin);cin.clear();
	system("cls");
    system("color 0");
    gotoxy(58,22);cout<<"::: O P E R A C I O N    E X I T O S A  :::";
	getch();
}if(op=="9"){
fflush(stdin);cin.clear();
	system("cls");
    system("color 0");
    gotoxy(58,22);cout<<"::: O P E R A C I O N    E X I T O S A  :::";
	getch();
	Menu();
}
}
////////////////////BASE DE DATOS
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
system("cls");
Archivo.open("Empleado.txt",ios::in);string letra;
while(!Archivo.eof()){
getline(Archivo,letra);
dato2.push_back(letra);
}
Archivo.close();
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
Archivo.close();
Archivo.open("Parametros.txt",ios::in);string letra;
while(!Archivo.eof()){
getline(Archivo,letra);
fflush(stdin);datob.push_back(letra);
}
Archivo.close();
}
}
void BaseArbol(){             /// ALMACENA LOS DATOS DEL FICHERO EMPLEADO EN LOS 3 ARBOLES CORRESPONDIENTES
fflush( stdin );
if(dato1.size()!=0){
int tam=dato1.size()/6;
fflush( stdin );int a=0,b=1,c=2,d=3,e=4,f=5,g=1,h=1,j=1;
for(int i=0;i<tam;i++){
fflush( stdin );string m = dato1[g];
g=g+6;
if(m==" ECOPETROL EMPRESA A"){
InsertarEmpleados(*&Arbol1,atoll(dato1[a].c_str()),dato1[b],dato1[c],dato1[d],dato1[e],atoll(dato1[f].c_str()));
}
a=a+6;b=b+6;c=c+6;d=d+6;e=e+6;f=f+6;
}
fflush( stdin );a=0,b=1,c=2,d=3,e=4,f=5;
for(int i=0;i<tam;i++){
fflush( stdin );string m = dato1[h];
h=h+6;
if(m==" BAVARIA EMPRESA B"){
InsertarEmpleados(*&Arbol2,atoll(dato1[a].c_str()),dato1[b],dato1[c],dato1[d],dato1[e],atoll(dato1[f].c_str()));
}
a=a+6;b=b+6;c=c+6;d=d+6;e=e+6;f=f+6;
}
a=0,b=1,c=2,d=3,e=4,f=5;j=1;
for(int i=0;i<tam;i++){
fflush( stdin );string m = dato1[j];
j=j+6;
if(m==" CEMENTOS ARGOS EMPRESA C"){
InsertarEmpleados(*&Arbol3,atoll(dato1[a].c_str()),dato1[b],dato1[c],dato1[d],dato1[e],atoll(dato1[f].c_str()));
}
a=a+6;b=b+6;c=c+6;d=d+6;e=e+6;f=f+6;
}
/*cout<<endl<<"ARBOL #1 ECOPETROL EMPRESA A"<<endl;
PreOrden(*&Arbol1);
cout<<endl<<"ARBOL #2 BAVARIA EMPRESA B"<<endl;
PreOrden(*&Arbol2);
cout<<endl<<"ARBOL #3 CEMENTOS ARGOS EMPRESA C"<<endl;
PreOrden(*&Arbol3);*/
}
}
//////////////////
int arbol=0;string Departamento;string NombreEmpresa;
void Empresa1(){     //VISUALIZA EL MENU DE LAS DIFERENTES EMPRESAS
system("cls");
fflush( stdin );cin.clear(); char Opcion[1]; int a=0 ;
gotoxy(27,8); cout<<" SELECCIONE  LA  EMPRESA  QUE  VA  A  AFILIAR  AL  EMPLEADO ";
gotoxy(42,10); cout<<"1. EMPRESA A (Ecopetrol)";
gotoxy(42,11); cout<<"2. EMPRESA B (Bavaria)";
gotoxy(42,13);cout<<"3. EMPRESA C (Cementos Argos)";
gotoxy(35,15);cout<<"Seleccione La Empresa Deacuerdo Al Numero -> ";fflush( stdin );cin>>Opcion;validar(Opcion);a=atoi(Opcion);
if(a==0 || a>=4){
system ("cls");
gotoxy(40,9);printf("I N G R E S O  N U M E R O  V A L I D O");getch();
gotoxy(42,15);exit(1);
}else{
if(a==1){
fflush( stdin );NombreEmpresa="ECOPETROL EMPRESA A";
}if(a==2){
fflush( stdin );NombreEmpresa="BAVARIA EMPRESA B";
}if(a==3){
fflush( stdin );NombreEmpresa="CEMENTOS ARGOS EMPRESA C";
}
}
Auxiliar[1]=NombreEmpresa;
arbol=a;
}
void Departamento1(){ //VISUALIZA EL MENU DE LAS DIFERENTES DEPARTAMENTOS
system("cls");
fflush( stdin );cin.clear();char Opcion[1];int a;
gotoxy(27,3); cout<<" SELECCIONE  EL DEPARTAMENTO QUE VA A TRABAJAR EL EMPLEADO ";
gotoxy(42,7); cout<<"1. SISTEMA";
gotoxy(42,9); cout<<"2. NOMINA";
gotoxy(42,11);cout<<"3. GESTION HUMANA";
gotoxy(42,13);cout<<"4. PRODUCCION";
gotoxy(42,15);cout<<"5. CONTABILIDAD";
gotoxy(35,17);cout<<"Seleccione EL Departamento Deacuerdo Al Numero -> ";fflush( stdin );cin>>Opcion;validar(Opcion);a=atoi(Opcion);
if(a==0 || a>=6){
system ("cls");
gotoxy(40,9);printf("I N G R E S O  N U M E R O  V A L I D O");getch();
gotoxy(42,15);exit(1);
}else{
if(a==1){
fflush( stdin );Departamento="SISTEMA";
}if(a==2){
fflush( stdin );Departamento="NOMINA";
}if(a==3){
fflush( stdin );Departamento="GESTION HUMANA";
}if(a==4){
fflush( stdin );Departamento="PRODUCCION";
}if(a==5){
fflush( stdin );Departamento="CONTABILIDAD";
}
Auxiliar[4]=Departamento;
}
getch();
}
void CrearEm(){       //INGRESA UN NUEVO USUARIO EN EL SISTEMA , EN LOS VECTORES , EN LOS ARBOLES , EN EL FICHERO
Empresa1();
Departamento1();
system("cls");
fflush( stdin );char Numero[256] ; long long Cedula ;string Nombre ;string FechaNacimiento ; long x;string y;long long Salario;
gotoxy(35,3); cout<<" I N G R E S E  L O S  D A T O S  D E L  N U E V O  E M P L E A D O";
gotoxy(42,7); cout<<"INGRESE LA CEDULA DEL NUEVO EMPLEADO : ";cin>>Numero;validar(Numero);y=Numero;string numero=Numero;Cedula=atoll(y.c_str());//validar(Codigo);Cedula = Convertir_letras(Cedula1);//Codifgetline(cin,Cedula1);//cin>>Cedula;cin.clear();//;Cedula1 = Codigo;//validar(Codigo);Cedula1 = Codigo;Verificar(Cedula1);
if(VerificarCedula(y)!=-1){
system("cls");
gotoxy(50,12);printf("I N G R E S E  U N A  C E D U L A  N O  R E P E T I D A");
getch();exit(1);
}
gotoxy(42,9); cout<<"INGRESE EL NOMBRE DEL NUEVO EMPLEADO : ";fflush( stdin );getline(cin,Nombre);Vacio(Nombre);
gotoxy(42,11);cout<<"INGRESE LA FECHA DE NACIMEINTO DEL NUEVO EMPLEADO : ";fflush( stdin );getline(cin,FechaNacimiento);Vacio(FechaNacimiento);Fecha(FechaNacimiento);
gotoxy(42,13);cout<<"INGRESE EL SALARIO DEL NUEVO EMPLEADO : ";fflush( stdin );cin>>Numero;validar(Numero);y=Numero;Salario=atoll(y.c_str());
ofstream Archivo;
Archivo.open("Empleado.txt",ios::app);
Archivo<<numero<<" * "<<NombreEmpresa<<" * "<<Nombre<<" * "<<FechaNacimiento<<" * "<<Departamento<<" * "<<Salario<<" * "<<endl;
Archivo.close();
	system("cls");
    system("color 0");
    gotoxy(58,22);cout<<":::D A T O S   G U A R D A D O S  CON  EXITO:::";
	getch();
BaseExtra();
BaseArbol();
}
/////////////////////////////////
void Eliminar(string x , vector<string>b,vector<string>c){ ///funcion que elimina la informacion completa del trabajador
if(VerificarCedula(x)!=-1){
int Posicion = VerificarCedula1(x,b);
fflush( stdin );Auxiliar.assign(b.begin()+Posicion,b.begin()+(Posicion+b.size()));
fflush( stdin );b.erase(b.begin()+Posicion,(b.begin()+(Posicion+b.size())));
if(Posicion==0){
c.erase(c.begin()+Posicion);
}else
{
c.erase(c.begin()+(Posicion/b.size()));
}
ofstream Archivo;
Archivo.open("Empleado.txt",ios::out);
for(int i=0;i<c.size();i++){
Archivo<<endl<<c[i];
}
getch();
Archivo.close();
system("cls");
}else{
system("cls");
gotoxy(50,12);printf("LA CEDULA NO SE ENCUENTRA EN EL SISTEMA");
getch();exit(1);
}
}nnn
void Modificar(string x){///funcion que modifica  la informacion del trabajador
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
///////////////////////////////////////////////
void VisualizarEmpleados(){
//cout<<dato1.size();
if(dato1.size()!=0){
fflush( stdin );
gotoxy(1,2);cout<<"CEDULA (CODIGO)";
gotoxy(28,2);cout<<"NOMBRE DE LA EMPRESA";
gotoxy(60,2);cout<<"NOMBRE COMPLETO";
gotoxy(99,2);cout<<"FECHA DE NACIMIENTO";
gotoxy(127,2);cout<<"DEPARTAMENTO";
gotoxy(154,2);cout<<"SALARIO BASE";
int y=4;int a=0,b=0,c=2,d=3,e=4,f=5;
for(int p=0;p<dato1.size();p++){
if(a<dato1.size()){
gotoxy(1,y);cout<<dato1[a];
gotoxy(28,y);cout<<dato1[b];
gotoxy(59,y);cout<<dato1[c];
gotoxy(99,y);cout<<dato1[d];
gotoxy(127,y);cout<<dato1[e];
gotoxy(154,y);cout<<"$ "<<dato1[f];
y++;a=a+6,b=b+6,c=c+6,d=d+6,e=e+6,f=f+6;
}
}
}
else{
system ("cls");
gotoxy(40,9);printf("NO HAY DATOS QUE PUEDAN BORRADOS O MODIFICADOS");
cout<<endl;getch();
gotoxy(42,15);//Menu();
}
}
void Parametros(){
fflush( stdin );cin.clear();
char NombreDeEmpresa[10];int a,arbol=0;string Cedula1;long long Cedula;char Codigo[500];
string NombreEmpresa,Departamento,Salario;
if(dato1.size()!=0){
fflush( stdin );cin.clear();char Opcion[10];int a;
VisualizarEmpleados();
cout<<endl<<endl<<endl<<"=============================================================================================================================================================================================";
cout<<endl<<endl<<endl<<" Digite La  Cedula Correspondiente del Empleado :";cin>>Codigo;validar(Codigo);Cedula1=Codigo;Cedula=atoll(Cedula1.c_str());
if(VerificarCedula(Cedula1)==-1){
system("cls");
gotoxy(40,9);printf("I N G R E S E  U N A  C E D U L A  R E G I S T R A D A");
            cout<<endl;getch();
            gotoxy(42,15);exit(1);
}
system("cls");
int posicion = VerificarCedula(Cedula1);
Cedula1=dato1[posicion];
NombreEmpresa=dato1[(posicion+1)];
Departamento=dato1[(posicion+4)];
Salario=dato1[(posicion+5)];
}
else{
system ("cls");
            gotoxy(40,9);cout<<"NO HAY DATOS REGISTRADOS EN EL SISTEMAS";
            cout<<endl;
            gotoxy(42,15);exit(1);
}
InsertarArchivo2(Cedula1,NombreEmpresa,Departamento,Salario);
}

void InsertarArchivo2(string Cedula,string NombreEmpresa,string NombreDepartamento,string Salario){
fflush( stdin );
int  a,b,c,d,e;
cin.ignore();int P = 0;string x;string y;string valor;string cod;int Valor;
P = VerificarCedula1(Cedula);
fstream Archivo;system("cls");
Cedula = Cedula.substr(1);NombreEmpresa = NombreEmpresa.substr(1);
NombreDepartamento = NombreDepartamento.substr(1);Salario = Salario.substr(1);
Archivo.open("Parametros.txt",ios::app);
if(VerificarCedula1(Cedula)==-1){
long long Sal = (atoll(Cedula.c_str())*26)/(365);
Archivo<<Cedula<<" * "<<NombreEmpresa<<" * "<<NombreDepartamento<<" * "<<Sal<<" * "<<"."<<" * "<<"."<<" * "<<"0"<<" * "<<"0"<<" * "<<"0"<<" * "<<endl;
Archivo.close();
}else{
ofstream Archivo;fflush( stdin );
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
datoa[P+4]=cod+datoa[P+4];
a=atoi(datoa[P+6].c_str());
c=atoi(datoa[P+7].c_str());
a=a+Valor;
int Total = atoi(datoa[P+8].c_str());
Total = (Total+c)-(a);
datoa[6]=Entero(a);
Archivo<<datoa[P+0]<<" * "<<datoa[P+1]<<" * "<<datoa[P+2]<<" * "<<datoa[P+3]<<" * "<<datoa[P+4]<<" * "<<datoa[P+5]<<" * "<<a<<" * "<<datoa[P+7]<<" * "<<Total<<endl;
//cout<<endl<<datoa[P+0]<<" * "<<datoa[P+1]<<" * "<<datoa[P+2]<<" * "<<datoa[P+3]<<" * "<<datoa[P+4]<<" * "<<datoa[P+5]<<" * "<<a<<" * "<<datoa[P+7]<<" * "<<Total<<endl;
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
datoa[4]=cod+datoa[4];
a=atoi(datoa[7].c_str());
c=atoi(datoa[6].c_str());
a=a+Valor;
int Total = atoi(datoa[8].c_str());
Total = (Total+a)-(c);
Archivo<<datoa[P+0]<<" * "<<datoa[P+1]<<" * "<<datoa[P+2]<<" * "<<datoa[P+3]<<" * "<<datoa[P+4]<<" * "<<datoa[P+5]<<" * "<<datoa[P+6]<<" * "<<a<<" * "<<Total<<endl;
//cout<<Base[P+0]<<" * "<<Base[P+1]<<" * "<<Base[P+2]<<" * "<<Base[P+3]<<" * "<<Base[P+4]<<" * "<<Base[P+5]<<" * "<<a<<" * "<<Base[P+7]<<" * "<<Total<<endl;    
}else{
system("cls");
exit(-1);
}
Archivo.close();
}        
}
