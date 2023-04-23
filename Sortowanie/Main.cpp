#include <iostream>
#include <list>
#include <string>
#include <ctime>
#include "Header.h"

using namespace std;

// TAIL (poczatek) -> HEAD (koniec)

int main() {
	DoublyLinkedList lista1, lista2;

	// ---------MERGESORT----------
	// dla 20k elementow: 0.834, 0.796, 0.893
	// dla 35k elementow: 2.206, 2.283, 2.255
	// dla 400k elementow: 1390.89

	assignment(lista1, 8);
	clock_t start123 = clock();
	mergesort_main(lista1);
	clock_t stop123 = clock();
	
	lista1.display(0, 9);
	checkList(lista1);
	cout << measure_time(start123, stop123, lista1.size(), 'm') << endl;


	return 0;
}