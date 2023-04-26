#include <iostream>
#include "Header.h"

using namespace std;

Node* partition(Node* start, Node* end) {
    int pivot = end->rate;
    Node* pivotNode = start;

    for (Node* i = start; i != end; i = i->next) {
        if (i->rate <= pivot) {
            swap(pivotNode->rate, i->rate);
            pivotNode = pivotNode->next;
        }
    }

    swap(pivotNode->rate, end->rate);

    return pivotNode;
}

void quick_sort(Node* start, Node* end) {
    if (start == NULL || end == NULL || start == end || end->next == start) {
        return;
    }

    Node* pivot = partition(start, end);

    quick_sort(start, pivot->previous);
    quick_sort(pivot->next, end);
}

void quicksort(DoublyLinkedList &lista) {
    quick_sort(lista.getFromTail(0), lista.getFromHead(lista.size() - 1));
}