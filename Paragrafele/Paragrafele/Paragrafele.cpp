// Paragrafele.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

class ListaParagrafe {
	string paragrafe[100];
	int numarParagrafe;
public:
	ListaParagrafe() {
		numarParagrafe = 0;
	}

	void Add(string s) {
		paragrafe[numarParagrafe] = s;
		numarParagrafe++;
	}
	
	string* begin() {
		return &paragrafe[0];
	}

	string* end() {
		return &paragrafe[numarParagrafe];
	}

	
};

class Procesator {
public:
	virtual void Proceseaza(string ceva) = 0;
	virtual void Print() = 0;
};

class ProcesatorNumarCuvinte : public Procesator {
	string propozitie;
	map<string, int> numarCuvinte;

public:
	ProcesatorNumarCuvinte() {
		propozitie = "";
	}

	void Proceseaza(string s) {
		
		string delims = "?!., ";
		int poz = 0;
		
		while (s.find_first_not_of(delims, 0) != -1) {
			poz = s.find_first_of(delims, 0);
			string cuvant = s.substr(0, poz);
			numarCuvinte[cuvant]++;
			s = s.substr(poz + 1);
		}
		numarCuvinte.erase("");
	}

	void Print() {
		for (auto x : numarCuvinte) {
			cout << x.first << ": " << x.second<<"\n";
		}
	}
};

class ProcesatorNumarPropozitii : public Procesator {
	string propozitie;
	int numarProp;

public:
	ProcesatorNumarPropozitii() {
		propozitie = "";
		numarProp = 0;
	};

	void Proceseaza(string s) {
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '.' || s[i] == '?' || s[i] == '!') {
				numarProp++;
			}
		}
	}

	void Print() {
		cout << numarProp << " propozitii" << '\n';
	}

};

int main() {
	ListaParagrafe L;
	L.Add("Ce usor e Testul la C++!");
	L.Add("Ce faci? Bine, tu Ce faci? Tot Bine.");
	
	Procesator *P = new ProcesatorNumarCuvinte();
	Procesator *P2 = new ProcesatorNumarPropozitii();
		for (auto paragraf : L) {
			P -> Proceseaza(paragraf);
			P2 ->Proceseaza(paragraf);
		}
		P->Print(); // Afiseaza "Testul: 1, la: 1, C++: 1, e: 1, usor: 1,Ce: 3, Bine: 2, faci: 2, Tot: 1, tu: 1"
		P2->Print(); // Afiseaza "4 propozitii"
		delete P;
		delete P2;
		for (auto paragraf : L) {
			cout << paragraf << "\n";
		}
	// For­ul de mai sus va afisa paragrafele originale date prin metoda Add:
	// Ce usor e Testul la C++!
	// Ce faci? Bine, tu Ce faci? Tot Bine.
		return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
