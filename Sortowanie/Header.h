#include <iostream>

using namespace std;

// TAIL (poczatek) -> HEAD (koniec)

struct Node {
	int index;
	string name;
	float rate;
	Node* next;
	Node* previous;
};

class DoublyLinkedList {
private:
	Node* head;
	Node* tail;
	int counter;
public:
	DoublyLinkedList();
	void newHead(int ind, string nm, float rt);
	void popHead();
	void newTail(int ind, string nm, float rt);
	void popTail();
	void display(int start, int end);
	int size();
	// metody pod sortowanie
	void swap(Node* n1, Node* n2);
	Node* pivot(Node* til, Node* hed);
	Node* getFromTail(int x);
	Node* getFromHead(int x);
};

void assignment(DoublyLinkedList &lista, int limit);
double measure_time(clock_t strt, clock_t stp);

void quicksort(DoublyLinkedList& lista, char c);
void quicksort_a(DoublyLinkedList &l1, int left, int right);
void quicksort_b(DoublyLinkedList &l1, int left, int right);

void mergesort_main(DoublyLinkedList& lista, char c);
void mergesort(DoublyLinkedList& lista, int left, int right, char c);
void merge_a(DoublyLinkedList& lista, int left, int middle, int right);
void merge_b(DoublyLinkedList& lista, int left, int middle, int right);
void merge_roboczy(DoublyLinkedList& lista, int left, int middle, int right);


void bucketsort(DoublyLinkedList& lista);