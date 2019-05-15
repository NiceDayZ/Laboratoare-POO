#include <iostream>
#include <exception>
using namespace std;

class exceptie1 : public exception
{
	virtual const char* what() const throw()
	{
		return "Impartire la 0!";
	}
};

class exceptie2 : public exception
{
	virtual const char* what() const throw()
	{
		return "Indexul este inafara domeniului!";
	}
};

class Compare

{

public:

	virtual int CompareElements(void* e1, void* e2) = 0;

};

class CompCrescator : public Compare
{
	int CompareElements(void* e1, void* e2) {
		int* x = (int*)e1;
		int* y = (int*)e2;
		if (*x == *y)
			return 0;
		if (*x > *y)
			return 1;
		else return -1;
	}
};


template<class T>
class ArrayIterator {
public:
	T** Current;
	ArrayIterator() {
		Current = 0;
	}
	~ArrayIterator() {
		Current = 0;
	}
	ArrayIterator& operator ++ () {
		++Current;
		return *this;
	}
	ArrayIterator& operator -- () {
		--Current;
		return *this;
	}
	bool operator = (ArrayIterator<T>& Iterator) {
		return Current == Iterator.Current;
	}
	bool operator != (ArrayIterator<T>& Iterator) {
		return Current != Iterator.Current + 1;
	}
	T operator * () {
		return **Current;
	}
	T* GetElement() {
		return Current;
	}
};

template<class T>

class Array

{

private:

	T** List; // lista cu pointeri la obiecte de tipul T*

	int Capacity; // dimensiunea listei de pointeri

	int Size; // cate elemente sunt in lista

public:

	Array() {
		Size = 0;
		Capacity = 0;
		List = nullptr;
	}// Lista nu e alocata, Capacity si Size = 0

	~Array() {
		delete[] List;
	}// destructor

	Array(int capacity) {
		Size = 0;
		Capacity = capacity;
		List = new T * [Capacity];
	}// Lista e alocata cu 'capacity' elemente

	Array(const Array<T>& otherArray) {
		Capacity = otherArray.GetCapacity();
		Size = otherArray.GetSize();

		for (int i = 0; i < otherArray.GetSize; i++) {
			List[i] = otherArray[i];
		}
	}// constructor de copiere



	T& operator[] (int index) {
		exceptie2 index_out_of_bound;

		try {
			if (index > Size - 1 || index<0) throw index_out_of_bound;
			return *(List[index]);
		}
		catch (exception& e) {
			cout << "Exceptie: " << e.what() << endl;
		}

	}// arunca exceptie daca index este out of range



	const Array<T>& operator+=(const T& newElem) {
		if (Size < Capacity) {
			T** newList = new T*[Size+1];
			newList = List;
			newList[Size] = new T;
			*newList[Size++] = newElem;
			List = newList;
		}
		
		return *this;
	}// adauga un element de tipul T la sfarsitul listei si returneaza this

	const Array<T>& Insert(int index, const T& newElem) {
		exceptie2 index_out_of_bound;

		try {
			if (index > Size || index < 0) throw index_out_of_bound;
			T** newList = new T * [Size];
			newList = List;
			newList[Size] = new T;
			for (int i = Size; i > index; i--) {
				*newList[i] = *newList[i - 1];
			}
			*newList[index] = newElem;
			List = newList;
			Size++;
			
		}
		catch (exception& e) {
			cout << "Exceptie: " << e.what() << endl;
		}

		return*this;

	}// adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie

	
	const Array<T>& Insert(int index, Array<T> &otherArray) {
		exceptie2 index_out_of_bound;
		try {
			if (index > Size || index < 0) throw index_out_of_bound;
			for (int i = 0; i < otherArray.GetSize(); i++) {
				Insert(index + i, otherArray[i]);
			}
		}
		catch (exception& e) {
			cout << "Exceptie: " << e.what() << endl;
		}
		return*this;
	}// adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	
	const Array<T>& Delete(int index) {
		exceptie2 index_out_of_bound;

		try {
			if (index > Size-1 || index < 0) throw index_out_of_bound;
			
			for (int i = index; i < Size-1; i++) {
				*List[i] = *List[i + 1];
			}
			
			Size--;

		}
		catch (exception& e) {
			cout << "Exceptie: " << e.what() << endl;
		}

		return*this;

	
	}// sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie

	

	bool operator=(const Array<T>& otherArray) {
		Capacity = otherArray.GetCapacity();
		Size = otherArray.GetSize();
		List = otherArray.List;
	}

		

	void Sort() {
		T t;
		for (int a = 1; a < Size; a++)
			for (int b = Size - 1; b >= a; b--)
				if (*List[b - 1] > *List[b]) {
					t = *List[b - 1];
					*List[b - 1] = *List[b];
					*List[b] = t;
		}
	}// sorteaza folosind comparatia intre elementele din T

		
	void Sort(int(*compare)(const T&, const T&)) {
		T t;
		for (int a = 1; a < Size; a++)
			for (int b = Size - 1; b >= a; b--)
				if (compare(*List[b - 1], *List[b]) == 1) {
					t = *List[b - 1];
					*List[b - 1] = *List[b];
					*List[b] = t;
				}
	}// sorteaza folosind o functie de comparatie

	
	void Sort(Compare* comparator) {
		T t;
		for (int a = 1; a < Size; a++)
			for (int b = Size - 1; b >= a; b--)
				if (comparator->CompareElements(List[b - 1], List[b]) == 1) {
					t = *List[b - 1];
					*List[b - 1] = *List[b];
					*List[b] = t;
				}
	}// sorteaza folosind un obiect de comparatie

	

	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
	
	int BinarySearch(const T& elem) {
		
			
			int low = 0, high = Size;
			
			while (low <= high)
			{

				int mid = (low + high) / 2;

				if (elem == *List[mid])
					return mid;

				else if (elem < *List[mid])
					high = mid - 1;

				else
					low = mid + 1;


			}
			return -1;
		
	}// cauta un element folosind binary search in Array
	
	int BinarySearch(const T& elem, int(*compare)(const T&, const T&)) {
		int low = 0, high = Size;

		while (low <= high)
		{

			int mid = (low + high) / 2;

			if (compare(elem, *List[mid])==0)
				return mid;

			else if (compare(elem, *List[mid])==-1)
				high = mid - 1;

			else
				low = mid + 1;


		}
		return -1;
	}//  cauta un element folosind binary search si o functie de comparatie

	int BinarySearch(const T& elem, Compare* comparator) {
		int low = 0, high = Size;

		while (low <= high)
		{

			int mid = (low + high) / 2;

			if (comparator->CompareElements((T*)& elem, List[mid]) == 0)
				return mid;

			else if (comparator->CompareElements((T*)& elem, List[mid]) == -1)
				high = mid - 1;

			else
				low = mid + 1;


		}
		return -1;
	}	//cauta un element folosind binary search si un comparator

	

	int Find(const T& elem){
		for (int i = 0; i < Size; i++) {
			if (List[i] == elem)
				return i;
		}
		return -1;
	}// cauta un element in Array

	int Find(const T& elem, int(*compare)(const T&, const T&)) {
		for (int i = 0; i < Size; i++) {
			if (compare(*List[i] , elem)==0)
				return i;
		}
		return -1;
	}//  cauta un element folosind o functie de comparatie

	int Find(const T& elem, Compare* comparator) {
		for (int i = 0; i < Size; i++) {
			if (comparator->CompareElements(List[i], (T*)& elem)==0)
				return i;
		}
		return -1;
	}//  cauta un element folosind un comparator
	
	

	int GetSize() {
		return Size;
	}
	
	int GetCapacity() {
		return Capacity;
	}
	


	ArrayIterator<T> begin(){
		ArrayIterator<T> Iterator;
		Iterator.Current = &List[0];
		return Iterator;
	}

	ArrayIterator<T> end() {
		ArrayIterator<T> Iterator;
		Iterator.Current = &List[Size-1];
		return Iterator;
	}

};


int compCresc(const int &x,const int &y)
{
	if (x == y)
		return 0;
	if (x > y)
		return 1;
	else return -1;
}

int main()
{
	Array<int> arr(20);
	arr += 4;
	arr += 3;
	arr.Insert(0, 10);
	arr.Insert(1, 15);

	for (auto it : arr) {
		cout << it << ' ';
	}

	cout << " += si insert an element\n";

	
	Array<int> arr2(3);
	arr2 += 23;
	arr2 += 9;

	arr.Insert(4, arr2);
	
	for (auto it : arr) {
		cout << it << ' ';
	}
	cout << " insert another Array\n";

	arr.Delete(2);

	for (auto it : arr) {
		cout << it << ' ';
	}
	cout << " Delete(2)\n";
	
	arr.Sort(compCresc);

	for (auto it : arr) {
		cout << it << ' ';
	}
	cout << " Sort(compareFunction)\n";

	CompCrescator comp;
	cout << arr.Find(23, &comp);

	cout << " Find(23)\n";


	
}

