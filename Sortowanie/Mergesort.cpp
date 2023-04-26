#include <iostream>
#include "Header.h"

using namespace std;

void mergesort(DoublyLinkedList& lista) {
    merge_sort(lista, lista.getFromTail(0), lista.getFromHead(lista.size() - 1));
}

void merge_sort(DoublyLinkedList& dll, Node* left, Node* right) {
    if (left == right) {
        return;
    }

    Node* middle = left;
    Node* end = left;
    while (end != right && end->next != right) {
        middle = middle->next;
        end = end->next->next;
    }

    merge_sort(dll, left, middle);
    merge_sort(dll, middle->next, right);
    merge(dll, left, middle, right);
}

void merge(DoublyLinkedList& dll, Node* left, Node* mid, Node* right) {
    DoublyLinkedList left_list;
    DoublyLinkedList right_list;

    Node* cur = left;
    while (cur != mid->next) {
        left_list.newHead(cur->index, cur->name, cur->rate);
        cur = cur->next;
    }
    while (cur != right->next) {
        right_list.newHead(cur->index, cur->name, cur->rate);
        cur = cur->next;
    }

    Node* i = left_list.getFromTail(0);
    Node* j = right_list.getFromTail(0);
    cur = left;
    while (i && j) {
        if (i->rate <= j->rate) {
            Swap(cur, i);
            i = i->next;
        }
        else {
            Swap(cur, j);
            j = j->next;
        }
        cur = cur->next;
    }

    while (i) {
        Swap(cur, i);
        i = i->next;
        cur = cur->next;
    }

    while (j) {
        Swap(cur, j);
        j = j->next;
        cur = cur->next;
    }
}