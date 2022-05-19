#pragma once
#include "hashmap_eda.h"
#include <stdexcept>
#include <vector>
#include <string>
#include <list>
#include "hashmap_eda.h"
#include <iostream>
using namespace std;
using canciones = std::string;

class ipud {
	
	struct infoCancion {
		string artista;
		int duracion;
		list<canciones>::iterator itPlaylist;
		list<canciones>::iterator it_Recientes;
	};
	unordered_map<string, infoCancion> ipud;
	list <string> playlist;
	list <string> recientes;
	int tiempoTotal;

public:
	//A anterior  D duracion
	void addCancion(string c, string A, int D) {
		if (ipud.count(c) > 0)
			throw std::domain_error("error addSong");
		ipud.insert({ c, {A,D,playlist.end(),recientes.end()}});

	}
	/*
	A~nade la cancion S al nal de la lista de reproduccion. Si la cancion ya se
encontraba en la lista entonces no se a~nade (es decir, la lista no tiene canciones repetidas). Si la
cancion no esta en el iPud se devuelve error.
	
	*/

	void addToPlaylist(string c) {
		if (ipud.count(c) ==0) //si no existe no puedo añadir a la playlist
			throw std::domain_error("error");
		if (ipud[c].itPlaylist == playlist.end()) { // Si no existe en la lista playlist
			auto it=playlist.insert(playlist.end(), c);
			ipud[c].itPlaylist = it;
			tiempoTotal += ipud[c].duracion;
		}
	}

	void play() {
		if (!playlist.empty()) {
			string cancionAct = playlist.front();
			playlist.pop_front();
			infoCancion &x = ipud[cancionAct];
			tiempoTotal -= x.duracion;
			if (x.it_Recientes != recientes.end())// Si ya estaba antes en recientes
				recientes.erase(x.it_Recientes);
			x.it_Recientes = recientes.insert(recientes.begin(), cancionAct);
		}
	}
};