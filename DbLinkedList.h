#ifndef DOUBLELL_H
#define DOUBLELL_H

#include "Falla.h"
#include <iostream>
using namespace std;

struct DbLinkedListNode {
    Falla data;
    DbLinkedListNode* next;
    DbLinkedListNode* prev;

    DbLinkedListNode(Falla data, DbLinkedListNode* prev, DbLinkedListNode* next) {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }

    DbLinkedListNode(Falla data) : DbLinkedListNode(data, nullptr, nullptr) {}
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
    void insertFirst(Falla data);
    void insertLast(Falla data);
    void insertAt(Falla data, int pos);
    void setAt(Falla data, int pos);
    void removeFirst();
    void removeLast();
    void removeAt(int pos);
    friend ostream& operator << (ostream& os, const DbLinkedList& dbll) {
        DbLinkedListNode* current = dbll.head;
        for (int i = 0; i < dbll.size; i++) {
            os << current->data << " ";
            current = current->next;
        }
        os << endl;
        return os;
    }
};

#endif