#include <iostream>
#include "MCliente.cpp"
//#include "UsAerolinea.cpp"

class GestorUsuario{
	private:
		Estructuras Es;
		string usuario;
		string clave;
		
    public:
    	void verificarUsuario(string usuario, string clave);
    	void registrarUsuario();
    	Estructuras* retornarObjeto();
    	GestorUsuario(Estructuras Est){
    		Es=Est;
    		system("cls");
    		cout<<"BIENVENIDO AL LOGIN DEL SISTEMA DE VIAJES "<<endl;
    		cout<<"Para registrarse digite 1"<<endl;
    		cout<<"Para ingresar al sistema digite 2"<<endl;
    		int op;
    		cin>>op;
    		switch(op){
    			case 1:
    				
    				break;
    			case 2:
    				cout<<"Porfavor digite el ID de su usuario: "<<endl;
     				cin>>usuario;
     				cout<<"porfavor Ingrese la Contraseña"<<endl;
     				cin>>clave;
     				verificarUsuario(usuario, clave);
    				break;
    			default:
    				cout<<"opcion erronea"<<endl;
    				break;
			}
		}

};
	void GestorUsuario::registrarUsuario(){
		
	}
	void GestorUsuario::verificarUsuario(string usuario, string clave){
		Usuario *us= Es.AsignarUsuario(usuario);
		if(us==NULL){
			char dec;
			cout<<"El usuario no Existe"<<endl;
			cout<<endl;
			cout<<"A. Volver a intentar"<<endl;
			cout<<"B. Menu Principal"<<endl;
			do{
     			do {
            		dec = toupper(getch ()); //este do con este while es para que al oprimir  la lerta de una vez ejecute sin el enter como un evento
     			}
     			while (!isalpha (dec)); // para que si escribe numero no deje
     		}    
      		while (dec<'A' || dec> 'B'); //este while que encierra el segundo do es para que el programa funcione solo cuando oprima de a a la d
			switch (dec){
        		case 'A':{
        		//	GestorUsuario(Es);
            		break;
             	}  
             	case 'B':{
                break;
             	}       
 			}
		}
		else{
			Usuario u;
			u= *us;
			if(us->clave==clave){
				if(us->tipoUsuario=="usaerolinea"){
				//	UsAerolinea usaero= UsAerolinea(Es, u);
				//	Es=*(usaero.retornarObjeto());
				}
				else{
					if(us->tipoUsuario=="cliente"){	
						MCliente cliente= MCliente(Es, u);
						//Es=*(cliente.retornarObjeto());
					}
				}
			}
			else{
				cout<<"La Clave del usuaio: "<<us->id<<" esta incorreca"<<endl;
				cout<<endl;
				char dec;
				cout<<"A. Volver a intentar"<<endl;
				cout<<"B. Menu Principal"<<endl;
				do{
		     		do {
		           		dec = toupper(getch ()); //este do con este while es para que al oprimir  la lerta de una vez ejecute sin el enter como un evento
		     		}
		     		while (!isalpha (dec)); // para que si escribe numero no deje
		     	}    
		      	while (dec<'A' || dec> 'B'); //este while que encierra el segundo do es para que el programa funcione solo cuando oprima de a a la d
				switch (dec){
		        	case 'A':{
		        //		GestorUsuario();
		        		break;
		           	}  
		           	case 'B':{
		              break;
		           	}       
		 		}
			}
		}
	}
	Estructuras* GestorUsuario::retornarObjeto(){
		Estructuras* est= new Estructuras;
		*est=Es;
		return est;
	}
	
