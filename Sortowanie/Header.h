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
	void swap(Node* tmp1, Node* tmp2);
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

void quicksort(DoublyLinkedList& lista, char c);
void quicksort_a(DoublyLinkedList &l1, int left, int right);
void quicksort_b(DoublyLinkedList &l1, int left, int right);

void merge(DoublyLinkedList& dll, Node* left, Node* mid, Node* right);
void merge_sort(DoublyLinkedList& dll, Node* left, Node* right);
void mergesort(DoublyLinkedList& dll);

void bucketsort(DoublyLinkedList& lista);