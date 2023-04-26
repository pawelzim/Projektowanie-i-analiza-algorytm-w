#include <iostream>
#include <stack>
#include "Header.h"

using namespace std;

void quicksort(DoublyLinkedList &lista) {
    quick_sort(lista.getFromTail(0), lista.getFromHead(lista.size() - 1));
}

void quick_sort(Node* tmpl, Node* tmpr) {
    if (tmpl == NULL || tmpr == NULL || tmpl == tmpr || tmpr->next == tmpl) {
        return;
    }

    stack<Node*> stack;
    stack.push(tmpl);
    stack.push(tmpr);

    while (!stack.empty()) {
        Node* end = stack.top();
        stack.pop();
        Node* start = stack.top();
        stack.pop();

        if (start == NULL || end == NULL || start == end || end->next == start) {
            continue;
        }

        Node* pivot = partition(start, end);

        stack.push(start);
        stack.push(pivot->previous);

        stack.push(pivot->next);
        stack.push(end);
    }
}

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