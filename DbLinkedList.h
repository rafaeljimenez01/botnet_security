#ifndef DOUBLELL_H
#define DOUBLELL_H

#include "Falla.h"
#include <iostream>
using namespace std;

struct DbLinkedListNode {
    Falla falla;
    DbLinkedListNode* next;
    DbLinkedListNode* prev;

    DbLinkedListNode(Falla falla, DbLinkedListNode* prev, DbLinkedListNode* next) {
        this->falla = falla;
        this->prev = prev;
        this->next = next;
    }

    DbLinkedListNode(Falla falla) : DbLinkedListNode(falla, nullptr, nullptr) {}
};

class DbLinkedList {
private:
    DbLinkedListNode* head;
    DbLinkedListNode* tail;
    int size = 0;
public:
    DbLinkedList();
    ~DbLinkedList();
    Falla first();
    Falla last();
    int length();
    Falla getAt(int pos);
    bool isEmpty();
    void insertFirst(Falla falla);
    void insertLast(Falla falla);
    void insertAt(Falla falla, int pos);
    void setAt(Falla falla, int pos);
    void removeFirst();
    void removeLast();
    void removeAt(int pos);
    friend ostream& operator << (ostream& os, const DbLinkedList& dbll) {
        DbLinkedListNode* current = dbll.head;
        for (int i = 0; i < dbll.size; i++) {
            os << current->falla << endl;
            current = current->next;
        }
        return os;
    }
};

#endif