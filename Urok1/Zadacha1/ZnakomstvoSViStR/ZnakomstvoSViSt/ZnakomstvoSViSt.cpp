#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::ifstream resurs("in.txt");
	std::string dannye;

	resurs >> dannye;
	int n = stoi(dannye);
	int* mass1 = new int[n];
	for (int i = 0; i < n; ++i) {
		resurs >> dannye;
		mass1[i] = stoi(dannye);
	}
	int m = n;
	resurs >> dannye;
	n = stoi(dannye);

	int* mass2 = new int[n];
	for (int i = 0; i < n; ++i) {
		resurs >> dannye;
		mass2[i] = stoi(dannye); 
	}

	std::ofstream itog("out.txt");
	itog << n << "\n";
	itog << mass2[n-1] << " ";
	for (int i = 0; i < n - 1; ++i) {
		itog << mass2[i] << " ";
	}
	itog << "\n";

	itog << m << "\n";	
	for (int i = 1; i < m ; ++i) {
		itog << mass1[i] << " ";
	}
	itog << mass1[0];

	resurs.close();
	itog.close();
	delete[] mass1;
	delete[] mass2;

	return 0;
}
