class Multime
{
	int Numere[100];
	int Count;
public:
	Multime(); // 1 p (constructor default – vom avea 0 elemente in multime
	Multime(int * lista, int size); // 2 p (se vor copia elementele din lista in vectorul Numere)
	// daca size e mai mare decat 100, se vor copia primele 100
	int Max(); // 1 p (returneaza elementul cu valoarea maxima)
	int Min(); // 1 p (returneaza elemental cu valoarea minima)
	void Sort(int(*compare)(int, int)); // 7 p – sorteaza vectorul folosind o functie de comparatie
	int GetSize(); // returneaza Count – numarul de elemente

	int operator[](int index);
	friend Multime operator& (Multime& m1, Multime& m2);
	friend Multime operator| (Multime& m1, Multime& m2);

};
