#include <iostream>

class MAerolinea{
	private:
		Estructuras Es;
    public:
    	MAerolinea(Estructuras E, Usuario u){
    		Es=E;
    		char dec; //decision
 			do{
 				system("cls");
 				cout<<"BIENVENIDO AL GESTOR DEL SISTEMA DE VIAJES"<<endl;
 				UsAerolinea usaero=*(Es.AsignarUsAerolinea(u.id));
 				cout<<"Ha ingresado Usuario de Aerolinea: "<< usaero.nombre<<" "<<usaero.apellidos<<endl;
 				cout<<"con indentificacion: "<<usaero.id<<endl;
 				cout<<endl;
		     	cout<<"A. Consultar programacion partidos"<<endl;
		     	cout<<"B. Consultar lista de equipos "<<endl;
		     	cout<<"C. Modificar plantilla de su equipo"<<endl;
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
		            	break;
		             }  
		             case 'B':{
		                break;
		             }   
		              case 'C':{
		                break;
		             }       
		             case 'D':{
		                break;
		             }       
		 		}
			}
		 	while (dec!= 'D');
		}
	//	void consultarEquipos();
	//	void ConsultarJugadores();
		//Estructuras* retornarObjeto();
};
/*	Estructuras* MCliente::retornarObjeto(){
		Estructuras* est= new Estructuras;
		*est=Es;
		return est;
	}*/
