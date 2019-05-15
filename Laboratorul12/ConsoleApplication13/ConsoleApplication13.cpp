// ConsoleApplication13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Contact {
public:
	string nume;
	int tip;
protected:
	Contact() {};
};

class Prieten : public Contact {
public:
	string data;
	string telefon;
	string adresa;


	Prieten(string nume, string data, string telefon, string adresa) {
		this->tip = 1;
		this->nume = nume;
		this->data = data;
		this->telefon = telefon;
		this->adresa = adresa;
	}
};

class Cunoscut : public Contact {
public:
	string telefon;

	Cunoscut(string nume, string telefon) {
		this->tip = 2;
		this->nume = nume;
		this->telefon = telefon;
	}


};

class Coleg : public Contact {
public:
	string telefon;
	string firma;
	string adresa;

	Coleg(string nume, string telefon, string firma, string adresa) {
		this->tip = 3;
		this->nume = nume;
		this->telefon = telefon;
		this->firma = firma;
		this->adresa = adresa;
	}
};


//Romb gol = pointeri la obiect
//Romb plin = obiecte in sine


class Agenda {
	vector<Contact*> contacte;

public:

	
	
	Contact* cauta(string nume) {
		for (Contact* c : contacte) {
			if (c->nume == nume)
				return c;
		}
		return nullptr;
	}

	vector<Contact*> listaPrieteni() {
		vector<Contact*> fList;
		for (Contact* c : contacte) {
			//Prieten *p = (Prieten*)c;
			if (c->tip == 1)
				fList.push_back(c);
		}
		return fList;
	}

	bool deleteContact(string nume) {
		int index = 0;
		for (Contact* c : contacte) {
			if (c->nume == nume) {
				contacte.erase(contacte.begin() + index);
				
				return true;
			}
			index++;
		}
		return false;
	}

	void addContact(Contact* c) {
		contacte.push_back(c);
	}

	void afisareContacte() {
		int index = 0;
		cout << "Contacte: " << endl;
		cout << "____________________________"<<endl;
		for (Contact* c : contacte) {
			index++;
			cout <<index<<": "<<c->nume << endl;
		}
	}
};

int main()
{

	Contact *p1 = new Prieten("Cineva", "09.07.1999", "0775579053", "adresa");
	Contact *p2 = new Prieten("Altcineva", "12.10.2000","0941231212", "alta adresa");
	Contact *c1 = new Cunoscut("Cineva cunoscut","085321421");
	Contact *co1 = new Coleg("Cristi", "0771231241", "O firma", "o adresa");


	Agenda myAg;

	myAg.addContact(p1);
	myAg.addContact(p2);
	myAg.addContact(c1);
	myAg.addContact(co1);

	myAg.afisareContacte();

	myAg.deleteContact("Cristi");

	myAg.afisareContacte();

	vector<Contact*> contacte = myAg.listaPrieteni();
	int index = 0;
	cout << endl << endl << endl;
	cout << "Prieteni: " << endl;
	cout << "____________________________"<<endl;
	for (Contact* c : contacte) {
		index++;
		cout << index << ": " << c->nume << endl;
	}
	
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
