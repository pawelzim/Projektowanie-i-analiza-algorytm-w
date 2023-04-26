#include <iostream>
#include "Header.h"

using namespace std;

// TAIL (poczatek) -> HEAD (koniec)

DoublyLinkedList::DoublyLinkedList() {
	head = nullptr;
	tail = nullptr;
	counter = 0;
}

void DoublyLinkedList::newHead(int ind, string nm, float rt) {
	Node* tmp = new Node();
	tmp->index = ind;
	tmp->name = nm;
	tmp->rate = rt;
	if (head == nullptr && tail == nullptr) {
		tmp->next = nullptr;
		tmp->previous = nullptr;
		head = tmp;
		tail = tmp;
		counter++;
		return;
	}
	tmp->next = nullptr;
	tmp->previous = head;
	head->next = tmp;
	head = tmp;
	counter++;
}

void DoublyLinkedList::popHead() {
	if (head == nullptr) {
		cout << "List is empty, cannot popHead" << endl;
		return;
	}
	Node* tmp = head;
	if (head == tail) {
		head = nullptr;
		tail = nullptr;
		delete tmp;
		counter--;
		return;
	}
	head = head->previous;
	delete tmp;
	head->next = nullptr;
	counter--;
}

void DoublyLinkedList::newTail(int ind, string nm, float rt) {
	Node* tmp = new Node();
	tmp->index = ind;
	tmp->name = nm;
	tmp->rate = rt;
	if (head == nullptr && tail == nullptr) {
		tmp->next = nullptr;
		tmp->previous = nullptr;
		head = tmp;
		tail = tmp;
		counter++;
		return;
	}
	tmp->previous = nullptr;
	tmp->next = tail;
	tail->previous = tmp;
	tail = tmp;
	counter++;
}

void DoublyLinkedList::popTail() {
	if (tail == nullptr) {
		cout << "List is empty, cannot popTail" << endl;
		return;
	}
	Node* tmp = tail;
	if (tail == head) {
		tail = nullptr;
		head = nullptr;
		delete tmp;
		counter--;
		return;
	}
	tail = tail->next;
	delete tmp;
	tail->previous = nullptr;
	counter--;
}

void DoublyLinkedList::display(int start, int end) {
	if (start > end) {
		cout << "Display error" << endl;
		return;
	}
	if (head == nullptr) {
		cout << "List is empty" << endl;
		return;
	}
	Node* tmp2 = tail;
	int pom = 0;
	while (tmp2 != nullptr && pom != start) {
		tmp2 = tmp2->next;
		pom++;
	}
	for (int i = start; i <= end; i++) {
		if (tmp2 != nullptr) {
			cout << tmp2->index << ". " << tmp2->name <<
				" ocena: " << tmp2->rate << endl;
			tmp2 = tmp2->next;
		}
		else {
			cout << "End of list" << endl;
			return;
		}
	}
}

int DoublyLinkedList::size() {
	return counter;
}

Node* DoublyLinkedList::getFromTail(int x) {
	if (x < 0 || x >= counter) {
		cout << "getFromTail error" << endl;
		return nullptr;
	}

	int i = 0;
	Node* tmp = tail;

	while (i != x && tmp != nullptr) {
		tmp = tmp->next;
		i++;
	}

	return tmp;
}

Node* DoublyLinkedList::getFromHead(int x) {
	if (x < 0 || x >= counter) {
		cout << "getFromHead error" << endl;
		return nullptr;
	}

	int i = 0;
	Node* tmp = head;

	while (i != (counter-x-1) && tmp != nullptr) {
		tmp = tmp->previous;
		i++;
	}

	return tmp;
}