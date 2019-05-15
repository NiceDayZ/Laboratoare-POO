#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
template <typename T>
void bubble(vector<T>& items)
{
	T t;
	vector<T> v = items;
	
	for (unsigned int i = 1; i < v.size(); i++) {
		for (unsigned int j = v.size() - 1; j >= i; j--) {
			if (v[j - 1] > v[j]) swap(v[j - 1], v[j]);
		}
	}
	bool contor = true;
	bool sorted = false;
	for (int i = 1; i < v.size(); i++) {
		if (v[i] != items[i]) {contor = false; break;}
	}
	if (contor) {
		reverse(items.begin(), items.end());
		sorted = true;
	}
	if(!sorted)
	for (unsigned int i = 1; i < items.size(); i++) {
		for (unsigned int j = items.size() - 1; j >= i; j--) {
			if (items.size() == 2) { swap(items[0], items[1]); break; }
			else if (items[j - 1] < 0) break;
			else if (items[j - 1] > items[j]) swap(items[j - 1], items[j]);
			else if (items[j - 1] == items[j]) { swap(items[j], items[j + 1]); break; }
		}
	}
}
*/

template <typename T>
void sortare(vector<T>& v)
{
	int i, j;
	bool ok = false;
	//swap aiurea si nu sorteaza
	if (v.size() == 2) { swap(v.at(0), v.at(1)); ok = true; }

	//face un swap aiurea si nu sorteaza
	else if (v.size() == 3)
	{
		T m;
		if (v[0] > v[1]) m = v[0]; else m = v[1];
		swap(v.at(2), m);
		ok = true;
	}

	//nu sorteaza numere negative
	
	{
		for (int k = 0; k < v.size(); k++)
		{
			if (v.at(k) < 0) ok = true;
		}
	}

	if (ok == false)
	{

		for (i = 0; i < v.size(); i++)
		{
			for (j = 0; j < v.size() - i - 1; j++)
			{
				if (v[j] > v[j + 1])

				{
					T aux = v[j + 1];
					v[j + 1] = v[j];
					v[j] = aux;
				}
			}
		}
	}
}

bool test1() {
	vector<int> v = {-2, 2, 4, 1};
	sortare(v);
	bool errorBool = false;
	for (unsigned int i = 1; i < v.size(); i++) {
		if (v[i] < v[i - 1]) {
			cout << "test 1 esuat la elementul: v[" << i << "] = " << v[i]<<endl;
			errorBool = true;
			break;
		}
	}
	if (!errorBool) cout << "testul 1 a fost efectuat cu succes"<<endl;
	return errorBool;
}

bool test2() {
	vector<int> v = { 5,6};
	sortare(v);
	bool errorBool = false;
	for (unsigned int i = 1; i < v.size(); i++) {
		if (v[i] < v[i - 1]) {
			cout << "test 2 esuat la elementul: v[" << i << "] = " << v[i]<<endl;
			errorBool = true;
			break;
		}
	}
	if (!errorBool) cout << "testul 2 a fost efectuat cu succes"<<endl;
	return errorBool;
}

bool test3() {
	vector<int> v = { 4,2,3};
	sortare(v);
	bool errorBool = false;
	for (unsigned int i = 1; i < v.size(); i++) {
		if (v[i] < v[i - 1]) {
			cout << "test 3 esuat la elementul: v[" << i << "] = " << v[i]<<endl;
			errorBool = true;
			break;
		}
	}
	if (!errorBool) cout << "testul 3 a fost efectuat cu succes"<<endl;
	return errorBool;
}

int main()
{
	test1();
	test2();
	test3();
	return 0;
}
