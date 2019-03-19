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

Empleados *Arbol1 = NULL;
Empleados *Arbol2 = NULL;
Empleados *Arbol3 = NULL;


Empleados *CrearEmpleados(Empleados *&Arbol ,long long Cedula ,string Nombre ,string NombreEmpresa , string FechaNacimiento , string Departamento , long Salario){
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
void InsertarEmpleados(Empleados *&Arbol,long long Cedula ,string Nombre ,string NombreEmpresa , string FechaNacimiento , string Departamento , long Salario){
 if   (Arbol == NULL){
      Arbol = CrearEmpleados(*&Arbol,Cedula ,Nombre ,NombreEmpresa ,FechaNacimiento ,Departamento ,Salario);
      }else if (Cedula < Arbol->Cedula) {
      InsertarEmpleados(Arbol->izq,Cedula ,Nombre ,NombreEmpresa ,FechaNacimiento ,Departamento ,Salario);
	  }else if (Cedula > Arbol->Cedula) {
      InsertarEmpleados(Arbol->der,Cedula,Nombre,NombreEmpresa,FechaNacimiento,Departamento, Salario);
      }
}

void CrearEm();
void PreOrden(Empleados *&Arbol){
     if(Arbol!=NULL)
     {
           cout <<"{"<<Arbol->Cedula<<"}"<<" -> "<<"{"<<Arbol->Nombre<<"}"<<" -> "<<"{"<<Arbol->NombreEmpresa<<"}"<<" -> "<<"{"<<Arbol->FechaNacimiento<<"}"<<" -> "<<"{"<<Arbol->Departamento<<"}"<<" -> "<<"{"<<Arbol->Salario<<"}"<<endl;
           PreOrden(Arbol->izq);
           PreOrden(Arbol->der);
     }
}
void Eliminar(string x , vector<string>b,vector<string>c);
void Modificar(string x , vector<string>b,vector<string>c);

void VisualizarEmpleados();
void BaseExtra();
void BaseArbol();
void BaseExtra2();

void Parametros();
void InsertarArchivo2(string Cedula,string NombreEmpresa,string NombreDepartamento,string Salario);





