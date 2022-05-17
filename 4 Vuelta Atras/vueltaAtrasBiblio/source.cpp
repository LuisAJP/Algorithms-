

bool isValid(const vector<int> & sol, const vector<int>& rain, const vector<int> & coats, 
	int k, int i, const vector<int> & contCoats) {
  
  // El abrigo tiene que soportar la lluvia.
  if (coats[sol[k]] < rain[k])
    return false;

  if (k > 0) {
    // No se usa un abrigo dos días seguidos.
    if (sol[k - 1] == sol[k])
      return false;

    // El abrigo que más haya usado no supere en dos días 
    // o más a un tercio de los días que van transcirridos.
    if (contCoats[i] > 2 + (k / 3))
      return false;
  }
  return true;
}



bool isSolution(std::vector<int> const& sol) {
  return sol[0] != sol[sol.size() - 1];
}


//Coste O(m^n) donde m son el número de abrigos y n los días.
void coatsCombinations(vector<int> sol,vector<int> const& rain, vector<int> const& coats,vector<int> contCoats, int n, int a, int k, int& numCoats) {
	for (int i = 0; i < a; i++) {
    sol[k] = i;
    contCoats[i]++;

    if (isValid(sol, rain, coats, k, i, contCoats)) {
      if (k == n - 1) {
        if (isSolution(sol))
          numCoats++;
      }
      else 
		  coatsCombinations(sol, rain, coats, contCoats, n, a, k + 1, numCoats);
    }

    contCoats[i]--;
  }
}