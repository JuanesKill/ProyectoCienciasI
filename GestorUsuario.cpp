#include <iostream>
#include "ManejoArchivos.cpp"
#include "MCliente.cpp"
#include "MAerolinea.cpp"

class GestorUsuario{
	private:
		ManejoArchivos man;
		Estructuras Es;
		string usuario;
		string clave;
		string id,nom, ape, sex, ed;
		Usuario us;
    	Cliente cliente;
    	UsAerolinea usaero;
		
    public:
    	void verificarUsuario(string usuario, string clave);
    	void registrarUsuario(Usuario us);
    	void registrarCliente(Cliente cliente);
    	void registrarUsAerolinea(UsAerolinea usaero);
    	Estructuras* retornarObjeto();
    	GestorUsuario(Estructuras Est){
    		Es=Est;
    		system("cls");
    		cout<<"BIENVENIDO AL LOGIN DEL SISTEMA DE VIAJES "<<endl;
    		cout<<"Para registrarse como cliente digite 1"<<endl;
    		cout<<"Para registrarse como usuario de aerolinea digite 2"<<endl;
    		cout<<"Para ingresar al sistema digite 3"<<endl;
    		int op;
    		cin>>op;
    		switch(op){
    			case 1:
    				cout<<"Digite en orden identificacion, nombre, apellidos, sexo, edad y clave"<<endl;
    				cin>>id;
    				cin>>nom;
    				cin>>ape;
    				cin>>sex;
    				cin>>ed;
    				cin>>clave;
					cliente.id =id;
					cliente.nombre= nom;
					cliente.apellidos= ape;
					cliente.sexo= sex;
					cliente.edad= ed;
					us.id=id;
					us.tipoUsuario="cliente";
					us.clave=clave;
					registrarUsuario(us);
					
    				break;
    			case 2:

    				cout<<"Digite en orden identificacion, nombre, apellidos, sexo, edad y clave"<<endl;
    				cin>>id;
    				cin>>nom;
    				cin>>ape;
    				cin>>sex;
    				cin>>ed;
    				cin>>clave;
					usaero.id =id;
					usaero.nombre= nom;
					usaero.apellidos= ape;
					usaero.sexo= sex;
					usaero.edad= ed;
					us.id=id;
					us.tipoUsuario="usaerolinea";
					us.clave=clave;
					registrarUsuario(us);
					man.registrarUsAerolinea(usaero);
    				break;
    				
					
    			case 3:
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
	void GestorUsuario::registrarUsuario(Usuario us){
		man.registrarUsuario(us);
	}
	
	void GestorUsuario::registrarCliente(Cliente cliente){
		man.registrarCliente(cliente);
	}
	
	void GestorUsuario::registrarUsAerolinea(UsAerolinea usaero){
		man.registrarUsAerolinea(usaero);
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
