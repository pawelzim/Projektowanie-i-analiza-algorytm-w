#include <iostream>
#include "Header.h"

using namespace std;

void mergesort(DoublyLinkedList& lista) {
    merge_sort(lista.getFromTail(0), lista.getFromHead(lista.size() - 1));
}

void merge_sort(Node* left, Node* right) {
    if (left == right) {
        return;
    }

    Node* start = left;
    Node* end = right;

    while (start != end && start != end->previous) {
        start = start->next;
        end = end->previous;
    }

    Node* middle = start;

    merge_sort(left, middle);
    merge_sort(middle->next, right);
    merge(left, middle, right);
}

void merge(Node* left, Node* middle, Node* right) {
    DoublyLinkedList l1;
    DoublyLinkedList l2;

    Node* tmpl = left;
    while (tmpl != middle->next) {
        l1.newHead(tmpl->index, tmpl->name, tmpl->rate);
        tmpl = tmpl->next;
    }
    while (tmpl != right->next) {
        l2.newHead(tmpl->index, tmpl->name, tmpl->rate);
        tmpl = tmpl->next;
    }

    Node* l = l1.getFromTail(0);
    Node* r = l2.getFromTail(0);

    tmpl = left;

    while (l != nullptr && r != nullptr) {
        if (l->rate <= r->rate) {
            Swap(tmpl, l);
            l = l->next;
        }
        else {
            Swap(tmpl, r);
            r = r->next;
        }
        tmpl = tmpl->next;
    }

    while (l != nullptr) {
        Swap(tmpl, l);
        l = l->next;
        tmpl = tmpl->next;
    }

    while (r != nullptr) {
        Swap(tmpl, r);
        r = r->next;
        tmpl = tmpl->next;
    }
}