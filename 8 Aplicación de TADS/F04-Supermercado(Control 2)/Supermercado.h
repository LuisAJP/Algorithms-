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

	unordered_map<codigo, tInfo> mapCliente;
	unordered_map<int, list<codigo>> mapCola;

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
		if (mapCliente.count(cod_cliente) == 1)
			throw domain_error("Cliente Duplicado");

		/*insert me inserta al final de la lista(push_back)
		insert me devuelve el iterador anterior a cola.end()*/
		auto it = mapCola[num_cola].insert(mapCola[num_cola].end(), cod_cliente);
		mapCliente.insert({ cod_cliente, { num_cola, it } });
	}

	
	
	/*El coste es O(1), el coste de la operacion erase e insert en una lista tiene coste O(1), 
	luego el coste para acceder al valor de un hashmap tienen coste O(1)*/
	void cambiar_cola(string cod_cliente,int num_cola) {
		if (num_cola < 0 || num_cola >= numeroCajas)
			throw domain_error("Cola inexistente");
		if (mapCliente.count(cod_cliente) == 0)
			throw domain_error("Cliente inexistente");
		
		int colaCliente = mapCliente[cod_cliente].ncola;
		if (colaCliente != num_cola) {//si el cliente cambia de cola
			
			mapCola[colaCliente].erase(mapCliente[cod_cliente].itCola);//elimino al cliente de su cola actual 			
			mapCliente[cod_cliente].ncola = num_cola;//actualizo el numero de cola del cliente
			
			//pongo a null, el iterator que apuntaba a la antigua cola del cliente
			//para hacer el insert luego es obligatorio dejarlo apuntado al final de la lista(end())
			mapCliente[cod_cliente].itCola = mapCola[num_cola].end();

			//inserto cliente al final de la nueva cola 
			auto it = mapCola[num_cola].insert(mapCliente[cod_cliente].itCola, cod_cliente);

			//actualizo el iterador, el iterator apunta a la nueva cola del cliente
			mapCliente[cod_cliente].itCola = it;
		}
	}

	/*El coste es O(1), el coste para devolver el tamaño de una lista es de coste O(1)*/
	int cuantos_en_cola(int num_cola) {
		if (num_cola < 0 || num_cola >= numeroCajas)
			throw domain_error("Cola inexistente");
		return mapCola[num_cola].size();
	}

	/*El coste es O(N) donde N es el numero de clientes que estan esperando en una cola(lista), 
	El coste es O(N) porque tiene que recorrer todos los elementos de la cola (lista),
	y en cada iteracion hace push_front coste O(1), por lo tanto el coste total es O(N)*/
	list<string> clientes_en_cola(int num_cola) {
		if (num_cola < 0 || num_cola >= numeroCajas)
			throw domain_error("Cola inexistente");
		list<string>lista;
		for (string x : mapCola[num_cola])
			lista.push_front(x);
		
		return lista;
	}
	
	/*El coste es O(1), el coste para acceder al valor de un hashmap tienen coste O(1) */
	int consultar_cliente(string cod_cliente) {
		if (mapCliente.count(cod_cliente) == 0)
			throw domain_error("Cliente inexistente");
		return mapCliente[cod_cliente].ncola;
	}
};
