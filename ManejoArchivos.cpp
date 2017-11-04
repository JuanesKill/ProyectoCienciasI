#include "separador.h"

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
		void cargarUsuario();
    	void cargarAministrador();
    	void cargarUsCliente();
    	void cargarUsAerolinea();
    	void cargarVuelosEspecificos();
    	void cargarVuelosPlaneados();
    	void cargarPasajeros();
    	Estructuras* retornarObjeto();
    	string AsignarGrupo();
};
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
			salida>>dato3;//si dentro del else se lee el primer dato  va a repetir el ultimo libro dos veces no se por que xD
			salida>>dato4;
			salida>>dato5;
			salida>>dato6;
			VueloEspecifico vueloespecifico;
			string codigo(dato1);
			string origen(dato2);
			string destino(dato3);
			string precio(dato4);
			string numSillasDispo(dato5);
			string fecha(dato6);
			int numSillasDisp = atoi(numSillasDispo.c_str());
			vueloespecifico->vuelo.codigo= codigo;
			vueloespecifico->vuelo.origen= origen;
			vueloespecifico->vuelo.destino= destino;
			vueloespecifico->vuelo.precio= precio;
			vueloespecifico.numSillasDisp= numSillasDisp;
			vueloespecifico.fecha= fecha;
			cout<<vueloespecifico->vuelo.codigo<<endl;
 		/*	equipo.director=Es.AsignarEntrenador(equipo.pais, 1);
 			if(equipo.director==NULL){
 				cout<<"el equipo no tiene director"<<endl;
			 }
			 else{
			 	cout<<equipo.director->nombres<<" "<<equipo.director->apellidos<<endl;	
			 }*/
		/*	 int pos=1;
			 int i=1;
			 while(pos <= posicionAux){
			 	Jugadores* juga= new Jugadores;
			 	juga=Es.AsignarJugador(equipo.pais,pos,1);
			 	if(juga==NULL){
			 		cout<<"no hay jugadores"<<endl;
			 		pos=posicionAux+1;
				 }
				 else{
				 	Jugadores jugador;
			 		jugador= *juga;
			 		equipo.jugadores.insertar_pos(jugador,i);
			 		pos=Es.AuxPos()+1;
			 		i++;
				 }
			 }
			 if(equipo.jugadores.lista_vacia()){
			 	cout<<"el equipo no tiene jugadores"<<endl;
			 }
			 else{
			 	Jugadores jug= equipo.jugadores.obtenerDato(1);
			 	cout<<jug.nombres<<" "<<jug.apellidos<<endl;
			 	Jugadores jug2= equipo.jugadores.obtenerDato(2);
			 	cout<<jug2.nombres<<" "<<jug2.apellidos<<endl;
			 }
			 Es.InsertarPaices(equipo,h);
            x=x+1;
            h=h+1;
            salida>>dato1;
         }*/
         cout<<"los vuelos especificos son "<<x<<endl;
         salida.close (); //se cierra la funcion
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
			string precios(dato4);
			string dia(dato5);
			string horainicio(dato6);
			string horafin(dato7);
			int precio = atoi(precios.c_str());
			vueloplaneado->vuelo.codigo= codigo;
			vueloplaneado->vuelo.origen= origen;
			vueloplaneado->vuelo.destino= destino;
			vueloplaneado->vuelo.precio= precio;
			vueloplaneado.dia= dia;
			vueloplaneado.horaInicio= horainicio;
			vueloplaneado.horaFin= horafin;
			cout<<vueloplaneado->vuelo.codigo<<endl;
 		/*	equipo.director=Es.AsignarEntrenador(equipo.pais, 1);
 			if(equipo.director==NULL){
 				cout<<"el equipo no tiene director"<<endl;
			 }
			 else{
			 	cout<<equipo.director->nombres<<" "<<equipo.director->apellidos<<endl;	
			 }*/
		/*	 int pos=1;
			 int i=1;
			 while(pos <= posicionAux){
			 	Jugadores* juga= new Jugadores;
			 	juga=Es.AsignarJugador(equipo.pais,pos,1);
			 	if(juga==NULL){
			 		cout<<"no hay jugadores"<<endl;
			 		pos=posicionAux+1;
				 }
				 else{
				 	Jugadores jugador;
			 		jugador= *juga;
			 		equipo.jugadores.insertar_pos(jugador,i);
			 		pos=Es.AuxPos()+1;
			 		i++;
				 }
			 }
			 if(equipo.jugadores.lista_vacia()){
			 	cout<<"el equipo no tiene jugadores"<<endl;
			 }
			 else{
			 	Jugadores jug= equipo.jugadores.obtenerDato(1);
			 	cout<<jug.nombres<<" "<<jug.apellidos<<endl;
			 	Jugadores jug2= equipo.jugadores.obtenerDato(2);
			 	cout<<jug2.nombres<<" "<<jug2.apellidos<<endl;
			 }
			 Es.InsertarPaices(equipo,h);
            x=x+1;
            h=h+1;
            salida>>dato1;
         }*/
         cout<<"los vuelos especificos son "<<x<<endl;
         salida.close (); //se cierra la funcion
     }
     x=0;
     j=0;
     getch (); 
	}
	
