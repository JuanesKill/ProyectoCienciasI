#include<iostream>
#include<time.h>
using namespace std;

struct City{
	string name, pais;
	int frecuencia;
};

struct Avion{
	string id, idaerolinea, tipoavion;
	//Lista<Silla> sillas;
	int capacidad;
	
};

struct Vuelo{
	int noVuelo;
	int horaInicio;
	int fechaFin;
	City origen;
	City destino;
	Vuelo *sig;	
};

struct VueloE{
	int dipo, precio;
	tm fechaSalida;
	Vuelo *v;
	VueloE *sig;		
};
/*
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
*/
class VueloPlaneado{
		Vuelo *cab;
		Vuelo *z;
	public:
		VueloPlaneado(){cab=z=NULL;}
		Vuelo *getCab();	
		void nuevo();	
		Vuelo *buscar(int);	
		void mostrar(Vuelo*);
		void mostrarTodo();
};

class VueloEspeci{
		VueloE *cab;
		VueloE *z;
	public:
		VueloEspeci(){cab=z=NULL;}
		void nuevo(VueloPlaneado);
};

Vuelo *VueloPlaneado::getCab(){
	return cab;
}

void VueloPlaneado::nuevo(){
	int m;
	Vuelo *v;
	v= new Vuelo;
	cout<<"\n\n Numero de vuelo: ";
	cin>>v->noVuelo;
	cout<<"\n Pais Origen: ";
	cin>>v->origen.pais;
	cout<<"\n Ciudad Origen: ";
	cin>>v->origen.name;
	cout<<"\n Pais destino: ";
	cin>>v->destino.pais;
	cout<<"\n Ciudad destino: ";
	cin>>v->destino.name;
	cout<<"\n Hora Inicio: \n";
	cin>>v->horaInicio;//0-23
	cout<<"\n Hora Fin: \n";
	cin>>v->fechaFin;//0-59
	
	if(cab){
		z->sig=v;				
	}else{		
		cab=v;
	}
	
	v->sig=NULL;
	z=v;
}

void VueloEspeci::nuevo(VueloPlaneado plan){
	int m, noVuelo;
	VueloPlaneado plane;
	plane=plan;
	VueloE *ve;
	ve= new VueloE;
	cout<<"\n\n Numero de vuelo asociado: ";
	cin>>noVuelo;
	ve->v=plane.buscar(noVuelo);
	plane.mostrar(ve->v);
	if(ve->v==NULL){
		return;
	}	
	cout<<"\n Fecha salida: hora, minuto, dia, mes, anio: \n";
	cin>>ve->fechaSalida.tm_hour;//0-23
	cin>>ve->fechaSalida.tm_min;//0-59
	cin>>ve->fechaSalida.tm_mday;//1-31
	cin>>m;
	ve->fechaSalida.tm_mon=m-1;//0-11
	cin>>ve->fechaSalida.tm_year;
	
	if(cab){
		z->sig=ve;				
	}else{		
		cab=ve;
	}
	
	ve->sig=NULL;
	z=ve;
}

Vuelo *VueloPlaneado::buscar(int noVuelo){
	int numero=0;
	Vuelo *aux=cab;
	Vuelo *aux1=cab;
	while(numero!=noVuelo){
		aux=aux1;
		if(aux==NULL){
			return NULL;
		}else{
			numero=aux->noVuelo;
			aux1=aux->sig;
		}		
	}
	return aux;
}

void VueloPlaneado::mostrarTodo(){
	Vuelo *aux=cab;
	while(aux){
		mostrar(aux);
		aux=aux->sig;
	}
}

void VueloPlaneado::mostrar(Vuelo *v){
	if(v==NULL){
		cout<<"\n Vuelo No Encontrado \n";
	}else{
		int m;
		cout<<"\n\n Numero de vuelo  "<<v->noVuelo<<"\n";
		cout<<" Pais Origen  "<<v->origen.pais<<"\n";
		cout<<" Ciudad Origen  "<<v->origen.name<<"\n";
		cout<<" Pais destino  "<<v->destino.pais<<"\n";
		cout<<" Ciudad destino  "<<v->destino.name<<"\n";
		cout<<" Hora Inicio  "<<v->horaInicio<<"\n";
		cout<<" Hora Fin  "<<v->fechaFin<<"\n";
		/*
		m=v->fechaSalida.tm_mon;		
		cout<<" Fecha salida: "<<v->fechaSalida.tm_year<<"-"<<m+1<<"-"<<v->fechaSalida.tm_mday<<"  "<<v->fechaSalida.tm_hour<<":"<<v->fechaSalida.tm_min<<":00 \n";
		*/
	}
		
}

char menu(){
  char opcion;
  cout<<"\n   MENU\n";
  cout<<"1-Agregar\n";  
  cout<<"2-Buscar\n";
  cout<<"3-Mostrar\n";
  cout<<"4-Agregar especifico\n";  
  cout<<"(T)erminar\n";
  cout<<"Escoja una opcion: ";
  cin>> opcion;
  return opcion;
}

int main(){
	VueloEspeci especi;
	VueloPlaneado planeado;
	Vuelo *v;
	int elemento;
	char opcion;
	do{
	   opcion=menu();
	   switch (opcion){
		  case '1':
		  case 'A':
		  	planeado.nuevo();
		  	break;		  	
		  	
		  case '2':
		  case 'M':
		  	planeado.mostrarTodo();
		  	break;
		  	
		  case '3':
		  case 'B':
		  	cout<<"\n ingrese el elemento a buscar: ";
		  	cin>>elemento;
		  	v=planeado.buscar(elemento);
		  	planeado.mostrar(v);
		  	break;
		  	
		  case '4':
		  case 'E':
		  	especi.nuevo(planeado);
		  	break;
		}
	}while(opcion!='t' && opcion!='T');
	
	return 1;
}




