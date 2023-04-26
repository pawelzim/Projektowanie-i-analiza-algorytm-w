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
	Node* getFromTail(int x);
	Node* getFromHead(int x);
};

void assignment(DoublyLinkedList &lista, int limit);
double measure_time(clock_t strt, clock_t stp, int n, char c);
void check_list(DoublyLinkedList& lista);
void Swap(Node* n1, Node* n2);

void quicksort(DoublyLinkedList& lista);
Node* partition(Node* start, Node* end);
void quick_sort(Node* head, Node* tail);

void mergesort(DoublyLinkedList& lista);
void merge_sort(Node* left, Node* right);
void merge(Node* left, Node* middle, Node* right);

void bucketsort(DoublyLinkedList& lista);