#include <iostream>
#include "Header.h"

using namespace std;

void bucketsort(DoublyLinkedList& lista) {
    DoublyLinkedList l[10];
    int ctr = 0;
    Node* tmp = lista.getFromTail(0);
    for (int i = 0; i < lista.size(); i++) {
        ctr = (int)tmp->rate - 1;
        l[ctr].newHead(tmp->index, tmp->name, tmp->rate);
        tmp = tmp->next;
    }
    Node* tmp2 = lista.getFromTail(0);

    for (int i = 0; i < 10; i++) {
        tmp = l[i].getFromTail(0);
        for (int k = 0; k < l[i].size(); k++) {
            tmp2->index = tmp->index;
            tmp2->name = tmp->name;
            tmp2->rate = tmp->rate;
            tmp2 = tmp2->next;
            tmp = tmp->next;
        }
    }
}