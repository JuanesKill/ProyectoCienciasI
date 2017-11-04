#include <cstdlib>
#include <iostream>
#include<stdio.h>
#include<fstream> //libreria para archivos
#include<conio.h>
#include<ctype.h>
#include<string.h> //libreria para modificar el archivo
#include "Estructuras.cpp"
#include "ManejoArchivos.cpp"
//#include "Invitado.cpp"
//#include "GestorUsuario.cpp"
#include "lista.h"

Estructuras Es;
int main(int argc, char** argv) {
	
	ManejoArchivos arch1= ManejoArchivos(Es);
	arch1.cargarAministrador();
	arch1.cargarPasajeros();
	arch1.cargarUsAerolinea();
	arch1.cargarUsCliente();
	arch1.cargarUsuario();
	arch1.cargarVuelosEspecificos();
	arch1.cargarVuelosPlaneados();
    arch1.cargarUsuario();
    Es=*(arch1.retornarObjeto());
    

}
