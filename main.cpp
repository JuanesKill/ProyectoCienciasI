#include <cstdlib>
#include <iostream>
#include<stdio.h>
#include<fstream> //libreria para archivos
#include<conio.h>
#include<ctype.h>
#include<string.h> //libreria para modificar el archivo
#include "Estructuras.cpp"
#include "GestorUsuario.cpp"
#include "ManejoArchivos.cpp"
#include "MCliente.cpp"
//#include "UsAerolinea.cpp"
#include "lista.h"

Estructuras Es;
int main(int argc, char** argv) {
	
	ManejoArchivos arch1= ManejoArchivos(Es);
	
//	arch1.cargarPasajeros();
	arch1.cargarUsuario();
	arch1.cargarCliente();
	arch1.cargarUsAerolinea();
	arch1.cargarVuelosPlaneados();
	arch1.cargarVuelosEspecificos();
	
	Es=*(arch1.retornarObjeto());
  	char dec; //decision
 	do{
 		system("cls");
 		cout<<"BIENVENIDO AL SISTEMA DE VIAJES "<<endl;
     	cout<<"A. Entrar como USUARIO"<<endl;
     	cout<<"B. Ingresar con USUARIO DE AEROLINEA"<<endl;
     	cout<<"C. Sobre La Aplicacion "<<endl;
     	cout<<"D. salir"<<endl;
     	do{
     		do {
            	dec = toupper(getch ()); //este do con este while es para que al oprimir  la lerta de una vez ejecute sin el enter como un evento
     		}
     		while (!isalpha (dec)); // para que si escribe numero no deje
     	}    
      	while (dec<'A' || dec> 'D'); //este while que encierra el segundo do es para que el programa funcione solo cuando oprima de a a la d
		switch (dec){
        	case 'A':{
        		GestorUsuario ges = GestorUsuario(Es);
             	Es= *(ges.retornarObjeto());
            	break;
             }  
             case 'B':{
             	//UsAerolinea usaero = UsAerolinea(Es);
             	//Es= *(usaero.retornarObjeto());
                break;
             }   
              case 'C':{
                break;
             }       
             case 'D':{
                exit(0);
                break;
             }       
 		}
	}
 	while (dec!= 'D');
    

}
