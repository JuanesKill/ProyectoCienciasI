#include <iostream>

class MCliente{
	private:
		Estructuras Es;
    public:
    	MCliente(Estructuras E, Usuario u){
    		Es=E;
    		char dec; //decision
 			do{
 				system("cls");
 				cout<<"BIENVENIDO AL GESTOR DEL SISTEMA DE VIAJES"<<endl;
 				Cliente cliente=*(Es.AsignarCliente(u.id));
 				cout<<"Ha ingresado cliente: "<< cliente.nombre<<" "<<cliente.apellidos<<endl;
 				cout<<"con indentificacion: "<<cliente.id<<endl;
 				cout<<endl;
		     	cout<<"A. Reservar"<<endl; //primero pedir origen destino cuantos pasajeros fecha de salida
		     	cout<<"B. Consultar Reservas"<<endl;
		     	cout<<"C. Buscar itinerarios"<<endl;
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
		        	//	reservar();
		            	break;
		             }  
		             case 'B':{
		             //	consultarReservas();
		                break;
		             }   
		              case 'C':{
		              	consultarItinerario();
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
	//	void reservar();
		void consultarReserva();
		void consultarItinerario();
		void menuOpcion();
	Estructuras* retornarObjeto();
};
	void MCliente::consultarReserva(){
		
		menuOpcion();
	}
	
	void MCliente::consultarItinerario(){
		
		menuOpcion();
	}
	/*void MCliente::reservar(){
		string origen,destino;
		int numpasajeros;
		system("cls");
		cout<<"Bienvenido a reservas"<<endl;
		cout<<"Digite su origen "<< endl;
		cin>>origen;
		cout<<"Digite su destino"<<endl;
		cin>>destino;
		
		// buscar vuelos directos y tambien puede pedir vuelos con escalas despues
		// puede ordernar porr precio duracion o horario de salida
		cout<<"Digite A si desea ver itinerarios con escalas"<<endl;
		do{
			do {
		   		dec = toupper(getch ()); //este do con este while es para que al oprimir  la lerta de una vez ejecute sin el enter como un evento
			}while (!isalpha (dec)); // para que si escribe numero no deje
		}while (dec<'A'); //este while que encierra el segundo do es para que el programa funcione solo cuando oprima de a a la d
		switch (dec){
			case 'A':{
				
				break;
			}        
		}
		menuOpcion();	
	}*/
	
	void MCliente::menuOpcion(){
		char dec;
		cout<<"A. Volver a menu"<<endl;
		do{
			do {
		   		dec = toupper(getch ()); //este do con este while es para que al oprimir  la lerta de una vez ejecute sin el enter como un evento
			}while (!isalpha (dec)); // para que si escribe numero no deje
		}while (dec<'A'); //este while que encierra el segundo do es para que el programa funcione solo cuando oprima de a a la d
		switch (dec){
			case 'A':{
				
				break;
			}        
		}
	}
	Estructuras* MCliente::retornarObjeto(){
		Estructuras* est= new Estructuras;
		*est=Es;
		return est;
	}
