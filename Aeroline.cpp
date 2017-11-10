#include <cstdlib>
#include <iostream>
#include <string>

#ifndef AEROLINEA_H     
#define AEROLINEA_H 

using namespace std;

struct itnr{
	string titulo;
	//se agregan todos los vuelos asinados al Itinerario  
};

struct Aerolinea{
	string nombre;
	int air_disp;
	itnr completo;
	int cta_banco;
}; 

Aerolinea *Airline= new Aerolinea[50];

void mostrar_nombre(int n){
	int i=0;  
	do{
		
		cout<<Airline[i].nombre<<"\n";	
		i++;
	}while(i<n);
}

int main(int argc, char** argv){
	
	int opcion; 
	int numAirline=0;
	
	
	do
    {
        
        cout << endl;
        cout << "Escoja una opcion:" << endl;
        cout << "1.- Agregar Aerolinea" << endl;
        cout << "2.- Mostrar Aerolineas" << endl;
        cout << "3.- Salir" << endl;
 
        cin >> opcion;
 
        switch(opcion){
            case 1:
                if (numAirline < 50){ 
                    cout << "Introduce el nombre de la Aerolinea: ";
                    cin >> Airline[numAirline].nombre;
                    cout << "Introduce el numero de la cuenta bancaria: ";
                    cin >> Airline[numAirline].cta_banco;
                    numAirline++; 
                }
                else 
                    cout << "Máximo de Aerolinea (50)!" << endl;
                break;
 
            case 2:
            	mostrar_nombre(numAirline);
                break; 
 
            case 3: 
            	cout << "Fin del programa" << endl;
                break;
 
            default: 
                break;
        }
    } while (opcion != 3);
}


#endif
