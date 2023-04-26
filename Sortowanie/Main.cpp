#include <iostream>
#include <list>
#include <string>
#include <ctime>
#include "Header.h"

using namespace std;

// TAIL (poczatek) -> HEAD (koniec)

int main() {
	// ---------MERGESORT----------
	// dla 20k elementow: 0.834, 0.796, 0.893
	// dla 35k elementow: 2.206, 2.283, 2.255
	// dla 400k elementow: 1390.89

	DoublyLinkedList lista;
	assignment(lista, 2500);
	clock_t start = clock();
	mergesort(lista);
	clock_t stop = clock();
	//cout << measure_time(start, stop, lista.size(), 'm') << endl;
	check_list(lista);


	return 0;
}