#include<string>
#include "list_eda.h"
#include "hashmap_eda.h"
using namespace std;

class iPud{
private:
	using cancion = string;

	typedef struct{
		string artista;
		int duracion;
		list<string>::iterator itPlaylist;
		list<string>::iterator itRecientes;
	}tInfo;

	int tiempoTotal=0;
	unordered_map<cancion, tInfo> mapa;

	list<cancion> playlist;//lista de reproduccion
	list<cancion> recientes;
public:
	
	//O(1)
	 void addSong(string C, string A, int D){
		 if (mapa.count(C)==1)//si la cancion ya existe
			 throw domain_error("addSong");
		 mapa.insert({ C, { A, D,playlist.end(),recientes.end() } });
	 }

	 //O(1)
	 /*Agrega la cancion S al final de la lista de reproduccion(playlist).
	 Si la cancion existe en la lista, no se añade(la lista no tiene canciones
	 repetidas). Si la cancion no esta en el iPud devuelve error.*/
	 void addToPlaylist(string S) {
		 if (mapa.count(S) == 0)//Si la cancion no esta en el iPud se devuelve error.
			 throw domain_error("addToPlaylist");

		 //Si la cancion es igual a null(Si la cancion no existe en playlist )
		 if (mapa[S].itPlaylist == playlist.end()) {
			/*insert me inserta al final de la lista(push_back)//O(1)
			/insert me devuelve el iterador anterior a playlist.end()*/
			 auto it = playlist.insert(mapa[S].itPlaylist,S);//me inserta al final de playlist
			 mapa[S].itPlaylist = it; //actualizamos en el mapa el iterador de la cancion
			
			tiempoTotal += mapa[S].duracion;
		 } 
	 }

	//O(1)
	/* Devuelve la primera cancion de la lista de reproduccion. 
	Si la lista de reproduccion es vacia se devuelve error.*/
	 string current() {
		 if (playlist.empty()) 
			throw domain_error("current");
	
		 return playlist.front();
	 }

	 //O(1)
	 //La primera cancion de la lista de reproduccion abandona la lista de reproduccion y se
	 //registra como reproducida.Si la lista es vacia la accion no tiene efecto.
	 cancion play() {
		 cancion C = "";
		 if (!playlist.empty()) {
			 C = playlist.front();//obtengo la primera cancion de la playlist
			 
			playlist.pop_front();//O(1)  elimina primera cancion playlist
			mapa[C].itPlaylist = playlist.end();//pongo a null(apunta nodo fantasma)

			tiempoTotal = tiempoTotal - mapa[C].duracion;//actualizo tiempo playlist

			 if (mapa[C].itRecientes != recientes.end()) {//si la cancion ya esta en recientes
				 recientes.erase(mapa[C].itRecientes);// //eliminamos de la lista y ponemos itRecientes igual a null
				 mapa[C].itRecientes = recientes.end();//pongo a null
			 }

			 recientes.push_front(C);//pones al principio de recientes
			 auto it = recientes.begin();//obtenemos el iterador del primer elemento de recientes
			 mapa[C].itRecientes = it;//dejamos apuntando a la cancion de recientes
		 }
		 return C;
	 }

	 //O(1)
	 /* Devuelve la suma de las duraciones de las canciones que integran 
	 la lista de reproduccion actual. Si es vacia se devuelve 0.*/
	 int totalTime() {
		 return tiempoTotal;
	 }


	 //O(N)
	 /*recent(N): Obtiene la lista con las N (mayor que 0) ultimas canciones que se han reproducido
	(mediante la operacion play), de la mas reciente a la mas antigua. Si el numero de canciones
	reproducidas es menor que N se devolveran todas. La lista no tiene repeticiones, de manera que si
	una cancion se ha reproducido mas de una vez solo figurara la reproduccion mas reciente.*/
	 list<cancion> recent(int N) {
		 list<cancion>lista;
		 string C;
		 auto it = recientes.begin();

		 for (int i = 0; i < N && it != recientes.end(); i++) {
			 C = *it;
			 lista.push_back(C);
			 it++;
		 }
		 return lista;
	 }

	 //O(1)
	 /*deleteSong(S): Elimina todo rastro de la cancion S del iPud. Si la cancion no existe la operacion
	 no tiene efecto.*/
	 void deleteSong(cancion S) {
		 if (mapa.count(S) == 1) {//si la cancion existe
			 if (mapa[S].itPlaylist != playlist.end()) {//si la cancion existe en la playlist
				 tiempoTotal = tiempoTotal - mapa[S].duracion;
				 playlist.erase(mapa[S].itPlaylist);//elimino S de playlist
				 mapa[S].itPlaylist = playlist.end();//elimino iterador  
			 }

			 if (mapa[S].itRecientes != recientes.end()) {//si la cancion existe en recientes
				 recientes.erase(mapa[S].itRecientes);//elimino S de recientes
				 mapa[S].itRecientes = recientes.end();//elimino iterador 
			 }
			 mapa.erase(S);//elimino la cancion S del mapa
		 }
	 }
};