#include <iostream>

class MAerolinea{
	private:
		Estructuras Es;
		ManejoArchivos man;
    public:
    	MAerolinea(Estructuras E, Usuario u, ManejoArchivos m){
    		Es=E;
    		man=m;
    		char dec; //decision
 			do{
 				system("cls");
 				cout<<"BIENVENIDO AL GESTOR DEL SISTEMA DE VIAJES"<<endl;
 				UsAerolinea usaero=*(Es.AsignarUsAerolinea(u.id));
 				cout<<"Ha ingresado Usuario de Aerolinea: "<< usaero.nombre<<" "<<usaero.apellidos<<endl;
 				cout<<"con indentificacion: "<<usaero.id<<endl;
 				cout<<endl;
		     	cout<<"A. Registrar vuelos planeados"<<endl; 
		     	cout<<"B. Generar Listas  "<<endl; 
		     	cout<<"C. Registrar Aerolinea"<<endl; 
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
		        			string codigo, origen, destino, dia, horaInicio, horaFin;
		              		cout<<"Digite codigo"<<endl;
			    			cin>>id;
			    			cout<<"Digite origen"<<endl;
			    			cin>>ori;
			    			cout<<"Digite destino"<< endl;
			    			cin>>dest;
			    			cout<<"Digite dia"<<endl;
			    			cin>>dia;
			    			cout<<"Digite horainicio"<<endl;
			    			cin>>horain;
			    			cout<<"Digite horafin"<< endl;
			    			cin>>horafin;
			    			VueloPlaneado vueloplan;
							vueloplan.codigo =id;
							vueloplan.origen= ori;
							vueloplan.destino= dest;
							vueloplan.dia= dia;
							vueloplan.horaInicio=horain;
							vueloplan.horaFin= horafin;
							//registrarVueloPlaneado(vueloplan);
							
							
		            	break;
		             }  
		             case 'B':{
		                break;
		             }   
		              case 'C':{
		              		cout<<" Registro de aerolinea"<<endl;
		              		string id,nom;
		              		int cuenta, avionesdisp;
		              		cout<<"Digite identificacion"<<endl;
			    			cin>>id;
			    			cout<<"Digite nombre"<<endl;
			    			cin>>nom;
			    			cout<<"Digite Cuenta de banco"<< endl;
			    			cin>>cuenta;
			    			Aerolinea aero;
							aero.id =id;
							aero.nombre= nom;
							aero.cta_banco= cuenta;
							aero.avionesdisp= 0;
							registrarAerolinea(aero);
		                break;
		             }       
		             case 'D':{
		                break;
		             }       
		 		}
			}
		 	while (dec!= 'D');
		}
		void registrarAerolinea(Aerolinea aero);
	//	void consultarEquipos();
	//	void ConsultarJugadores();
		//Estructuras* retornarObjeto();
};
	void MAerolinea::registrarAerolinea(Aerolinea aero){
		man.registrarAerolinea(aero);
	}
	
/*	Estructuras* MCliente::retornarObjeto(){
		Estructuras* est= new Estructuras;
		*est=Es;
		return est;
	}*/
