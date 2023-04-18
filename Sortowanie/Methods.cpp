#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Header.h"

using namespace std;

void assignment(DoublyLinkedList &lista, int limit) {
    fstream file;
    file.open("projekt2_dane.csv");

    if (!(file.good())) {
        cout << "Error opening file" << endl;
        exit(0);
    }

    string line, l1, l2, l3, l4, nam;
    int inde, ctr = 0, i = -1;
    float rat;

    while (getline(file, line)) {
        if (i == -1 || i == 186112 || i == 368121 || i == 390575) {
            i++;
            continue;
        }
        stringstream ss(line);
        i++;

        getline(ss, l1, ',');
        getline(ss, l2, ',');
        if (l2[0] == '"') {
            getline(ss, l4, ',');
            while (l4[l4.length()-1] != '"' || count(l4.begin(), l4.end(), '"') % 2 == 0) {
                l2 = l2 + l4;
                getline(ss, l4, ',');
            }
            l2 = l2 + l4;
        }
        getline(ss, l3);
        if (l1.empty() || l2.empty() || l3.empty()) {
            continue;
        }

        inde = stoi(l1);
        nam = l2;
        rat = stof(l3);

        //cout << inde << ". " << nam << " " << rat << endl;

        lista.newHead(inde, nam, rat);

        if (i == limit) {
            break;
        }
    }
    file.close();
}

double measure_time(clock_t strt, clock_t stp) {
    return static_cast<double>(stp - strt) / CLOCKS_PER_SEC;
}

// ------------SORTOWANIA------------

// ------------quicksort-------------

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
void quicksort_a(DoublyLinkedList &l1, int left, int right) {
    if (left >= right) {
        cout << "Error quicksort_a" << endl;
        return;
    }

    Node* piv = l1.pivot(l1.getFromTail(left), l1.getFromTail(right));
    int auxL = left;
    int auxR = right;
    
    while (auxL <= auxR) {
        while (piv->rate > l1.getFromTail(auxL)->rate) auxL++;
        while (piv->rate < l1.getFromTail(auxR)->rate) auxR--;

        if (auxL <= auxR) {
            l1.swap(l1.getFromTail(auxL), l1.getFromTail(auxR));
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

// ------------mergesort-------------

void mergesort_main(DoublyLinkedList& lista, char c) {
    if (c != 'a' && c != 'b' && c != 'c') {
        cout << "mergesort_main error" << endl;
    }
    else {
        mergesort(lista, 0, (lista.size() - 1), c);
    }
}

void mergesort(DoublyLinkedList& lista, int left, int right, char c) {
    if (right <= left) {
        return;
    }

    int middle = (right + left) / 2;

    mergesort(lista, left, middle, c);
    mergesort(lista, middle + 1, right, c);
    if (c == 'a') {
        merge_a(lista, left, middle, right);
    }
    if (c == 'b') {
        merge_b(lista, left, middle, right);
    }
    if (c == 'c') {
        merge_roboczy(lista, left, middle, right);
    }
}

void merge_a(DoublyLinkedList& lista, int left, int middle, int right) {
    int i = 0;
    int j = ((right - left) / 2) + 1;
    middle = (right - left) / 2;
    int right2 = right - left;
    DoublyLinkedList l1;
    Node* tmp;

    for (int k = left; k <= right; k++) {
        tmp = lista.getFromTail(k);
        l1.newHead(tmp->index, tmp->name, tmp->rate);
    }

    for (int k = left; k <= right; k++) {
        if (i <= middle) {
            if (j <= right2) {
                if (l1.getFromTail(j)->rate < l1.getFromTail(i)->rate) {
                    tmp = l1.getFromTail(j);
                    lista.getFromTail(k)->index = tmp->index;
                    lista.getFromTail(k)->name = tmp->name;
                    lista.getFromTail(k)->rate = tmp->rate;
                    j++;
                }
                else {
                    tmp = l1.getFromTail(i);
                    lista.getFromTail(k)->index = tmp->index;
                    lista.getFromTail(k)->name = tmp->name;
                    lista.getFromTail(k)->rate = tmp->rate;
                    i++;
                }
            }
            else {
                tmp = l1.getFromTail(i);
                lista.getFromTail(k)->index = tmp->index;
                lista.getFromTail(k)->name = tmp->name;
                lista.getFromTail(k)->rate = tmp->rate;
                i++;
            }
        }
        else {
            tmp = l1.getFromTail(j);
            lista.getFromTail(k)->index = tmp->index;
            lista.getFromTail(k)->name = tmp->name;
            lista.getFromTail(k)->rate = tmp->rate;
            j++;
        }
    }
}

void merge_roboczy(DoublyLinkedList& lista, int left, int middle, int right) {
    int i = 0;
    int j = ((right - left) / 2) + 1;
    middle = (right - left) / 2;
    int right2 = right - left;
    DoublyLinkedList l1;
    Node* tmp, * tmp2, * tmpi, * tmpj = nullptr;

    if (left >= lista.size() / 2) {
        tmp = lista.getFromHead(left);
        tmp2 = lista.getFromHead(left);
    }
    else {
        tmp = lista.getFromTail(left);
        tmp2 = lista.getFromTail(left);
    }

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

void merge_b(DoublyLinkedList& lista, int left, int middle, int right) {
    int i = 0;
    int j = ((right - left) / 2) + 1;
    middle = (right - left) / 2;
    int right2 = right - left;
    DoublyLinkedList l1;
    Node* tmp;
    Node* tmp2;

    for (int k = left; k <= right; k++) {
        if (k >= lista.size()/2) {
            tmp = lista.getFromHead(k);
        }
        else {
            tmp = lista.getFromTail(k);
        }
        l1.newHead(tmp->index, tmp->name, tmp->rate);
    }
    
    for (int k = left; k <= right; k++) {
        if (i <= middle) {
            if (j <= right2) {
                if (l1.getFromTail(j)->rate < l1.getFromTail(i)->rate) {
                    if (k >= lista.size() / 2) {
                        if (j >= l1.size() / 2) {
                            tmp = l1.getFromHead(j);
                            lista.getFromHead(k)->index = tmp->index;
                            lista.getFromHead(k)->name = tmp->name;
                            lista.getFromHead(k)->rate = tmp->rate;
                            j++;
                        }
                        else {
                            tmp = l1.getFromTail(j);
                            lista.getFromHead(k)->index = tmp->index;
                            lista.getFromHead(k)->name = tmp->name;
                            lista.getFromHead(k)->rate = tmp->rate;
                            j++;
                        }
                    }
                    else {
                        if (j >= l1.size() / 2) {
                            tmp = l1.getFromHead(j);
                            lista.getFromTail(k)->index = tmp->index;
                            lista.getFromTail(k)->name = tmp->name;
                            lista.getFromTail(k)->rate = tmp->rate;
                            j++;
                        }
                        else {
                            tmp = l1.getFromTail(j);
                            lista.getFromTail(k)->index = tmp->index;
                            lista.getFromTail(k)->name = tmp->name;
                            lista.getFromTail(k)->rate = tmp->rate;
                            j++;
                        }
                    }
                }
                else {
                    if (k >= lista.size() / 2) {
                        if (i >= l1.size() / 2) {
                            tmp = l1.getFromHead(i);
                            lista.getFromHead(k)->index = tmp->index;
                            lista.getFromHead(k)->name = tmp->name;
                            lista.getFromHead(k)->rate = tmp->rate;
                            i++;
                        }
                        else {
                            tmp = l1.getFromTail(i);
                            lista.getFromHead(k)->index = tmp->index;
                            lista.getFromHead(k)->name = tmp->name;
                            lista.getFromHead(k)->rate = tmp->rate;
                            i++;
                        }
                    }
                    else {
                        if (i >= l1.size() / 2) {
                            tmp = l1.getFromHead(i);
                            lista.getFromTail(k)->index = tmp->index;
                            lista.getFromTail(k)->name = tmp->name;
                            lista.getFromTail(k)->rate = tmp->rate;
                            i++;
                        }
                        else {
                            tmp = l1.getFromTail(i);
                            lista.getFromTail(k)->index = tmp->index;
                            lista.getFromTail(k)->name = tmp->name;
                            lista.getFromTail(k)->rate = tmp->rate;
                            i++;
                        }
                    }
                }
            }
            else {
                if (k >= lista.size() / 2) {
                    if (i >= l1.size() / 2) {
                        tmp = l1.getFromHead(i);
                        lista.getFromHead(k)->index = tmp->index;
                        lista.getFromHead(k)->name = tmp->name;
                        lista.getFromHead(k)->rate = tmp->rate;
                        i++;
                    }
                    else {
                        tmp = l1.getFromTail(i);
                        lista.getFromHead(k)->index = tmp->index;
                        lista.getFromHead(k)->name = tmp->name;
                        lista.getFromHead(k)->rate = tmp->rate;
                        i++;
                    }
                }
                else {
                    if (i >= l1.size() / 2) {
                        tmp = l1.getFromHead(i);
                        lista.getFromTail(k)->index = tmp->index;
                        lista.getFromTail(k)->name = tmp->name;
                        lista.getFromTail(k)->rate = tmp->rate;
                        i++;
                    }
                    else {
                        tmp = l1.getFromTail(i);
                        lista.getFromTail(k)->index = tmp->index;
                        lista.getFromTail(k)->name = tmp->name;
                        lista.getFromTail(k)->rate = tmp->rate;
                        i++;
                    }
                }
            }
        }
        else {
            if (k >= lista.size() / 2) {
                if (j >= l1.size() / 2) {
                    tmp = l1.getFromHead(j);
                    lista.getFromHead(k)->index = tmp->index;
                    lista.getFromHead(k)->name = tmp->name;
                    lista.getFromHead(k)->rate = tmp->rate;
                    j++;
                }
                else {
                    tmp = l1.getFromTail(j);
                    lista.getFromHead(k)->index = tmp->index;
                    lista.getFromHead(k)->name = tmp->name;
                    lista.getFromHead(k)->rate = tmp->rate;
                    j++;
                }
            }
            else {
                if (j >= l1.size() / 2) {
                    tmp = l1.getFromHead(j);
                    lista.getFromTail(k)->index = tmp->index;
                    lista.getFromTail(k)->name = tmp->name;
                    lista.getFromTail(k)->rate = tmp->rate;
                    j++;
                }
                else {
                    tmp = l1.getFromTail(j);
                    lista.getFromTail(k)->index = tmp->index;
                    lista.getFromTail(k)->name = tmp->name;
                    lista.getFromTail(k)->rate = tmp->rate;
                    j++;
                }
            }
        }
    }
}

// -------------bucketsort--------------

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