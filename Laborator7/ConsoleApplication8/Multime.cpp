#include "Multime.h"

void Multime::Sort(int(*compare)(int, int)) {
	//compare(Numere[0], Numere[2]);

	for (int i = 0; i < Count-1; i++) {
		for (int j = i + 1; j < Count; j++) {
			if (compare(Numere[i], Numere[j]) == 1) {
				int aux = Numere[i];
				Numere[i] = Numere[j];
				Numere[j] = aux;
			}
		}
	}
}

int Multime::GetSize() {
	return Count;
}

Multime::Multime() {
	Count = 0;
}

Multime::Multime(int * lista, int count) {
	if (count > 100) Count = 100;
	else Count = count;
	for (int i = 0; i < Count; i++) {
		Numere[i] = lista[i];
	}
}

int Multime::Max() {
	int temp = Numere[0];
	for (int i = 1; i < Count; i++) {
		if (Numere[i] > temp)
			temp = Numere[i];
	}
	return temp;
}

int Multime::Min() {
	int temp = Numere[0];
	for (int i = 1; i < Count; i++) {
		if (Numere[i] < temp)
			temp = Numere[i];
	}
	return temp;
}

int Multime::operator[](int index) {
	return Numere[index];
}

Multime operator& (Multime& m1, Multime& m2) {
	int v[100];
	int contor=0;

	for (int i = 0; i < m1.GetSize(); i++) {
		for (int j = 0; j < m2.GetSize(); j++) {
			if (m1[i] == m2[j]) {
				v[contor] = m1[i];
				contor++;
			}
		}
	}
	return Multime(v, contor);
}

Multime operator| (Multime& m1, Multime &m2) {
	int v[200];
	int contor = 0;

	for (int i = 0; i < m1.GetSize(); i++) {
		bool flag = true;
		for (int j = 0; j < contor; j++)
			if (v[j] == m1[i]) flag = false;
		if (flag) {
			v[contor] = m1[i];
			contor++;
		}
	}

	for (int i = 0; i < m2.GetSize(); i++) {
		bool flag = true;
		for (int j = 0; j < contor; j++)
			if (v[j] == m2[i]) flag = false;
		if (flag) {
			v[contor] = m2[i];
			contor++;
		}
	}

	return Multime(v, contor);
}