#include <iostream>
#include "lista.h"

struct Usuario {
	string id, tipoUsuario, clave;
};

struct UsAerolinea {
	string id,	nombre,apellidos, sexo, edad;
	Usuario* usuario;
};

struct Cliente {
	string id,	nombre,apellidos, sexo, edad;
	Usuario* usuario;
};

struct Pasajero {
	string nombres, apellidos, numidentificacion, fechaNacimiento, tipo;
	
};

struct Silla{
	string id,estado;
	Silla* sig;
	
};

struct Reserva{
	string idreserva, idusuario, idsilla; 
	Lista<Pasajero> pasajeros; 
};

/*struct Vuelo{
	string codigo, origen, destino, precio;
	Lista<Silla> sillas;
};*/
struct Avion{
	string id, idaerolinea, tipoavion;
	Lista<Silla> sillas;
	int capacidad;
	
};

struct VueloPlaneado { //registrar vuelos planeados en el archivo;
	string codigo, origen, destino, dia, horaInicio, horaFin;
	//Lista<Silla> sillas;
	
};

struct VueloEspecifico{ // registrar veulos especificos  en el archivos;
	string  codigo, fecha;
 	int numSillasDisp, adtarifa, nitarifa;
	VueloPlaneado* vueloplan;
	Avion* avion;
};
struct itnr{
	string titulo, id;
	Lista<VueloEspecifico> vuelos;
	//se agregan todos los vuelos asinados al Itinerario  
};
struct Aerolinea{ //Funcion registrar aerolinea desde los archivos;
	string id ,nombre;
	int avionesdisp, cta_banco;
	itnr* itnrcompleto;
	Lista<Avion> aviones;
}; 




class Estructuras{
	private:
		Lista<Usuario> usuarios;
		Lista<UsAerolinea> usAerolineas;
		Lista<Aerolinea> aerolineas;	
		Lista<Cliente> clientes;
		Lista<Pasajero> pasajeros;
		Lista<Silla> sillas ;
//		Lista<Vuelo> vuelos;
		Lista<VueloPlaneado> vuelosPlaneados;
		Lista<VueloEspecifico> vuelosEspecificos;
		int posicionAux;
    public:
    	Estructuras(){
		}
		void insertarusAerolinea(UsAerolinea, int pos);
		void insertarCliente (Cliente cliente, int pos);
		void insertarUsuario(Usuario usuario, int pos);
		//void InsertarVuelo(Vuelo vuelo, int pos);
		void InsertarPasajero(Pasajero pasajero, int pos);
		void insertarAerolinea(Aerolinea aerolinea, int pos);
		void insertarVueloPlaneado(VueloPlaneado vueloplan, int pos);
		void insertarVueloEspecifico(VueloEspecifico vueloesp, int pos);
		void EliminarVueloPlaneado(string codigo);
		void EliminarVueloEspecifico(string codigo);
		void EliminarPasajero(string nombre, string );
		void insertarAvion();
		string AsignarAerolinea(string dato, Avion avion);
		Usuario* AsignarUsuario(string dato);
		VueloPlaneado* AsignarvueloPlan(string dato);
		itnr* AsignarItinerario(string dato);
		Cliente* AsignarCliente(string dato);
		UsAerolinea* AsignarUsAerolinea(string dato);
	  /*  
	    ProgramacionF1* ObtenerProgramacion(string dato, int pos, int op);
	   ProgramacionF2* ObtenerProgramacion2(string dato, int pos, int op);
        Entrenadores* AsignarEntrenador(string dato, int op);
	      Jugadores* AsignarJugador(string dato, int pos, int op);
	    PartidosF1* obtenerPartidos(string dato, int pos);
	   PartidosF2* obtenerPartidos2(string dato, int pos);
		Estadios* ObtenerEstadio(string dato, int pos, int op);
		Equipos* ObtenerEquipo(string dato, int op, int pos);
		Grupos* ObtenerGrupo(string dato, int pos, int op);*/
	/*	int AuxPos();
		int faseDos();
		int finTorneo();*/
};
	void Estructuras::insertarUsuario(Usuario usuario, int pos){
		usuarios.insertar_pos(usuario, pos);
		cout<<"El tamaño de la lista de usuarios es: "<<usuarios.tamano_lista()<<endl;
	}
	
	void Estructuras::insertarCliente(Cliente cliente, int pos){
		clientes.insertar_pos(cliente, pos);
		cout<<"El tamaño de la lista de clientes es: "<<clientes.tamano_lista()<<endl;
	}
	void Estructuras::insertarusAerolinea(UsAerolinea usaerolinea, int pos){
		usAerolineas.insertar_pos(usaerolinea, pos);
		cout<<"El tamaño de la lista de usuarios de aerolineas es: "<<usAerolineas.tamano_lista()<<endl;
	}
	void Estructuras::insertarAerolinea(Aerolinea aerolinea, int pos){
		aerolineas.insertar_pos(aerolinea, pos);
		cout<<"El tamaño de la lista de aerolineas es: "<<aerolineas.tamano_lista()<<endl;
	}
	
	void Estructuras::insertarVueloPlaneado(VueloPlaneado vueloplan, int pos){
		vuelosPlaneados.insertar_pos(vueloplan, pos);
		cout<<"El tamaño de la lista vuelos planeados es: "<<vuelosPlaneados.tamano_lista()<<endl;
	}
	void Estructuras::insertarVueloEspecifico(VueloEspecifico vueloespe, int pos){
		vuelosEspecificos.insertar_pos(vueloespe, pos);
		cout<<"El tamaño de la lista vuelos especificos es: "<<vuelosEspecificos.tamano_lista()<<endl;
	}
	
	
	Usuario* Estructuras::AsignarUsuario(string dato){
		int i=1;
		Usuario* us= new Usuario;
		*us=usuarios.obtenerDato(i);
		while(us->id!= dato){
			if(i<usuarios.tamano_lista()){
				i++;
				*us= usuarios.obtenerDato(i);
			}
			else{
				return NULL;
			}
		}
		 return us;
	}
	
	VueloPlaneado* Estructuras::AsignarvueloPlan(string dato){
		int i=1;
		VueloPlaneado* vuelo= new VueloPlaneado;
		*vuelo=vuelosPlaneados.obtenerDato(i);
		while(vuelo->codigo!= dato){
			if(i<vuelosPlaneados.tamano_lista()){
				i++;
				*vuelo= vuelosPlaneados.obtenerDato(i);
			}
			else{
				return NULL;
			}
		}
		 return vuelo;
	}
	
	Cliente* Estructuras::AsignarCliente(string dato){
		int i=1;
		Cliente *cliente= new Cliente;
		*cliente=clientes.obtenerDato(i);
		while(cliente->id != dato){
			if(i<clientes.tamano_lista()){
				i++;
				*cliente= clientes.obtenerDato(i);
			}
			else{
				return NULL;
			}
		}
		 return cliente;
	}
	
	UsAerolinea* Estructuras::AsignarUsAerolinea(string dato){
		int i=1;
		UsAerolinea *usaero= new UsAerolinea;
		*usaero=usAerolineas.obtenerDato(i);
		while(usaero->id != dato){
			if(i<usAerolineas.tamano_lista()){
				i++;
				*usaero= usAerolineas.obtenerDato(i);
			}
			else{
				return NULL;
			}
		}
		 return usaero;
	}
	string Estructuras::AsignarAerolinea(string dato, Avion avion){
		int i=1;
		Aerolinea* aerolinea= new Aerolinea;
		*aerolinea=aerolineas.obtenerDato(i);
		while(aerolinea->id!= dato){
			if(i<aerolineas.tamano_lista()){
				i++;
				*aerolinea= aerolineas.obtenerDato(i);
			}
			else{
				return "na";
			}
		}
		 aerolinea->aviones.insertar_final(avion);
		 aerolinea->avionesdisp= aerolinea->avionesdisp+1;
		 return aerolinea->id;
	}
	
	/*itnr* Estructuras::AsignarItinerario(string dato){
		int i=1;
		itnr *itin= new itnr;
		*itin=usAerolineas.obtenerDato(i);
		while(usaero->id != dato){
			if(i<usAerolineas.tamano_lista()){
				i++;
				*usaero= usAerolineas.obtenerDato(i);
			}
			else{
				return NULL;
			}
		}
		 return usaero;
	}*/
	/*void Estructuras::InsertarJugadores(Jugadores jugador, int pos){
		listaJugadores.insertar_pos(jugador, pos);
		cout<<"El tamaño de la lista de jugadores es: "<<listaJugadores.tamano_lista()<<endl;
	}
	
	void Estructuras::InsertarPaices(Equipos eq, int pos){
		listaEquipos.insertar_pos(eq,pos);
		cout<<"El tamaño de la lista de equipos es: "<<listaEquipos.tamano_lista()<<endl;
	}
	
	void Estructuras::InsertarGrupos(Grupos gr, int pos){
		listaGrupos.insertar_pos(gr,pos);
		cout<<"El tamaño de la lista de grupos es: "<<listaGrupos.tamano_lista()<<endl;
	}
	
	void Estructuras::InsertarEstadios(Estadios es, int pos){
		listaEstadios.insertar_pos(es, pos);
		cout<<"El tamaño de la lista de estadios es: "<<listaEstadios.tamano_lista()<<endl;
	}
	
	void Estructuras::InsertarProgramaciones(ProgramacionF1 programacion, int pos){
		listaProgramacion.insertar_pos(programacion, pos);
		cout<<"El tamaño de la lista de Programaciones es: "<<listaProgramacion.tamano_lista()<<endl;
	}
	
	void Estructuras::InsertarProgramaciones2(ProgramacionF2 programacion, int pos){
		listaProgramacion2.insertar_pos(programacion, pos);
		cout<<"El tamaño de la lista de Programaciones es: "<<listaProgramacion2.tamano_lista()<<endl;
	}
	
	void Estructuras::InsertarPartidos(PartidosF1 partido, int pos){
		listaPartidos.insertar_pos(partido, pos);
		cout<<"El tamaño de la lista de Partidos es: "<<listaPartidos.tamano_lista()<<endl;
	}
	
	void Estructuras::InsertarPartidos2(PartidosF2 partido, int pos){
		listaPartidos2.insertar_pos(partido, pos);
		cout<<"El tamaño de la lista de Partidos es: "<<listaPartidos2.tamano_lista()<<endl;
	}*/
	/*
	void Estructuras::EliminarEquipo(string equipo){
		int u=1;
		Equipos eq;
		eq=listaEquipos.obtenerDato(u);
		while(eq.pais !=equipo){
			u++;
			eq=listaEquipos.obtenerDato(u);
		}
		listaEquipos.eliminar(u);
		posicionAux=u;
		cout<<"El tamaño de la lista de equipos es: "<<listaEquipos.tamano_lista()<<endl;			
	}
	
	void Estructuras::EliminarGrupo(string grupo){
		int u=1;
		Grupos gr;
		gr=listaGrupos.obtenerDato(u);
		while(gr.idGrupo !=grupo){
			u++;
			gr=listaGrupos.obtenerDato(u);
		}
		listaGrupos.eliminar(u);
		posicionAux=u;
		cout<<"El tamaño de la lista de equipos es: "<<listaGrupos.tamano_lista()<<endl;
					
	}
	
	void Estructuras::EliminarJugador(string nomJugador, string apJugador){
		int u=1;
		int aux=1;
		Jugadores jug;
		while(aux!= -1){
			jug=listaJugadores.obtenerDato(u);
			if(jug.nombres==nomJugador){
				if(jug.apellidos==apJugador){
					aux=-1;
				}
				else{
					u++;
				}
			}
			else{
				u++;	
			}
		}
		listaJugadores.eliminar(u);
		posicionAux=u;
		cout<<"El tamaño de la lista de equipos es: "<<listaJugadores.tamano_lista()<<endl;			
	}
	
	Usuarios* Estructuras::AsignarUsuario(string dato){
		cout<<usuarios.tamano_lista()<<endl;
		int i=1;
		Usuarios* us= new Usuarios;
		*us=usuarios.obtenerDato(i);
		while(us->id!= dato){
			if(i<usuarios.tamano_lista()){
				i++;
				*us= usuarios.obtenerDato(i);
			}
			else{
				return NULL;
			}
		}
		 return us;
	}
	
	Entrenadores* Estructuras::AsignarEntrenador(string dato, int op){
		int i=1;
		Entrenadores* en= new Entrenadores;
		*en=directores.obtenerDato(i);
		if(op==1){
			while(en->seleccionesDirigidas.obtenerDato(1) != dato){
				if(i<directores.tamano_lista()){
					i++;
					*en= directores.obtenerDato(i);
				}
				else{
					return NULL;
				}
			}
			 return en;	
		}
		if(op==2){
			while(en->id != dato){
			if(i<directores.tamano_lista()){
				i++;
				*en= directores.obtenerDato(i);
			}
			else{
				return NULL;
			}
		}
		 return en;
		}
		return NULL;
	}
	
	Administradores* Estructuras::AsignarAdministrador(string dato){
		int i=1;
		Administradores *adm= new Administradores;
		*adm=administradores.obtenerDato(i);
		while(adm->id != dato){
			if(i<administradores.tamano_lista()){
				i++;
				*adm= administradores.obtenerDato(i);
			}
			else{
				return NULL;
			}
		}
		 return adm;
	}
	
	Jugadores* Estructuras::AsignarJugador(string dato, int pos, int op){
		Jugadores* jug= new Jugadores;
		if(op==1){
			*jug=listaJugadores.obtenerDato(pos);
			while(jug->nacionalidad != dato){
				if(pos<listaJugadores.tamano_lista()){
					pos++;
					*jug= listaJugadores.obtenerDato(pos);
				}
				else{
					return NULL;
				}
			}
			posicionAux=pos;
			return jug;
		}
		if(op==2){
			*jug=listaJugadores.obtenerDato(pos);
			while(jug->nombres != dato){
				if(pos<listaJugadores.tamano_lista()){
					pos++;
					*jug= listaJugadores.obtenerDato(pos);
				}
				else{
					return NULL;
				}
			}
			posicionAux=pos;
			return jug;
		}
		if(op==3){
			if(pos<listaJugadores.tamano_lista()){
				*jug= listaJugadores.obtenerDato(pos);
				return jug;
			}
			else{
				return NULL;
			}
		}
		if(op==4){
			*jug= listaJugadores.obtenerDato(pos);
			while(jug->fechasSancion.obtenerDato(1) != dato){
				if(pos<=listaJugadores.tamano_lista()){
					pos++;
					*jug= listaJugadores.obtenerDato(pos);
				}
				else{
					return NULL;
				}
			}
			posicionAux=pos;
			return jug;
		}
	}
	
	Equipos* Estructuras::ObtenerEquipo(string dato, int op, int pos){
		Equipos* eq= new Equipos;
		if(op==1){
			if(pos<=listaEquipos.tamano_lista()){
				*eq=listaEquipos.obtenerDato(pos);
			 	return eq;
			}
			else {
				return NULL;
			}
		}
		if(op==2){
			int k=1;
			*eq= listaEquipos.obtenerDato(k);
			while(eq->pais != dato){
				if(k<=listaEquipos.tamano_lista()){
					k++;
					*eq= listaEquipos.obtenerDato(k);
				}
				else{
					return NULL;
				}
			}
			 return eq;
		}
		if(op==3){
			*eq= listaEquipos.obtenerDato(pos);
			while(eq->grupo != dato){
				if(pos<=listaEquipos.tamano_lista()){
					pos++;
					*eq= listaEquipos.obtenerDato(pos);
				}
				else{
					return NULL;
				}
			}
			posicionAux=pos;
			return eq;
		}
		if(op==4){
			*eq= listaEquipos.obtenerDato(pos);
			while(eq->confederacion != dato){
				if(pos<=listaEquipos.tamano_lista()){
					pos++;
					*eq= listaEquipos.obtenerDato(pos);
				}
				else{
					return NULL;
				}
			}
			posicionAux=pos;
			return eq;
		}
		return NULL;
	}
	
	PartidosF1* Estructuras::obtenerPartidos(string dato, int pos){
		PartidosF1* par= new PartidosF1;
		if(pos<=listaPartidos.tamano_lista()){
			*par=listaPartidos.obtenerDato(pos);
		 	return par;
		}
		else {
			return NULL;
		}
	}
	
	PartidosF2* Estructuras::obtenerPartidos2(string dato, int pos){
		PartidosF2* par= new PartidosF2;
		if(pos<=listaPartidos2.tamano_lista()){
			*par=listaPartidos2.obtenerDato(pos);
		 	return par;
		}
		else {
			return NULL;
		}
	}
	
	Grupos* Estructuras::ObtenerGrupo(string dato, int pos, int op){
		Grupos* gr= new Grupos;
		if(op==1){
			if(pos<=listaGrupos.tamano_lista()){
				*gr=listaGrupos.obtenerDato(pos);
			 	return gr;
			}
			else {
				return NULL;
			}
		}
		if(op==2){
			*gr= listaGrupos.obtenerDato(pos);
			while(gr->idGrupo != dato){
				if(pos<=listaGrupos.tamano_lista()){
					pos++;
					*gr= listaGrupos.obtenerDato(pos);
				}
				else{
					return NULL;
				}
			}
			 return gr;
		}	
	}
	
	ProgramacionF1* Estructuras::ObtenerProgramacion(string dato, int pos, int op){
		ProgramacionF1* pr= new ProgramacionF1;
		if(op==1){
			if(pos<=listaProgramacion.tamano_lista()){
				*pr=listaProgramacion.obtenerDato(pos);
			 	return pr;
			}
			else {
				return NULL;
			}
		}
		if(op==2){
			*pr= listaProgramacion.obtenerDato(pos);
			while(pr->fecha != dato){
				if(pos<=listaProgramacion.tamano_lista()){
					pos++;
					*pr= listaProgramacion.obtenerDato(pos);
				}
				else{
					return NULL;
				}
			}
			posicionAux=pos;
			return pr;
		}
		if(op==3){
			*pr= listaProgramacion.obtenerDato(pos);
			while(pr->estadio != dato){
				if(pos<=listaProgramacion.tamano_lista()){
					pos++;
					*pr= listaProgramacion.obtenerDato(pos);
				}
				else{
					return NULL;
				}
			}
			posicionAux=pos;
			return pr;
		}
		return NULL;
	}
	
	ProgramacionF2* Estructuras::ObtenerProgramacion2(string dato, int pos, int op){
		ProgramacionF2* pr= new ProgramacionF2;
		if(op==1){
			if(pos<=listaProgramacion2.tamano_lista()){
				*pr=listaProgramacion2.obtenerDato(pos);
			 	return pr;
			}
			else {
				return NULL;
			}
		}
		if(op==2){
			*pr= listaProgramacion2.obtenerDato(pos);
			while(pr->fecha != dato){
				if(pos<=listaProgramacion2.tamano_lista()){
					pos++;
					*pr= listaProgramacion2.obtenerDato(pos);
				}
				else{
					return NULL;
				}
			}
			posicionAux=pos;
			return pr;
		}
		if(op==3){
			*pr= listaProgramacion2.obtenerDato(pos);
			while(pr->estadio != dato){
				if(pos<=listaProgramacion2.tamano_lista()){
					pos++;
					*pr= listaProgramacion2.obtenerDato(pos);
				}
				else{
					return NULL;
				}
			}
			posicionAux=pos;
			return pr;
		}
		return NULL;
	}
	
	Estadios* Estructuras::ObtenerEstadio(string dato, int pos, int op){
		Estadios* es= new Estadios;
		if(op==1){
			if(pos<=listaEstadios.tamano_lista()){
				*es=listaEstadios.obtenerDato(pos);
			 	return es;
			}
			else {
				return NULL;
			}
		}
		if(op==2){
			*es= listaEstadios.obtenerDato(pos);
			while(es->nombre != dato){
				if(pos<=listaEstadios.tamano_lista()){
					pos++;
					*es= listaEstadios.obtenerDato(pos);
				}
				else{
					return NULL;
				}
			}
			 return es;
		}
		return NULL;
	}
	
	int Estructuras::AuxPos(){
		return posicionAux;
	}
	
	int Estructuras::faseDos(){
		int aux;
		aux= listaPartidos.tamano_lista();
		return aux;
	}
	
	int Estructuras::finTorneo(){
		int aux;
		aux= listaPartidos2.tamano_lista();
		return aux;
	}*/
