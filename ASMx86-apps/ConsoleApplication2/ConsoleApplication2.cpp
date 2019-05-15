// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;



int fibbo(int) {
	//Fibbo recursiv
	_asm {
		mov ecx, [ebp+8]
		cmp ecx, 1
		jbe _final
		
		
		//fibbo(n-1) + fibbo(n-2)
		sub ecx, 1
		push ecx
		call fibbo
		mov ebx, eax
		add esp, 4
		

		mov ecx, [ebp+8]
		sub ecx, 2
		push ecx
		call fibbo
		add eax, ebx
		add esp, 4

		jmp _final2

		_final:
		mov eax, 1

		_final2:
	}
}


int adunare(int, int) {
	//neimportant teste cu stiva
	_asm {
		push 3 //c
		push 6 //d
		

		cmp [esp+4], 15

		jb _maimic

		mov eax, 0
		add eax, [ebp + 8]
		add eax, [ebp + 12]
		add eax, [esp + 4]
		add eax, [esp]
		jmp _final


		_maimic:
			mov eax, 0
			add eax, [ebp + 8]
			add eax, [ebp + 12]
			add eax, [esp + 4]
			sub eax, [esp]
			jmp _final
			
		_final:
		add esp, 8
	}
}

int vectori(int *v,int n) {
	_asm {
		//suma elementelor pare dintr-un vector
		mov edi, [ebp + 8]
		mov ecx, [ebp + 12]
		mov eax, 0
		


		_myloop:
			test [edi], 1
			jnz _odd
			add eax, [edi]
			
			_odd:
			add edi, 4
			loop _myloop

	}
}



int vocale(char *p) {
	_asm {
		//numarul de litere 'a' dintr-un sir de caractere
		mov edi, [ebp + 8]
		mov eax, 0
		cmp [edi], 0
		jne _while
		jmp _final
		
		_while:
			cmp [edi], 'a';
			je _vocala
			jmp _cons
			
			_vocala:
				inc eax
			_cons:
			add edi, 1
			cmp [edi], 0
			jne _while
		_final:
	}
}

int matrice(int *p, int c) {
	_asm{
		mov esi, [ebp + 12]
		mov ebx, [ebp + 8]

		push 2
		push 4

		mov eax, 1
		mul [esp + 4]
		mul ebx
		mul [esp]
		add esi, eax
		mov eax, 1
		mul [esp + 4]
		mul [esp]

		add esi, eax
		mov eax, [esi]

		add esp, 8
	}
}

void suma_matrice_statice(int *, int *, int)
{
	// A = A + B
	_asm
	{
		//A
		mov edi, [ebp + 8]
		//B
		mov esi, [ebp + 12]
		//size
		mov ecx, [ebp + 16]
		// Suma pozitie cu pozitie de n^2 ori
		mov eax, [ebp + 16]
		mov edx, 0
		mov ebx, [ebp + 16]
		mul ebx
		mov ecx, eax

		_myloop :
		mov ebx, [esi]
			add[edi], ebx
			add esi, 4
			add edi, 4
			loop _myloop

	}
}

struct Str1 {
	char c;
	short s;
	int i;
};


void generate(char c, short s, int i, Str1* x)
{
	//generarea unei structuri
	_asm {
		//esi e adresa structurii.
		mov esi, [ebp + 20]
		//in eax punem c. Folosim 4 bytes pentru ca stiva e aliniata.
		mov eax, [ebp + 8]
		//Doar ultimul byte din cei 4 din eax contin c. Il punem in [esi+0]
		mov[esi], al

		//La fel, doar ca vom lua ultimii 2 bytes.
		mov eax, [ebp + 12]
		mov[esi + 2], ax

		//Aici ii punem pe toti 4. Nu conteaza ce returnam in eax.
		mov eax, [ebp + 16]
		mov[esi + 4], eax
	}
}

int prim(int) {
	//verifica daca un numar este prim
	_asm {
		mov ebx, 2
		mov eax, [ebp+8]
		mov edx, 0
		div ebx
		mov ecx, eax
		cmp ecx, 0
		je _notprim

		_myloop:
			cmp ecx, 1
			je _prim

			mov eax, [ebp+8]
			mov edx, 0
			div ecx
			cmp edx, 0
			je _notprim
		loop _myloop

		_prim:
			mov eax, 1
			jmp _final

		_notprim :
			mov eax, 0
		_final :
	}

	

}

int problema_matrice(int, int *) {
	//returneaza o matrice care contine:
	//1 daca numarul este par
	//2 daca numarul este prim (consideram 2 prim)
	//3 in alte cazuri
	int doi = 2, unu = 1;
	_asm {
		mov esi, [ebp + 12]
		mov ecx, 0
		mov ebx, [ebp+8]
		mov eax, ebx
		mul eax
		mov ebx, eax
		mov edi, [ebp+8]


		_while:
			cmp ecx, 0
			je _caz_particular
			mov eax, ecx
			mov edx, 0
			div edi
			add edx, eax

			push ebx
			push ecx


			push edx
			call prim
			add esp, 4


			cmp eax, 1
			je _prim
				test edx, 1
				jz _par

				mov edx, 3
				mov [esi], edx
				add esi, 4
				jmp _final_while

				_par:
					mov edx, 1
					mov[esi], edx
					add esi, 4

			

			jmp _final_while

			_prim:
			mov edx, 2
			mov [esi], edx
			add esi, 4

		_final_while:
		mov ecx, [esp]
		mov ebx, [esp + 4]
		add esp, 8
		inc ecx
		cmp ecx, ebx
		jne _while
		jmp _gata

		_caz_particular:
			mov edx, 1
			mov [esi], edx
			add esi, 4
			inc ecx
			jmp _while

		_gata:
	}
}

struct counter{
	short numarCifre;
	char numarLitere;
	int total;
};

int counterFunction(char *, counter* str1) {
	_asm {
		//creaza o structura ce contine numarul de cifre, litere si totalul lor dintr-un sir de caractere
		mov esi, [ebp + 8] //char vector
		mov edi, [ebp + 12] //struct

		_while:
		movzx eax, [esi]
		cmp eax, '9'
		jbe _cifra_poate

		cmp eax, 'z'
		jbe _litera_poate

		_litera_poate:
			cmp eax, 'A'
			jae _litera_sigur
			jmp _final_while

			_litera_sigur:
			mov al, [edi + 2]
			inc al
			mov[edi + 2], al;
			jmp _final_while

		_cifra_poate:
			cmp eax, '1'
			jae _cifra_sigur
			jmp _final_while

			_cifra_sigur:
			mov ax, [edi]
			inc ax
			mov [edi], ax

		_final_while:
		add esi, 1
		cmp[esi], '0';
		jne _while

			movzx eax, word ptr[edi];
			movzx ebx, byte ptr[edi+2]
			add eax, ebx
			mov [edi+4], eax
	}
}



int bubble_sort(int, int *) {
	//bubble sort...
	_asm {
	
		
		_while :
			mov ecx, 1
			mov edx, 0
			mov edi, [ebp + 12]
			_for:
				mov eax, [edi]
				mov ebx, [edi+4]
				cmp eax, ebx
				ja _interschimba
				jmp _final_for
				_interschimba :
					mov [edi], ebx
					mov [edi+4], eax
					mov edx, 1
			_final_for :
				add edi, 4
				inc ecx
				cmp ecx, [ebp+8]
				jne _for
				cmp edx, 0
			jne _while
	}
}

int ic(int *, int, int *, int, int *) {
	//interclasarea a 2 vectori
	_asm {
		mov edi, [ebp + 8]
		mov esi, [ebp + 16]
		mov edx, [ebp + 24]
		push 0 //i [esp + 4]
		push 0 //j [esp]

		_while:
			mov eax, [edi]
			mov ebx, [esi]

			cmp eax, ebx
			jb _if
			jmp _else
			
			_if:
				mov [edx], eax
				add edx, 4
				add edi, 4
				mov ecx, [esp + 4]
				mov eax, [esp]
				inc ecx
				add esp, 8
				push ecx
				push eax
				jmp _final_if

			_else:
				mov [edx], ebx
				add edx, 4
				add esi, 4
				mov ecx, [esp]
				mov eax, [esp + 4]
				inc ecx
				add esp, 8
				push eax
				push ecx

				jmp _final_if

			_final_if:

		mov ecx, [esp + 4] 
		cmp ecx, [ebp + 12]
			jb _prima_conditie
			jb _end_while

			_prima_conditie:
				mov ecx, [esp]
				cmp ecx, [ebp + 20]
					jb _while
		_end_while:
		
		mov ecx, [esp + 4]
		cmp ecx, [ebp + 12]
			jb _if_i
			jmp _end_if_i

			_if_i:
				_for:
					mov eax, [edi]
					mov [edx], eax
					add edi, 4
					add edx, 4
					inc ecx
				cmp ecx, [ebp + 12]
				jb _for
			_end_if_i:

		mov ecx, [esp]
		cmp ecx, [ebp + 20]
			jb _if_j
			jmp _end_if_j

			_if_j:
				_forfinal:
					mov eax, [esi]
					mov [edx], eax
					add esi, 4
					add edx, 4
					inc ecx
				cmp ecx, [ebp + 20]
				jb _forfinal
			_end_if_j:
		add esp, 8
	}
}
struct rect {
	int x, y; //coltul stanga jos
	int width; //latime
	int height; //lungime
};

int intersectie(rect *, rect *) {
	//se dau 2 dreptunghiuri prin structura de mai sus
	//returneaza 1 daca primul dreptunghi este inclus in al doilea
	// 2 daca al doilea este inclus in primul
	// 0 daca nu se indeplineste nicio conditie de mai sus
	_asm {
		mov esi, [ebp + 8]
		mov edi, [ebp + 12]

		mov eax, dword ptr [esi] // x d1
		mov ebx, dword ptr [edi]// x d2
		mov ecx, dword ptr [esi + 8] // w d1
		mov edx, dword ptr [edi + 8] // w d2


		cmp eax, ebx
			jb _caz1
			jmp _caz2

		_caz1:
			add eax, ecx // x2 d1
			add ebx, edx // x2 d2
			cmp eax, ebx
			ja _caz11
			jmp _caz0
			
			_caz11:
				mov eax, dword ptr [esi + 4] // y d1
				mov ebx, dword ptr [edi + 4] // y d2
				mov ecx, dword ptr [esi + 12]// h d1
				mov edx, dword ptr [edi + 12]// h d2
				
				cmp eax, ebx
				jb _caz111
				jmp _caz0
				_caz111:
					add eax, ecx // y2 d1
					add ebx, edx // y2 d2
					cmp eax, ebx
					ja _raspuns1
					jmp _caz0

		_caz2:
			add eax, ecx // x2 d1
			add ebx, edx // x2 d2
			cmp eax, ebx
			jb _caz22
			jmp _caz0
			
			_caz22:
				mov eax, dword ptr [esi + 4] // y d1
				mov ebx, dword ptr [edi + 4] // y d2
				mov ecx, dword ptr [esi + 12]// h d1
				mov edx, dword ptr [edi + 12]// h d2
				
				cmp eax, ebx
				ja _caz222
				jmp _caz0
				_caz222:
					add eax, ecx // y2 d1
					add ebx, edx // y2 d2
					cmp eax, ebx
					jb _raspuns2
					jmp _caz0
		
		_caz0:
			mov eax, 0
			jmp _final
		_raspuns1:
			mov eax, 1
			jmp _final
		_raspuns2:
			mov eax, 2
		_final:
	}
}

int verificaVocala(char) {
	//returneaza daca caracterul este o vocala sau consoana
	//(se considera consoana tot ce nu e vocala)
	_asm {
		push 'a'//0
		push 'A'//4
		push 'e'//8
		push 'E'//12
		push 'i'//16
		push 'I'//20
		push 'o'//24
		push 'O'//28
		push 'u'//32
		push 'U'//36

		mov bl, [ebp + 8]
		mov ecx, 10
		mov esi, 4

		_loop:
			mov eax, ecx
			mul esi
			sub eax, 4
			cmp bl, byte ptr [esp + eax]
			je _vocala
		loop _loop

		_consoana:
			mov eax, 1
			jmp _final

		_vocala:
			mov eax, 0

		_final:
		add esp, 40
	}
}

int numarVC(char *) {
	//returneaza numarul de vocale urmate de o consoana intr-un sir de caractere
	_asm {
		mov edi, [ebp + 8]
		mov esi, 0
		_while:
			
			push byte ptr [edi]
			call verificaVocala
			add esp, 4
			cmp eax, 0
			je _verificare
			jmp _final_while
			
			_verificare:
				push[edi+1]
				call verificaVocala
				add esp, 4
				cmp eax, 1
				je _poate_ok
				jmp _final_while
				_poate_ok:
					cmp[edi+1], '\0'
					jne _marire_contor
					jmp _final_while
					_marire_contor:
						inc esi

		_final_while:
			add edi, 1
			cmp[edi], '\0'
			jne _while
		mov eax, esi
	}
}

int rotire90dr(int *, int *, int) {
	//roteste o matrice 90 grade spre dreapta
	_asm {
		mov esi, [ebp + 8] // matricea creata
		mov edi, [ebp + 12] // matricea pe care o construim
		push 4
		
		mov ecx, 0;
		
		_while:
			push ecx;
			mov edx, 0
			mov eax, ecx
			mov ecx, [ebp + 16]
			div ecx // eax = i, edx=j
			mov ecx, edx // j = ecx
			mul [ebp + 16]
			add eax, ecx
			mul [esp + 4] //eax devine elementul la care am ajuns
			push eax //[esp] devine elementul la care am ajuns cu matricea pe care o construiesc
			
			mov edx, 0
			mov ecx, [esp + 4]
			mov eax, ecx
			mov ecx, [ebp + 16]
			div ecx // eax = i, edx = j
			mov ecx, eax //ecx = i
			mov eax, [ebp + 16]
			sub eax, edx
			sub eax, 1
			mul [ebp + 16]
			add eax, ecx
			mul [esp + 8]
			mov ebx, [esp]
			mov eax, [esi + eax]
			mov [edi + ebx], eax
			
			mov ecx, [esp + 4]
			add esp, 8


			inc ecx
			mov eax, [ebp + 16]
			mul eax
			cmp ecx, eax

		jb _while
		add esp, 4
	}
}

void solutii(int a, int b, int c) {
	_asm {
		mov eax, [ebp + 12] //b
		mov ebx, [ebp + 8] //a
		mov ecx, [ebp + 16] //c
		

		//calculez delta
		mul eax
		push eax
		mov eax, ebx
		mul ecx
		push 4
		mul [esp]
		add esp, 4
		
		mov ebx, eax //ebx = 4ac
		mov eax, [esp] //eax = b^2
		add esp, 4

		sub eax, ebx
		cmp eax, 0
		je _osolutie

		_douaSolutii:
			mov eax, 1
			jmp _final
		_osolutie:
			mov eax, 0

		_final:
	}
}

void afisare(int nrsol, int a, int b) {
	if (nrsol == 1)
		cout << "Ecuatia are doua solutii distincte." << endl;
	else if (nrsol == 0)
		cout << "Ecuatia are o singura solutie, care este egala cu: " << (double)-b / (a * 2) << endl;
	else
		cout << "Ecuatia nu are solutii." << endl;
}


int main()
{
	int a = 1;
	int b = -2;
	int c = 1;

	_asm {
		mov eax, c
		push eax
		mov ebx, b
		push ebx
		mov ecx, a
		push ecx

		call solutii
		add esp, 12

		push ebx
		push ecx
		push eax
		call afisare
		add esp, 12
	}



	/*
	char c[29] = "Azi am examen la arhitectura";
	int rez;
	_asm {
		lea eax, c
		push eax
		call numarVC
		add esp, 4
		mov rez, eax;
	}
	*//*
	int a[3][3]{ {1,2,3}, {4,5,6}, {7,8,9} };
	int b[3][3]{ {0,0,0}, {0,0,0}, {0,0,0} };
	int n = 3;

	_asm {
		mov eax, n
		push eax
		lea eax, b
		push eax
		lea eax, a
		push eax
		call rotire90dr
		add esp, 12
		
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << b[i][j] << ' ';
		} cout << '\n';
	}
		*/

	//cout << rez;
	/*
	rect rect1;
	rect rect2;
	int rez;
	rect1.x = 2;
	rect1.y = 3;
	rect1.width = 9;
	rect1.height = 10;

	rect2.x = 6;
	rect2.y = 5;
	rect2.width = 4;
	rect2.height = 3;

	_asm {
		lea eax, rect1
		push eax
		lea eax, rect2
		push eax
		call intersectie
		mov rez, eax
		add esp, 8
	}

	cout << rez;
	*/


	/*
	int a[5] = { 1, 3, 5, 7, 10 };
	int b[7] = { 4, 8, 9, 11,12,13,14 };
	int c[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	_asm{
		lea eax, c
		push eax
		mov eax, 7
		push eax
		lea eax, b
		push eax
		mov eax, 5
		push eax
		lea eax, a
		push eax

		call ic
		add esp, 20
	}
	for (int i = 0; i < 12; i++) {
		cout << c[i] << ' ';
	}
	*/
	/*
	_asm {
		push 5
		call fibbo
		mov rez, eax
		add esp, 4
		
	}
	*/
	/*
	_asm {
		push 5
		push 3
		call adunare
		mov rez, eax
		add esp, 8
	}
	*/
	/*
	int a, b;
	int v[5] = { 5,1,2,3,6 };
	int *p = v;
	int s;

	_asm {
		push 5
		push p
		call vectori
		mov s, eax;
		add esp, 8
		mov rez, eax
	}
	*/

	/*
	char c[5] = { 'a','b','a', 'd', 0x00 };
	char *p = c;
	int s;
	_asm {
		push p;
		call vocale
		mov s, eax
		add esp, 4
	}
	cout << s;
	*/
	/*
	int a[3][3] = { {0,1,0}, {1,0,1}, {0,1,0} };
	int b[3][3] = { {2,1,2}, {1,2,1}, {2,1,2} };

	Str1 str;
	short sh =  8;
	char c = 'c';
	int n = 3;
	_asm {
		lea eax, str
		push eax
		mov eax, n
		push eax
		movzx eax, sh
		push eax
		movzx eax, c
		push eax
		call generate
		add esp, 16
	}

	cout << str.s;
	*/

	/*
	int n[4][4] = { {0,0,0,0}, {0,0,0,0}, {0,0,0,0},{0,0,0,0 } };

	_asm {
		lea eax, n
		push eax
		push 4
		call problema_matrice

		mov rez, eax
		add esp, 8
	}
	for (int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++)
			cout << n[i][j]<<' ';
		cout << '\n';
	}
	*/

	/*
	char c[] = { 'a','1','3','4','c','f','g','3','B','0x00' };
	
	counter str;
	str.numarCifre = 0;
	str.numarLitere = 0;
	
	_asm {
		lea eax, str
		push eax
		lea eax, c
		push eax
		call counterFunction
		add esp, 8
	}

	cout <<(int) str.total;

	*/
/*
int a[7] = {1,5,2,3,9,4,10};
_asm {
	lea eax, a
	push eax
	push 7
	call bubble_sort2
	add esp, 8
}
for (int i = 0; i < 7; i++) {
	cout << a[i] << ' ';
}
*/
	//TODO: ADUNARE MATRICI
}



//test eax, 1
// jz (daca e par)

//MOVZX -> muta din o adresa pe mai putini biti in una pe mai multi
//byte ptr[str] (doar un octet)
//word ptr[str] (2 octeti)
//dword ptr[str] (4 octeti)

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. toUpper/ to Lower
//   2. Bubble sort
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
