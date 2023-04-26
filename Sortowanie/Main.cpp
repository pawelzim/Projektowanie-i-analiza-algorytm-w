#include <iostream>
#include <list>
#include <string>
#include <ctime>
#include "Header.h"

using namespace std;

// TAIL (poczatek) -> HEAD (koniec)

int main() {

	// 10k, 100k, 250k, 500k (wszystkie elementy)

	DoublyLinkedList lista;
	assignment(lista, 500000);
	////lista.display(0, 19);
	//cout << "--------------" << endl;
	clock_t start = clock();
	bucketsort(lista);
	clock_t stop = clock();
	////lista.display(0, 19);
	cout << measure_time(start, stop, lista.size(), 'b') << endl;
	check_list(lista);


	return 0;
}