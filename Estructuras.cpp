#include <iostream>
#include "lista.h"

struct Usuario {
	string id, nombre,apellidos, sexo, edad, tipoUsuario, Clave;
};

struct Administrador {
	string id;
	Usuario* usuario;
};

struct UsAerolinea {
	string id;
	Usuario* usuario;
};

struct UsCliente {
	string id;
	Usuario* usuario;
};

struct Pasajero {
	string nombres, apellidos, numidentificacion, fechaNacimiento, tipo;
};
struct Silla{
	string id,estado;
};
struct Vuelo{
	string codigo, origen, destino, precio;
	Lista<Silla> sillas;
};
struct VueloPlaneado {
	string dia, horaInicio, horaFin;
	Vuelo* vuelo;
};

struct VueloEspecifico{
	string  fecha;
	int numSillasDisp;
	Lista <Silla> SillasVendidas, Sillasdisp;
	Vuelo* vuelo;
};
class Estructuras{
	private:
		Lista<Usuario> usuarios;
		Lista<Administrador> administradores;
		Lista<UsAerolinea> usAerolineas;	
		Lista<UsCliente> usCliente;
		Lista<Pasajero> pasajeros;
		Lista<Silla> sillas;
		Lista<Vuelo> vuelos;
		Lista<VueloPlaneado> vuelosPlaneados;
		Lista<VueloEspecifico> vuelosEspecificos;
		int posicionAux;
    public:
    	Estructuras(){
		}
		void insertarUsAerolinea(UsAerolinea, int pos);
		void insertarAdministradores(Administradores administrador, int pos);
		void InsertarUsCliente (UsCliente cliente, int pos);
		//void InsertarUsuarios(Usuarios usuario, int pos);
		//void InsertarVuelo(Vuelo vuelo, int pos);
		void InsertarPasajero(Pasajero pasajero, int pos);
		void InsertarVueloPlaneado(VueloPlanedo vueloplan, int pos);
		void InsertarVueloEspecifico(VueloEspecifico vueloesp, int pos);
		void EliminarVueloPlaneado(string codigo);
		void EliminarVueloEspecifico(string codigo);
		void EliminarPasajero(string nombre, string );
	    Administradores* AsignarAdministrador(string dato);
	    ProgramacionF1* ObtenerProgramacion(string dato, int pos, int op);
	   ProgramacionF2* ObtenerProgramacion2(string dato, int pos, int op);
        Entrenadores* AsignarEntrenador(string dato, int op);
	      Jugadores* AsignarJugador(string dato, int pos, int op);
	    PartidosF1* obtenerPartidos(string dato, int pos);
	   PartidosF2* obtenerPartidos2(string dato, int pos);
		Usuarios* AsignarUsuario(string en);
		Estadios* ObtenerEstadio(string dato, int pos, int op);
		Equipos* ObtenerEquipo(string dato, int op, int pos);
		Grupos* ObtenerGrupo(string dato, int pos, int op);
		int AuxPos();
		int faseDos();
		int finTorneo();
};

	void Estructuras::insertarEntrenadores(Entrenadores director, int pos){
		directores.insertar_pos(director, pos);
		cout<<"El tamaño de la lista de entrenadores es: "<<directores.tamano_lista()<<endl;
	}
	
	void Estructuras::insertarAdministradores(Administradores administrador, int pos){
		administradores.insertar_pos(administrador, pos);
		cout<<"El tamaño de la lista de Administradores es: "<<administradores.tamano_lista()<<endl;
	}
	
	void Estructuras::InsertarJugadores(Jugadores jugador, int pos){
		listaJugadores.insertar_pos(jugador, pos);
		cout<<"El tamaño de la lista de jugadores es: "<<listaJugadores.tamano_lista()<<endl;
	}
	
	
	void Estructuras::InsertarUsuarios(Usuarios usuario, int pos){
		usuarios.insertar_pos(usuario, pos);
		cout<<"El tamaño de la lista de usuarios es: "<<usuarios.tamano_lista()<<endl;
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
	}
	
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
	}


