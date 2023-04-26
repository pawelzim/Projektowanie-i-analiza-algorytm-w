#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
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
        if (i == -1 || i == 186112 || i == 368121 || i == 390575 || i == 405365) {
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

        lista.newHead(inde, nam, rat);

        if (i == limit) {
            break;
        }
    }
    file.close();
}

double measure_time(clock_t strt, clock_t stp, int n, char c) {
    fstream file;
    file.open("Wyniki.txt", ios::out | ios::app);
    if (!(file.good())) {
        cout << "Error opening file (wyniki.txt)" << endl;
        return static_cast<double>(stp - strt) / CLOCKS_PER_SEC;
    }
    if (c == 'q') {
        file << "Quicksort dla " << n << " elementów: " << static_cast<double>(stp - strt) / CLOCKS_PER_SEC << " s" << endl;
    }
    else if (c == 'm') {
        file << "Mergesort dla " << n << " elementów: " << static_cast<double>(stp - strt) / CLOCKS_PER_SEC << " s" << endl;
    }
    else if (c == 'b') {
        file << "Bucketsort dla " << n << " elementów: " << static_cast<double>(stp - strt) / CLOCKS_PER_SEC << " s" << endl;
    }
    else {
        cout << "Error measure time char" << endl;
    }
    file.close();
    return static_cast<double>(stp - strt) / CLOCKS_PER_SEC;
}

void check_list(DoublyLinkedList& lista) {
    Node* tmp = lista.getFromTail(0);
    float ctr = 0;
    while (tmp != nullptr) {
        if (ctr > tmp->rate) {
            cout << "Incorrect order" << endl;
            return;
        }
        if (tmp->rate > ctr) {
            ctr = tmp->rate;
        }
        tmp = tmp->next;
    }
    cout << "Correct order" << endl;
}

void Swap(Node* n1, Node* n2) {
    int index1 = n1->index;
    string name1 = n1->name;
    float rate1 = n1->rate;
    n1->index = n2->index;
    n1->name = n2->name;
    n1->rate = n2->rate;
    n2->index = index1;
    n2->name = name1;
    n2->rate = rate1;
}