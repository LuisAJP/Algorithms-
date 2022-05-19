#include<string>
#include "list_eda.h"
using namespace std;
#include "hashmap_eda.h"

class supermercado{
private:
	using codigo = string;

	typedef struct{
		int ncola;//numero cola
		list<string>::iterator itCola;
	}tInfo;

	unordered_map<codigo, tInfo> hmap;
	unordered_map<int, list<codigo>> cmap;

	int numeroCajas;

public:
	
	//Crea un nuevo supermercado sin clientes, y con el número de cajas indicado.
	 supermercado(int num_cajas) {
		numeroCajas = num_cajas;
	}

	 //El coste es O(1), las operaciones de count e insert en un hashmap tiene coste O(1)
	 //el coste de insert en una lista es O(1)
	void nuevo_cliente(string cod_cliente, int num_cola) {
		if( num_cola< 0||num_cola >= numeroCajas)
			throw domain_error("Cola inexistente");
		if(hmap.count(cod_cliente)==1)
			throw domain_error("Cliente Duplicado");
		
		if (cmap.count(num_cola) == 0) {//compruebo que num_cola no existe
			list<codigo> lista;
			cmap.insert({ num_cola, lista});//inserto el numero de cola y una lista vacia
		}
		/*insert me inserta al final de la lista(push_back)
		insert me devuelve el iterador anterior a cola.end()*/
		auto it = cmap[num_cola].insert(cmap[num_cola].end(),cod_cliente);
		hmap.insert({ cod_cliente, {num_cola,it} });
	}

	/*Se llama a este método cuando un cliente decide salirse de su cola para pasarse a la de otra caja.
	De este modo, ahora será el último de la cola indicada por num_cola, excepto si el cliente ya estaba
	en esa misma cola, en cuyo caso no se haría nada. Si num_cola está fuera de rango, se lanzará una
	excepción domain_error con el mensaje Cola inexistente. Si el cliente no estaba registrado en el
	sistema, se lanzará una excepción domain_error con el mensaje Cliente inexistente.*/
	
	/*El coste es O(1), el coste de la operacion erase e insert en una lista tiene coste O(1), luego el coste para acceder
	 al valor de un hashmap tienen coste O(1)
	*/
	void cambiar_cola(string cod_cliente,int num_cola) {
		if (num_cola < 0 || num_cola >= numeroCajas)
			throw domain_error("Cola inexistente");
		if(hmap.count(cod_cliente)==0)
			throw domain_error("Cliente inexistente");
		
		if (hmap[cod_cliente].ncola != num_cola) {//si el cliente cambia de cola
			cmap[hmap[cod_cliente].ncola].erase(hmap[cod_cliente].itCola);//elimino al cliente de su cola actual 			
			hmap[cod_cliente].ncola = num_cola;//actualizo el numero de cola del cliente
			hmap[cod_cliente].itCola = cmap[num_cola].end();//pongo a null, el iterator que apuntaba a la antigua cola del cliente

			auto it = cmap[num_cola].insert(hmap[cod_cliente].itCola,cod_cliente);//inserto el cliente al final de la nueva cola 
			hmap[cod_cliente].itCola = it;//actualizo el iterador, el iterator apunta a la nueva cola del cliente
			//it=cmap[num_cola].insert(it, cod_cliente);
			//hmap[cod_cliente].itCola = it;
		}
	}

	/*Devuelve un número que indica cuántos clientes hay esperando en la cola pasada comoparámetro.
	Si num_cola está fuera de rango, se lanzará una excepción domain_error con el mensaje Cola
	inexistente.*/

	/*El coste es O(1), el coste para devolver el tamaño de una lista es de coste O(1)*/
	int cuantos_en_cola(int num_cola) {
		if (num_cola < 0 || num_cola >= numeroCajas)
			throw domain_error("Cola inexistente");
		return cmap[num_cola].size();
	}

	/*Devuelve una lista con los clientes que están esperando en una determinada cola, desde el último
	hasta el primero. Si num_cola está fuera de rango se lanzará una excepción domain_error con el
	mensaje Cola inexistente.*/

	/*El coste es O(N) donde N es el numero de clientes que estan esperando en una cola(lista), 
	El coste es O(N) porque tiene que recorrer todos los elementos de la cola (lista),
	y en cada iteracion hace un push_front que tiene un coste O(1), por lo tanto
	el coste total es O(N)*/
	list<string> clientes_en_cola(int num_cola) {
		if (num_cola < 0 || num_cola >= numeroCajas)
			throw domain_error("Cola inexistente");
		list<string>lista;
		for (string x : cmap[num_cola])
			lista.push_front(x);
		
		return lista;
	}

	/*Devuelve el número de cola en la que se encuentra el cliente dado. Si el cliente no está registrado
	en el sistema lanza una excepción domain_error con el mensaje Cliente inexistente.*/

	/*El coste es O(1), el coste para acceder al valor de un hashmap tienen coste O(1) */
	int consultar_cliente(string cod_cliente) {
		if (hmap.count(cod_cliente) == 0)
			throw domain_error("Cliente inexistente");
		return hmap[cod_cliente].ncola;
	}
};
