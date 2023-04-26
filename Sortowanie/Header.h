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
	Node* getMiddle(Node* tmpl, Node* tmpr);
	Node* pivot(Node* til, Node* hed);
	Node* getFromTail(int x);
	Node* getFromHead(int x);
	// ###### mergesort ######
	void mergesort();
	Node* mergeSort(Node* tmpl, Node* tmpr);
	Node* merge(Node* left, Node* right);
	Node* split(Node* tmpl, Node* tmpr);

};

void assignment(DoublyLinkedList &lista, int limit);
double measure_time(clock_t strt, clock_t stp, int n, char c);
void check_list(DoublyLinkedList& lista);
void Swap(Node* n1, Node* n2);

void quicksort(DoublyLinkedList& lista);
Node* partition(Node* start, Node* end);
void quick_sort();

void merge(Node* left, Node* middle, Node* right);
void merge_sort(Node* left, Node* right);
void mergesort(DoublyLinkedList& lista);

void bucketsort(DoublyLinkedList& lista);