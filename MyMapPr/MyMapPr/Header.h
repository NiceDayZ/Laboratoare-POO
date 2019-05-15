#pragma once

#include <string>
#include <initializer_list>
using namespace std;

template <typename T>
class MyMap {
public:
	
	pair<string, T> values[1000];
	int Contor;

	MyMap(initializer_list<pair<string, T>> list);
	MyMap();
	T operator[](string ceva);

	pair<string, T>* begin();
	pair<string, T>* end();

	virtual operator int();

	bool Add(string, T);
	bool Delete(string);

	template<T> friend MyMap<T> operator&(MyMap<T>,MyMap<T>);
	template<T> friend MyMap<T> operator|(MyMap<T>, MyMap<T>);

};





template<typename T>
inline MyMap<T>::MyMap(initializer_list<pair<string, T>> list)
{
	typename initializer_list<pair<string, T>>::iterator iteratorList;
	Contor = 0;
	int i = 0;
	for (iteratorList = list.begin(); iteratorList != list.end(); iteratorList++) {
		values[i].first = iteratorList->first;
		values[i].second = iteratorList->second;
		i++;
		Contor++;
	}
}

template<typename T>
inline MyMap<T>::MyMap()
{
	Contor = 0;
}



template<typename T>
inline T MyMap<T>::operator[](string ceva)
{
	for (int i = 0; i < Contor; i++) {
		if (values[i].first == ceva)
			return values[i].second;
	}
	

}

template<typename T>
inline pair<string, T>* MyMap<T>::begin()
{
	return &values[0];
}

template<typename T>
inline pair<string, T>* MyMap<T>::end()
{
	return &values[Contor];
}


template<typename T>
inline MyMap<T>::operator int()
{
	return Contor;
}

template<typename T>
inline bool MyMap<T>::Add(string nume, T value)
{
	for (int i = 0; i < Contor; i++) {
		if (values[i].first == nume) {
			if (values[i].second < value) {
				values[i].second = value;
				return true;
			}
			return false;
		}
	}

	values[Contor].first = nume;
	values[Contor].second = value;
	Contor++;
	return true;
}

template<typename T>
inline bool MyMap<T>::Delete(string nume)
{
	for (int i = 0; i < Contor; i++) {
		if (values[i].first == nume) {
			for (int j = i; j < Contor; j++) {
				values[j] = values[j + 1];
			}
			Contor--;
			return true;
		}
	}

	return false;
}

template<typename T>
MyMap<T> operator&(MyMap<T> mapi, MyMap<T> mapi2) {
	MyMap<T> ceva = mapi2;
	for (int i = 0; i < (int)mapi; i++) {
		ceva.Add(mapi.values[i].first, mapi.values[i].second);
	}
	
	return ceva;
}

template<typename T>
MyMap<T> operator|(MyMap<T> mapi, MyMap<T> mapi2) {
	MyMap<T> ceva({});
	int k = 0;
	for(int i = 0; i<(int) mapi; i++)
		for (int j = 0; j < (int)mapi2; j++) {
			if (mapi.values[i].first == mapi2.values[j].first) {
				if (mapi.values[i].second > mapi2.values[j].second) {
					ceva.Add(mapi.values[i].first, mapi.values[i].second);
					break;
				}
				else {
					ceva.Add(mapi2.values[i].first, mapi2.values[i].second);
					break;
				}
			}
		}
	return ceva;
}





/*
supraîncărcați operatorul & folosind funcții friend pentru a permite sa uniți doua map-uri. 
Dacă exista elemente cu aceeași cheie în map, se păstrează elementul cu valoarea cea mai mare 
(implică faptul că operatorul > există definit în tipul T). In exemplu pe care îl veți face pentru 
a ilustra acest lucru, creați și o structura în care supraîncărcați acest operator.


supraîncărcați operatorul | folosind funcții friend pentru a permite sa obțineți un map care 
conține doar elementele cu aceeași cheie din doua map-uri. In acest caz se păstrează elementul cu
valoarea cea mai mare (implică că operatorul > există definit în tipul T). In exemplu pe care îl veți
face pentru a ilustra acest lucru, creați și o structura în care supraîncărcați acest operator.
*/
