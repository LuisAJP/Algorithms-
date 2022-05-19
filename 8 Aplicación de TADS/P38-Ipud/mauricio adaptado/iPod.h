#ifndef iPod_h
#define iPod_h

#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <iterator>
#include <stdexcept>
using namespace std;



class iPod {
private:	
	using cancion = string;
	using artista = string;

	struct tInfo {
		artista a;
		int duracion;
		std::list<cancion>::const_iterator itPlaylist;
		std::list<cancion>::const_iterator itRecientes;
	};
	
	
    std::unordered_map<cancion, tInfo> mapa;
    std::list<cancion> playlist;
	std::list<cancion> listaRecientes;
    int total = 0;
    
public:
    void addSong(const cancion &S, const artista &A, const int D) { //O(1)
        const auto it = mapa.find(S);
        if (it != mapa.cend())
            throw std::domain_error("addSong");
        else
			mapa.insert({ S, { A, D, playlist.cend(), listaRecientes.cend() } });
    }
    
    void addToPlaylist(const cancion &S) { //O(1)
        const auto it = mapa.find(S);//obtiene el valor(info) si existe
        if (it == mapa.cend())
            throw std::domain_error("addToPlaylist");
		else if (it->second.itPlaylist == playlist.cend()) {//si no existe en la playlist
            playlist.push_back(S);//pone al final de playlist

			//obtengo el iterator del ultimo elemento de playlist
			auto tmp = playlist.cend();
            tmp--;
			
			it->second.itPlaylist = tmp;//itPlaylist apunta a la cancion de playlist
            total += it->second.duracion;//actualizo el tiempo
        }
    }
    
    cancion current() const { //O(1)
        if (playlist.empty())
            throw std::domain_error("current");
        return playlist.front();
    }
    
    void play() { //O(1)
        if (!playlist.empty()) {
            std::cout << "Sonando " << current() << "\n";
			listaRecientes.push_back(current());//agrega la cancion al final de listaRecientes
            auto it = mapa.find(current());//current ->obtiene valor de la primera cancion de playlist
			
			it->second.itPlaylist = playlist.cend();//pone a null la cancion de la lista reproduccion

			if (it->second.itRecientes != listaRecientes.cend())//si la cancion ya existe en la listareproducidas
				listaRecientes.erase(it->second.itRecientes);
			auto itTmp = listaRecientes.cend();
            itTmp--;//accedo a la penultima
			it->second.itRecientes = itTmp;//dejo apuntando itListaReproducidas a la cancion de listaReproducidas

            playlist.pop_front();//elimino la primera cancion de listaReproduccion
            total -= it->second.duracion;//actualizo el tiempo total de la listaReproduccion
        }
        else
            std::cout << "No hay canciones en la lista\n";
    }
    
    int totalTime() const { //O(1)
        return total;
    }
    
    std::list<cancion> recent(int N) const { //O(n)
        std::list<cancion> resultado;
        
		auto it = listaRecientes.crbegin();
		string C;
		for (int i = 0; i < N && it != listaRecientes.crend(); ++i) {
			C = *it;
           // resultado.push_back(*it);
			resultado.push_back(C);
            ++it;
        }
        return resultado;
    }
    
    void deleteSong(const cancion &S) { //O(1)
        const auto it = mapa.find(S);
        if (it != mapa.cend()) {
			if (it->second.itPlaylist != playlist.cend()) {
                total -= it->second.duracion;
				playlist.erase(it->second.itPlaylist);
            }
			if (it->second.itRecientes != listaRecientes.cend())
				listaRecientes.erase(it->second.itRecientes);
            mapa.erase(it);
        }
    }
    
};

#endif // iPod_h
