#include <iostream>
#include <list>
#include <string>
#include <ctime>
#include "Header.h"

using namespace std;

// TAIL (poczatek) -> HEAD (koniec)

int main() {
	DoublyLinkedList lista1, lista2;


	assignment(lista1, 1000);
	clock_t start123 = clock();
	mergesort_main(lista1, 'c');
	clock_t stop123 = clock();
	lista1.display(900, 930);
	
	//bucketsort(lista1);

	//lista1.display(380000, 380500);
	cout << measure_time(start123, stop123) << endl;

	//assignment(lista2, 50000);


	//clock_t start1 = clock();
	//mergesort_main(lista1, 'a');
	//clock_t stop1 = clock();

	/*clock_t start2 = clock();
	mergesort_main(lista2, 'b');
	clock_t stop2 = clock();*/

	//cout << "--------------------" << endl;
	//cout << "Mergesort_a: " << measure_time(start1, stop1) << endl;

	//cout << "--------------------" << endl;
	//cout << "Mergesort_b: " << measure_time(start2, stop2) << endl;
	//cout << "--------------------" << endl;

	//clock_t start2 = clock();
	//quicksort(lista2, 'b');
	//clock_t stop2 = clock();
	////lista2.display(0, 9);

	//cout << "Quicksort_b: " << measure_time(start2, stop2) << endl;

	/*DoublyLinkedList l1;
	assignment(l1, 10);
	l1.display(0, 9);
	cout << "--------------------" << endl;
	cout << l1.getFromHead(1)->name << endl;
	cout << l1.getFromTail(1)->name << endl;*/


	return 0;
}