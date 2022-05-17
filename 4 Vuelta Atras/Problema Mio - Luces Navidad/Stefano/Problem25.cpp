/*
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <vector>


bool isValid(std::vector<int> sol, int k, std::vector<int> contColors, int totalLights) {
	if (k > 1 && sol[k] == sol[k - 1] && sol[k - 1] == sol[k - 2])
		return false;

	if (contColors[sol[k]] > (totalLights - contColors[sol[k]]) + 1)
		return false;

	return true;
}

bool isSolution(int consumption, int totalConsumption) {
	return totalConsumption <= consumption;
}


//Coste O(m^n) donde m son el número de tipos de colores de bombillas y n la cantidad de luces.
void christmasLights(std::vector<int> sol, std::vector<int> contColors,
	std::vector<int> colors, int consumption, int totalConsumption, int k, int totalLights, int & total) {
	int lon = colors.size();
	for (int i = 0; i < lon; i++) {
		sol[k] = i;
		contColors[i]++;
		totalConsumption += colors[i];
		totalLights++;

		if (isValid(sol, k, contColors, totalLights)) {
			if (k == sol.size() - 1) {
				if (isSolution(consumption, totalConsumption))
					total++;
			}
			else christmasLights(sol, contColors, colors, consumption, totalConsumption, k + 1, totalLights, total);
		}

		contColors[i]--;
		totalConsumption -= colors[i];
		totalLights--;
	}
}

bool resuelveCaso() {

	int lon, numColors, consumption;
	std::cin >> lon >> numColors >> consumption;
	if (!std::cin) return false;

	std::vector<int> sol(lon);
	std::vector<int> contColors(numColors);
	std::vector<int> colors(numColors);

	int value;
	for (int i = 0; i < numColors; i++) {
		std::cin >> value;
		colors[i] = value;
	}
	int total = 0;
	christmasLights(sol, contColors, colors, consumption, 0, 0, 0, total);
	std::cout << total << '\n';

	return true;
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos25.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	while (resuelveCaso()) {}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}