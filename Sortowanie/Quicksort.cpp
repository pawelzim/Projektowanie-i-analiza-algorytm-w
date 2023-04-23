#include <iostream>
#include "Header.h"

using namespace std;

void quicksort(DoublyLinkedList& l1, char c) {
    if (c == 'a') {
        quicksort_a(l1, 0, l1.size() - 1);
    }
    else if (c == 'b') {
        quicksort_b(l1, 0, l1.size() - 1);
    }
    else {
        cout << "Error quicksort option" << endl;
    }
}

// dla listy jednokierunkowej
void quicksort_a(DoublyLinkedList& l1, int left, int right) {
    if (left >= right) {
        cout << "Error quicksort_a" << endl;
        return;
    }
    Node* tmpl, * tmpr;
    //tmpl = l1.getPointer(left);
    //tmpr = l1.getPointer(right);
//    Node* piv = l1.pivot(tmpl, tmpr);
    int auxL = left;
    int auxR = right;

    while (auxL <= auxR) {
        //while (piv->rate > l1.getPointer(auxL)->rate) auxL++;
        //while (piv->rate < l1.getPointer(auxR)->rate) auxR--;

        if (auxL <= auxR) {
            //            l1.swap(l1.getPointer(auxL), l1.getPointer(auxR));
            auxL++;
            auxR--;
        }
        if (auxL <= auxR) {
            break;
        }
    }

    if (auxR > left)
        quicksort_a(l1, left, auxR);
    if (auxL < right)
        quicksort_a(l1, auxL, right);
}

// dla listy dwukierunkowej
void quicksort_b(DoublyLinkedList& l1, int left, int right) {
    if (left >= right) {
        cout << "Error quicksort_b" << endl;
        return;
    }

    int auxL = left;
    int auxR = right;
    Node* piv = new Node();

    if (auxL > ((l1.size() - 1) / 2)) {
        piv = l1.pivot(l1.getFromHead(left), l1.getFromHead(right));
    }
    else if (auxR < ((l1.size() - 1) / 2)) {
        piv = l1.pivot(l1.getFromTail(left), l1.getFromTail(right));
    }
    else {
        piv = l1.pivot(l1.getFromTail(left), l1.getFromHead(right));
    }

    while (auxL <= auxR) {
        while (piv->rate > l1.getFromTail(auxL)->rate) auxL++;
        while (piv->rate < l1.getFromHead(auxR)->rate) auxR--;

        if (auxL <= auxR) {
            if (auxL > ((l1.size() - 1) / 2)) {
                l1.swap(l1.getFromHead(auxL), l1.getFromHead(auxR));
            }
            else if (auxR < ((l1.size() - 1) / 2)) {
                l1.swap(l1.getFromTail(auxL), l1.getFromTail(auxR));
            }
            else {
                l1.swap(l1.getFromTail(auxL), l1.getFromHead(auxR));
            }
            auxL++;
            auxR--;
        }
        if (auxL <= auxR) {
            break;
        }
    }

    if (auxR > left)
        quicksort_b(l1, left, auxR);
    if (auxL < right)
        quicksort_b(l1, auxL, right);
}