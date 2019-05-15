// ConsoleApplication9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <functional>


template <class T>
int partionate(std::vector<T>&lista, int low, int high, std::function<int(T&, T&)> Compare){
	T pivot = lista[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (Compare(lista[j], pivot) == 1 || Compare(lista[j], pivot) == 0)
		{
			i++;
			T var = lista[j];
			lista[j] = lista[i];
			lista[i] = var;
		}
	}
	T var = lista[i + 1];
	lista[i + 1] = lista[high];
	lista[high] = var;
	return (i + 1);

}

template <class T>
void quickSort(std::vector<T>&lista, int low, int high, std::function<int(T&, T&)> Compare){
	if (low < high)
	{
		int mid = partionate(lista, low, high, Compare);
		quickSort<T>(lista, low, mid - 1, Compare);
		quickSort<T>(lista, mid + 1, high, Compare);
	}
}

template<class T>
void Sort(std::vector<T>&lista, std::function<int(T&, T&)> Compare){
	quickSort<T>(lista, 0, lista.size() - 1, Compare);
}

int main()
{
	std::vector<int> ls = {9,2,5,12,3,6,7,22,5};
	
	
	Sort<int>(ls , [](int &e1, int &e2)->int {if (e1 < e2)return 1; else return -1; return 0; });

	for (int i : ls) {
		std::cout << i << " ";
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
