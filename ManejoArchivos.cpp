#define MAX_ARGS 90
#define MAX_CADENA 100

using namespace std;

class ManejoArchivos{
	private:
		char dato1[30];
     	char dato2[30];
     	char dato3[30];
     	char dato4[30];
     	char dato5[30];
     	char dato6[30];
    	char dato7[30];
     	char dato8[30];
     	char dato9[30];
     	char dato10[30];
     	int x; //contador
     	int j;
     	int i;
     	int posicionAux;
     	Estructuras Es;
    public:
    	
    	ManejoArchivos(Estructuras Est){
    		Es=Est;
		}
		ManejoArchivos(){
		}
		void cargarUsuario();
    	void cargarCliente();
    	void cargarUsAerolinea();
    	void cargarVuelosPlaneados();
    	void cargarVuelosEspecificos();
    	void cargarAerolinea();
    	void cargarAviones();
		void registrarUsuario(Usuario us);
		void registrarCliente(Cliente cli);
		void registrarUsAerolinea(UsAerolinea usaero);
		void registrarAerolinea(Aerolinea aero);
    	void cargarPasajeros();
    	Estructuras* retornarObjeto();
    	string AsignarGrupo();
};

	void ManejoArchivos::cargarAviones(){
			ifstream salida;
			salida.open ("Aviones.txt", ios::in); 
	     	if (salida.fail()){
	      		cout<<"error al abrir el archivo :( "<<endl;
	      		getch();         
	     	}
	     	else{
	         	salida>>dato1;
	         while (!salida.eof()) {
	         	salida>>dato2;
	            salida>>dato3; 
	            salida>>dato4;
				string id(dato1);
				string idaero(dato2);
				string tip(dato3);
				string capacidad(dato4);
				int capa = atoi(capacidad.c_str());
				Avion avion;
				avion.id=id;
				avion.tipoavion = tip;
				avion.capacidad= capa;
				avion.idaerolinea= idaero;
			/*	int pos=0;
				while(pos <= capa){
					Silla *silla = new Silla;
					silla->id = "A0"+1;
					silla->estado= "vacia";
					avion.sillas.insertar_pos(*silla,pos);
					pos=pos+1;
				}*/
				int j=1;
				avion.idaerolinea=Es.AsignarAerolinea(avion.idaerolinea, avion);
				//avion.sillas.obtenerDato(1);
				if(avion.idaerolinea=="na"){
				cout<<"el avion no tiene aerolinea"<<endl;
				}
				else{
					cout<<" el id de la aerolinea es "<<avion.idaerolinea << endl;
				}
            	x=x+1;
            	salida>>dato1;
         	}
	        cout<<"los aviones son "<<x<<endl;
	        salida.close (); 
	     }
	     x=0;
	     j=0;
	     getch ();
	
	}

	void ManejoArchivos::cargarUsuario(){
			ifstream salida;
			salida.open ("Usuarios.txt", ios::in); 
	     	if (salida.fail()){
	      		cout<<"error al abrir el archivo :( "<<endl;
	      		getch();         
	     	}
	     	else{
	         	salida>>dato1;
	         while (!salida.eof()) {
	         	salida>>dato2;
	            salida>>dato3; 
				string id(dato1);
				string tip(dato2);
				string cla(dato3);
				Usuario usuario;
				usuario.id=id;
				usuario.tipoUsuario = tip;
				usuario.clave= cla;
				int j=1;
				Es.insertarUsuario(usuario,j);
	            x=x+1;
	            j=j+1;
	            salida>>dato1;
	         }
	         cout<<"los Usuarios son "<<x<<endl;
	         salida.close (); 
	     }
	     x=0;
	     j=0;
	     getch ();
		}
	void ManejoArchivos::cargarCliente(){
		ifstream salida;
		salida.open ("clientes.txt", ios::in); 
     	if (salida.fail()){
      		cout<<"error al abrir el archivo :( "<<endl;
      		getch();         
     	}
     	else{
         	salida>>dato1;
         while (!salida.eof()) {
         	salida>>dato2;
            salida>>dato3;
			salida>>dato4; 
			salida>>dato5;//si dentro del else se lee el primer dato  va a repetir el ultimo libro dos veces no se por que xD
			string id(dato1);
			string nom(dato2);
			string ape(dato3);
			string sex(dato4);
			string ed(dato5);
			Cliente cliente;
			cliente.id =id;
			cliente.nombre= nom;
			cliente.apellidos= ape;
			cliente.sexo= sex;
			cliente.edad= ed;
			cliente.usuario=Es.AsignarUsuario(cliente.id);
			cout<<cliente.id<<endl;
			if(cliente.usuario==NULL){
				cout<<"el cliente no tiene usuario"<<endl;
			}
			else{
				cout<<cliente.usuario->id<<" "<<cliente.usuario->tipoUsuario<<endl;
			}
			Es.insertarCliente(cliente,j+1);
            x=x+1;
            salida>>dato1;
         }
         cout<<"los Clientes son "<<x<<endl;
         salida.close (); 
     }
     x=0;
     j=0;
     getch ();
	}
	
	void ManejoArchivos::cargarUsAerolinea(){
		ifstream salida;
		salida.open ("usAerolineas.txt", ios::in); 
     	if (salida.fail()){
      		cout<<"error al abrir el archivo :( "<<endl;
      		getch();         
     	}
     	else{
         	salida>>dato1;
         while (!salida.eof()) {
         	salida>>dato2;
            salida>>dato3;
			salida>>dato4; 
			salida>>dato5;//si dentro del else se lee el primer dato  va a repetir el ultimo libro dos veces no se por que xD
			string id(dato1);
			string nom(dato2);
			string ape(dato3);
			string sex(dato4);
			string edad(dato5);
			UsAerolinea usaerolinea;
			usaerolinea.id =id;
			usaerolinea.nombre= nom;
			usaerolinea.apellidos= ape;
			usaerolinea.sexo= sex;
			usaerolinea.edad= edad;
			usaerolinea.usuario=Es.AsignarUsuario(usaerolinea.id);
			cout<<usaerolinea.id<<endl;
			if(usaerolinea.usuario==NULL){
				cout<<"el Usuario de Aerolinea no tiene usuario"<<endl;
			}
			else{
				cout<<usaerolinea.usuario->id<<" "<<usaerolinea.usuario->tipoUsuario<<endl;
			}
			Es.insertarusAerolinea(usaerolinea,j+1);
            x=x+1;
            salida>>dato1;
         }
         cout<<"los Usuarios de aerolineas son "<<x<<endl;
         salida.close (); 
     }
     x=0;
     j=0;
     getch ();
	} 
	void ManejoArchivos::cargarAerolinea(){
			ifstream salida;
			salida.open ("Aerolinea.txt", ios::in); 
	     	if (salida.fail()){
	      		cout<<"error al abrir el archivo :( "<<endl;
	      		getch();         
	     	}
	     	else{
	         	salida>>dato1;
	         while (!salida.eof()) {
	         	salida>>dato2;
	            salida>>dato3;
	            salida>>dato4;
				string id(dato1);
				string nombre(dato2);
				string avionesdisp(dato3);
				string cuent(dato4);
				int avionesdispo = atoi(avionesdisp.c_str());
 				int cuenta = atoi(cuent.c_str());
				Aerolinea aerolinea;
				aerolinea.id=id;
				aerolinea.avionesdisp = avionesdispo;
				aerolinea.nombre= nombre;
				aerolinea.cta_banco=cuenta;
				int j=1;
				Es.insertarAerolinea(aerolinea,j);
	            x=x+1;
	            j=j+1;
	            salida>>dato1;
	         }
	         cout<<"las aerolineas son "<<x<<endl;
	         salida.close (); 
	     }
	     x=0;
	     j=0;
	     getch ();
	}
	void ManejoArchivos::cargarVuelosPlaneados(){
		ifstream salida; //para leer lo que esta en el archivo con una funcion que llame salida
		salida.open ("vuelosplaneados.txt", ios::in); //abrimos el archivo
     	if (salida.fail()){ //if por si ocurre un error
      		cout<<"error al abrir el archivo :( "<<endl;
      		getch();         
     	}
     	else{
     		int h=1;
         	salida>>dato1;//aqui leemos primero el nombre del lobro antes del white por lo siguiente:
         while (!salida.eof()) //(esto significa que recorre el archivo hasta el final)
         {
            salida>>dato2; 
			salida>>dato3;//si dentro del else se lee el primer dato  va a repetir el ultimo libro dos veces no se por que xD
			salida>>dato4;
			salida>>dato5;
			salida>>dato6;
			VueloPlaneado vueloplaneado;
			string codigo(dato1);
			string origen(dato2);
			string destino(dato3);
			string dia(dato4);
			string horainicio(dato5);
			string horafin(dato6);
			vueloplaneado.codigo= codigo;
			vueloplaneado.origen= origen;
			vueloplaneado.destino= destino;
			vueloplaneado.dia= dia;
			vueloplaneado.horaInicio= horainicio;
			vueloplaneado.horaFin= horafin;
			cout<< "codigo: "<< vueloplaneado.codigo<<endl;
 		/*	equipo.director=Es.AsignarEntrenador(equipo.pais, 1);
 			if(equipo.director==NULL){
 				cout<<"el equipo no tiene director"<<endl;
			 }
			 else{
			 	cout<<equipo.director->nombres<<" "<<equipo.director->apellidos<<endl;	
			 }*/
			 Es.insertarVueloPlaneado(vueloplaneado,h);
            x=x+1;
            h=h+1;
            salida>>dato1;
         }
         cout<<"los vuelos planeados son "<<x<<endl;
         salida.close (); //se cierra la funcion
     }
     x=0;
     j=0;
     getch (); 
	}

	void ManejoArchivos::cargarVuelosEspecificos(){
		ifstream salida; //para leer lo que esta en el archivo con una funcion que llame salida
		salida.open ("vuelosespecificos.txt", ios::in); //abrimos el archivo
     	if (salida.fail()){ //if por si ocurre un error
      		cout<<"error al abrir el archivo :( "<<endl;
      		getch();         
     	}
     	else{
     		int h=1;
         	salida>>dato1;//aqui leemos primero el nombre del lobro antes del white por lo siguiente:
         while (!salida.eof()) //(esto significa que recorre el archivo hasta el final)
         	{
         	salida>>dato2;
         	salida>>dato3;
         	salida>>dato4;
         	salida>>dato5;
         	string codigo(dato1);
  			string numSillasDispo(dato3);
  			string fecha(dato2);
 			string adutarifa(dato4);
 			string nintarifa(dato5);
  			int numSillasDisp = atoi(numSillasDispo.c_str());
 			int adtarifa = atoi(adutarifa.c_str());
 			int nitarifa = atoi(nintarifa.c_str());
 			VueloEspecifico vueloespecifico;
  			vueloespecifico.codigo= codigo;
  			vueloespecifico.numSillasDisp= numSillasDisp;
  			vueloespecifico.fecha= fecha;
 			vueloespecifico.adtarifa= adtarifa;
 			vueloespecifico.nitarifa= nitarifa;
  			cout<< "codigo: "<< vueloespecifico.codigo<<endl;
   			vueloespecifico.vueloplan=Es.AsignarvueloPlan(vueloespecifico.codigo);
            if(vueloespecifico.vueloplan==NULL){
 				cout<<"el vuelo especifico no tiene vuelo planeado"<<endl;
			 }
			 else{
			 	cout<<vueloespecifico.vueloplan->codigo<<" "<<vueloespecifico.vueloplan->destino<<" "<<vueloespecifico.vueloplan->origen<<" "<<vueloespecifico.vueloplan->dia<<" "<<vueloespecifico.vueloplan->horaInicio<<" "<<vueloespecifico.vueloplan->horaFin<<" "<<endl;	
			 }
			Es.insertarVueloEspecifico(vueloespecifico,h);
            x=x+1;
            h=h+1;
            salida>>dato1;
         }
         cout<<"los vuelos especificos son "<<x<<endl;
         salida.close (); //se cierra la funcion
     }
     x=0;
     j=0;
     getch (); 
	}
	void ManejoArchivos::registrarUsuario(Usuario us){
			ofstream entrada;
			entrada.open ("Usuarios.txt", ios::app); 
	     	if (entrada.fail()){
	      		cout<<"error al abrir el archivo :( "<<endl;
	      		getch();         
	     	}
	     	else{
	         	entrada<<"\n"<<us.id<<" ";
	         	entrada<<us.tipoUsuario<<" ";
	            entrada<<us.clave<<" "; 
	            Es.insertarUsuario(us,j+1);
	         
	         cout<<"el id de registro es "<<us.id<<endl;
	         entrada.close (); 
	     }
	     getch ();
		}
	void ManejoArchivos::registrarCliente(Cliente cli){
		ofstream entrada;
		entrada.open ("clientes.txt", ios::app); 
     	if (entrada.fail()){
      		cout<<"error al abrir el archivo :( "<<endl;
      		getch();         
     	}
     	else{
         	entrada<<"\n"<<cli.id<<" ";
         	entrada<<cli.nombre<<" ";
            entrada<<cli.apellidos<<" ";
            entrada<<cli.sexo<<" ";//si dentro del else se lee el primer dato  va a repetir el ultimo libro dos veces no se por que xD
			entrada<<cli.edad<<" "; 
			cli.usuario= Es.AsignarUsuario(cli.id);
			Es.insertarCliente(cli,j+1);        
		 
         cout<<"el id de cliente es"<<cli.id<<endl;
         entrada.close (); 
     }
     getch ();
	}
	void ManejoArchivos::registrarUsAerolinea(UsAerolinea usaero){
		ofstream entrada;
		entrada.open ("usAerolineas.txt", ios::app); 
     	if (entrada.fail()){
      		cout<<"error al abrir el archivo :( "<<endl;
      		getch();         
     	}
     	else{
         	entrada<<"\n"<<usaero.id<<" ";
         	entrada<<usaero.nombre<<" ";
            entrada<<usaero.apellidos<<" ";
			entrada<<usaero.edad<<" "; 
			entrada<<usaero.sexo<<" ";//si dentro del else se lee el primer dato  va a repetir el ultimo libro dos veces no se por que xD
         	usaero.usuario= Es.AsignarUsuario(usaero.id);
         	Es.insertarusAerolinea(usaero, j+1);
		 
         cout<<"el id del usuario de aerolinea es"<<usaero.id<<endl;
         entrada.close (); 
     }
     getch ();
	}
	void ManejoArchivos::registrarAerolinea(Aerolinea aero){
		ofstream entrada;
		entrada.open ("Aerolinea.txt", ios::app); 
     	if (entrada.fail()){
      		cout<<"error al abrir el archivo :( "<<endl;
      		getch();         
     	}
     	else{
         	entrada<<"\n"<<aero.id<<" ";
         	entrada<<aero.nombre<<" ";
            entrada<<aero.avionesdisp<<" ";
			entrada<<aero.cta_banco<<" "; 
         	Es.insertarAerolinea(aero, j+1);
		 	
         cout<<"el id de la aerolinea es"<<aero.id<<endl;
         entrada.close (); 
     }
     getch ();
	}
	
	Estructuras* ManejoArchivos::retornarObjeto(){
		Estructuras* est= new Estructuras;
		*est=Es;
		return est;
	}


	
	
