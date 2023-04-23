#include <iostream>
#include "Header.h"

using namespace std;

void mergesort_main(DoublyLinkedList& lista) {
    Node* tmpl = lista.getFromTail(0);
    Node* tmpl = lista.getFromHead(lista.size() - 1);
    mergesort(lista, 0, (lista.size() - 1), tmpl);
}

void mergesort(DoublyLinkedList& lista, int left, int right, Node* tmpl) {
    if (right <= left) {
        return;
    }

    int middle = (right + left) / 2;

    Node* tmpl1 = new Node(*tmpl);
    Node* tmpl2 = new Node(*tmpl1);

    mergesort(lista, left, middle, tmpl1);

    for (int i = 0; i < middle + 1; i++) {
        if (tmpl2->next != nullptr) {
            tmpl2 = tmpl2->next;
        }
    }

    mergesort(lista, middle + 1, right, tmpl2);
    
    merge(lista, left, middle, right, tmpl);
}

void merge(DoublyLinkedList& lista, int left, int middle, int right, Node *tmpl) {
    int i = 0;
    int j = ((right - left) / 2) + 1;
    middle = (right - left) / 2;
    int right2 = right - left;
    DoublyLinkedList l1;
    Node* tmpi = nullptr, * tmpj = nullptr;

    Node* tmp = new Node(*tmpl);
    Node* tmp2 = tmp;

    //if (left >= lista.size() / 2) {
    //    tmp = lista.getFromHead(left);
    //    tmp2 = tmp;
    //}
    //else {
    //    tmp = lista.getFromTail(left);
    //    tmp2 = tmp;
    //}

    for (int k = left; k <= right; k++) {
        l1.newHead(tmp->index, tmp->name, tmp->rate);
        tmp = tmp->next;
    }

    tmpi = l1.getFromTail(0);
    tmpj = l1.getFromTail(j);

    for (int k = left; k <= right; k++) {
        if (i <= middle) {
            if (j <= right2) {
                if (tmpj->rate < tmpi->rate) {
                    tmp2->index = tmpj->index;
                    tmp2->name = tmpj->name;
                    tmp2->rate = tmpj->rate;
                    tmpj = tmpj->next;
                    j++;
                }
                else {
                    tmp2->index = tmpi->index;
                    tmp2->name = tmpi->name;
                    tmp2->rate = tmpi->rate;
                    tmpi = tmpi->next;
                    i++;
                }
            }
            else {
                tmp2->index = tmpi->index;
                tmp2->name = tmpi->name;
                tmp2->rate = tmpi->rate;
                tmpi = tmpi->next;
                i++;
            }
        }
        else {
            tmp2->index = tmpj->index;
            tmp2->name = tmpj->name;
            tmp2->rate = tmpj->rate;
            tmpj = tmpj->next;
            j++;
        }
        tmp2 = tmp2->next;
    }
}