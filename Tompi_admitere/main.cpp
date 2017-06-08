#include <iostream>
#include <fstream>

/*
N- nr de prieteni pe fb
M relatii de forma (i,j) unde i,j din [1,N] , graf orientat => (i,j) = (j,i)
*/

//typedef nod* pointer_nod ; //mereu inainte de struct :* 

typedef struct nod {
	int numar;	
	int nr_prieteni; 
	nod* urm; //legatura la urm nod :) 
};

typedef nod* pointer_nod;

//pt prima cerinta ai nevoie de lista inlantuita cu adaugare in ordice a rangurilor...
void adaugare_lista(nod* &first, int prieten) {

	pointer_nod iterator = first;

	pointer_nod prieten_nod = new nod;
		prieten_nod->nr_prieteni = 1;
		prieten_nod->numar = prieten;
		prieten_nod->urm = NULL;

	if (iterator == NULL) {
		iterator = prieten_nod;
		return;
	}

	while (iterator ->urm!= NULL && iterator->urm->numar >prieten) { 
		
		if (iterator->numar == prieten) {
			iterator->nr_prieteni++;
			return; // ne oprim daca am gasit element in lista
		}
		iterator = iterator->urm;
	}

	prieten_nod->urm = iterator->urm;
	iterator->urm = prieten_nod;

}

using namespace std;

void citire_date(int &N, int &M, int &K, pointer_nod & first) {

	ifstream f("input.txt");
	f >> N >> M >> K;

	int a, b;

	while (f >> a >> b) {
		adaugare_lista(first,a);
		adaugare_lista(first, b);
	}

	f.close();
	
}

void cerinta_1(pointer_nod & first) {
	ofstream g("cerinta1.txt");
	pointer_nod iterator = first;
	while (iterator != NULL) {
		cout << "da";
		g << iterator->nr_prieteni << " ";
	}
	g.close();
}

int main() {
	int N, M, K;
	pointer_nod first = NULL;
	citire_date(N, M, K, first);
	cerinta_1(first);
	int x;
	cin >> x;
}