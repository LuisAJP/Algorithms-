#include "hashmap_eda.h"
#include "treemap_eda.h"
#include <list>
#include <string>
using namespace std;

class ventaLibros{
private:
	
	struct tInfo{
		int n=0;//numero ejemplares
		int v=0;//numero libros vendidos
		list<string>::iterator itLibro;
	};

	//libros e info//libros e info
	unordered_map<string,tInfo> hmap;

	//numero ejemplares vendidos y lista libros 
	map<int, list<string>, greater<int> > tmap;


public:

	//O(1)
	//inserto un libro e incremento ejemplares en 1
	void nuevoLibro(int n, string x){
			hmap[x].n += n;	
	}

	//O(logN), donde N  es el numero de ejemplares vendidos
	//el coste de insertar elemento en un treemap es logN
	void  comprar(string x){
		if (hmap.count(x) == 0)//si el libro no existe
			throw invalid_argument("Libro no existente");
		if (hmap[x].n <=0)//si no hay ejemplares
			throw out_of_range("No hay ejemplares");
		
		//si hay ejemplares vendidos
		if (hmap[x].v > 0){
			//elimino libro de la lista tmap
			tmap[hmap[x].v].erase(hmap[x].itLibro);
		}
			
		hmap[x].n -= 1;//decremente ejemplares
		hmap[x].v += 1;//incrementa libros vendidos

		//numero de ejemplares vendidos
		int vendidos = hmap[x].v;

	//inserto ejemplares vendidos al treemap 	
	//inserto libro al principio lista, 
	//si hay varios libros con mismo numero ejemplares vendidos,
	// prevalecera de recientes a mas antiguos(push_front) 
		tmap[vendidos].push_front(x);

	//dejo apuntando el itLibros al libro de lista de tmap 
		hmap[x].itLibro = tmap[vendidos].begin();
	}

	//O(1)
	int  estaLibro(string x){
		return hmap.count(x);
	}

	//O(1) si no existe libro, en otro caso O(LogN) 
	//donde N es numero de ejemplares vendidos
	//coste [] y erase del treemap es logN 
	//coste erase lista, con iterator como parametro es O(1)
	void elimLibro(string x){
		if (hmap.count(x) == 1){//si el libro existe
			int vendidos = hmap[x].v;//numero ejemplares vendidos
			if (vendidos > 0)//si hay libros vendidos
				tmap[vendidos].erase(hmap[x].itLibro);//se elimina de la lista tmap
			hmap.erase(x);//elimina libro del sistema
		}
	}

	//O(1)
	int  numEjemplares(string x){
		if (hmap.count(x) == 0)
			throw invalid_argument("Libro no existente");
		return hmap[x].n;
	}

	//O(N), donde N es el numero maximo(10) de elementos que puede contener
	//la lista, aunque haya bucle anidado, lo maximo que puede llegar a recorrer
	//a lo sumo es 10
	list<string> top10(){
		list<string>l;
		auto it=tmap.begin();
		for (int i = 0; i < 10 && it != tmap.end(); ++it){
			auto itLibros=it->valor.begin();//obtengo lista libros
			for (itLibros; i < 10 && itLibros != it->valor.end(); i++){
				l.push_back(*itLibros);
				itLibros++;
			}
		}
		return l;
	}
};
